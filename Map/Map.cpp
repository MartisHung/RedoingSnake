#include "Map.h"

Map::Map(){
    write(1,(char*)"press the arrow to select the Map\nAnd press enter to play",58);
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
    switch(MapSelect & 0b1111){
        case 0b00:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b01:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b10:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0b11:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)write(1,MapUsing[i],MAX_OF_MAP_X);break;
    }
}

void Map::MapSelecting(){
    printf("press '0' to select \nleft / right to switch map");
    char ch;
    while(ch!='0'){
        if(_kbhit()){
            ch = _getch();
            switch(ch){
                case 'a':{if(MapSelect==0b00){MapSelect=3;}else{MapSelect--;} break;}
                case 'd':{if(MapSelect==0b11){MapSelect=0;}else{MapSelect++;} break;}
                case '-32':{
                    ch = _getch();
                    switch(ch){
                        case 75:if(MapSelect==0b00){MapSelect=3;}else{MapSelect--;}break;
                        case 77:if(MapSelect==0b11){MapSelect=0;}else{MapSelect--;}break;
                    }
                }
            }
        }
    }
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

Map::~Map() {
    write(1,"finish",7);
}