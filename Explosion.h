#pragma once
#include "Unit.h"
#include <iostream>

class Explosion:public Unit
{
protected:
    int sprite;
public:
    Explosion(LTexture*,Point pos,int dep,int id);
    Explosion();
    ~Explosion();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    bool GetAlive();
    void setSpriteClips();
};
