/**
 * @file Snake.hpp
 * @brief sentimentel index defination of the Snake
 * @author Martis
 * @include ForTypeDef.h
 */
#ifndef __SNAKE_H__
#define __SNAKE_H__
#include "../ForTypeDef.h"

class Snake {
  public:
    Snake();
    ~Snake();
    void Resize();
    direction Direction;
    bool operator|=(const char **MapUsing);

  private:
    int16 length;
    int8 dx = 0, dy = 0;
    SnakeLocate *location = nullptr;
    bool Alive = 1, foodeated = 0;
};

#endif