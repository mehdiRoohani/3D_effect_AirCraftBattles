#include <SDL.h>
#include <stdio.h>
#include "Character.h"
#include "Word.h"
#include "Button.h"
#include "DrawScreen.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "GameScreen.h"
#include "loseScreen.h"
#include "Point.h"

#include <iostream>

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

bool init();                            //Starts up SDL and creates window
bool loadMedia();                       //Loads media
void close();                           //Frees media and shuts down SDL

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;     //The surface contained by the window

LTexture gSpriteSheetTexture;
LTexture gSpriteSheetTexture2;
LTexture gSpriteSheetTexture3;



int main(int argc, char* args[])
{

    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
            Point position;                 //DETERMINIG CENTER OF THE SCREEN, ALL OBJECTS WILL BE DRAWN WITH RESPECT TO.
            position.x=0;
            position.y=0;
		    bool quit = false;//Main loop controller
		    bool mouseClicked = false;
		    int state = 0;
			SDL_Event e;
			const Uint8* currentKeyStates;
			int score=0;

////--------------------------------following are checks----------------------------------------------------------------
//			Word* welcome = new Word(&gSpriteSheetTexture,SCREEN_WIDTH/2,(SCREEN_HEIGHT/2)+50, "welcome to arkanoid");
//			Word* loadfile = new Word(&gSpriteSheetTexture,SCREEN_WIDTH/2,(SCREEN_HEIGHT/2)+50, "Load your saved game");
//			Word* Endgame = new Word(&gSpriteSheetTexture,SCREEN_WIDTH/2,(SCREEN_HEIGHT/2)-15, "E N D");
////          ^ these are only checks so dont get confuse with these.
//--------------------------------------------------------------------------------------------------------------------

            SplashScreen* splashScreen=NULL;
			MainMenu* menu=NULL;
			GameScreen* gameScreen=NULL;
			LoseScreen* loseScreen=NULL;

			while( !quit )   // Main game runs in this while loop
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
						//e.type = SDL_QUIT;     Hasan after doing that remove this!
                    }
                    currentKeyStates = SDL_GetKeyboardState( NULL );

                switch(state)
                {

                    case 0:
                    {
                        if(splashScreen==NULL)
                            splashScreen = new SplashScreen(&gSpriteSheetTexture2,position);
                        break;
                    }
                    case 1:
                    {
                        if(menu==NULL)
                            menu = new  MainMenu(&gSpriteSheetTexture2,&gSpriteSheetTexture,position);
                        menu->Event(e,currentKeyStates,&mouseClicked,&state,&quit);

                        break;
                    }
                    case 2:
                    {
                        if(gameScreen==NULL){
                            gameScreen = new  GameScreen(&gSpriteSheetTexture3,&gSpriteSheetTexture,position);
                            delete loseScreen;
                            loseScreen=NULL;
                        }
                        gameScreen->Event(e,currentKeyStates,&mouseClicked,&state,gRenderer);
                        break;
                    }
                    case 3:
                    {
                        if(loseScreen ==NULL){
                            loseScreen = new  LoseScreen(&gSpriteSheetTexture2,&gSpriteSheetTexture,position,score);
                            delete gameScreen;
                            gameScreen=NULL;
                        }
                        loseScreen->Event(e,currentKeyStates,&mouseClicked,&state,&quit);

                        break;
                    }

                }}

                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);
                switch(state){
                    case 0:{
                        splashScreen->Render(gRenderer);
                        SDL_RenderPresent(gRenderer);
                        SDL_Delay(1000);
                        state=1;
                        break;
                    }
                    case 1:{
                        if(menu!=NULL)
                            menu->Render(gRenderer);
                        break;
                    }
                    case 2:{
                        if(gameScreen!=NULL){
                            gameScreen->Play(&gSpriteSheetTexture,&state,&score);
                            gameScreen->Render(gRenderer);
                        }
                        break;
                    }
                    case 3:{
                        if(loseScreen!=NULL){
                            loseScreen->Render(gRenderer);
                        }
                        break;
                    }
                }
                SDL_RenderPresent(gRenderer);
			}

			close();

            delete splashScreen;
            delete menu;
            delete gameScreen;
            delete loseScreen;
		}
	}
    return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "FLASH GAMES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	if( !gSpriteSheetTexture.LoadFromFile( "Images/fontSprite1.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gSpriteSheetTexture2.LoadFromFile( "Images/backgrounds.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet 2 texture!\n" );
		success = false;
	}
	if( !gSpriteSheetTexture3.LoadFromFile( "Images/19471.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet 3 texture!\n" );
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();
	gSpriteSheetTexture2.Free();
	gSpriteSheetTexture3.Free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	//SDL_DestroyTexture(&gSpriteSheetTexture);
	gWindow = NULL;
	gRenderer = NULL;


	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
