#include <stdio.h>
#include <vector>
#include <GLUT/glut.h>

#include "main.h"

using namespace std;

bool isOnObj(int x, int y);
int draged_idx = -1;
int drag_start_x;
int drag_start_y;

void mouse(int button, int state, int x, int y) {
    Obj square = {
        double(x), 
        double(y),
        0,
        0,
        0,
        9.8,
        20
    };
    extern vector<Obj> square_list;
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_UP) {
                square_list[draged_idx].vx = drag_start_x - x;
                square_list[draged_idx].vy = drag_start_y - y;
                draged_idx = -1;
            } else {
                drag_start_x = x;
                drag_start_y = y;
                if (isOnObj(x, y)) break;
                square_list.push_back(square);
            }
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
        default:
            break;
    }
}

bool isOnObj(int x, int y) {
    extern vector<Obj> square_list;
    for (int i=0; i<int(square_list.size()); i++) {
        Obj &obj = square_list[i];

        if (!(x >= obj.x - obj.size 
            && x <= obj.x + obj.size)) continue;
        if (!(y >= obj.y - obj.size 
            && y <= obj.y + obj.size)) continue;
        draged_idx = i;
        return true;
    }
    return false;
}

void motion(int x, int y) {
    extern vector<Obj> square_list;
    if (draged_idx < 0) return;
    Obj &obj = square_list[draged_idx];
    obj.x = x;
    obj.y = y;
}
