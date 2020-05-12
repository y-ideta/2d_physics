#include <vector>
#include <GLUT/glut.h>

#include "draw.h"
#include "mouse.h"


using namespace std;



void display(void) {
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT); // ウィンドウの塗り潰し
    vector<vector<int> > vtx = {
        {w/2+10, h/2-10},
        {w/2-10, h/2-10},
        {w/2-10, h/2+10},
        {w/2+10, h/2+10},
    };
    drawSquare(vtx); // 四角形の描画
    drawBaseLine(w, h); 

    glFlush(); // 処理の実行
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-0.5, (GLdouble)w - 0.5, (GLdouble)h - 0.5, -0.5, -1.0, 1.0);
    // glOrtho(-w / 200.0, w / 200.0, -h / 200.0, h / 200.0, -1.0, 1.0);
}

void init(void) {
    /*
     * 画面の初期化
     * RGBA: 0~1, 0~1, 0~1, 0~1
     */
    glClearColor(0.7, 0.7, 0.7, 0.7); // 背景色の指定
}

int main(int argc, char * argv[]) {
    glutInitWindowSize(320, 240); // ウィンドウズサイズの固定
    glutInit(&argc, argv); // GLUT,OpenGL環境の初期化
    glutInitDisplayMode(GLUT_RGBA); // ディスプレイの表示モード
    glutCreateWindow("2D simulator"); // ウィンドウの作成
    glutDisplayFunc(display); // 画面表示を行う関数を受け取る関数
    glutReshapeFunc(resize);
    glutMouseFunc(mouse); // マウスイベントの取得
    init(); // 初期化の関数をここで呼ぶ
    glutMainLoop(); // 無限ループ(イベントの待ち受け状態にする)
    return 0;
}
