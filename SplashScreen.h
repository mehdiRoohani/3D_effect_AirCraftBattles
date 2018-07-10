#pragma once
#include "Word.h"
#include "Button.h"
#include "LTexture.h"
#include "DrawScreen.h"
#include "Point.h"
#include <iostream>
#include <SDL.h>


using namespace std;

class SplashScreen : public DrawScreen
{
    int state;
public:
    SplashScreen();
    ~SplashScreen();
    SplashScreen(LTexture* image, Point pos);
    void Render(SDL_Renderer* gRenderer);

};

