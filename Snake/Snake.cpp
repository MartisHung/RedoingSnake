#include "Snake.h"
#include "../Map/Map.h"
#include "../ForCrossPlatform.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Construct a new Snake:: Snake object
 * @param Snake(MapSelect-MapUsing-nullptr) Player Snake
 * @param Snake(MapUsing) Robot's Snake
 */
Snake::Snake(bool_array MapSelect, char **MapUsing) {
    location = new SnakeLocate[1];
    For_Snake |= 0b110;
    do { if (initLocate(rand() % MAX_OF_MAP_X, rand() % 0x17, (const char**)MapUsing))break; } while (1);
    MapUsing[location[0].a.y][location[0].a.x] = 'H';
}
Snake::Snake(char **MapUsing) {
    For_Snake |= 0x2;
    location =new SnakeLocate[1];
    do {
        location[0].a.x = rand() % MAX_OF_MAP_X;
        location[0].a.y = rand() % 0x15;
    } while (MapUsing[location[0].a.y][location[0].a.x] != ' ');
    MapUsing[location[0].a.y][location[0].a.x] = 'E';
}

bool Snake::initLocate(int8 x, int8 y, const char **MapUsing) {
    if (MapUsing[y][x] == ' ') { location[0].a.x = x; location[0].a.y = y; return true;}
    return false;
}

Snake::~Snake() { delete[] location; }

// for ensure the snake hitten and eatten then move the snake
void Snake::operator^=(char **MapUsing) {
    // Scan the snake  alive or not
    if (MapUsing[location[0].a.y + dy][location[0].a.x + dx] == '#' ||
        MapUsing[location[0].a.y + dy][location[0].a.x + dx] == 'E' ){
        For_Snake &= 0b00;
        _write(1, "Snake Dead\n", 11);
        return;
    }
    else if (MapUsing[location[0].a.y + dy][location[0].a.x + dx] == '.') For_Snake |= 1;
    
    Resize();
    
    switch (direction) {
        case Direction::forward:    dx = 0;dy =-1;break;
        case Direction::backward:   dx = 0;dy = 1;break;
        case Direction::left:       dx =-1;dy = 0;break;
        case Direction::right:      dx = 1;dy = 0;break;
    }
}

void Snake::operator|=(char** MapUsing) {
    switch(this->direction){
        case Direction::UNDEFINED:     direction=Direction(rand()%4+1);                                         break;
        case Direction::forward:    do{direction=Direction(rand()%4+1);}while(direction==Direction::forward);   break;
        case Direction::backward:   do{direction=Direction(rand()%4+1);}while(direction==Direction::backward);  break;
        case Direction::left:       do{direction=Direction(rand()%4+1);}while(direction==Direction::left);      break;
        case Direction::right:      do{direction=Direction(rand()%4+1);}while(direction==Direction::right);     break;
    }
    switch(this->direction){
        case Direction::forward:    dx = 0;dy =-1;break;
        case Direction::backward:   dx = 0;dy = 1;break;
        case Direction::left:       dx =-1;dy = 0;break;
        case Direction::right:      dx = 1;dy = 0;break;
    }

    if( MapUsing[location[0].a.y+dy][location[0].a.x+dx]=='#'||
        MapUsing[location[0].a.y+dy][location[0].a.x+dx]=='P'||
        MapUsing[location[0].a.y+dy][location[0].a.x+dx]=='E'){
        For_Snake&=0x0;
        return;
    }else if(MapUsing[location[0].a.y+dy][location[0].a.x+dx]=='.')For_Snake|=1;

    Resize();
    
    switch(direction){
        case Direction::forward:    dx = 0;dy =-1;break;
        case Direction::backward:   dx = 0;dy = 1;break;
        case Direction::left:       dx =-1;dy = 0;break;
        case Direction::right:      dx = 1;dy = 0;break;
    }
}

void Snake::RenderOnMap(char **MapUsing) {
    if (For_Snake == 0b110) {
        for (int8 i = 0; i < length; i++)MapUsing[location[i].a.y][location[i].a.x] = 'P';
    }
    else if (For_Snake == 0b010) {
        for (int8 i = 0; i < length; i++)MapUsing[location[i].a.y][location[i].a.x] = 'E';
    }
}

void Snake::EraseOnMap(char **MapUsing) const  {
    for(int8 i = 0; i < length; i++)MapUsing[location[i].a.y][location[i].a.x] = ' ';
}

// get the snake alive or not
bool Snake::operator==(_nullptr_t) const  { 
    return (For_Snake & 0b10) ? true : false;
}

void Snake::Resize() {
    if( For_Snake & 0b01 ){
        length++;
        SnakeLocate *temp = new SnakeLocate[length];
        for (int8 i = 1; i < length ; i++) temp[i] = location[i-1];
        temp[0].a.x = location[0].a.x+dx; temp[0].a.y = location[0].a.y+dy;
        delete[] location;
        location = temp;
        temp = nullptr;
        For_Snake&=0xF6;
    }
    else{
        for (int8 i = length - 1; i > 0; i--)location[i] = location[i - 1];
        location[0].a.x += dx;
        location[0].a.y += dy;
    }
}

bool Snake::getMovement(char ch) {
    switch (ch) {
        case 'w':case 'W':direction = Direction::forward;   dx = 0;dy =-1;break;
        case 's':case 'S':direction = Direction::backward;  dx = 0;dy = 1;break;
        case 'a':case 'A':direction = Direction::left;      dx =-1;dy = 0;break;
        case 'd':case 'D':direction = Direction::right;    dx = 1;dy = 0;break;
        case (char)0xE0: {
            ch = _getch();
            switch (ch) {
                case 72:direction = Direction::forward; dx = 0;dy =-1;break;
                case 80:direction = Direction::backward;dx = 0;dy = 1;break;
                case 75:direction = Direction::left;    dx =-1;dy = 0;break;
                case 77:direction = Direction::right;   dx = 1;dy = 0;break;
            }
            break;
        }
        default: return false;
    }
    return true;
}

void Snake::ChangeToFood(char **MapUsing) const { MapUsing[location[0].a.y][location[0].a.x] = '.'; }