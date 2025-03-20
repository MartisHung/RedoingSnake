#ifndef __SNAKE_H__
#define __SNAKE_H__

#include "../ForTypeDef.h"
// #include "../Map/Map.h"
#include <stdlib.h>

class Snake {
  public:
    Snake             (bool_array MapSelect,char **MapUsing);
    Snake             (char** MapUsing);        //Enemy's
    ~Snake();
    bool              getMovement  (char ch);
    void              RenderOnMap  (char **MapUsing);
    void              operator^=   (char **MapUsing);        //Player's movement
    void              operator|=   (char **MapUsing);        //enemy's  movement
    bool              operator==   (_nullptr_t)      const ; //Get alive
    void              EraseOnMap   (char **MapUsing) const ;
    void              ChangeToFood (char **MapUsing) const ;
    inline bool_array returnForSnake() const {return For_Snake;}
    Direction direction = Direction::UNDEFINED;
    SnakeLocate *location=nullptr;
  private:
    void Resize();
    bool initLocate(int8 x,int8 y,const char**MapUsing);
    int8 dx,dy;
    int16 length = 1;
    /**
     * @param For_Snake 
     * @brief 3 bit: Player/_bot_ 2 bit:alive / _died_  1 bit: foodeated 
     * @n else: null
     */
    bool_array For_Snake = 0x0;
};

#endif