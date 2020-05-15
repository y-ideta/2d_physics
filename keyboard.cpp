#include <stdlib.h>
#include <vector>

#include "main.h"

using namespace std;

void keyboard(unsigned char key, int x, int y)
{
    extern vector<Obj> squareList;
    switch (key) {
        case 'c':
            squareList.clear(); 
            break;
        case 'q':
        case 'Q':
        case '\033': // ESC
            exit(0);
            break;
        default:
            break;
    }
}
