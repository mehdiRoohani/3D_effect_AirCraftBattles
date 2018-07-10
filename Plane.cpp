#include"Plane.h"

Plane::Plane()
{

}

Plane::~Plane()
{
    cout<<"Plane Deallocated"<<endl;
}

Plane::Plane(LTexture* image, Point pos,int id):Unit(image, pos,id)
{
    depth =1;
    setSpriteClips();

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
    collider.w=this->width;
    collider.h=this->height;
}


void Plane::Move()
{
    speedx = speedx * friction;
    speedy = speedy * friction;

    position.x = position.x + speedx;
    position.y = position.y + speedy;
//
    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
}

void Plane::Move(int direc,SDL_Renderer* gRenderer,Queue * q,Background * bg,Background * bg1)
{

    if(direc==LEFT)
    {
        speedx = -5;
        position.x+=speedx;
    }

    if(direc==RIGHT)
    {
        speedx = 5;
        position.x+=speedx;
    }

    if(direc==UP)
    {
        animateSpriteClips(direc,gRenderer,q,bg,bg1);
        setSpriteClips();
    }

    if(direc==DOWN)
    {
        animateSpriteClips(direc,gRenderer,q,bg,bg1);
        setSpriteClips();

    }
    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
}

void Plane::setSpriteClips(){

    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = 0;

    switch(depth){
        case 1:{
            spriteClips[ 0 ].x = 0;
            spriteClips[ 1 ].x = 76;
            spriteClips[ 2 ].x = (76*2);
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 76;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;

            break;
        }
        case 2:{
            spriteClips[ 0 ].x = (76*3);
            spriteClips[ 1 ].x = (76*3)+61;
            spriteClips[ 2 ].x = (76*3)+(61*2);
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 61;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
        case 3:{
            spriteClips[ 0 ].x = (76*3)+(61*3);
            spriteClips[ 1 ].x = (76*3)+(61*3)+46;
            spriteClips[ 2 ].x = (76*3)+(61*3)+(46*2);
            spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 46;
            spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
            break;
        }
    }

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    collider.x=this->position.x-width/2;
    collider.y=this->position.y-height/2;
}

void Plane::animateSpriteClips(int direc,SDL_Renderer* gRenderer,Queue* q,Background * bg,Background * bg1){

    long int frame=0;
    if(direc==UP && depth<3){
        depth+=1;
        switch(depth){
            case 2:{
                for(int i=1; i<8; i++){
                    frame=i;
                    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = i*20;
                    position.y-=4;
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    bg->Move();
                    bg->Render(frame,gRenderer);
                    bg1->Move();
                    bg1->Render(frame,gRenderer);
                    q->Move();
                    q->Render(frame,gRenderer);
                    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[i%2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(20);
                }
                break;
            }
            case 3:{
                for(int i=1; i<8; i++){
                    frame=i;
                    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = i*20;
                    position.y-=4;
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    bg->Move();
                    bg1->Render(frame,gRenderer);
                    bg1->Move();
                    bg->Render(frame,gRenderer);
                    q->Move();
                    q->Render(frame,gRenderer);
                    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[i%2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(20);
                }
                break;
            }
        }
    }
    else if(direc==DOWN && depth>1){
        depth-=1;
        switch(depth){
            case 1:{
                for(int i=14; i>=8; i--){
                    frame=i;
                    position.y+=4;
                    spriteClips[ 0 ].x = 0;
                    spriteClips[ 1 ].x = 76;
                    spriteClips[ 2 ].x = (76*2);
                    spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 76;
                    spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
                    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = i*20;
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    bg->Move();
                    bg->Render(frame,gRenderer);
                    bg1->Move();
                    bg1->Render(frame,gRenderer);
                    q->Move();
                    q->Render(frame,gRenderer);
                    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[i%2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(20);
                }
                break;
            }
            case 2:{
                for(int i=14; i>=8; i--){
                    frame=i;
                    position.y+=4;
                    spriteClips[ 0 ].x = (76*3);
                    spriteClips[ 1 ].x = (76*3)+61;
                    spriteClips[ 2 ].x = (76*3)+(61*2);
                    spriteClips[ 0 ].w = spriteClips[ 1 ].w = spriteClips[ 2 ].w = 61;
                    spriteClips[ 0 ].h = spriteClips[ 1 ].h = spriteClips[ 2 ].h = 20;
                    spriteClips[ 0 ].y = spriteClips[ 1 ].y = spriteClips[ 2 ].y = i*20;
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );
                    bg->Move();
                    bg->Render(frame,gRenderer);
                    bg1->Move();
                    bg1->Render(frame,gRenderer);
                    q->Move();
                    q->Render(frame,gRenderer);
                    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips[i%2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay(20);
                }
                break;
            }
        }
    }

}

void Plane::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Unit::Render(frame,gRenderer);
}

