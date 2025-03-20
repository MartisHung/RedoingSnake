/**
 * @author Martis
 * @brief Defination of some own types
 */
#ifndef __FOR_TYPEDEF_H__
#define __FOR_TYPEDEF_H__
#include <chrono>

typedef char int8;
typedef short int16;
typedef char bool_array;
typedef std::nullptr_t _nullptr_t;
typedef std::chrono::time_point<std::chrono::system_clock> m_clock_t;

enum class Direction : int8 {
    UNDEFINED = 0x0,
    forward = 0x1,
    backward = 0x2,
    left = 0x3,
    right = 0x4
};

union SnakeLocate{
    int16 ll;
    struct bodyRecord { int8 x;int8 y;}a;
};

#endif // __FOR_TYPEDEF_H__