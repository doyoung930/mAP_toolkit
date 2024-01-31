#include <GL/glut.h>
#include "tool/Tool.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("mAP Calculation Tool");

    // OpenGL 설정
    glEnable(GL_DEPTH_TEST);

    // Facade 패턴을 사용하여 기능을 하나로 묶음
    Tool mapTool;

    // 파일에서 데이터를 읽어오기
    std::string fileName = "data.txt";  // 파일 이름은 원하는 파일명으로 변경
    std::vector<std::string> data;

    // 전체 기능 실행
    //mapTool.run(data);

    glutMainLoop();

    return 0;
}