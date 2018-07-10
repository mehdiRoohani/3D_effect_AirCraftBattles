#include "SplashScreen.h"


SplashScreen::SplashScreen()
{

}

SplashScreen::SplashScreen(LTexture* image, Point pos):DrawScreen(image,pos)
{

}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::Render(SDL_Renderer* gRenderer)
{
    image->Render( position.x, position.y, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}
