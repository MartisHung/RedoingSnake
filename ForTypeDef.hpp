/**
 * @author Martis
 * @brief Defination of some own types
 */
#ifndef __FOR_TYPEDEF_HPP__
#define __FOR_TYPEDEF_HPP__

typedef char int8;
typedef char bool_array;
typedef short int16;

enum class direction:int8{
    forward=0x1,backward=0x2,left=0x3,right=0x4
};

struct bodyRecord{
    int8 x,y;
};
#endif 