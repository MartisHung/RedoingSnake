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
class Map;
class Snake {
  public:
    Snake(bool_array MapSelect,char **MapUsing,decltype(nullptr));
    Snake(bool_array MapSelect,char **MapUsing,int)=delete;
    Snake(char** MapUsing);
    ~Snake();
    bool operator==(decltype(nullptr))const;
    bool operator==(int)=delete;
    void operator^=(char **MapUsing);
    bool getMovement(char ch);
    direction Direction;
    SnakeLocate *location=nullptr;
  private:
    void Resize();
    bool initLocate(int8 x,int8 y,char**MapUsing);
    int8 dx,dy;
    int16 length;
    /**
     * @param For_Snake 
     * @brief 3 bit:player/_Robot_ 2 bit:alive 1 bit: foodeated
     * @brief else: null
     */
    bool_array For_Snake = 0b10;
};

#endif