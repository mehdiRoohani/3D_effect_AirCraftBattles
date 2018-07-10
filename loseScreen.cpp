#include "loseScreen.h"

LoseScreen::LoseScreen() : DrawScreen()
{


}

LoseScreen::LoseScreen(LTexture* image,LTexture* fontImage, Point pos,int score):DrawScreen(image,pos)
{
    replay = new Button(fontImage,pos.shift((spriteClips.w/2),(spriteClips.h/2)+25), "REPLAY");
    scoreW = new Word(fontImage, pos.shift((spriteClips.w/2)+25,(spriteClips.h/2)-30), "YOUR SCORE");
    replay->setButWidth(10);

    /* SCORE */

    strscore = itoa(score,buff, 10);
    Pscore = new Word(fontImage,pos.shift((spriteClips.w/2)+25,(spriteClips.h/2)), strscore);

    isFile=false;
}

LoseScreen::~LoseScreen()
{
//    delete NG;
//    NG = NULL;
//    delete LG;
//    LG = NULL;
//    delete Qut;
//    Qut = NULL;
//    delete welcome;
//    LG = NULL;

}

void LoseScreen::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state,bool* quit)
{

    if( e.type == SDL_MOUSEBUTTONDOWN && *mouseClicked == false)
    {
        Point p;
        int x,y;
        SDL_GetMouseState( &x, &y );
        p.x=x;
        p.y=y;


        if (e.button.button == SDL_BUTTON_LEFT){

            *mouseClicked = true;
            if(checkClick(replay->returnButtonRect(),p))
            {
                *state = 2;
            }
        }
    }
    if( e.type == SDL_MOUSEBUTTONUP && *mouseClicked == true)
    {
        *mouseClicked=false;
    }
}

void LoseScreen::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    replay->Render(gRenderer,10);
    Pscore->Render(gRenderer);
    scoreW->Render(gRenderer);
}


