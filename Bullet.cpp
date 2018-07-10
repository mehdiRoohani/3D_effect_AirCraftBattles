#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    cout<<"Bullet Deallocated"<<endl;
}

Bullet::Bullet(LTexture* image, Point pos,int dep,int id):Unit(image, pos,id)
{
    depth = dep;
    setSpriteClips();

    speedx = 10;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
    collider.w=this->width;
    collider.h=this->height;
}


void Bullet::Move()
{
    position.x += speedx;
    collider.x=this->position.x-width/2;
}

void Bullet::setSpriteClips(){


    switch(depth){
        case 1:{
            spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = 0;
            spriteClips[ 0 ].x = 549;
            spriteClips[ 1 ].x = 549+14;
            spriteClips[ 2 ].x = 549+28;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 14;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
        case 2:{
            spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = 20;
            spriteClips[ 0 ].x = 549;
            spriteClips[ 1 ].x = 549+14;
            spriteClips[ 2 ].x = 549+28;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 14;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
        case 3:{
            spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = 40;
            spriteClips[ 0 ].x = 549;
            spriteClips[ 1 ].x = 549+14;
            spriteClips[ 2 ].x = 549+28;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 14;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
    }
}

void Bullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
