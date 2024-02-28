#include "MapCalculation.h"



void MapCalculation::SaveIoU() {

   //auto true_it = _true_bboxes.begin();
   //auto predicted_it = _predicted_bboxes.begin();
   //for (; true_it != _true_bboxes.end()
   //    && predicted_it != _predicted_bboxes.end();
   //    ++true_it, ++predicted_it) {
   //    const int& class_name = true_it->id;
   //    const BoundingBox& true_box = *true_it;
   //    const BoundingBox& predicted_box = *predicted_it;
   //
   //    _id_IoU.emplace_back(class_name, CalculateIoU(true_box, predicted_box));
   //}

    float temp_iou = 0;
    for (auto& true_it : _true_bboxes) {
        const int& class_name = true_it.id;
        for (auto& predicted_it : _predicted_bboxes) {
            temp_iou = (temp_iou > CalculateIoU(true_it, predicted_it) ? temp_iou : CalculateIoU(true_it, predicted_it;
        }
        _id_IoU.emplace_back(class_name, temp_iou);
    }
}


float MapCalculation::CalculateIoU(const BoundingBox& box1, const BoundingBox& box2) {
    float intersection_width = std::max(0.f, std::min(box1.x + box1.width, box2.x + box2.width) - std::max(box1.x, box2.x));
    float intersection_height = std::max(0.f, std::min(box1.y + box1.height, box2.y + box2.height) - std::max(box1.y, box2.y));

    float intersection_area = intersection_width * intersection_height;
    float union_area = box1.width * box1.height + box2.width * box2.height - intersection_area;

    if (union_area == 0)
        return 0; 

    return intersection_area / union_area;
}


void MapCalculation::CalculationTPFPFN() {
    auto true_it = _true_bboxes.begin();
    auto predicted_it = _predicted_bboxes.begin();
    auto iou_it = _id_IoU.begin();
    
    int tp = 0, fp = 0, fn = 0; // TP, FP, FN 값 초기화

    std::vector<vector<float>> precisions; 
    std::vector<vector<float>> recalls; 

    for (; true_it != _true_bboxes.end() && predicted_it != _predicted_bboxes.end();
        ++true_it, ++predicted_it, ++iou_it) {
        if (true_it->id == predicted_it->id) {
            // 
            if (iou_it->iou >= t) {
                // tp
                tp++;
            }
            else {
                // fn
                fn++;
            }
        }
        else {
            if (iou_it->iou >= t) {
                // fp
                fp++;
            }
        }
        // Precision과 Recall을 계산하여 PR 곡선에 저장
        float precision = (tp + epsilon) / ((tp + fp) + epsilon);
        float recall = (tp + epsilon) / ((tp + fn) + epsilon);

        precisions[true_it->id].push_back(precision);
        recalls[true_it->id].push_back(recall);
    }
    for (int i = 1; i < precisions.size(); i++) {
        float ap = calculateAP(precisions[i], recalls[i]);

        aps.emplace_back(ap);
    }
  

    

}


float MapCalculation::calculateAP(const std::vector<float>& precisions, const std::vector<float>& recalls) {


    std::vector<float> interpolated_precisions;
    for (const auto& recall : recalls) {
        float max_precision = 0.0f;
        for (size_t i = 0; i < recalls.size(); ++i) {
            if (recalls[i] >= recall && precisions[i] > max_precision) {
                max_precision = precisions[i];
            }
        }
        interpolated_precisions.push_back(max_precision);
    }

   
    float ap = 0.0f;
    for (size_t i = 0; i < interpolated_precisions.size(); ++i) {
        ap += interpolated_precisions[i];
    }
    ap /= interpolated_precisions.size();

    return ap;
}

float MapCalculation::calculateMAP() {
    float total_ap = 0.0;
    for (const auto& ap : aps) {
        total_ap += ap;
    }
    return total_ap / aps.size(); 
}

void MapCalculation::Truth_GetData(string directory_path){

    // 특정 디렉토리에 있는 모든 .txt 파일 탐색
    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << entry.path().string() << std::endl;
                continue;
            }

            // 파일 내용 읽어서 _true_bboxes에 저장
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                int id;
                double x, y, w, h;
                if (!(iss >> id >> x >> y >> w >> h)) {
                    std::cerr << "Invalid input: " << line << std::endl;
                    continue;
                }
                _true_bboxes.emplace_back(id, x, y, w, h);
            }

            // 파일 닫기
            file.close();
        }
    }
}

void MapCalculation::Predicted_GetData(string directory_path) {

    // 특정 디렉토리에 있는 모든 .txt 파일 탐색
    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << entry.path().string() << std::endl;
                continue;
            }

            // 파일 내용 읽어서 _true_bboxes에 저장
            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                int id;
                double x, y, w, h;
                if (!(iss >> id >> x >> y >> w >> h)) {
                    std::cerr << "Invalid input: " << line << std::endl;
                    continue;
                }
                _true_bboxes.emplace_back(id, x, y, w, h);
            }

            // 파일 닫기
            file.close();
        }
    }
}