#include<bits/stdc++.h>
#include <SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include"screens.h"
#include"functions.h"
using namespace std;
#define winhgt 700
#define winwid 1360
int playmode=0;
vector<int> team,team2;

void Initialize_all()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    TTF_Init();
    font = TTF_OpenFont("Media/font.ttf", 50);

    game=SDL_CreateWindow("CRICX",1,22, winwid, winhgt, SDL_WINDOW_FULLSCREEN);
    grenderer=SDL_CreateRenderer(game, -1, 0);
}



void close_all()
{
    SDL_DestroyWindow(game);
    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

int main( int argc, char * argv[] )
{
    //freload("database.txt","w",stdout);
    Initialize_all();
    Load_all_media();
    screen1();
    int level=levels();
    playmode=screen2();
    if(playmode==1)
    {
        team=defaultteam();
    }
    else
    {
        team=createteam();
        team=choosebat(team,database);
        SDL_Delay(500);
        team=choosewik(team,database);
        SDL_Delay(500);
        team=choosealr(team,database);
        SDL_Delay(500);
        team=choosebol(team,database);
    }
    screen3(team,database);
    SDL_Delay(1000);
    int tos=toss();
    int bat;
    SDL_Delay(1000);
    if(tos)
    {
        bat=choose1();
    }
    else
    {
        srand (time(NULL));
        int p=rand()%2;
        choose2(p);
        bat=p+1;
    }
    SDL_Delay(1000);
    screen4();
    int run1=-1,run2=-1;
    if(bat==1)
    {
        run1=batt(team,level,run2);
        run2=bowl(team,level,run1);
    }
    else
    {
        run2=bowl(team,level,run1);
        run1=batt(team,level,run2);
    }
    if(run1>run2)
        finall(" YOU WIN ");
    else if(run2>run1)
        finall(" YOU LOSE ");
    else
        finall(" MATCH TIED ");

    close_all();

    return 0;
}

