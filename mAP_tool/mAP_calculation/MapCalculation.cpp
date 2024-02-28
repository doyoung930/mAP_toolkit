#include "MapCalculation.h"


// IoU 저장 
void MapCalculation::SaveIoU() {
    float temp_iou = 0;
    for (auto& true_it : _true_bboxes) {
        const int& class_name = true_it.id;
        for (auto& predicted_it : _predicted_bboxes) {
            temp_iou = temp_iou > CalculateIoU(true_it, predicted_it) ? temp_iou : CalculateIoU(true_it, predicted_it);
        }
        _id_IoU.emplace_back(class_name, temp_iou);
    }
}

// IoU 계산
float MapCalculation::CalculateIoU(const BoundingBox& box1, const BoundingBox& box2) {
    float intersection_width = std::max(0.f, std::min(box1.x + box1.width, box2.x + box2.width) - std::max(box1.x, box2.x));
    float intersection_height = std::max(0.f, std::min(box1.y + box1.height, box2.y + box2.height) - std::max(box1.y, box2.y));

    float intersection_area = intersection_width * intersection_height;
    float union_area = box1.width * box1.height + box2.width * box2.height - intersection_area;

    if (union_area == 0)
        return 0; 

    return intersection_area / union_area;
}

// Confusion Matrix
void MapCalculation::CalculationTPFPFN() {
    auto true_it = temp_true_bboxes.begin();
    auto predicted_it = temp_predicted_bboxes.begin();
    auto iou_it = _id_IoU.begin();
    
    int tp = 0, fp = 0, fn = 0; // TP, FP, FN �� �ʱ�ȭ

    for (; true_it != temp_true_bboxes.end() && predicted_it != temp_predicted_bboxes.end();
        ++true_it, ++predicted_it, ++iou_it) {
        if (true_it->id == predicted_it->id) {
            // 
            if (iou_it->iou >= t) {
                // tp
                recalls[true_it->id].tp++;
            }
            else {
                // fn
                recalls[true_it->id].fn++;
            }
        }
    }
    for (auto& pair : recalls) {
        pair.second.tpfn = pair.second.tp + pair.second.fn;
        recalls[true_it->id].tp = 0;
        recalls[true_it->id].fn = 0;
    }
    true_it = temp_true_bboxes.begin();
    predicted_it = temp_predicted_bboxes.begin();
    iou_it = _id_IoU.begin();
    for (; true_it != temp_true_bboxes.end() && predicted_it != temp_predicted_bboxes.end();
        ++true_it, ++predicted_it, ++iou_it) {
        if (true_it->id == predicted_it->id) {
            // 
            if (iou_it->iou >= t) {
                // tp
                recalls[true_it->id].tp++;
                precisions[true_it->id].tp++;
            }
            else {
                // fn
                recalls[true_it->id].fn++;
                precisions[true_it->id].fn++;
            }
        }
        else {
            if (iou_it->iou >= t) {
                // fp
                recalls[true_it->id].fp++;
                precisions[true_it->id].fp++;
            }
            else
            {
                continue;
            }
        }
        float temp_precision = round((precisions[true_it->id].tp / (precisions[true_it->id].tp + precisions[true_it->id].fp + 0.0001f)) * 1000) / 1000;
        float temp_recall = round((recalls[true_it->id].tp) / (recalls[true_it->id].tpfn)) *1000/1000;

        precisions[true_it->id].precsision = temp_precision;
        recalls[true_it->id].recall = temp_recall;
    }
 //   for (int i = 1; i < precisions.size(); i++) {
//        float ap = calculateAP(precisions[i], recalls[i]);
//
 //       this->aps.emplace_back(ap);
 //   }


}
// AP 계산 
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

// mAP 계산
float MapCalculation::calculateMAP() {
    float total_ap = 0.0;
    for (const auto& ap : aps) {
        total_ap += ap;
    }
    return total_ap / aps.size(); 
}

void MapCalculation::Truth_GetData(string directory_path){

    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << entry.path().string() << std::endl;
                continue;
            }

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

            file.close();
        }
    }
}

void MapCalculation::Predicted_GetData(string directory_path) {

    for (const auto& entry : std::filesystem::directory_iterator(directory_path)) {
        if (entry.path().extension() == ".txt") {
            std::ifstream file(entry.path());
            if (!file.is_open()) {
                std::cerr << "Failed to open file: " << entry.path().string() << std::endl;
                continue;
            }
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

            file.close();
        }
    }
}