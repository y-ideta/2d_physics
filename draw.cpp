#include <stdio.h>
#include <vector>
#include <cmath>
#include <math.h>
#include <GLUT/glut.h>

using namespace std;

void drawBaseLine(int w, int h) {
    /*
     * 十字に赤と青の線をひく
     */
    glLineWidth(1);
    glColor3d(1.0, 0.0, 0.0); // 線の色の指定
    glBegin(GL_LINE_LOOP); // 描画する線の種類
    glVertex2f(0, h/2);
    glVertex2f(w, h/2);
    glEnd();
    
    glColor3d(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(w/2, 0);
    glVertex2f(w/2, h);
    glEnd();
}

void drawSquare(int x, int y, int size) {
    /*
     * 四角形の描画
     * input: int x, int y, int size
     * output: none
     */
    glColor3d(0.0, 1.0, 0.0); // 線の色の指定
    glBegin(GL_POLYGON); // 描画する線の種類
    glVertex2i(x+size, y-size);
    glVertex2i(x+size, y+size);
    glVertex2i(x-size, y+size);
    glVertex2i(x-size, y-size);
    glEnd();
}

void drawArrow(int sx, int sy, int ex, int ey) {
    /*
     * 矢印の描画
     * input: int sx, int sy, int ex, int ey
     * 矢印のスタート位置と終了位置のを受け取る
     * output: none
     */
    extern int draged_idx;
    const int arrow_len = sqrt(pow(ex-sx, 2) + pow(ey - sy, 2));
    if (ex-sx == 0) return;
    float tilt = -1/(float(ey - sy)/float(ex - sx));
    if (draged_idx < 0) return;

    glColor3d(0.0, 0.0, 0.0); // 線の色の指定
    glLineWidth(5);
    glBegin(GL_LINES); // 描画する線の種類
    glVertex2i(sx, sy);
    glVertex2i(ex, ey);
    glEnd();
}
