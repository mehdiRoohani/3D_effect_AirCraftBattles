#pragma once
#include "Word.h"
#include "Button.h"
#include "LTexture.h"
#include "DrawScreen.h"

using namespace std;

class LoseScreen : public DrawScreen
{
protected:
    Button* replay;
    Word* scoreW;

    Word* Pscore;
    char buff[32];
    char *strscore;

    int maxNoOfL;
    int isFile;

public:
    LoseScreen();
    LoseScreen(LTexture* image,LTexture* fontImage, Point pos,int score);
    ~LoseScreen();
    void Event(SDL_Event e,const Uint8* currentKeyStates,bool*,int* state,bool*);
    void Render(SDL_Renderer* gRenderer);
};
