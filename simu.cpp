#include <stdio.h>
#include <vector>
#include <cmath>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"

#define G_NUM 9.8 // 重力加速度
#define TIME_STEP 5 // 1秒間に何秒進めるか
#define FRAME_RATE 1/60 // 描画の関数が呼ばれる時間
#define TIME FRAME_RATE * TIME_STEP
#define E_NUM 0.8 // 反発係数

using namespace std;


void calc() {
    /*
     * 重力による変位のみ計算
     */
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    extern vector<Obj> squareList;
    for (Obj &obj : squareList) {
        if ((obj.y+obj.size) >= h) { // 床に当たった時
            float diff = h - (obj.y + obj.size);
            obj.vy = E_NUM * -obj.vy;
            obj.y = h - obj.size + diff; // diffを足してやらないとはみ出た分が意図しない損失になる
        }

        if ((obj.y-obj.size) <= 0) { // 天井に当たった時
            float diff = obj.y - obj.size;
            obj.vy = E_NUM * -obj.vy;
            obj.y = obj.size - diff;
        }

        obj.vy += obj.ay * TIME;
        obj.y += obj.vy * TIME; // dx = v dt
        drawSquare(obj.x, obj.y, obj.size);
    }
}
