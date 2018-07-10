#include "DrawScreen.h"

DrawScreen::DrawScreen()
{
}

DrawScreen::DrawScreen(LTexture* image, Point pos)
{
    position=pos;

    this->image = image;

    spriteClips.x =   0;
    spriteClips.y =   0;
    spriteClips.w = 800;
    spriteClips.h = 600;


    width=spriteClips.w;
    height=spriteClips.h;
}
DrawScreen::~DrawScreen()
{
    image = NULL;
}

bool DrawScreen::checkClick(SDL_Rect a,Point p){

    /*BOUNDARIES OF THE BUTTON*/
    int left;
    int right;
    int top;
    int bottom;

    /*CALCULATE THE SIZE OF RECTANGEL*/
    left = a.x;
    right = a.x + a.w;
    top = a.y;
    bottom = a.y + a.h;

    if(p.x>left && p.x<right && p.y>top && p.y<bottom){
        return true;
    }
    else{
        return false;
    }
}
void DrawScreen::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
