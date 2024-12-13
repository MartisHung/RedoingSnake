#ifndef __Snake_hpp__
#define __Snake_hpp__
#pragma once
#include<stdint.h>
#include<iostream>

struct bodyRecord{
    uint8_t x,y;
    bool operator==(const bodyRecord& other)const;
    
};

class Snake{
private:
    bool Alive = 1;
    uint8_t length=1;
    bodyRecord* ASnake;
public:
    Snake();
    ~Snake();
    void Resize();
};

#endif