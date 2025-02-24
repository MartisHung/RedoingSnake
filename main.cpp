/**
 * @author Martis
 * I know the codes sucks like there's some Assembly,lots of low level code in high level language,nonsence of operator overloading
 * but this is my code none of your busine... no I mean like ... I'll do it better, and all these you see is for self-training
 * whatever hope you enjoy it 
 */

#include "ForCrossPlatform.h"
#include "Snake/Snake.h"
#include "Map/Map.h"
#include <stdlib.h>
#include <time.h>
//TODO : food generate | bot moving logic 
int main() {
    srand(time(NULL));
    TemporyKeyboardSetting();
    Map player1;
    player1.GameLoop();
    return 0;
}