#include "Button.h"
#include <iostream>
#include "string.h"
#include "Character.h"
#include "Word.h"
#include <ctype.h>
#include "Point.h"

Button::Button()
{

}

Button::Button(LTexture* image,Point pos, char* text)
{
    position.x = pos.x;
    position.y = pos.y;

    noOfLetters=strlen(text);
    buttonWord = new Word(image,pos.shift(20,15), text);

    middle = image;
    left = image;
    right = image;
    //Left
    ButtonLeft.x = 0;
    ButtonLeft.y = 90;
    ButtonLeft.w = 20;
    ButtonLeft.h = 30;

    ButtonCenter.x = 20;
    ButtonCenter.y = 90;
    ButtonCenter.w = 20;
    ButtonCenter.h = 30;

    ButtonRight.x = 80;
    ButtonRight.y = 90;
    ButtonRight.w = 20;
    ButtonRight.h = 30;

    buttonRect.x = position.x-(((noOfLetters/2)+1)*20);
    buttonRect.y = position.y;
    buttonRect.w = 20*(noOfLetters+2);
    buttonRect.h = 30;

    this->width = ButtonCenter.w;
    this->height = ButtonCenter.h;

}

int Button::returnNoOfLetter(){
    return noOfLetters;
}

void Button::setButWidth(int nl){
    buttonRect.x = position.x-(((nl/2)+1)*20);
    buttonRect.w = 20*(nl+2);
}

SDL_Rect Button::returnButtonRect(){
    return buttonRect;
}

void Button::Render(SDL_Renderer* gRenderer,int nl)
{
    left->Render( position.x-((nl/2)*20)-20, position.y, &ButtonLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    right->Render( position.x+((nl/2)*20)+20, position.y, &ButtonRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//    left->Render( position.x-100, position.y, &ButtonLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
//    right->Render( position.x+100, position.y, &ButtonRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    for(int i=-(nl/2); i<(nl/2)+1; i++)
//    for(int i=-4; i<5; i++)
    {
        middle->Render( position.x+20*i, position.y, &ButtonCenter, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    buttonWord->Render(gRenderer);
}
