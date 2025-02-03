#include "Snake.h"
#include "../Map/Map.h"
#include <io.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * @brief Construct a new Snake:: Snake object
 * @param Snake(MapSelect-MapUsing-nullptr) Player Snake
 * @param Snake(MapUsing) Robot's Snake
 */
Snake::Snake(bool_array MapSelect,char **MapUsing,decltype(nullptr)) {
    SnakeLocate *location = new SnakeLocate[1];
    bool Tf = 1;
    For_Snake |= 0b100;
    Direction = (direction::UNDEFINED);
    do{
        location[0].a.x = rand() % MAX_OF_MAP_X;
        switch (MapSelect & 0x7) {
            case 0x0: location[0].a.y = rand() % MAX_OF_MAP_1_Y; break;
            case 0x1: location[0].a.y = rand() % MAX_OF_MAP_2_Y; break;
            case 0x2: location[0].a.y = rand() % MAX_OF_MAP_3_Y; break;
            case 0x3: location[0].a.y = rand() % MAX_OF_MAP_4_Y; break;
        }
    }while (MapUsing[location[0].a.y][location[0].a.x]!=' ');
    MapUsing[location[0].a.y][location[0].a.x] = 'H';
    printf("%x\n%x\t%x\n",location[0].ll, location[0].a.x, location[0].a.y);
}
Snake::Snake(char**MapUsing) {
    do{
        location[0].ll = (rand()%MAX_OF_MAP_X)<<8 | rand()%0x15;
        if(MapUsing[location[0].a.y][location[0].a.x]==' ') break;
        else continue;
    }while(1);
    MapUsing[location[0].a.y][location[0].a.x] = 'E';
    For_Snake &= 0x2;
}

Snake::~Snake(){
    delete[] location;
}

// for ensure the snake hitten and eatten then move the snake
void Snake::operator^=(char **MapUsing) {
    if(location==nullptr) _write(1,"fuck\n", 5);
    //Scan the snake  alive or not
    if(For_Snake&0b100){
        printf("debug0\n");
        printf("%x\n",location[0].ll);
        printf("%x\t%x\n",location[0].a.x,location[0].a.y);
        _write(1,"debug1\n", 7);
        if (MapUsing[location[0].a.y + dy][location[0].a.x + dx] == '#' ||
            MapUsing[location[0].a.y + dy][location[0].a.x + dx] == 'E' ||
            MapUsing[location[0].a.y + dy][location[0].a.x + dx] == 'H'){
            For_Snake &=0b01;
            _write(1,"Snake Dead\n", 11);
        }
        _write(1,"debug1\n", 7);
    }
    else if((For_Snake>>2)==0){
        if (MapUsing[location[0].a.y + dy][location[0].a.x + dx] == '#' ||
            MapUsing[location[0].a.y + dy][location[0].a.x + dx] == 'P' ||
            MapUsing[location[0].a.y + dy][location[0].a.x + dx] == 'H'){
            For_Snake &= 0b01;
        }
    }
    _write(1,"debug2\n", 7);
    //movment
    for (int8 i = 0; i < length; i++) {
        if(For_Snake&0b10) {
            location[0].a.x += dx;location[0].a.y = dy;
            dx=location[length-1].a.x;dy=location[length-1].a.y;
            for (int8 i = 1; i < length; i++) location[i].ll = location[i - 1].ll;
        }
    }
    if (MapUsing[location[0].a.y][location[0].a.x] == '.') {
        For_Snake |= 0b01;
        Resize();
    }
}
//get the snake alive or not
bool Snake::operator==(decltype(nullptr))const {
    return (For_Snake&0b10)?true:false;
}

void Snake::Resize() {
    length++;
    SnakeLocate *tempory = new SnakeLocate[length];
    for(int8 i=0;i<length-1;i++) tempory[i].ll=location[i].ll;
    tempory[length-1].ll=(dx<<8)+dy;
    delete[] location; location = tempory;
    if(tempory!=nullptr) tempory = nullptr;
    dx=dy=0;For_Snake &= 0b10;
}

void Snake::getMovement(char ch) {
    switch(ch){
        case 'w': Direction = direction::forward;   dx = 0; dy = -1;break;
        case 's': Direction = direction::backward;  dx = 0; dy = +1;break;
        case 'a': Direction = direction::left;      dx = -1; dy = 0;break;
        case 'd': Direction = direction::right;     dx = +1; dy = 0;break;
        case -32: {
            switch (_getch()) {
            case 72: Direction = direction::forward;    dx = 0; dy = -1;break;
            case 80: Direction = direction::backward;   dx = 0; dy = +1;break;
            case 75: Direction = direction::left;       dx = -1; dy = 0;break;
            case 77: Direction = direction::right;      dx = +1; dy = 0;break;
            }
        }
    }
}
