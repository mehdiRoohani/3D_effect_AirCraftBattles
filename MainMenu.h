#pragma once
#include "Word.h"
#include "Button.h"
#include "LTexture.h"
#include "DrawScreen.h"

using namespace std;

class MainMenu : public DrawScreen
{
    Button* NG;
    Button* LG;
    Button* Qut;
    int maxNoOfL;
    int isFile;

public:
    MainMenu();
    MainMenu(LTexture* image,LTexture* fontImage, Point pos);
    ~MainMenu();
    void Event(SDL_Event e,const Uint8* currentKeyStates,bool*,int* state,bool*);
    void Render(SDL_Renderer* gRenderer);
};
