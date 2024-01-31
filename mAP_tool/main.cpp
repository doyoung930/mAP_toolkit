#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <GL/glew.h>
#include <GL/glut.h>


#include <iostream>
#include <experimental/filesystem>

//int main() {
//    std::experimental::filesystem::path currentPath = std::experimental::filesystem::current_path();
//    std::cout << "현재 작업 디렉토리: " << currentPath << std::endl;
//
//    return 0;
//}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    // 여기에 렌더링 코드를 추가할 수 있습니다.
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
}

int main(int argc, char** argv) {
    // GLUT 초기화
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutCreateWindow("OpenGL Window");

    // GLEW 초기화
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "GLEW 초기화 실패\n");
        return -1;
    }

    // 렌더링 함수 지정
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);

    // OpenGL 초기화
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // 렌더링 루프 진입
    glutMainLoop();

    return 0;
}