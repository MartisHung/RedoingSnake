#include "Snake.h"
#include "../Map/Map.h"
#include <conio.h>

Snake::Snake(bool_array MapSelect,char **MapUsing) {
    SnakeLocate *location = new SnakeLocate[1];
    bool Tf = 1;
    do{
        location[0].a.x = rand()%MAX_OF_MAP_X;
        switch (MapSelect & 0x7) {
            case 0x0: 
                location[0].a.y = rand() % MAX_OF_MAP_1_Y;
                if(MapUsing[location[0].a.y][location[0].a.x]==' ')Tf=0; 
                break;
            case 0x1: 
                location[0].a.y = rand() % MAX_OF_MAP_2_Y; 
                if(MapUsing[location[0].a.y][location[0].a.x]==' ')Tf=0;
                break;  
            case 0x2: 
                location[0].a.y = rand() % MAX_OF_MAP_3_Y; 
                if(MapUsing[location[0].a.y][location[0].a.x]==' ')Tf=0;
                break;
            case 0x3: 
                location[0].a.y = rand() % MAX_OF_MAP_4_Y; 
                if(MapUsing[location[0].a.y][location[0].a.x]==' ')Tf=0;
                break;
        }
    }while ( Tf);
    _write(1,"location initialized correctly\n", 31);
    ShowOnMap(MapUsing);
}

Snake::~Snake() {
    delete[] location;
    _write(1,"\nhi", 3);
}
// for ensure the snake hitten and eatten then move the snake
bool Snake::operator^=( char **MapUsing) {
    switch (Direction) {
        case (direction::forward):  dx = 0; dy = -1;break;
        case (direction::backward): dx = 0; dy = 1; break;
        case (direction::left):     dx = -1;dy = 0; break;
        case (direction::right):    dx = 1; dy = 0; break;
    }
    for (int8 i = 0; i < length; i++) {
        if (MapUsing[location[i].a.y + dy][location[i].a.x + dx] == '#' ||
            MapUsing[location[i].a.y + dy][location[i].a.x + dx] == 'P' ||
            MapUsing[location[i].a.y + dy][location[i].a.x + dx] == 'E' ||
            MapUsing[location[i].a.y + dy][location[i].a.x + dx] == 'H') {
            For_Snake &=0b01;
        }
        else {
            location[0].a.x += dx;location[0].a.y = dy;
            dx=location[length-1].a.x;dy=location[length-1].a.y;
            for (int8 i = 1; i < length; i++) location[i].ll = location[i - 1].ll;
        }
    }
    if (MapUsing[location[0].a.y][location[0].a.x] == '.') {
        For_Snake |= 0b01;
        Resize();
    }
    return For_Snake;
}
//get the snake alive or not
bool Snake::operator==(std::nullptr_t a)const {
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
void Snake::ShowOnMap(char **MapUsing) {
    ///@bug the function has no assability to the adjust MapUsing
    MapUsing[location[0].a.y][location[0].a.x] = 'H';
    system("pause");
    _write(1,"setted\n",7);
    system("pause");
}
void Snake::moving(char** MapUsing) {
    if(_kbhit()){
        switch(_getch()){
            case 'w': Direction = direction::forward; break;
            case 's': Direction = direction::backward; break;
            case 'a': Direction = direction::left; break;
            case 'd': Direction = direction::right; break;
            case -32: {
                switch (_getch()) {
                case 72: Direction = direction::forward; break;
                case 80: Direction = direction::backward; break;
                case 75: Direction = direction::left; break;
                case 77: Direction = direction::right; break;
                }
            }
        }
    }
    *this^= MapUsing;
}