#include "Explosion.h"

Explosion::Explosion()
{

}
Explosion::~Explosion()
{
    spriteSheetTexture = NULL;
}

Explosion::Explosion(LTexture* image, Point pos,int dep,int id):Unit(image, pos,id)
{
    depth = dep;
    setSpriteClips();

    sprite=0;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
    collider.w=this->width;
    collider.h=this->height;
}

void Explosion::setSpriteClips(){


    switch(depth){
        case 1:{
            spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = spriteClips[ 3 ].y = 300;
            spriteClips[ 4 ].y = spriteClips[ 5 ].y = spriteClips[ 6 ].y = spriteClips[ 7 ].y = 370;
            spriteClips[ 8 ].y = spriteClips[ 9 ].y = spriteClips[ 10 ].y = spriteClips[ 11 ].y = 370+70;
            spriteClips[ 0 ].x = 800;
            spriteClips[ 1 ].x = 858;
            spriteClips[ 2 ].x = 858+58;
            spriteClips[ 3 ].x = 858+(58*2);
            spriteClips[ 4 ].x = 800;
            spriteClips[ 5 ].x = 858;
            spriteClips[ 6 ].x = 858+58;
            spriteClips[ 7 ].x = 858+(58*2);
            spriteClips[ 8 ].x = 800;
            spriteClips[ 9 ].x = 858;
            spriteClips[ 10 ].x = 858+58;
            spriteClips[ 11 ].x = 858+(58*2);
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = spriteClips[ 3 ].w = spriteClips[ 4 ].w = spriteClips[ 5 ].w = spriteClips[ 6 ].w = spriteClips[ 7 ].w = spriteClips[ 8 ].w = spriteClips[ 9 ].w = spriteClips[ 10 ].w = spriteClips[ 11 ].w = 58 ;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = spriteClips[ 3 ].h = spriteClips[ 4 ].h = spriteClips[ 5 ].h = spriteClips[ 6 ].h = spriteClips[ 7 ].h = spriteClips[ 8 ].h = spriteClips[ 9 ].h = spriteClips[ 10 ].h = spriteClips[ 11 ].h = 70;
            break;
        }

    }
}

void Explosion::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x-width/2 , position.y-height/2 , &spriteClips[ sprite ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    sprite++;
    if (sprite >= 12)
    {
        alive =false;
    }
}



