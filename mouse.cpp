#include <stdio.h>
#include <vector>
#include <GLUT/glut.h>

#include "main.h"

using namespace std;


void mouse(int button, int state, int x, int y) {
    Obj square = {
        double(x), 
        double(y),
        0,
        0,
        0,
        9.8,
        10
    };
    extern vector<Obj> squareList;
    switch (button) {
        case GLUT_LEFT_BUTTON:
            squareList.push_back(square);
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
