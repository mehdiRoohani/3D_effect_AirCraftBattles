#pragma once
#include "SDL.h"
#include "string"
#include "Word.h"
#include "LTexture.h"
#include "Point.h"

class Button
{
protected:
    Point position;
    SDL_Rect buttonRect;
    Button* charr;
    int noOfLetters;
    SDL_Rect ButtonLeft;
    SDL_Rect ButtonCenter;
    SDL_Rect ButtonRight;
    SDL_Rect ButtonBackground;
    LTexture gSpriteSheetTexture;
    LTexture* middle;
    LTexture* left;
    LTexture* right;
    Word* buttonWord;
    int width, height, widthshift;
public:
    Button();
    ~Button();
    Button(LTexture* image, Point pos, char* text);
    int returnNoOfLetter();
    SDL_Rect returnButtonRect();
    void setButWidth(int nl);
    void Render(SDL_Renderer* gRenderer,int nl);
};
