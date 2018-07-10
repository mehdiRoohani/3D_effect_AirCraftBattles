#pragma once
#include"Unit.h"

class Enemy:public Unit
{
public:
    Enemy(LTexture* image, Point pos,int dep,int id,int speed);
    Enemy();
    ~Enemy();
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void setSpriteClips();
};
