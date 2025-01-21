/**
 * @file Snake.hpp
 * @brief sentimentel index defination of the Snake
 * @author Martis
 * @include ForTypeDef.h
 */
#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "../ForTypeDef.h"
// #include "../Map/Map.h"
#include <stdlib.h>
#include <io.h>

class Snake {
  public:
    Snake(bool_array MapSelect,char **MapUsing);
    ~Snake();
    void Resize();
    direction Direction;
    ///@param operator^= for ensure the snake hitten or not and move the snake
    bool operator^=(const char **MapUsing);
  private:
    int16 length;
    int8 dx = 0, dy = 0;
    SnakeLocate *location = nullptr;
    ///@param For_Snake 
    ///@brief 1:alive 2: foodeated
    ///else: tempory null
    bool_array For_Snake = 0b10;
};

#endif