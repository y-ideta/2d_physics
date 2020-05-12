#include <vector>
#include <GLUT/glut.h>

using namespace std;

void drawBaseLine(int w, int h) {
    /*
     * 十字に赤と青の線をひく
     */
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

void drawSquare(vector<vector<int> > vtxList) {
    /*
     * n角形の描画
     * input: Glint[][]
     * output: none
     */
    glColor3d(0.0, 1.0, 0.0); // 線の色の指定
    glBegin(GL_POLYGON); // 描画する線の種類
    for (vector<int> v : vtxList) {
        glVertex2i(v[0], v[1]);
    }
    glEnd();
}
