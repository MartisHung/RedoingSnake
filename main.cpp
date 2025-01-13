/**
 * @file main.cpp
 * @brief Main Function
 * @author Martis
 * @include Dictionary : Snake & Map | File : ForTypeDef.h & ArrowInitization.h| LibC :time.h stdlib.h
 * @copyright 2024 Martis,the codes forbid financial purpose,self using or educational purpose are allow
 */
#include<time.h>
#include<stdlib.h>
#include"Snake/Snake.hpp"
#include"Map/Map.hpp"
#include"ArrowInitilization.hpp"

int main(){
    srand(time(NULL));
    /**
     *@brief Map select
     */
    if(_kbhit()){
        char ch = _getch();
        int8 MapSelected=0;
        switch(ch){
            case 'a':{if(MapSelected==0){MapSelected=3;}else{MapSelected--;} break;}
            case 'd':{if(MapSelected==3){MapSelected=0;}else{MapSelected++;} break;}
            case '-32':{
                ch = _getch();
                switch(ch){
                    case 75:if(MapSelected==0){MapSelected=3;}else{MapSelected--;}
                    case 77:if(MapSelected==3){MapSelected=0;}else{MapSelected--;}
                }
            }
        }
    }
    
    while(1){
        
    }
}