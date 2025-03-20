/**
 * @author Martis
 * I know the codes sucks like there's some Assembly,lots of low level code in high level language,nonsence of operator overloading,
 * bot moving randomly but this is my code none of your busine... no I mean like ... I'll do it better, and all these you've 
 * seen is for self-training
 * Whatever if you have any idea or suggestion plz throw it to pull issue, hope you would enjoy it 
 */

 #include "ForCrossPlatform.h"
 #include "Snake/Snake.h"
 #include "Map/Map.h"
 #include <stdlib.h>
 #include <time.h>
 //TODO : Teleport Logic (undo)
 int main() {
     Map player1;
     srand(time(NULL));
     TemporyKeyboardSetting();
     player1.GameLoop();
     return 0;
 }