#include <stdio.h>
#include <vector>
#include <cmath>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"

#define G_NUM 9.8 // 重力加速度
#define TIME_STEP 10 // 1秒間に何秒進めるか
#define FRAME_RATE 1/60 // 描画の関数が呼ばれる時間
#define TIME FRAME_RATE * TIME_STEP
#define E_NUM 0.8 // 反発係数

using namespace std;

void updatePosByWall(Obj& obj, int w, int h);
void updatePosByOtherObj(Obj& obj1, Obj& obj2);


void calc() {
    /*
     * 壁と他オブジェクトとの衝突を計算
     */
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    extern vector<Obj> square_list;

    for (int i =0; i < int(square_list.size()); i++) {
        Obj &obj1 = square_list[i];
        
        // 壁の判定
        updatePosByWall(obj1, w, h);

        for (int j = i+1; j < int(square_list.size()); j++) { 
            /* 
            * 自分以外の要素を1個ずつ見ていく
            * TODO: 複数同時に衝突した場合は厳密には
            * 違う挙動になるはずなので改めて考える必要あり
            */
            Obj &obj2 = square_list[j];
            // 他オブジェクトの判定
            updatePosByOtherObj(obj1, obj2);
        }
        drawSquare(obj1.x, obj1.y, obj1.size);
    }
}

void updatePosByWall(Obj& obj, int w, int h) {
    // 床に当たった時
    if ((obj.y + obj.size) >= h) {
        float diff = (obj.y + obj.size) - h;
        obj.vy = E_NUM * -obj.vy;

        // diffを足してやらないとはみ出た分が意図しない損失になる
        obj.y -= diff;
    }

    // 天井に当たった時
    if ((obj.y - obj.size) <= 0) {
        float diff = obj.y - obj.size;
        obj.vy = E_NUM * -obj.vy;
        obj.y -= diff;
    }

    // 右壁に当たった時
    if ((obj.x + obj.size) >= w) {
        float diff = (obj.x + obj.size) - w;
        obj.vx = E_NUM * -obj.vx;
        obj.x -= diff;
    }

    // 左壁に当たった時
    if ((obj.x + obj.size) <= 0) {
        float diff = obj.x - obj.size;
        obj.vx = E_NUM * -obj.vx;
        obj.x -= diff;
    }

    obj.vy += obj.ay * TIME;
    obj.y += obj.vy * TIME;

    obj.vx += obj.ax * TIME;
    obj.x += obj.vx * TIME;
}

void updatePosByOtherObj(Obj& obj1, Obj& obj2) {
    // x座標が衝突しうる位置にあるかチェック
    // なければcontinueで次に行く
    double xs2 = obj2.x - obj2.size;
    double xe2 = obj2.x + obj2.size;
    if ( !(((obj1.x + obj1.size) >= xs2 && (obj1.x + obj1.size) <= (xe2 + (obj1.size * 2)))) )  return;

    double ys2 = obj2.y - obj2.size;
    double ye2 = obj2.y + obj2.size;
    if ( !(((obj1.y + obj1.size) >= ys2 && (obj1.y + obj1.size) <= (ye2 + (obj1.size * 2)))) ) return;

    // ここまで来たら衝突してると考えて処理する
    double diff_y;
    double v1d = (obj1.vy*(1-E_NUM) + obj2.vy*(1+E_NUM)) / 2;
    double v2d = (obj1.vy*(1+E_NUM) + obj2.vy*(1-E_NUM)) / 2;
    obj1.vy = v1d;
    obj2.vy = v2d;
    if(obj1.y <= obj2.y) {
        diff_y = (obj1.y + obj1.size) - ys2;
        obj1.y -= diff_y;
    } else {
        diff_y = ye2-(obj1.y - obj1.size);
        obj2.y -= diff_y;
    }
}
