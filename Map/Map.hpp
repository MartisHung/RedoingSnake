#ifndef __Map_H__
#define __MAP_H__

#include "../ArrowInitilization.hpp"
#include <unistd.h>

#define MAX_OF_MAP_X 0x40

#define MAX_OF_MAP_1_Y 0x18

#define MAX_OF_MAP_2_Y 0x15

#define MAX_OF_MAP_3_Y 0x15

class Map{
    private:
        //each bit represent a map finish or not
        char EnsureTheMapFinish=0b0000;
        char**Map1=new char*[MAX_OF_MAP_1_Y];
        char**Map2=new char*[MAX_OF_MAP_2_Y];
        char**Map3=new char*[MAX_OF_MAP_3_Y];
        char**Map4=new char*[MAX_OF_MAP_3_Y];
    public:
        Map();
        ~Map();
};

#endif