#include "Map.h"
#include "../Snake/Snake.h"
#include "../ForCrossPlatform.h"

#include <chrono>
#include <thread>
#include <iostream>


Map::Map(){
    _write(1,"press the arrow to select the Map\nAnd press enter to play\n",58);
    this->MapSelecting();
    _write(1,"Map Select finished ,after pressing WASD or arrow key will start\n", 65);
    Player = new Snake(this->MapSelect,this->MapUsing,nullptr);
    this->ShowMap(nullptr);
    do{
        while(!_kbhit())continue;
        if(Player->getMovement(_getch()))break;
        printf("error the key you press is neither arrow nor WASD");
    }while(1);
    this->foodGenerate();
    printf("\033[2J\033[H");
    this->ShowMap(nullptr);

   
}

Map::~Map() {
    if(this->MapUsing!=nullptr){
        switch(this->MapSelect&0x7){
            case 0x0: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] this->MapUsing[i];} break;
            case 0x1: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] this->MapUsing[i];} break;
            case 0x2: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] this->MapUsing[i];} break;
            case 0x3: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] this->MapUsing[i];} break;
        }
        delete[] this->MapUsing;
    }
    _write(1,"release finish", 14);
    system("pause");
}

void Map::GameLoop() {
     //Scan is alive or not (opertor have been overloaded)
    //game start
    while(Player->operator==(nullptr)){
        Player->EraseOnMap(this->MapUsing);
        Player->operator^=(this->MapUsing);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        this->foodGenerate();
        Player->RenderOnMap(this->MapUsing);
        printf("\033[2J\033[H");
        this->ShowMap(nullptr);
        if(_kbhit()) Player->getMovement(_getch());
        for(int8 i=0;i<5;i++){
            printf("\033[2J\033[H");this->ShowMap(nullptr);
        }
    }
}

void Map::MapTransfer() {
    if(this->MapUsing!=nullptr){
        switch(this->MapSelect>>4){
            case 0x0: for(int8 i=0;i<MAX_OF_MAP_1_Y;i++) {delete[] this->MapUsing[i];} delete[] this->MapUsing; break;
            case 0x1: for(int8 i=0;i<MAX_OF_MAP_2_Y;i++) {delete[] this->MapUsing[i];} delete[] this->MapUsing; break;
            case 0x2: for(int8 i=0;i<MAX_OF_MAP_3_Y;i++) {delete[] this->MapUsing[i];} delete[] this->MapUsing; break;
            case 0x3: for(int8 i=0;i<MAX_OF_MAP_4_Y;i++) {delete[] this->MapUsing[i];} delete[] this->MapUsing; break;
        }
    }
    this->MapSelect&=0x0F;
    switch( this->MapSelect ){
        case 0x0:
            this->MapUsing=new char*[MAX_OF_MAP_1_Y];
            for(int8 i=0;i<MAX_OF_MAP_1_Y;i++){this->MapUsing[i] = new char [MAX_OF_MAP_X]; this->MapCoping(i);} break;
        case 0x1:
            this->MapUsing=new char*[MAX_OF_MAP_2_Y];
            for(int8 i=0;i<MAX_OF_MAP_2_Y;i++){this->MapUsing[i] = new char [MAX_OF_MAP_X]; this->MapCoping(i);} break;
        case 0x2:
            this->MapUsing=new char*[MAX_OF_MAP_3_Y];
            for(int8 i=0;i<MAX_OF_MAP_3_Y;i++){this->MapUsing[i] = new char [MAX_OF_MAP_X]; this->MapCoping(i);} break;
        case 0x3:
            this->MapUsing=new char*[MAX_OF_MAP_4_Y];
            for(int8 i=0;i<MAX_OF_MAP_4_Y;i++){this->MapUsing[i] = new char [MAX_OF_MAP_X]; this->MapCoping(i);} break;
    }
}

