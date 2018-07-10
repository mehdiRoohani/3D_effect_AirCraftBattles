#include "GameScreen.h"

GameScreen::GameScreen() : DrawScreen()
{

}

GameScreen::~GameScreen()
{

}

GameScreen::GameScreen(LTexture* gameImage,LTexture* fontImage, Point pos):DrawScreen(gameImage,pos)
{
    /* BACKGROUND SCROLLING */

    display = new Background(gameImage, position.shift(800, 600),10);
    display2 = new Background(gameImage, position.shift(800*2, 600),10);


    /* FRAMES */

    frame = 1;              //ANIMATION FRAME
    intervalFrame = 100;    //INTERVAL FRAME
    enemySpeed=5;
    buulet=false;

    /* PLAYER */

    plane = new Plane(gameImage, position.shift(100, 200),1);

    /* SCORE */

    strscore = itoa(score,buff, 10);
    score=0;
    sword = new Word(fontImage, position.shift(110, 585), "SCORE");
    Pscore = new Word(fontImage, position.shift(350, 585), strscore);

}

void GameScreen::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state,SDL_Renderer* gRenderer)
{
    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
    {
        plane->Move(RIGHT,gRenderer,&q,display,display2);
    }

    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
    {
        plane->Move(LEFT,gRenderer,&q,display,display2);
    }

    if(currentKeyStates[ SDL_SCANCODE_UP ])
    {
        plane->Move(UP,gRenderer,&q,display,display2);

    }
    if(currentKeyStates[ SDL_SCANCODE_DOWN ])
    {
        plane->Move(DOWN,gRenderer,&q,display,display2);
    }
    if(currentKeyStates[ SDL_SCANCODE_SPACE])
    {
        if(!buulet){
            Unit* bullet = new Bullet(this->image, plane->returnPosition().shift(0, 10-((plane->getDepth()-1)*3)),plane->getDepth(),3);
            q.Enqueue(bullet);
            buulet=true;
        }
    }
}

void GameScreen::Play(LTexture* fontImage,int * state,int* scoreMain)
{
    display->Move();
    display2->Move();

    srand (time(NULL));     //RANDOM SEED
    random = 0;

    if(frame%500==0 && intervalFrame>=25){
        intervalFrame-=10;
        cout<<"Here";
    }
    if(frame%5000==0){
        enemySpeed+=1;
    }

    if(frame%intervalFrame == 0)
    {
        random = (rand() % 3);
        enemyPlane = new Enemy(this->image, this->position.shift(800, (200)-(((random+frame)%3)*28)),((random+frame)%3)+1,2,enemySpeed);
        q.Enqueue(enemyPlane);
    }

    q.Move();
    q.Clean(800,&score);
    q.collision(plane,image,&score);
    *scoreMain=score;

    strscore = itoa(score,buff, 10);
    delete Pscore;
    Pscore = new Word(fontImage, position.shift(200, 585), strscore);

    plane->Move();

    if(plane->GetAlive()==false){
        *state=3;
    }

    buulet=false;
    ++frame;
}

void GameScreen::Render(SDL_Renderer* gRenderer)
{
    display->Render(frame, gRenderer);
    display2->Render(frame, gRenderer);
    plane->Render(frame, gRenderer);
    Pscore->Render(gRenderer);
    sword->Render(gRenderer);

    q.Render(frame, gRenderer);

}
