#include "Map.h"
#include "../Snake/Snake.h"
#include <conio.h>
//class Map :pub Snake
//2
Map::Map() {
    _write(1, (char*)"press the arrow to select the Map\nAnd press enter to play\n", 58);
    MapSelecting();
    MapTransfer();
    _write(1, "Map Select finish the game is going to start\n", 46);
}

//3
Map::~Map() {
    if (MapUsing != nullptr) {
        switch (MapSelect >> 4) {
            case 0b00: for (int8 i = 0; i < MAX_OF_MAP_1_Y; i++) { delete[] MapUsing[i]; } break;
            case 0b01: for (int8 i = 0; i < MAX_OF_MAP_2_Y; i++) { delete[] MapUsing[i]; } break;
            case 0b10: for (int8 i = 0; i < MAX_OF_MAP_3_Y; i++) { delete[] MapUsing[i]; } break;
            case 0b11: for (int8 i = 0; i < MAX_OF_MAP_4_Y; i++) { delete[] MapUsing[i]; } break;
        }
        delete[] MapUsing;
    }
}

void Map::MapTransfer() {
    if(MapUsing!=nullptr){
        switch(MapSelect>>4){
            case 0b00: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] MapUsing[i];} break;
            case 0b01: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] MapUsing[i];} break;
            case 0b10: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] MapUsing[i];} break;
            case 0b11: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] MapUsing[i];} break;
        }
    }
    switch( MapSelect & 0b1111){
        case 0b00:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(i);} break;
        case 0b01:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(i);} break;
        case 0b10:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(i);} break;
        case 0b11:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X+1]; MapCoping(i);} break;
    }
}

void Map::ShowMap(){
    printf("\033[2J\033[H");
    switch(MapSelect & 0b1111){
        case 0b00:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b01:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b10:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b11:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
    }
}

void Map::MapSelecting(){
    char ch;
    do{
        printf("press '0' to select \nleft / right to switch map");
        ShowMap();
        if(_kbhit()){
            ch = _getch();
            switch(ch){
                case 'a':{if((MapSelect&0b0111)==0b00){MapSelect|=0b11;}else{MapSelect--;} break;}
                case 'd':{if((MapSelect&0b0111)==0b11){MapSelect&=0b00;}else{MapSelect++;} break;}
                case 72:{
                    ch = _getch();
                    switch(ch){
                        case 75:if((MapSelect&0b0111)==0b00){MapSelect|=0b11;}else{MapSelect--;}break;
                        case 77:if((MapSelect&0b0111)==0b11){MapSelect&=0b00;}else{MapSelect++;}break;
                    }
                }
                default:break;
            }
        }
    } while(ch!='0');
}

//(Asm) MOV map2,map1
void Map::MapCoping(int8 i) {
    switch(MapSelect & 0b1111){
        case 0b00:for(int8 j=0;i<MAX_OF_MAP_X;i++) MapUsing[i][j]=Map1[i][j];break;
        case 0b01:for(int8 j=0;i<MAX_OF_MAP_X;i++) MapUsing[i][j]=Map2[i][j];break;
        case 0b10:for(int8 j=0;i<MAX_OF_MAP_X;i++) MapUsing[i][j]=Map3[i][j];break;
        case 0b11:for(int8 j=0;i<MAX_OF_MAP_X;i++) MapUsing[i][j]=Map4[i][j];break;
    }
}