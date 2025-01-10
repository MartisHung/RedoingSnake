#include"Snake.hpp"
//if hitten
bool Snake::operator|=(const char** MapUsing){
    switch(Direction){
        case(direction::forward):   dx=0; dy=-1;break;
        case(direction::backward):  dx=0; dy=1; break;
        case(direction::left):      dx=-1;dy=0; break;
        case(direction::right):     dx=1; dy=0; break;
    }
    for(int i=0;i<length;i++){
        if(MapUsing[ASnake[i].y+dy][ASnake[i].x+dx]=='#'
            ||MapUsing[ASnake[i].y+dy][ASnake[i].x+dx]=='P'
            ||MapUsing[ASnake[i].y+dy][ASnake[i].x+dx]=='E'
            ||MapUsing[ASnake[i].y+dy][ASnake[i].x+dx]=='H'){
            Alive=0;
        }
        else {
            ASnake[0].x+=dx;ASnake[0].y=dy;
            for(int8 i=1;i<length;i++){
                ASnake[i].x=ASnake[i-1].x;
                ASnake[i].y=ASnake[i-1].y;
            }
        }
    }
}


Snake::Snake(){
    
}

Snake::~Snake(){

}

void Snake::Resize(){
    
}
