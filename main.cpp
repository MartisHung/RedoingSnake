/**
 * @file main.cpp
 * @brief Main Function
 * @author Martis
 * @include Dictionary : Snake & Map | File : ForTypeDef.h & ArrowInitization.h|
 * LibC :time.h stdlib.h
 * @copyright 2024 Martis,the codes forbid financial purpose,self using or
 * educational purpose are allow
 */
#include "ArrowInitilization.hpp"
#include "Map/Map.hpp"
#include "Snake/Snake.hpp"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    /**
     *@brief Map select
     *@param MapSelected : the high four bit is the map elder selected
     */
    int8 MapSelected = 0;
    Map player1;
    player1.MapSelecting(&MapSelected);
    bool IDK_RN;
    while (1) {
        if (IDK_RN) {
            break;
        }
    }
}
