/**
 * @file Snake.hpp
 * @brief sentimentel index defination of the Snake
 * @author Martis
 * @include ForTypeDef.h
 */

#ifndef __Snake_hpp__
#define __Snake_hpp__
#include "../ForTypeDef.hpp"

class Snake {
  public:
    Snake();
    ~Snake();
    void Resize();
    direction Direction;
    // for ensure the snake hitten or not.and move the snake
    bool operator|=(const char **MapUsing);

  private:
    bool Alive = 1,foodeated = 0;
    short length;
    int8 dx = 0, dy = 0;
    bodyRecord *ASnake;
};

#endif