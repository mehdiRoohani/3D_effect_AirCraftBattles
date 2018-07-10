#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Point.h"

using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
protected:
    int id;
    bool alive;
    Point position;
    int depth;
    float speedx;
    float speedy;
    int width;
    int height;
    float friction; //lower speed means more friction
    SDL_Rect collider;

    enum ANIMATION_FRAMES {FLYING_FRAMES = 3};
    SDL_Rect spriteClips[ 12 ];
    LTexture* spriteSheetTexture;

public:
    Unit(LTexture* image, Point pos,int id);
    Unit();
    virtual ~Unit();
    void SetAlive(bool);
    bool GetAlive();
    int getDepth();
    int getId();
    SDL_Rect getRect();
    Point returnPosition();
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    virtual void Move();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer);
    virtual void setSpriteClips();
};



