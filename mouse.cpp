#include <stdio.h>
#include <GLUT/glut.h>

#define MAXPOINTS 100      /* 記憶する点の数　　 */
GLint point[MAXPOINTS][2]; /* 座標を記憶する配列 */
int pointnum = 0;          /* 記憶した座標の数　 */


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
