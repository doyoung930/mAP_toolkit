#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <map>

std::map<int, std::string> CharMap;

namespace fs = std::filesystem;

std::string GetIntToStr(std::string str)
{
    return CharMap[std::stoi(str)];
}

void readAndCompareTxtFiles(const std::string& directoryPath) {
    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.path().extension() == ".txt") {
                std::string filename = entry.path().filename().string();
                std::ifstream file(entry.path());

                if (file.is_open()) {
                    //std::cout << "File: " << filename << std::endl;
                    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
                    //std::cout << "Content:\n" << content << std::endl;
                    //std::cout << "----------------------\n";

                    std::vector<std::string> lines;
                    std::string line;
                    lines.reserve(4);
                    std::stringstream StringStream(content);
                    while (std::getline(StringStream, line, '\n'))
                    {
                        lines.push_back(line);
                    }

                    std::string ResultString = "";
                    for (const auto& l : lines)
                    {
                        std::stringstream Linecontent(l);
                        std::string temp;
                        Linecontent >> temp;
                        ResultString += GetIntToStr(temp);
                    }

                    if (std::string::npos == filename.find(ResultString))
                    {
                        std::cout << "File: " << filename << std::endl;
                        std::cout << "\"" << ResultString << "\" is Different!" << std::endl;
                    }

                    file.close();
                }
                else {
                    std::cerr << "Unable to open file: " << filename << std::endl;
                }
            }
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

void Init()
{
    CharMap.insert(std::make_pair(1, "1"));
    CharMap.insert(std::make_pair(2, "2"));
    CharMap.insert(std::make_pair(3, "3"));
    CharMap.insert(std::make_pair(4, "4"));
    CharMap.insert(std::make_pair(5, "5"));
    CharMap.insert(std::make_pair(6, "6"));
    CharMap.insert(std::make_pair(7, "7"));
    CharMap.insert(std::make_pair(8, "8"));
    CharMap.insert(std::make_pair(9, "9"));
    CharMap.insert(std::make_pair(10, "0"));
    CharMap.insert(std::make_pair(11, "가"));
    CharMap.insert(std::make_pair(12, "나"));
    CharMap.insert(std::make_pair(13, "다"));
    CharMap.insert(std::make_pair(14, "라"));
    CharMap.insert(std::make_pair(15, "마"));
    CharMap.insert(std::make_pair(16, "바"));
    CharMap.insert(std::make_pair(17, "사"));
    CharMap.insert(std::make_pair(18, "아"));
    CharMap.insert(std::make_pair(19, "자"));
    CharMap.insert(std::make_pair(20, "거"));
    CharMap.insert(std::make_pair(21, "너"));
    CharMap.insert(std::make_pair(22, "더"));
    CharMap.insert(std::make_pair(23, "러"));
    CharMap.insert(std::make_pair(24, "머"));
    CharMap.insert(std::make_pair(25, "버"));
    CharMap.insert(std::make_pair(26, "서"));
    CharMap.insert(std::make_pair(27, "어"));
    CharMap.insert(std::make_pair(28, "저"));
    CharMap.insert(std::make_pair(29, "고"));
    CharMap.insert(std::make_pair(30, "노"));
    CharMap.insert(std::make_pair(31, "도"));
    CharMap.insert(std::make_pair(32, "로"));
    CharMap.insert(std::make_pair(33, "모"));
    CharMap.insert(std::make_pair(34, "보"));
    CharMap.insert(std::make_pair(35, "소"));
    CharMap.insert(std::make_pair(36, "오"));
    CharMap.insert(std::make_pair(37, "조"));
    CharMap.insert(std::make_pair(38, "구"));
    CharMap.insert(std::make_pair(39, "누"));
    CharMap.insert(std::make_pair(40, "두"));
    CharMap.insert(std::make_pair(41, "루"));
    CharMap.insert(std::make_pair(42, "무"));
    CharMap.insert(std::make_pair(43, "부"));
    CharMap.insert(std::make_pair(44, "수"));
    CharMap.insert(std::make_pair(45, "우"));
    CharMap.insert(std::make_pair(46, "주"));
    CharMap.insert(std::make_pair(47, "허"));
    CharMap.insert(std::make_pair(48, "하"));
    CharMap.insert(std::make_pair(49, "호"));
    CharMap.insert(std::make_pair(50, "배"));
    CharMap.insert(std::make_pair(51, "공"));
    CharMap.insert(std::make_pair(52, "해"));
    CharMap.insert(std::make_pair(53, "육"));
    CharMap.insert(std::make_pair(54, "합"));
    CharMap.insert(std::make_pair(55, "국"));
    CharMap.insert(std::make_pair(56, "울"));
    CharMap.insert(std::make_pair(57, "경"));
    CharMap.insert(std::make_pair(58, "기"));
    CharMap.insert(std::make_pair(59, "강"));
    CharMap.insert(std::make_pair(60, "원"));
    CharMap.insert(std::make_pair(61, "북"));
    CharMap.insert(std::make_pair(62, "대"));
    CharMap.insert(std::make_pair(63, "남"));
    CharMap.insert(std::make_pair(64, "전"));
    CharMap.insert(std::make_pair(65, "산"));
    CharMap.insert(std::make_pair(66, "제"));
    CharMap.insert(std::make_pair(67, "영"));
    CharMap.insert(std::make_pair(68, "충"));
    CharMap.insert(std::make_pair(69, "인"));
    CharMap.insert(std::make_pair(70, "천"));
    CharMap.insert(std::make_pair(71, "세"));
    CharMap.insert(std::make_pair(72, "종"));
}

int main() {
    Init();

    std::string directoryPath = "C:\\Users\\user\\Desktop\\LPR vat\\aihub_lpr";
    readAndCompareTxtFiles(directoryPath);

    return 0;
}