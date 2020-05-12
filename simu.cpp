#include <stdio.h>
#include <cmath>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"
#define G_NUM 9.8 // 重力加速度
#define TIME_STEP 1 // 1秒間に何秒進めるか
#define FRAME_RATE 1/60 // 描画の関数が呼ばれる時間
#define TIME FRAME_RATE * TIME_STEP
#define E_NUM 0.7 // 反発係数

void calc(Obj& obj) {
    /*
     * 重力による変位のみ計算
     */
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    if ((obj.y+obj.size) >= h) {
        float diff = h - (obj.y + obj.size);
        obj.vy = E_NUM * -obj.vy;
        obj.y = h - obj.size;
    }

    if ((obj.y-obj.size) <= 0) {
        float diff = obj.y - obj.size;
        obj.vy = E_NUM * -obj.vy;
        obj.y = 0+obj.size;
    }

    obj.vy += obj.ay * TIME;
    obj.y += obj.vy * TIME; // dx = v dt

    drawSquare(obj.x, obj.y, obj.size);
}
