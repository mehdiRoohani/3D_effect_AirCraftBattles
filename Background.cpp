#include "Backgound.h"

Background::Background()
{

}

Background::Background(LTexture* image, Point pos,int id):Unit(image, pos,id)
{
    setSpriteClips();
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

}
Background::~Background()
{

}

void Background::Move()
{
    speedx=1;
    speedx = speedx * friction;
    position.x = position.x - speedx;
    if (position.x<0)
    {
        position.x=1600;
    }
}

void Background::setSpriteClips(){

    spriteClips[ 0 ].x = 0;                 //coordinates calculated through the select option in paint.
    spriteClips[ 0 ].y = 300;                  //y coordinate and width,height remains same. x changes.
    spriteClips[ 0 ].w = 800;
    spriteClips[ 0 ].h = 600;

}

void Background::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x-width, position.y-height, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
