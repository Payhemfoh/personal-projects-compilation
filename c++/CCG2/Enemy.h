#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <cmath>
#include "character.h"
class Enemy :
    public Character
{
private:
    double hitbox;
public:
    Enemy(float x, float y, int hp, float speed);
    void draw();
    Bullet* attack();
    void attacked(Bullet& bullet);
};

#endif