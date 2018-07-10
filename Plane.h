#pragma once
#include"Unit.h"
#include "Queue.h"
#include "Backgound.h"

class Plane:public Unit
{
public:
    Plane(LTexture* image, Point pos,int id);
    Plane();
    virtual ~Plane();
    void Move();
    void Move(int direc, SDL_Renderer* gRenderer,Queue* q,Background * bg,Background * bg1);
    void animateSpriteClips(int direc,SDL_Renderer* gRenderer,Queue* q,Background * bg,Background * bg1);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void setSpriteClips();
};

