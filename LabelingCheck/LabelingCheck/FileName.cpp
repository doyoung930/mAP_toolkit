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
    CharMap.insert(std::make_pair(11, "��"));
    CharMap.insert(std::make_pair(12, "��"));
    CharMap.insert(std::make_pair(13, "��"));
    CharMap.insert(std::make_pair(14, "��"));
    CharMap.insert(std::make_pair(15, "��"));
    CharMap.insert(std::make_pair(16, "��"));
    CharMap.insert(std::make_pair(17, "��"));
    CharMap.insert(std::make_pair(18, "��"));
    CharMap.insert(std::make_pair(19, "��"));
    CharMap.insert(std::make_pair(20, "��"));
    CharMap.insert(std::make_pair(21, "��"));
    CharMap.insert(std::make_pair(22, "��"));
    CharMap.insert(std::make_pair(23, "��"));
    CharMap.insert(std::make_pair(24, "��"));
    CharMap.insert(std::make_pair(25, "��"));
    CharMap.insert(std::make_pair(26, "��"));
    CharMap.insert(std::make_pair(27, "��"));
    CharMap.insert(std::make_pair(28, "��"));
    CharMap.insert(std::make_pair(29, "��"));
    CharMap.insert(std::make_pair(30, "��"));
    CharMap.insert(std::make_pair(31, "��"));
    CharMap.insert(std::make_pair(32, "��"));
    CharMap.insert(std::make_pair(33, "��"));
    CharMap.insert(std::make_pair(34, "��"));
    CharMap.insert(std::make_pair(35, "��"));
    CharMap.insert(std::make_pair(36, "��"));
    CharMap.insert(std::make_pair(37, "��"));
    CharMap.insert(std::make_pair(38, "��"));
    CharMap.insert(std::make_pair(39, "��"));
    CharMap.insert(std::make_pair(40, "��"));
    CharMap.insert(std::make_pair(41, "��"));
    CharMap.insert(std::make_pair(42, "��"));
    CharMap.insert(std::make_pair(43, "��"));
    CharMap.insert(std::make_pair(44, "��"));
    CharMap.insert(std::make_pair(45, "��"));
    CharMap.insert(std::make_pair(46, "��"));
    CharMap.insert(std::make_pair(47, "��"));
    CharMap.insert(std::make_pair(48, "��"));
    CharMap.insert(std::make_pair(49, "ȣ"));
    CharMap.insert(std::make_pair(50, "��"));
    CharMap.insert(std::make_pair(51, "��"));
    CharMap.insert(std::make_pair(52, "��"));
    CharMap.insert(std::make_pair(53, "��"));
    CharMap.insert(std::make_pair(54, "��"));
    CharMap.insert(std::make_pair(55, "��"));
    CharMap.insert(std::make_pair(56, "��"));
    CharMap.insert(std::make_pair(57, "��"));
    CharMap.insert(std::make_pair(58, "��"));
    CharMap.insert(std::make_pair(59, "��"));
    CharMap.insert(std::make_pair(60, "��"));
    CharMap.insert(std::make_pair(61, "��"));
    CharMap.insert(std::make_pair(62, "��"));
    CharMap.insert(std::make_pair(63, "��"));
    CharMap.insert(std::make_pair(64, "��"));
    CharMap.insert(std::make_pair(65, "��"));
    CharMap.insert(std::make_pair(66, "��"));
    CharMap.insert(std::make_pair(67, "��"));
    CharMap.insert(std::make_pair(68, "��"));
    CharMap.insert(std::make_pair(69, "��"));
    CharMap.insert(std::make_pair(70, "õ"));
    CharMap.insert(std::make_pair(71, "��"));
    CharMap.insert(std::make_pair(72, "��"));
}

int main() {
    Init();

    std::string directoryPath = "C:\\Users\\user\\Desktop\\LPR vat\\aihub_lpr";
    readAndCompareTxtFiles(directoryPath);

    return 0;
}