/**
 * @file main.cpp
 * @brief Main Function
 * @author Martis
 * @include Dictionary : Snake & Map | File : ForTypeDef.h & ArrowInitization.h | LibC :time.h stdlib.h
 * @copyright 2024 Martis,the codes forbid financial purpose,self using or educational purpose are allow
 */
#include "ArrowInitilization.hpp"
#include "Map/Map.h"
#include "Snake/Snake.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    Map player1;
    int8 MapSelected = 0;
    player1.MapSelecting(&MapSelected);
    bool IDK_RN;
    while (1) {
        if (IDK_RN) {
            break;
        }
    }
}
