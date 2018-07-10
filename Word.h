#pragma once
#include "string"
#include "Character.h"
#include "LTexture.h"
#include "Point.h"

class Word
{
private:
    Character* charr;
    int noOfLetters;
public:
    Word();
    ~Word();
    Word(LTexture* image, Point pos, char* text);
    void Render(SDL_Renderer* gRenderer);
};
