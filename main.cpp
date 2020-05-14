#include <vector>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"
#include "mouse.h"
#include "simu.h"

using namespace std;

int w = glutGet(GLUT_WINDOW_WIDTH);
int h = glutGet(GLUT_WINDOW_HEIGHT);

vector<Obj> squareList;


void display(void) {
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT); // ウィンドウの塗り潰し

    calc();
    drawBaseLine(w, h); 

    glFlush(); // 処理の実行
    glutSwapBuffers(); // 描画をいい感じにしてくれるやつ
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
}

void init(void) {
    /*
     * 画面の初期化
     * RGBA: 0~1, 0~1, 0~1, 0~1
     */
    glClearColor(0.7, 0.7, 0.7, 0.7); // 背景色の指定
}

void idle() {
    glutPostRedisplay(); // glutDisplayFunc()の呼び出し
}

int main(int argc, char * argv[]) {
    glutInitWindowSize(320, 240); // ウィンドウズサイズの固定
    glutInit(&argc, argv); // GLUT,OpenGL環境の初期化
    glutInitDisplayMode(GLUT_RGBA); // ディスプレイの表示モード
    glutCreateWindow("2D simulator"); // ウィンドウの作成
    glutDisplayFunc(display); // 画面表示を行う関数を受け取る関数
    glutReshapeFunc(resize);
    glutMouseFunc(mouse); // マウスイベントの取得
    glutIdleFunc(idle); 
    init(); // 初期化の関数をここで呼ぶ
    glutMainLoop(); // 無限ループ(イベントの待ち受け状態にする)
    return 0;
}
