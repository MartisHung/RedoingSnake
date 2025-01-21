#include "Snake.h"
#include "../Map/Map.h"

Snake::Snake(bool_array MapSelect,char **MapUsing) {
    SnakeLocate *location = new SnakeLocate[1];
    do{
        location[0].a.x = rand()%MAX_OF_MAP_X;
        switch (MapSelect & 0x7) {
            case 0x0: location[0].a.y = rand() % MAX_OF_MAP_1_Y; break;
            case 0x1: location[0].a.y = rand() % MAX_OF_MAP_2_Y; break;
            case 0x2: location[0].a.y = rand() % MAX_OF_MAP_3_Y; break;
            case 0x3: location[0].a.y = rand() % MAX_OF_MAP_4_Y; break;
        }
    }while (
        (MapSelect & 0x7) == 0x0 && MapUsing[location[0].a.y][location[0].a.x] != '#' ||
        (MapSelect & 0x7) == 0x1 && MapUsing[location[0].a.y][location[0].a.x] != '#' ||
        (MapSelect & 0x7) == 0x2 && MapUsing[location[0].a.y][location[0].a.x] != '#' ||
        (MapSelect & 0x7) == 0x3 && MapUsing[location[0].a.y][location[0].a.x] != '#'
        );
        
}

Snake::~Snake() {
    delete[] location;
    _write(1,"\nhi", 3);
}
// for ensure the snake hitten or not and move the snake
bool Snake::operator^=(const char **MapUsing) {
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
            for (int8 i = 1; i < length; i++) location[i].ll = location[i - 1].ll;
        }
    }
    return For_Snake;
}

void Snake::Resize() {
    length++;
    SnakeLocate *tempory = new SnakeLocate[length];
    for(int8 i=0;i<length-1;i++) tempory[i].ll=location[i].ll;
    delete[] location; location = tempory;
    if(tempory!=nullptr) tempory = nullptr;
}