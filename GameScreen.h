#include <stdlib.h>
#include <time.h>
#include "Plane.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Backgound.h"
#include "Queue.h"
#include "Word.h"
#include "Button.h"
#include "DrawScreen.h"
#include "Explosion.h"


using namespace std;

class GameScreen : public DrawScreen
{
protected:

    Background* display;
    Background* display2;
    long int frame;             //ANIMATION FRAME;
    bool buulet;
    Queue q;
    Plane* plane;
    Unit* enemyPlane;
    int random;

    Word* sword;

    Word* Pscore;
    int score;
    char buff[32];
    char *strscore;

    long int intervalFrame;     //INTERVAL FRAME;
    int enemySpeed;

public:
    GameScreen();
    GameScreen(LTexture* gameImage,LTexture* fontImage, Point pos);
    ~GameScreen();
    void Render(SDL_Renderer* gRenderer);
    void Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state,SDL_Renderer* gRenderer);
    void Play(LTexture* fontImage,int * state,int* scoreMain);
    void saveGame();
    //int Play (LTexture* image3,int* state, SDL_Renderer* gRenderer);  //image3 is basically wo wali image jis se fariha shozab ne sprites liye hain ball e.t.c

};

