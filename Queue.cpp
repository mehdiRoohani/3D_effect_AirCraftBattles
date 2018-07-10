#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        cout<<"Deallocating value: "<<temp->unit<<endl;
        delete temp;
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Clean(int Wid,int* score)
{
    Node* temp = head;
    while(temp!=NULL){

        if((temp->unit->returnPosition().x)<-50){

            *score-=1;
        }
        if((temp->unit->returnPosition().x)>Wid+28 || (temp->unit->returnPosition().x)<-50){
            Node* del=temp;
            temp=temp->next;
            if((del->prev)!=NULL)
            {
                del->prev->next = del->next;
            }
            else
                head=del->next;
            if((del->next)!=NULL){
                del->next->prev = del->prev;
            }
            else
                tail=del->prev;
            delete del;

        }
        else if(temp->unit->GetAlive()==false){
            Node* del=temp;
            temp=temp->next;
            if((del->prev)!=NULL)
            {
                del->prev->next = del->next;
            }
            else
                head=del->next;
            if((del->next)!=NULL){
                del->next->prev = del->prev;
            }
            else
                tail=del->prev;
            delete del;
        }

        else
            temp=temp->next;
    }

}

void Queue::collision(Unit* pla,LTexture* image,int* score)
{
    Node* temp1 = head;
    Node* temp2;
    if(head!=NULL)
        temp2 = head->next;
    else
        temp2=NULL;
    while(temp1!=NULL){
        while(temp2!=NULL){
            if((temp1->unit->getId()==3 && temp2->unit->getId()==2)){
                if(!temp1->unit->checkCollision(temp1->unit->getRect(),temp2->unit->getRect())){
                    if(temp1->unit->getDepth()==temp2->unit->getDepth()){

                        explode = new Explosion(image, temp2->unit->returnPosition(),1,9);
                        Enqueue(explode);

                        *score+=5;

                        /* DELETE BULLET */
                        Node* del=temp1;
                        temp1=temp1->next;
                        if((del->prev)!=NULL)
                        {
                            del->prev->next = del->next;
                        }
                        else
                            head=del->next;
                        if((del->next)!=NULL){
                            del->next->prev = del->prev;
                        }
                        else
                            tail=del->prev;
                        delete del;

                        temp1=head;

                        /* DELETE ENEMY */
                        Node * del1=temp2;
                        temp2=temp2->next;
                        if((del1->prev)!=NULL)
                        {
                            del1->prev->next = del1->next;
                        }
                        else
                            head=del1->next;
                        if((del1->next)!=NULL){
                            del1->next->prev = del1->prev;
                        }
                        else
                            tail=del1->prev;
                        delete del1;

                        temp1=head;
                        temp2=head;
                    }
                }
            }
            else if((temp1->unit->getId()==2)){
                if(!temp1->unit->checkCollision(pla->getRect(),temp1->unit->getRect())){
                    if(temp1->unit->getDepth()==pla->getDepth()){

                        pla->SetAlive(false);
                        explode = new Explosion(image, temp1->unit->returnPosition().shift(-50,0),1,9);
                        Enqueue(explode);

                        /* DELETE ENEMY */
                        Node* del=temp1;
                        temp1=temp1->next;
                        if((del->prev)!=NULL)
                        {
                            del->prev->next = del->next;
                        }
                        else
                            head=del->next;
                        if((del->next)!=NULL){
                            del->next->prev = del->prev;
                        }
                        else
                            tail=del->prev;
                        delete del;

                        temp1=head;
                    }
                }
            }

            if(temp2!=NULL)
                temp2=temp2->next;
        }
        if(temp1!=NULL)
            temp1=temp1->next;
        temp2=head;
    }
}

void Queue::Render(long int& frame, SDL_Renderer* gRenderer)
{
    Node* temp=head;
    while(temp!=NULL){
        temp->unit->Render(frame, gRenderer);
        temp=temp->next;
    }
    delete temp;
}

void Queue::Move()
{
    Node* temp=head;
    while(temp!=NULL){
        temp->unit->Move();
        temp=temp->next;
    }
}