void Map::MapSelecting(){
    char ch=0x00;
    _write(1,"press 'q' to select \nleft / right to switch map\n",48);
    this->ShowMap();
    do{
        if(_kbhit()){
            printf("\033[2J\033[H");
            ch = _getch();
            switch(ch){
                case 'A':case 'a':{if((this->MapSelect&0x3)==0x0){this->MapSelect|=0x3;}else{this->MapSelect--;} this->ShowMap();break;}
                case 'D':case 'd':{if((this->MapSelect&0x3)==0x3){this->MapSelect&=0x0;}else{this->MapSelect++;} this->ShowMap();break;}
                case (char)0xE0:{
                    ch = _getch();
                    switch(ch){
                        case 75:{if((this->MapSelect&0x3)==0x0){this->MapSelect|=0x3;}else{this->MapSelect--;} this->ShowMap();break;}
                        case 77:{if((this->MapSelect&0x3)==0x3){this->MapSelect&=0x0;}else{this->MapSelect++;} this->ShowMap();break;}
                    }
                }
                case 'Q':case 'q':if(ch=='Q'){ch+= 32;}break;
                default:this->ShowMap();_write(1,"error the key you press is neither arrow nor WASD",49);break;
            }
        }
    } while(ch!='q');
    this->MapTransfer();
}

void Map::foodGenerate() {
    static int8 addingTimes= 0x44;
    asm( "rolb $1, %0" : "=r"(addingTimes) : "0"(addingTimes) );
    if(addingTimes&0x80){    
        int8 x,y;
        do{
            x=rand() % MAX_OF_MAP_X;
            y=rand() % 0x17;
        } while( this->MapUsing[y][x]!=' ' );
        this->MapUsing[y][x]='.';
    }
}   

//(Asm) MOV map2,map1
void Map::MapCoping(int8 i) {
    switch(this->MapSelect ){
        case 0x0:for(int8 j=0;j<MAX_OF_MAP_X;j++) {this->MapUsing[i][j]=Map1[i][j];}break;
        case 0x1:for(int8 j=0;j<MAX_OF_MAP_X;j++) {this->MapUsing[i][j]=Map2[i][j];}break;
        case 0x2:for(int8 j=0;j<MAX_OF_MAP_X;j++) {this->MapUsing[i][j]=Map3[i][j];}break;
        case 0x3:for(int8 j=0;j<MAX_OF_MAP_X;j++) {this->MapUsing[i][j]=Map4[i][j];}break;
    }
}
/// @brief Show the map 
/// @param ShowMap(nullptr) will show the map rn using 
/// @param this->ShowMap() will show the map selected
void Map::ShowMap(decltype(nullptr)) const{
    switch(this->MapSelect & 0x7){
        case 0x0:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)_write(1,this->MapUsing[i],MAX_OF_MAP_X);break;
        case 0x1:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)_write(1,this->MapUsing[i],MAX_OF_MAP_X);break;
        case 0x2:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)_write(1,this->MapUsing[i],MAX_OF_MAP_X);break;
        case 0x3:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)_write(1,this->MapUsing[i],MAX_OF_MAP_X);break;
    }
}
void Map::ShowMap()const{
    switch(this->MapSelect & 0xF){
        case 0b00:for(int8 i=0;i<MAX_OF_MAP_1_Y;i++)_write(1,Map1[i],MAX_OF_MAP_X);break;
        case 0b01:for(int8 i=0;i<MAX_OF_MAP_2_Y;i++)_write(1,Map2[i],MAX_OF_MAP_X);break;
        case 0b10:for(int8 i=0;i<MAX_OF_MAP_3_Y;i++)_write(1,Map3[i],MAX_OF_MAP_X);break;
        case 0b11:for(int8 i=0;i<MAX_OF_MAP_4_Y;i++)_write(1,Map4[i],MAX_OF_MAP_X);break;
    }
}

void Map::enemyGenerate() {
    static int8 addingTimes= 0x55,enemyExist=0;
    //add logic
    if(enemyExist!=10){
        if(addingTimes&0x80){
            enemyExist++;
            this->Enemy[enemyExist]=new Snake(this->MapSelect,this->MapUsing,nullptr);
        }
        asm( "rolb $1, %0" : "=r"(addingTimes) : "0"(addingTimes) );
    }
    //Scan is alive or not (opertor have been overloaded)
    for(int8 i=0;i<enemyExist;i++){
        if(this->Enemy[i]->operator==(nullptr)){
        
        }
        else{
            this->Enemy[i]->EraseOnMap(this->MapUsing);//change to "operator delete"
            enemyExist--;
            delete this->Enemy[i];
            for(int8 j=i;j<enemyExist;j++)this->Enemy[j]=this->Enemy[j+1];
        }
    }
}