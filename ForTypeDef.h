/**
 * @author Martis
 * @brief Defination of some own types
 */
#ifndef __FOR_TYPEDEF_H__
#define __FOR_TYPEDEF_H__

typedef char int8;
typedef short int16;
typedef char bool_array;

enum class direction : int8 {
    forward = 0x1,
    backward = 0x2,
    left = 0x3,
    right = 0x4
};

union SnakeLocate{
    int16 ll;
    struct bodyRecord { int8 x, y;}a;
};

#endif