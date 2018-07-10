#pragma once
#include "Unit.h"

class Background:public Unit
{
public:
    Background();
    Background(LTexture* image, Point pos,int id);
    ~Background();
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void setSpriteClips();
};
