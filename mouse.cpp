#include <stdio.h>
#include <vector>
#include <GLUT/glut.h>

#include "main.h"
#include "draw.h"

using namespace std;

bool isOnObj(int x, int y);
void leftClickUp(int x, int y);
void leftClickDown(int x, int y);
extern int draged_idx;

void mouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_UP) {
                leftClickUp(x, y);
            } else {
                leftClickDown(x, y);
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

void leftClickUp (int x, int y) {
    extern vector<Obj> square_list;
    extern int draged_idx, drag_start_x, drag_start_y, mouse_x, mouse_y;
    square_list[draged_idx].vx = drag_start_x - x;
    square_list[draged_idx].vy = drag_start_y - y;
    draged_idx = -1;
    drag_start_x = -1; 
    drag_start_y = -1; 
    mouse_x = 0; 
    mouse_y = 0; 
}

void leftClickDown (int x, int y) {
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
    extern int drag_start_x, drag_start_y;
    drag_start_x = x;
    drag_start_y = y;
    if (isOnObj(x, y)) return;
    square_list.push_back(square);
}

bool isOnObj(int x, int y) {
    extern vector<Obj> square_list;
    extern int draged_idx;
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
    extern int draged_idx, drag_start_x, drag_start_y, mouse_x, mouse_y;
    mouse_x = x;
    mouse_y = y;
    if (draged_idx < 0) return;
    Obj &obj = square_list[draged_idx];
    obj.x = x;
    obj.y = y;
}
