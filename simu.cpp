#include <stdio.h>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"

void calc(Obj& obj) {
    /*
     * 重力による変位のみ計算
     */
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    obj.y += obj.vy * 0.1; // v * t

    if (obj.y >= h || obj.y <= 0) {
        obj.vy = -obj.vy;
    }

    drawSquare(obj.x, obj.y, obj.size);
}
