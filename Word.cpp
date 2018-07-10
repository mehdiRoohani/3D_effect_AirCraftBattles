#include "Word.h"
#include <iostream>
#include "string.h"
#include "Character.h"

using namespace std;

Word::Word()
{

}
Word::Word(LTexture* image,Point pos, char* text)
{
    noOfLetters=strlen(text);
    charr = new Character[noOfLetters];

    int shift = -(noOfLetters/2);
    if(noOfLetters%2==0)
    {
        for(int i=0; i<noOfLetters; i++)
        {
            charr[i].generateCharacter(image, pos.shift((shift*charr[i].characterWidth()),0), text[i]);
            shift++;
        }
    }
    else                                                                            // conditions for shifting the word
    {
        for(int i=0; i<noOfLetters; i++)
        {
            charr[i].generateCharacter(image, pos.shift((shift*charr[i].characterWidth())-10,0), text[i]);
            shift++;
        }
    }
}
Word::~Word()
{
    delete[] charr;
}


void Word::Render(SDL_Renderer* gRenderer)
{
    for(int j=0; j<noOfLetters; j++)
    {
        charr[j].Render(gRenderer);
    }

}
