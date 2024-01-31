#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <GL/glew.h>
#include <GL/glut.h>


#include <iostream>
#include <experimental/filesystem>

//int main() {
//    std::experimental::filesystem::path currentPath = std::experimental::filesystem::current_path();
//    std::cout << "���� �۾� ���丮: " << currentPath << std::endl;
//
//    return 0;
//}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    // ���⿡ ������ �ڵ带 �߰��� �� �ֽ��ϴ�.
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char** argv) {
    // GLUT �ʱ�ȭ
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("OpenGL Window");

    // GLEW �ʱ�ȭ
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "GLEW �ʱ�ȭ ����\n");
        return -1;
    }

    // ������ �Լ� ����
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);

    // OpenGL �ʱ�ȭ
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // ������ ���� ����
    glutMainLoop();

    return 0;
}