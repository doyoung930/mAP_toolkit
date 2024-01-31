#include <GL/glut.h>
#include "tool/Tool.h"

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("mAP Calculation Tool");

    // OpenGL ����
    glEnable(GL_DEPTH_TEST);

    // Facade ������ ����Ͽ� ����� �ϳ��� ����
    Tool mapTool;

    // ���Ͽ��� �����͸� �о����
    std::string fileName = "data.txt";  // ���� �̸��� ���ϴ� ���ϸ����� ����
    std::vector<std::string> data;

    // ��ü ��� ����
    //mapTool.run(data);

    glutMainLoop();

    return 0;
}