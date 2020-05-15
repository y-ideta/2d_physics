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


void calc() {
    /*
     * 重力による変位のみ計算
     */
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    extern vector<Obj> squareList;

    for (int i =0; i < int(squareList.size()); i++) {
        Obj &obj1 = squareList[i];

        if ((obj1.y + obj1.size) >= h) { // 床に当たった時
            float diff = h - (obj1.y + obj1.size);
            obj1.vy = E_NUM * -obj1.vy;
            obj1.y = h - obj1.size + diff; // diffを足してやらないとはみ出た分が意図しない損失になる
        }

        if ((obj1.y - obj1.size) <= 0) { // 天井に当たった時
            float diff = obj1.y - obj1.size;
            obj1.vy = E_NUM * -obj1.vy;
            obj1.y = obj1.size - diff;
        }

        obj1.vy += obj1.ay * TIME;
        obj1.y += obj1.vy * TIME; // dx = v dt
        
        // xe1: x end of obj1
        double xe1 = obj1.x + obj1.size;
        double ys1 = obj1.y - obj1.size;
        double ye1 = obj1.y + obj1.size;

        for (int j = i+1; j < int(squareList.size()); j++) { 
            /* 
            * 自分以外の要素を1個ずつ見ていく
            * TODO: 複数同時に衝突した場合は厳密には
            * 違う挙動になるはずなので改めて考える必要あり
            */
            Obj &obj2 = squareList[j];

            // x座標が衝突しうる位置にあるかチェック
            // なければcontinueで次に行く
            double xs2 = obj2.x - obj2.size;
            double xe2 = obj2.x + obj2.size;
            if ( !((xe1 >= xs2 && xe1 <= (xe2 + (obj1.size * 2)))) )  continue;

            double ys2 = obj2.y - obj2.size;
            double ye2 = obj2.y + obj2.size;
            if ( !((ye1 >= ys2 && ye1 <= (ye2 + (obj1.size * 2)))) ) continue;

            // ここまで来たら衝突してると考えて処理する
            double ydiff;
            double v1d = (obj1.vy*(1-E_NUM) + obj2.vy*(1+E_NUM)) / 2;
            double v2d = (obj1.vy*(1+E_NUM) + obj2.vy*(1-E_NUM)) / 2;
            obj1.vy = v1d;
            obj2.vy = v2d;
            if(obj1.y <= obj2.y) {
                ydiff = ye1 - ys2;
                obj1.y -= ydiff;
            } else {
                ydiff = ye2-ys1;
                obj2.y -= ydiff;
            }
        }
        drawSquare(obj1.x, obj1.y, obj1.size);
    }
}
