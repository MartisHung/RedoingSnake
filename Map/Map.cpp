#include "Map.h"
#include "../Snake/Snake.h"
#include <conio.h>
#include <iostream>
#include <chrono>
#include <thread>

Map_Scorpe::Map::Map(){
    _write(1,"press the arrow to select the Map\nAnd press enter to play\n",58);
    MapSelecting();
    _write(1,"Map Select finish press any key to start\n",41);
    while(!_kbhit());
    Snake *Player=new Snake(MapSelect,MapUsing);
    printf("\033[2J\033[H");
    //Scan is alive or not (opertor have been overloaded)
    while(Player->operator== (nullptr)){
        ShowMap(nullptr);
        Player->moving(MapUsing);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

Map_Scorpe::Map::~Map() {
    if(MapUsing!=nullptr){
        switch(MapSelect&0x7){
            case 0x0: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] MapUsing[i];} break;
            case 0x1: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] MapUsing[i];} break;
            case 0x2: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] MapUsing[i];} break;
            case 0x3: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] MapUsing[i];} break;
        }
        delete[] MapUsing;
    }
    _write(1,"release finish", 14);
    system("pause");
}

void Map_Scorpe::Map::MapTransfer() {
    if(MapUsing!=nullptr){
        switch(MapSelect>>4){
            case 0x0: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] MapUsing[i];} delete[] MapUsing; break;
            case 0x1: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] MapUsing[i];} delete[] MapUsing; break;
            case 0x2: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] MapUsing[i];} delete[] MapUsing; break;
            case 0x3: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] MapUsing[i];} delete[] MapUsing; break;
        }
    }
    switch( MapSelect & 0x7){
        case 0x0:
            MapUsing=new char*[MAX_OF_MAP_1_Y];
            for(int8 i=0;i<MAX_OF_MAP_1_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X]; MapCoping(i);} break;
        case 0x1:
            MapUsing=new char*[MAX_OF_MAP_2_Y];
            for(int8 i=0;i<MAX_OF_MAP_2_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X]; MapCoping(i);} break;
        case 0x2:
            MapUsing=new char*[MAX_OF_MAP_3_Y];
            for(int8 i=0;i<MAX_OF_MAP_3_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X]; MapCoping(i);} break;
        case 0x3:
            MapUsing=new char*[MAX_OF_MAP_4_Y];
            for(int8 i=0;i<MAX_OF_MAP_4_Y;i++){MapUsing[i] = new char [MAX_OF_MAP_X]; MapCoping(i);} break;
    }
}

void Map_Scorpe::Map::MapSelecting(){
    char ch=0x00;
    _write(1,"press 'q' to select \nleft / right to switch map\n",48);
    ShowMap();
    while(!_kbhit()) continue;
    do{
        if(_kbhit()){
            printf("\033[2J\033[H");
            ch = _getch();
            switch(ch){
                case 'a':{if((MapSelect&0x7)==0x0){MapSelect|=0x3;}else{MapSelect--;} ShowMap();break;}
                case 'd':{if((MapSelect&0x7)==0x3){MapSelect&=0x0;}else{MapSelect++;} ShowMap();break;}
                case (char)0xE0:{
                    ch = _getch();
                    switch(ch){
                        case 75:{if((MapSelect&0x7)==0x0){MapSelect|=0x3;}else{MapSelect--;} ShowMap();break;}
                        case 77:{if((MapSelect&0x7)==0x3){MapSelect&=0x0;}else{MapSelect++;} ShowMap();break;}
                    }
                }
                case 'q':break;
            }
        }
    } while(ch!='q');
    Map_Scorpe::Map::MapTransfer();
}

//(Asm) MOV map2,map1
void Map_Scorpe::Map::MapCoping(int8 i) {
    switch(MapSelect & 0x7){
        case 0x0:for(int8 j=0;j<MAX_OF_MAP_X;j++) {MapUsing[i][j]=Map1[i][j];}break;
        case 0x1:for(int8 j=0;j<MAX_OF_MAP_X;j++) {MapUsing[i][j]=Map2[i][j];}break;
        case 0x2:for(int8 j=0;j<MAX_OF_MAP_X;j++) {MapUsing[i][j]=Map3[i][j];}break;
        case 0x3:for(int8 j=0;j<MAX_OF_MAP_X;j++) {MapUsing[i][j]=Map4[i][j];}break;
    }
}
/// @brief Show the map 
/// @param ShowMap(nullptr) will show the map rn using 
/// @param ShowMap() will show the map selected
void Map_Scorpe::Map::ShowMap(std::nullptr_t a) {
    switch(MapSelect & 0x7){
        case 0x0:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0x1:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0x2:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
        case 0x3:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)_write(1,MapUsing[i],MAX_OF_MAP_X);break;
    }
}
void Map_Scorpe::Map::ShowMap(){
    switch(MapSelect & 0b1111){
        case 0b00:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)_write(1,Map1[i],MAX_OF_MAP_X);break;
        case 0b01:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)_write(1,Map2[i],MAX_OF_MAP_X);break;
        case 0b10:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)_write(1,Map3[i],MAX_OF_MAP_X);break;
        case 0b11:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)_write(1,Map4[i],MAX_OF_MAP_X);break;
    }
}