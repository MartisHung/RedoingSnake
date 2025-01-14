#include "Snake.h"
// for ensure the snake hitten or not and move the snake
bool Snake::operator|=(const char **MapUsing) {
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
            Alive = 0;
        }
        else {
            location[0].a.x += dx;location[0].a.y = dy;
            for (int8 i = 1; i < length; i++) location[i].ll = location[i - 1].ll;
        }
    }
}

Snake::Snake() {
    SnakeLocate *location = new SnakeLocate[1]; location[0].ll = 0x1010;
}

Snake::~Snake() {
    delete[] location;
}

void Snake::Resize() {
    length++;
    SnakeLocate *tempory = new SnakeLocate[length];
    for(int8 i=0;i<length-1;i++) tempory[i].ll=location[i].ll;
    delete[] location; location = tempory;
    if(tempory!=nullptr) tempory = nullptr;
    
}