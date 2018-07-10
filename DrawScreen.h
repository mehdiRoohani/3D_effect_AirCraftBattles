#pragma once
#include "LTexture.h"
#include <SDL.h>
#include <stdio.h>
#include "Point.h"
#include <fstream>
#include <iostream>


class DrawScreen
{
protected:
    LTexture* image;
    SDL_Rect spriteClips;
    Point position;
    float width;
    float height;
    FILE* filePointer;                          //Declaring a file pointer

public:
    DrawScreen();
    ~DrawScreen();
    DrawScreen(LTexture* image, Point pos);
    bool checkClick(SDL_Rect a, Point p);
//    virtual void SetPosition(LTexture* image, int x, int y);
    virtual void Render(SDL_Renderer* gRenderer);
};
