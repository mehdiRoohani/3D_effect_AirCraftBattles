#include "MainMenu.h"

MainMenu::MainMenu() : DrawScreen()
{


}

MainMenu::MainMenu(LTexture* image,LTexture* fontImage, Point pos):DrawScreen(image,pos)
{

    NG = new Button(fontImage,pos.shift((spriteClips.w/2),(spriteClips.h/2)-20), "New Game");
    Qut = new Button(fontImage,pos.shift((spriteClips.w/2),(spriteClips.h/2)+20), "Quit");

    if(NG->returnNoOfLetter()>Qut->returnNoOfLetter())
        maxNoOfL=NG->returnNoOfLetter();
    else if(Qut->returnNoOfLetter()>NG->returnNoOfLetter())
        maxNoOfL=Qut->returnNoOfLetter();
    NG->setButWidth(maxNoOfL);
    Qut->setButWidth(maxNoOfL);

    isFile=false;
}

MainMenu::~MainMenu()
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

void MainMenu::Event(SDL_Event e,const Uint8* currentKeyStates,bool* mouseClicked,int* state,bool* quit)
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
            if(checkClick(NG->returnButtonRect(),p))
            {
                *state = 2;
            }
            if (checkClick(Qut->returnButtonRect(),p))
            {
                *quit = true;
            }
        }
    }
    if( e.type == SDL_MOUSEBUTTONUP && *mouseClicked == true)
    {
        *mouseClicked=false;
    }
}

void MainMenu::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    NG->Render(gRenderer,maxNoOfL);
    Qut->Render(gRenderer,maxNoOfL);
}

