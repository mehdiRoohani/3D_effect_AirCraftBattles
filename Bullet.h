#pragma once
#include"Unit.h"

class Bullet:public Unit
{
public:
    Bullet(LTexture* image, Point pos,int dep,int id);
    Bullet();
    ~Bullet();
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void setSpriteClips();
};

