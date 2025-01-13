#ifndef __Map_H__
#define __MAP_H__

#include "../ArrowInitilization.hpp"
#include "../ForTypeDef.hpp"
#include <unistd.h>

#define MAX_OF_MAP_X 0x41

#define MAX_OF_MAP_1_Y 0x18
#define MAX_OF_MAP_2_Y 0x15
#define MAX_OF_MAP_3_Y 0x15
#define MAX_OF_MAP_4_Y 0x17

class Map{
public:
    Map();
    ~Map();
    void MapTransfer(char **MapUsing,int8 MapSelect)const;
private:
    // each bit represent a map finish or not
    bool_array EnsureTheMapFinish = 0b0000;
    //Map reference
    const char **Map1 = new char *[MAX_OF_MAP_1_Y];
    const char **Map2 = new char *[MAX_OF_MAP_2_Y];
    const char **Map3 = new char *[MAX_OF_MAP_3_Y];
    const char **Map4 = new char *[MAX_OF_MAP_4_Y];
};
void ShowMap(char **MapUsing,int8 MapSelected);

#endif