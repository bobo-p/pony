
#include<iostream>
#include<SDL.h>
#include <SDL_main.h>
#include <SDL_ttf.h>
#undef main
using namespace std;
int main()
{
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;    
    }
	
	TTF_Init();
}