#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, Point pos,int id)
{
    spriteSheetTexture = image;

    this->position=pos;

    this->id=id;

    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;

}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}


bool Unit::GetAlive()
{
    return alive;
}

void Unit::Move()
{

}

Point Unit::returnPosition()
{
    return position;
}

int Unit::getDepth()
{
    return depth;
}

int Unit::getId()
{
    return id;
}

SDL_Rect Unit::getRect(){
    return collider;
}

bool Unit::checkCollision(SDL_Rect a, SDL_Rect b){

    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if(rightA>=leftB && bottomA>=topB && topA<=bottomB && rightA<=rightB)
    {
        return false;
    }
    else
        return true;
}

void Unit::setSpriteClips(){

}


void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( int(position.x - width/2), int(position.y - height/2), &spriteClips[ frame % FLYING_FRAMES ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
