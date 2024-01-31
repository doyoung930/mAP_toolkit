#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<GL/glew.h>
#include<GL/glut.h>

#include <iostream>
#include <experimental/filesystem>

int main() {
    std::experimental::filesystem::path currentPath = std::experimental::filesystem::current_path();
    std::cout << "현재 작업 디렉토리: " << currentPath << std::endl;

    return 0;
}