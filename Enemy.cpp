#include"Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    cout<<"Enemy Deallocated"<<endl;
}

Enemy::Enemy(LTexture* image, Point pos,int dep,int id,int speed):Unit(image,pos,id)
{
    depth = dep;
    setSpriteClips();

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    collider.x=this->position.x-this->width/2;
    collider.y=this->position.y-this->height/2;
    collider.w=this->width;
    collider.h=this->height;

    speedx = speed;
}


void Enemy::Move()
{
    position.x = position.x - speedx;

    collider.x=this->position.x-width/2;
}

void Enemy::setSpriteClips(){

    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = 0;

    switch(depth){
        case 1:{
            spriteClips[ 0 ].x = 0+591;
            spriteClips[ 1 ].x = 76+591;
            spriteClips[ 2 ].x = (76*2)+591;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 76;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
        case 2:{
            spriteClips[ 0 ].x = (76*3)+591;
            spriteClips[ 1 ].x = (76*3)+61+591;
            spriteClips[ 2 ].x = (76*3)+(61*2)+591;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 61;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
        case 3:{
            spriteClips[ 0 ].x = (76*3)+(61*3)+591;
            spriteClips[ 1 ].x = (76*3)+(61*3)+46+591;
            spriteClips[ 2 ].x = (76*3)+(61*3)+(46*2)+591;
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 46;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
    }
}

void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[ frame % 3 ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
}
