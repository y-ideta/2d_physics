#include <stdio.h>
#include <GLUT/glut.h>

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */
int rubberband = 0;        /* ラバーバンドの消去 */


void mouse(int button, int state, int x, int y) {

    switch (button) {
        case GLUT_LEFT_BUTTON:
            point[pointnum][0] = x;
            point[pointnum][1] = y;
            if (state == GLUT_UP) {
                glColor3d(0, 0, 0);
                glBegin(GL_LINES);
                glVertex2iv(point[pointnum - 1]);
                glVertex2iv(point[pointnum]);
                glEnd();
                glFlush();
                rubberband = 0;
            }
            if (pointnum < MAXPOINTS - 1) ++pointnum;
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
        default:
            break;
    }

    printf(" at (%d, %d)\n", x, y);
}

void motion(int x, int y) {

  static GLint savepoint[2]; /* 以前のラバーバンドの端点 */

  /* 論理演算機能 ON */
  glEnable(GL_COLOR_LOGIC_OP);
  glLogicOp(GL_INVERT);

  glBegin(GL_LINES);
  if (rubberband) {
    /* 以前のラバーバンドを消す */
    glVertex2iv(point[pointnum - 1]);
    glVertex2iv(savepoint);
  }
  /* 新しいラバーバンドを描く */
  glVertex2iv(point[pointnum - 1]);
  glVertex2i(x, y);
  glEnd();

  glFlush();

  /* 論理演算機能 OFF */
  glLogicOp(GL_COPY);
  glDisable(GL_COLOR_LOGIC_OP);

  /* 今描いたラバーバンドの端点を保存 */
  savepoint[0] = x;
  savepoint[1] = y;
  rubberband = 1;
}
