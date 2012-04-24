
#include<iostream>
#include<SDL.h>
#include <SDL_main.h>
#include <SDL_ttf.h>
#include<cmath>
#undef main
using namespace std;
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
class fucker
{
public:
	SDL_Rect obj;
	float x,y;
	fucker()
	{
		x=20;
		y=20;
	}
	bool is_int(float x)
	{
		if(x-floor(x)==0) return true;
		else return false;
	}
	void sys_draw_rect(float xv, float yv, int w, int h,SDL_Surface *s)
	{
			SDL_Rect rect;
			rect.x = x;
			rect.y = y;
			rect.w = w;
			rect.h = h;
			SDL_FillRect(s,&rect,SDL_MapRGB(s->format,0,0,0));
			//SDL_Flip( s );
			if (x<s->w-25&&x>0)x+=xv;
			else if(xv<0&&x>0)x+=xv;
			else if(xv>0&&x<s->w-25) x+=xv;

			if(y<s->h-25&&y>0)y+=yv;
			else if(yv<0&&y>0)y+=yv;
			else if(yv>0&&y<s->h-25)y+=yv;
			rect.x+=xv;
			rect.y+=yv;
			SDL_FillRect(s,&rect,SDL_MapRGB(s->format,20,90,20));		
	}
	
};

int main()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
	
	

	SDL_WM_SetCaption( "Pony", NULL );
	SDL_Surface* screen = NULL;
	screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE );
	
	TTF_Init();
	SDL_Surface *message=NULL;
	TTF_Font *font = NULL;
	SDL_Color textColor = { 255, 255, 255 };
	font = TTF_OpenFont( "D:/AmphionExtrabold Regular.ttf", 30 );
	if (font==0) 
	{
		cout<<"Nie moge otworzyc pliku ttf";

	}
	else message = TTF_RenderText_Solid( font, "Dzialam kurwa!!!", textColor );

	apply_surface( 150, 5, message, screen );

	fucker x;

	float xvel,yvel;
	bool quit=1;
    xvel=0;
	yvel=0;
	SDL_Event event;

	while(quit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT) quit=0;

			if(event.type==SDL_KEYDOWN)
			{
				
				switch( event.key.keysym.sym )
				{
					case SDLK_UP: yvel=-1;
						break;
					case SDLK_LEFT:xvel=-1;
						break;
					case SDLK_DOWN:yvel=1;
						break;
					case SDLK_RIGHT:xvel=1;
						break;
				}

				
			}

			if(event.type==SDL_KEYUP)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_LEFT:xvel=0;
					break;
					case SDLK_RIGHT:xvel=0;
					break;
					case SDLK_UP:yvel=0;
					break;
					case SDLK_DOWN:yvel=0;
					break;
					default:
						break;
				}

			}

		}

		x.sys_draw_rect(xvel,yvel,25,25,screen);
		apply_surface( 150, 5, message, screen );
			SDL_Flip( screen );
			SDL_Delay(3);
	}
	TTF_Quit();
	SDL_Quit();
	return 0;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
	SDL_BlitSurface( source, NULL, destination, &offset );
	
}


