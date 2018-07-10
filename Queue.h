#pragma once
#include"Node.h"
#include "Explosion.h"

class Queue
{
private:
    Node* head;
    Node* tail;
    Explosion* explode;

public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Clean(int,int* score);
    void collision(Unit* pla,LTexture* image,int* score);
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move();
};
