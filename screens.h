#include<bits/stdc++.h>
using namespace std;
SDL_Window *game=NULL;
SDL_Surface *circle;
SDL_Surface *buttons[100],*score[8];
SDL_Surface *bg[12];
SDL_Renderer *grenderer=NULL;
SDL_Texture *gtexture=NULL;
TTF_Font *font=NULL;
struct data
{
    string name;
    int match;
    int innings;
    int run;
    string bestbat;
    int overs;
    int wickets;
    int runC;
    string bestbowl;
};
struct data database[65];
SDL_Color color= {30,144,255};//light blue
SDL_Color color2= {0,0,128};//deep blue
SDL_Color bgcl= {173,216,230};
SDL_Color color3= {220,20,60};
SDL_Color silver= {169,169,169};
SDL_Color silver2= {192,192,192};

SDL_Event e;
void Load_all_media()
{
    freopen("database.txt","r",stdin);
    string s,ss,sss;
    int a,b,c,d,f,g,i,j,k;
    for(int i=0; i<65; i++)
    {
        getline(cin,s);
        cin>>a>>b>>c>>ss>>d>>g>>f>>sss;
        cin.ignore();
        database[i].name=s;
        database[i].match=a;
        database[i].innings=b;
        database[i].run=c;
        database[i].bestbat=ss;
        database[i].overs=d;
        database[i].wickets=g;
        database[i].runC=f;
        database[i].bestbowl=sss;
    }

    SDL_Color color= {30,144,255};//light blue
    SDL_Color color2= {0,0,128};//deep blue
    SDL_Color bgcl= {173,216,230};
    SDL_Color color3= {220,20,60};
    bg[0]=IMG_Load("Media/bg.jpg");
    bg[1]=IMG_Load("Media/bg1.jpg");
    bg[11]=IMG_Load("Media/bg.jpg");
    bg[2]=IMG_Load("Media/bg2.jpg");
    bg[3]=IMG_Load("Media/bg3.jpg");
    bg[4]=IMG_Load("Media/bg4.jpg");
    bg[5]=IMG_Load("Media/bg5.jpg");
    bg[6]=IMG_Load("Media/bg6.jpg");
    bg[7]=IMG_Load("Media/bg7.jpg");
    bg[8]=IMG_Load("Media/bg8.jpg");
    bg[9]=IMG_Load("Media/bg9.jpg");
    bg[10]=IMG_Load("Media/bg10.jpg");
    circle=IMG_Load("Media/circle_1.png");
    buttons[0]=TTF_RenderText_Solid(font,"|PLAY|", color2);
    buttons[1]=TTF_RenderText_Shaded(font,"|QUIT|", color, bgcl);
    buttons[2]=TTF_RenderText_Solid(font,"|DEFAULT TEAM|", color);
    buttons[3]=TTF_RenderText_Solid(font,"|CREATE TEAM|", color);
    buttons[4]=TTF_RenderText_Shaded(font,"RUN : ", color, bgcl);
    buttons[5]=TTF_RenderText_Shaded(font,"WICKETS : ", color, bgcl);
    buttons[6]=TTF_RenderText_Shaded(font,"OVERS : ", color, bgcl);
    buttons[7]=TTF_RenderText_Shaded(font,"BOWLER : ", color, bgcl);
    buttons[8]=TTF_RenderText_Shaded(font,"BATSMAN* : ", color, bgcl);
    buttons[9]=TTF_RenderText_Shaded(font,"BATSMAN : ", color, bgcl);
    buttons[10]=TTF_RenderText_Solid(font,"|MENU|", color);
    buttons[11]=TTF_RenderText_Shaded(font,"CHOOSE 4 BATSMEN", color2, bgcl);
    buttons[12]=TTF_RenderText_Shaded(font,"CHOOSE YOUR WICKETKEEPER", color, bgcl);
    buttons[13]=TTF_RenderText_Shaded(font,"CHOOSE 3 ALROUNDERS", color, bgcl);
    buttons[43]=TTF_RenderText_Shaded(font,"CHOOSE 3 BOWLERS", color, bgcl);
    buttons[14]=TTF_RenderText_Shaded(font,"YOUR TEAM", color, bgcl);
    buttons[15]=TTF_RenderText_Shaded(font,"OPONENT TEAM", color, bgcl);
    buttons[16]=TTF_RenderText_Shaded(font,"|CONTINUE|", color3, bgcl);
    buttons[17]=TTF_RenderText_Solid(font," T O S S ", color);
    buttons[18]=TTF_RenderText_Solid(font," H E A D S ", color);
    buttons[19]=TTF_RenderText_Solid(font," T A I L S ", color);
    buttons[20]=TTF_RenderText_Solid(font,"YOU WON", color);
    buttons[21]=TTF_RenderText_Solid(font,"BAT FIRST", color2);
    buttons[22]=TTF_RenderText_Solid(font,"BOWL FIRST", color2);
    buttons[23]=TTF_RenderText_Solid(font,"YOUR OPPONENT WON", color);
    buttons[24]=TTF_RenderText_Solid(font,"THEY'LL BOWL FIRST", color);
    buttons[25]=TTF_RenderText_Solid(font,"THEY'LL BAT FIRST", color);
    buttons[26]=TTF_RenderText_Solid(font,"LET THE FUN BEGIN", color);
    buttons[27]=TTF_RenderText_Solid(font,"| L E V E L   1 |", color);
    buttons[28]=TTF_RenderText_Solid(font,"| 2  OVERS, OPPONENT SKILL  0 |", silver);
    buttons[29]=TTF_RenderText_Solid(font,"| L E V E L   2 |", color);
    buttons[30]=TTF_RenderText_Solid(font,"| 4  OVERS, OPPONENT SKILL  1 |", silver);
    buttons[31]=TTF_RenderText_Solid(font,"| L E V E L   3 |", color);
    buttons[32]=TTF_RenderText_Solid(font,"| 5  OVERS, OPPONENT SKILL  2 |", silver);
    buttons[33]=TTF_RenderText_Solid(font,"| L E V E L   4 |", color);
    buttons[34]=TTF_RenderText_Solid(font,"| 6  OVERS, OPPONENT SKILL  3 |", silver);
    buttons[35]=TTF_RenderText_Solid(font,"| L E V E L   5 |", color);
    buttons[36]=TTF_RenderText_Solid(font,"| 10  OVERS, OPPONENT SKILL  5 |", silver);
    score[5]=TTF_RenderText_Shaded(font,"D O T   B A L L", color, bgcl);
    score[4]=TTF_RenderText_Shaded(font,"1   R U N", color, bgcl);
    score[3]=TTF_RenderText_Shaded(font,"2   R U N S", color, bgcl);
    score[2]=TTF_RenderText_Shaded(font,"3   R U N S", color, bgcl);
    score[1]=TTF_RenderText_Shaded(font," F O U R ", color, bgcl);
    score[0]=TTF_RenderText_Shaded(font," S I X ", color, bgcl);
    score[6]=TTF_RenderText_Shaded(font," O U T ", color, bgcl);
    score[7]=TTF_RenderText_Shaded(font,"TAKE A SHOT", color, bgcl);
    score[8]=TTF_RenderText_Shaded(font,"CHOOSE A PLACE", color, bgcl);
}


void screen1()
{
    SDL_Rect play;
    play.x=550;
    play.y=200;
    play.h=100;
    play.w=200;
    bool s1=1;
    while(s1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            s1=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>520&&x<740&&y>180&&y<320)
            {
                s1=0;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[1]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[0]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &play);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }
}
//
//
int screen2()
{
    SDL_Rect manual,create,men;
    men.x=620;
    men.y=50;
    men.h=50;
    men.w=100;
    manual.x=130;
    manual.y=350;
    manual.h=100;
    manual.w=300;
    create.x=900;
    create.y=350;
    create.h=100;
    create.w=300;
    while(1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>120&&x<540&&y>340&&y<460)
            {
                return 1;
            }
            else if(x>890&&x<1210&&y>340&&y<460)
            {
                return 2;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[9]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[10]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &men);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[2]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &manual);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[3]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &create);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
//
//
void mainp()
{
    int ang=0;
    int i=0;
    SDL_Rect des,quit;
    quit.x=10;
    quit.y=10;
    quit.h=30;
    quit.w=60;
    bool running=true;
    bool rotat=false;
    des.x=30;
    des.y=30;
    des.h=400;
    des.w=400;
    int framedelay=10,frametime;
    int framestart=SDL_GetTicks();
    while(running)
    {
        framestart=SDL_GetTicks();
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            running=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x,y;
            SDL_GetMouseState(&x,&y);
            if(x<70&&y<40)
            {
                running=0;
            }
            break;
        case SDL_KEYDOWN:
            if(e.key.keysym.sym==SDLK_r)
                if(rotat)
                    rotat=false;
                else
                    rotat=true;
            break;
        }



        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[2]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);
        gtexture = SDL_CreateTextureFromSurface(grenderer, circle);
        if(rotat)
            SDL_RenderCopyEx(grenderer, gtexture, NULL, &des, ang,NULL, SDL_FLIP_NONE);
        else
            SDL_RenderCopy(grenderer, gtexture, NULL, &des);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[1]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &quit);
        SDL_DestroyTexture(gtexture);


        ang=ang+15;
        if(ang>=360)
            ang-=360;
        frametime=SDL_GetTicks()-framestart;
        if(frametime<framedelay)
        {
            SDL_Delay(framedelay-frametime);
        }
        SDL_RenderPresent(grenderer);
        //SDL_Delay(100);
    }

}
//
//
vector<int> choosebat(vector <int> team,struct data stat[])
{
    SDL_Rect players[25],text;
    text.x=10;
    text.y=10;
    text.h=50;
    text.w=300;
    players[0].x=900;
    players[0].y=10;
    players[0].h=25;
    players[0].w=300;
    for(int i=1; i<25; i++)
    {
        players[i].x=900;
        players[i].y=players[i-1].y+26;
        players[i].h=25;
        players[i].w=300;
    }
    map<int,int>mp;
    int a=0;
    for(int i=0; i<11; i++)
    {
        mp[team[i]]=1;
    }
    SDL_Surface *but;

    while(a<4)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            a=5;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>895&&x<1205&&y>9&&y<661)
            {
                int p=(y-10)/26;
                if(mp[p]==0)
                {
                    team.push_back(p);
                    mp[p]=1;
                    a++;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[11]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);

        for(int i=0; i<25; i++)
        {
            if(mp[i]!=0)
                continue;
            but=TTF_RenderText_Shaded(font,stat[i].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }
    return team;

}
//
//
vector<int> choosewik(vector <int> team,struct data stat[])
{
    SDL_Rect players[5],text;
    text.x=10;
    text.y=10;
    text.h=50;
    text.w=300;
    players[0].x=900;
    players[0].y=50;
    players[0].h=25;
    players[0].w=300;
    for(int i=1; i<5; i++)
    {
        players[i].x=900;
        players[i].y=players[i-1].y+35;
        players[i].h=25;
        players[i].w=300;
    }
    map<int,int>mp;
    int a=0;
    for(int i=0; i<15; i++)
    {
        mp[team[i]]=1;
    }
    SDL_Surface *but;

    while(a==0)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            a=5;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>895&&x<1205&&y>49&&y<226)
            {
                int p=25+(y-50)/35;
                if(mp[p]==0)
                {
                    team.push_back(p);
                    mp[p]=1;
                    a++;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[12]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);

        for(int i=0; i<5; i++)
        {
            if(mp[i+25]!=0)
                continue;
            but=TTF_RenderText_Shaded(font,stat[i+25].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }
    return team;

}
//
//
vector<int> choosealr(vector <int> team,struct data stat[])
{
    SDL_Rect players[15],text;
    text.x=10;
    text.y=10;
    text.h=50;
    text.w=300;
    players[0].x=900;
    players[0].y=30;
    players[0].h=25;
    players[0].w=300;
    for(int i=1; i<15; i++)
    {
        players[i].x=900;
        players[i].y=players[i-1].y+30;
        players[i].h=25;
        players[i].w=300;
    }
    map<int,int>mp;
    int a=0;
    for(int i=0; i<16; i++)
    {
        mp[team[i]]=1;
    }
    SDL_Surface *but;

    while(a<3)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            a=5;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>895&&x<1205&&y>29&&y<481)
            {
                int p=30+(y-30)/30;
                if(mp[p]==0)
                {
                    team.push_back(p);
                    mp[p]=1;
                    a++;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[13]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);

        for(int i=0; i<15; i++)
        {
            if(mp[i+30]!=0)
                continue;
            but=TTF_RenderText_Shaded(font,stat[i+30].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }
    return team;

}
//
//
vector<int> choosebol(vector <int> team,struct data stat[])
{
    SDL_Rect players[20],text;
    text.x=10;
    text.y=10;
    text.h=50;
    text.w=300;
    players[0].x=900;
    players[0].y=30;
    players[0].h=25;
    players[0].w=300;
    for(int i=1; i<20; i++)
    {
        players[i].x=900;
        players[i].y=players[i-1].y+30;
        players[i].h=25;
        players[i].w=300;
    }
    map<int,int>mp;
    int a=0;
    for(int i=0; i<19; i++)
    {
        mp[team[i]]=1;
    }
    SDL_Surface *but;

    while(a<3)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            a=5;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>895&&x<1205&&y>29&&y<631)
            {
                int p=45+(y-30)/30;
                if(mp[p]==0)
                {
                    team.push_back(p);
                    mp[p]=1;
                    a++;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[43]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);

        for(int i=0; i<20; i++)
        {
            if(mp[i+45]!=0)
                continue;
            but=TTF_RenderText_Shaded(font,stat[i+45].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }
    return team;

}
//
//
bool s3=1;
void screen3(vector<int> team,struct data stat[])
{
    SDL_Rect you,youp[11],they,theyp[11],play;
    you.x=10;
    you.y=10;
    you.h=50;
    you.w=200;
    they.x=1000;
    they.y=10;
    they.h=50;
    they.w=200;
    youp[0].x=10;
    youp[0].y=100;
    youp[0].h=30;
    youp[0].w=300;
    play.x=585;
    play.y=340;
    play.h=100;
    play.w=200;
    int i;
    for(i=1; i<11; i++)
    {
        youp[i].x=10;
        youp[i].y=youp[i-1].y+50;
        youp[i].h=30;
        youp[i].w=300;
    }
    theyp[0].x=1000;
    theyp[0].y=100;
    theyp[0].h=30;
    theyp[0].w=300;
    SDL_Surface *but;
    for(i=1; i<11; i++)
    {
        theyp[i].x=1000;
        theyp[i].y=youp[i-1].y+50;
        theyp[i].h=30;
        theyp[i].w=300;
    }

    while(s3)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>580&&x<785&&y>335&&y<445)
            {
                s3=0;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[5]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[14]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &you);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[15]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &they);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[16]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &play);
        SDL_DestroyTexture(gtexture);

        for(int i=0; i<11; i++)
        {
            but=TTF_RenderText_Shaded(font,stat[team[i]].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &theyp[i]);
            SDL_DestroyTexture(gtexture);
        }
        for(int i=11; i<22; i++)
        {
            but=TTF_RenderText_Shaded(font,stat[team[i]].name.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &youp[i-11]);
            SDL_DestroyTexture(gtexture);
        }


        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
bool tos=1;
int toss()
{
    SDL_Rect manual,create,men;
    men.x=570;
    men.y=10;
    men.h=100;
    men.w=200;
    manual.x=130;
    manual.y=580;
    manual.h=100;
    manual.w=300;
    create.x=900;
    create.y=580;
    create.h=100;
    create.w=300;
    srand (time(NULL));
    int a=rand()%2;

    while(1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x<660)
            {
                if(a==0)
                    return 1;
                else
                    return 0;
            }
            else if(x>700)
            {
                return a;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[10]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[17]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &men);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[18]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &manual);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[19]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &create);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
int choose1()
{
    SDL_Rect manual,create,men;
    men.x=570;
    men.y=10;
    men.h=100;
    men.w=200;
    manual.x=30;
    manual.y=400;
    manual.h=100;
    manual.w=300;
    create.x=1030;
    create.y=400;
    create.h=100;
    create.w=300;
    while(1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x<660)
            {
                return 1;
            }
            else if(x>700)
            {
                return 2;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[6]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[20]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &men);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[21]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &manual);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[22]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &create);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
void choose2(int f)
{
    SDL_Rect manual,create,men;
    men.x=700;
    men.y=10;
    men.h=100;
    men.w=300;
    manual.x=1230;
    manual.y=635;
    manual.h=50;
    manual.w=100;
    create.x=700;
    create.y=560;
    create.h=100;
    create.w=400;
    bool s2=1;
    while(s2)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            s2=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>1220&&y>620)
            {
                s2=0;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[23]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &men);
        SDL_DestroyTexture(gtexture);
        if(!f)
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[24]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &create);
            SDL_DestroyTexture(gtexture);
        }
        else
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[25]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &create);
            SDL_DestroyTexture(gtexture);
        }
        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[16]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &manual);
        SDL_DestroyTexture(gtexture);
        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
void screen4()
{
    SDL_Rect play;
    play.x=500;
    play.y=5;
    play.h=100;
    play.w=300;
    SDL_RenderClear(grenderer);
    gtexture = SDL_CreateTextureFromSurface(grenderer, bg[8]);
    SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
    SDL_DestroyTexture(gtexture);

    gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[26]);
    SDL_RenderCopy(grenderer, gtexture, NULL, &play);
    SDL_DestroyTexture(gtexture);

    SDL_RenderPresent(grenderer);
    SDL_Delay(5000);
}
//
//
bool s6=1;
int levels()
{
    SDL_Rect lv,lv1,lv11,lv2,lv22,lv3,lv33,lv4,lv44,lv5,lv55;
    lv.x=620;
    lv.y=50;
    lv.h=50;
    lv.w=100;
    lv1.x=150;
    lv1.y=150;
    lv1.h=100;
    lv1.w=300;
    lv2.x=700;
    lv2.y=250;
    lv2.h=100;
    lv2.w=300;
    lv3.x=150;
    lv3.y=350;
    lv3.h=100;
    lv3.w=300;
    lv4.x=700;
    lv4.y=450;
    lv4.h=100;
    lv4.w=300;
    lv5.x=150;
    lv5.y=550;
    lv5.h=100;
    lv5.w=300;
    lv11.x=150;
    lv11.y=250;
    lv11.h=30;
    lv11.w=300;
    lv22.x=700;
    lv22.y=350;
    lv22.h=30;
    lv22.w=300;
    lv33.x=150;
    lv33.y=450;
    lv33.h=30;
    lv33.w=300;
    lv44.x=700;
    lv44.y=550;
    lv44.h=30;
    lv44.w=300;
    lv55.x=150;
    lv55.y=650;
    lv55.h=30;
    lv55.w=300;


    while(1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x>lv1.x&&x<lv1.x+lv1.w&&y>lv1.y&&y<lv11.y)
            {
                return 1;
            }
            else if(x>lv2.x&&x<lv2.x+lv2.w&&y>lv2.y&&y<lv22.y)
            {
                return 2;
            }
            else if(x>lv3.x&&x<lv3.x+lv3.w&&y>lv3.y&&y<lv33.y)
            {
                return 3;
            }
            else if(x>lv4.x&&x<lv4.x+lv4.w&&y>lv4.y&&y<lv44.y)
            {
                return 4;
            }
            else if(x>lv5.x&&x<lv5.x+lv5.w&&y>lv5.y&&y<lv55.y)
            {
                return 5;
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[3]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[27]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv1);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[29]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv2);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[31]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv3);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[33]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv4);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[35]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv5);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[28]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv11);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[30]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv22);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[32]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv33);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[34]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv44);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[36]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &lv55);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }

}
//
//
int countscore(int x, int y)
{
    srand (time(NULL));
    int a=rand()%18;
    double c=sqrt((x-288)*(x-288)+(y-288)*(y-288));
    double d=sqrt((x-0)*(x-0)+(y-288)*(y-288));
    double e=sqrt((x-288)*(x-288)+(y-0)*(y-0));
    c=acos((c*c+d*d-e*e)/(2*c*d));
    x=ceil(c/20);
    int b=rand()%18;
    x=abs(a-b);
    if(18-x<x)
        x=18-x;
    if(x<0)
        x=0;
    else
    {
        x--;
    }
    if(x>4&&x<7)
        x--;
    if(x>6)
        x=6;
    return x;
}
int batt(vector <int> team,int level,int tar)
{
    int i;
    string target,runs,wiks,bat1s,bat2s,bols,overs;
    vector<int>batteam,bolteam;
    for(i=0; i<11; i++)
    {
        bolteam.push_back(team[i]);
    }
    for(i=11; i<22; i++)
    {
        batteam.push_back(team[i]);
    }
    if(tar<0)
        target = "T A R G E T ::  NOT PLAYED";
    else
        target = "T A R G E T ::  "+to_string(tar+1);
    int run =0,over;
    if(level==1)
        over=2;
    else if(level==2)
        over=4;
    else if(level==3)
        over=5;
    else if(level==4)
        over=6;
    else if(level==5)
        over=10;
    int wicket=0,bol[11][3]= {0},bat[11]= {0},bap[11]= {0},tmp;
    bap[0]=1;
    bap[1]=1;
    int b1r=0,b2r=0,ovr=0,balls=0,bata=0,batb=1,bola=10,r;
    int ang=0;
    i=0;
    SDL_Rect des,quit,ov,rn,wk,tr,b1,b2,bo,comment,state;
    state.x=650;
    state.y=10;
    state.h=50;
    state.w=150;
    comment.x=30;
    comment.y=600;
    comment.h=75;
    comment.w=300;
    rn.x=900;
    rn.y=20;
    rn.h=50;
    rn.w=200;
    wk.x=900;
    wk.y=100;
    wk.h=50;
    wk.w=200;
    ov.x=900;
    ov.y=180;
    ov.h=50;
    ov.w=200;
    tr.x=900;
    tr.y=280;
    tr.h=40;
    tr.w=200;
    b1.x=900;
    b1.y=360;
    b1.h=50;
    b1.w=200;
    b2.x=900;
    b2.y=440;
    b2.h=50;
    b2.w=200;
    bo.x=900;
    bo.y=520;
    bo.h=30;
    bo.w=460;
    quit.x=10;
    quit.y=10;
    quit.h=30;
    quit.w=60;
    bool rotat=false;
    des.x=30;
    des.y=30;
    des.h=500;
    des.w=500;
    r=7;
    SDL_Surface *but;
    while(wicket<10&&ovr<over)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            if(x&&y)
            {
                if(x<70&&y<40)
            {
                exit(1);
            }
                if(250>sqrt((x-278)*(x-278)+(y-278)*(y-278)))
                {
                    r=countscore(x,y);
                    if(r==0)
                    {
                        run+=6;
                        bat[bata]+=6;
                        bol[bola][1]+=6;
                    }
                    else if(r==1)
                    {
                        run+=4;
                        bat[bata]+=4;
                        bol[bola][1]+=4;
                    }
                    else if(r==2)
                    {
                        run+=3;
                        bat[bata]+=3;
                        bol[bola][1]+=3;
                        swap(bata,batb);
                    }
                    else if(r==3)
                    {
                        run+=2;
                        bat[bata]+=2;
                        bol[bola][1]+=2;
                    }
                    else if(r==4)
                    {
                        run+=1;
                        bat[bata]+=1;
                        bol[bola][1]+=1;
                        swap(bata,batb);
                    }
                    else if(r==5)
                        run+=0;
                    else if(r==6)
                    {
                        wicket++;
                        b1r=0;
                        bol[bola][2]++;
                        for(int k=0; k<11; k++)
                        {
                            if(bap[k]==0)
                            {
                                bap[k]=1;
                                bata=k;
                                break;
                            }
                        }
                    }
                    balls++;
                    rotat=1;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[2]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture = SDL_CreateTextureFromSurface(grenderer, circle);
        if(rotat)
            SDL_RenderCopyEx(grenderer, gtexture, NULL, &des, ang,NULL, SDL_FLIP_NONE);
        else
            SDL_RenderCopy(grenderer, gtexture, NULL, &des);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[1]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &quit);
        SDL_DestroyTexture(gtexture);

        if(balls==6)
        {
            balls=0;
            ovr++;
            swap(bata,batb);
            tmp=rand()%7;
            if(tmp==0)
            {
                tmp=rand()%5;
            }
            else
                tmp+=4;
            if(tmp==bola)
            {
                tmp--;
            }
            bol[bola][0]++;
            bola=tmp;
        }
        runs="R U N  ::  "+to_string(run)+"  ";
        wiks="W I C K E T ::  "+to_string(wicket)+"  ";
        overs="O V E R  ::  "+to_string(ovr)+" . "+to_string(balls)+"  ";
        bat1s=database[batteam[bata]].name+"  :  "+to_string(bat[bata])+"  ";
        bat2s=database[batteam[batb]].name+"  :  "+to_string(bat[batb])+"  ";
        bols=database[bolteam[bola]].name +"  :  "+to_string(bol[bola][0])+" . "+to_string(balls)+" OVERS ::  "+to_string(bol[bola][1])+" R U N  conceeded  ::  "+to_string(bol[bola][2])+" WICKETS ";

        but=TTF_RenderText_Shaded(font,runs.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &rn);
        SDL_DestroyTexture(gtexture);


        but=TTF_RenderText_Shaded(font," BATTING ", color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &state);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,wiks.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &wk);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,target.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &tr);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bat1s.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &b1);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,overs.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &ov);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bat2s.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &b2);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bols.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &bo);
        SDL_DestroyTexture(gtexture);

        if(rotat)
        {
            ang=ang+24;
            if(ang>360)
            {
                r=7;
                rotat=0;
                ang=0;
            }
        }
        if(!rotat)
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, score[7]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &comment);
            SDL_DestroyTexture(gtexture);
        }
        else
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, score[r]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &comment);
            SDL_DestroyTexture(gtexture);
        }


        SDL_RenderPresent(grenderer);
        SDL_Delay(17);
    }

    string ss;
    while(1)
    {
        SDL_Rect players[25],text;
        text.x=10;
        text.y=10;
        text.h=50;
        text.w=450;
        players[0].x=900;
        players[0].y=10;
        players[0].h=25;
        players[0].w=300;
        for(int i=1; i<11; i++)
        {
            players[i].x=900;
            players[i].y=players[i-1].y+26;
            players[i].h=25;
            players[i].w=300;
        }
        ss=" YOU SCORED : "+to_string(run)+" RUNS   LOSING   "+to_string(wicket)+"   WICKETS ";
        for(int i=11; i<24; i++)
        {
            players[i].x=900;
            players[i].y=players[i-1].y+26;
            players[i].h=25;
            players[i].w=400;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);


        for(int i=0; i<11; i++)
        {
            ss=database[batteam[i]].name+"    "+to_string(bat[i])+"  ";
            but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }
        int k=12;
        for(int i=0; i<11; i++)
        {
            if(bol[i][0])
            {
                ss=database[bolteam[i]].name+"  "+to_string(bol[i][0])+"  "+"OVERS  "+to_string(bol[i][1])+"  "+"RUNS Conc  "+to_string(bol[i][2])+"  "+"  WICKETS";
                but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
                gtexture=SDL_CreateTextureFromSurface(grenderer, but);
                SDL_RenderCopy(grenderer, gtexture, NULL, &players[k++]);
                SDL_DestroyTexture(gtexture);
            }
        }
        SDL_RenderPresent(grenderer);
        SDL_Delay(8000);
        break;
    }
    return run;
}
//
//
int bowl(vector <int> team,int level,int tar)
{
    int i;
    string target,runs,wiks,bat1s,bat2s,bols,overs;
    vector<int>batteam,bolteam;
    for(i=11; i<22; i++)
    {
        bolteam.push_back(team[i]);
    }
    for(i=0; i<11; i++)
    {
        batteam.push_back(team[i]);
    }
    if(tar<0)
        target = "T A R G E T ::  NOT PLAYED";
    else
        target = "T A R G E T ::  "+to_string(tar+1);
    int run =0,over;
    if(level==1)
        over=2;
    else if(level==2)
        over=4;
    else if(level==3)
        over=5;
    else if(level==4)
        over=6;
    else if(level==5)
        over=10;
    int wicket=0,bol[11][3]= {0},bat[11]= {0},bap[11]= {0},tmp;
    bap[0]=1;
    bap[1]=1;
    int b1r=0,b2r=0,ovr=0,balls=0,bata=0,batb=1,bola=10,r;
    int ang=0;
    i=0;
    SDL_Rect des,quit,ov,rn,wk,tr,b1,b2,bo,comment,state;
    comment.x=30;
    comment.y=600;
    comment.h=75;
    comment.w=300;
    state.x=650;
    state.y=10;
    state.h=50;
    state.w=150;
    rn.x=900;
    rn.y=20;
    rn.h=50;
    rn.w=200;
    wk.x=900;
    wk.y=100;
    wk.h=50;
    wk.w=200;
    ov.x=900;
    ov.y=180;
    ov.h=50;
    ov.w=200;
    tr.x=900;
    tr.y=280;
    tr.h=40;
    tr.w=200;
    b1.x=900;
    b1.y=360;
    b1.h=50;
    b1.w=200;
    b2.x=900;
    b2.y=440;
    b2.h=50;
    b2.w=200;
    bo.x=900;
    bo.y=520;
    bo.h=30;
    bo.w=460;
    quit.x=10;
    quit.y=10;
    quit.h=30;
    quit.w=60;
    bool rotat=false;
    des.x=30;
    des.y=30;
    des.h=500;
    des.w=500;
    r=7;
    SDL_Surface *but;
    while(wicket<10&&ovr<over)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            if(x&&y)
            {
                if(x<70&&y<40)
            {
                exit(1);
            }
                if(250>sqrt((x-278)*(x-278)+(y-278)*(y-278)))
                {

                    r=countscore(x,y);
                    if(r==0)
                    {
                        run+=6;
                        bat[bata]+=6;
                        bol[bola][1]+=6;
                    }
                    else if(r==1)
                    {
                        run+=4;
                        bat[bata]+=4;
                        bol[bola][1]+=4;
                    }
                    else if(r==2)
                    {
                        run+=3;
                        bat[bata]+=3;
                        bol[bola][1]+=3;
                        swap(bata,batb);
                    }
                    else if(r==3)
                    {
                        run+=2;
                        bat[bata]+=2;
                        bol[bola][1]+=2;
                    }
                    else if(r==4)
                    {
                        run+=1;
                        bat[bata]+=1;
                        bol[bola][1]+=1;
                        swap(bata,batb);
                    }
                    else if(r==5)
                        run+=0;
                    else if(r==6)
                    {
                        wicket++;
                        b1r=0;
                        bol[bola][2]++;
                        for(int k=0; k<11; k++)
                        {
                            if(bap[k]==0)
                            {
                                bap[k]=1;
                                bata=k;
                                break;
                            }
                        }
                    }
                    balls++;
                    rotat=1;
                }
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[2]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        gtexture = SDL_CreateTextureFromSurface(grenderer, circle);
        if(rotat)
            SDL_RenderCopyEx(grenderer, gtexture, NULL, &des, ang,NULL, SDL_FLIP_NONE);
        else
            SDL_RenderCopy(grenderer, gtexture, NULL, &des);
        SDL_DestroyTexture(gtexture);

        gtexture=SDL_CreateTextureFromSurface(grenderer, buttons[1]);
        SDL_RenderCopy(grenderer, gtexture, NULL, &quit);
        SDL_DestroyTexture(gtexture);

        if(balls==6)
        {
            balls=0;
            ovr++;
            swap(bata,batb);
            tmp=rand()%7;
            if(tmp==0)
            {
                tmp=rand()%5;
            }
            else
                tmp+=4;
            if(tmp==bola)
            {
                tmp--;
            }
            bol[bola][0]++;
            bola=tmp;
        }
        runs="R U N  ::  "+to_string(run)+"  ";
        wiks="W I C K E T ::  "+to_string(wicket)+"  ";
        overs="O V E R  ::  "+to_string(ovr)+" . "+to_string(balls)+"  ";
        bat1s=database[batteam[bata]].name+"  :  "+to_string(bat[bata])+"  ";
        bat2s=database[batteam[batb]].name+"  :  "+to_string(bat[batb])+"  ";
        bols=database[bolteam[bola]].name +"  :  "+to_string(bol[bola][0])+" . "+to_string(balls)+" OVERS ::  "+to_string(bol[bola][1])+" R U N  conceeded  ::  "+to_string(bol[bola][2])+" WICKETS ";

        but=TTF_RenderText_Shaded(font,runs.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &rn);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font," BOWLING ", color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &state);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,wiks.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &wk);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,target.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &tr);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bat1s.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &b1);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,overs.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &ov);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bat2s.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &b2);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,bols.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &bo);
        SDL_DestroyTexture(gtexture);

        if(rotat)
        {
            ang=ang+24;
            if(ang>360)
            {
                r=8;
                rotat=0;
                ang=0;
            }
        }
        if(!rotat)
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, score[8]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &comment);
            SDL_DestroyTexture(gtexture);
        }
        else
        {
            gtexture=SDL_CreateTextureFromSurface(grenderer, score[r]);
            SDL_RenderCopy(grenderer, gtexture, NULL, &comment);
            SDL_DestroyTexture(gtexture);
        }


        SDL_RenderPresent(grenderer);
        SDL_Delay(17);
    }
    string ss;
    while(1)
    {
        SDL_Rect players[25],text;
        text.x=10;
        text.y=10;
        text.h=50;
        text.w=450;
        players[0].x=900;
        players[0].y=10;
        players[0].h=25;
        players[0].w=300;
        for(int i=1; i<11; i++)
        {
            players[i].x=900;
            players[i].y=players[i-1].y+26;
            players[i].h=25;
            players[i].w=300;
        }
        ss=" YOUR OPPONENT SCORED : "+to_string(run)+" RUNS   LOSING   "+to_string(wicket)+"   WICKETS ";
        for(int i=11; i<24; i++)
        {
            players[i].x=900;
            players[i].y=players[i-1].y+26;
            players[i].h=25;
            players[i].w=400;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[4]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
        gtexture=SDL_CreateTextureFromSurface(grenderer, but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &text);
        SDL_DestroyTexture(gtexture);


        for(int i=0; i<11; i++)
        {
            ss=database[batteam[i]].name+"    "+to_string(bat[i])+"  ";
            but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
            gtexture=SDL_CreateTextureFromSurface(grenderer, but);
            SDL_RenderCopy(grenderer, gtexture, NULL, &players[i]);
            SDL_DestroyTexture(gtexture);
        }
        int k=12;
        for(int i=0; i<11; i++)
        {
            if(bol[i][0])
            {
                ss=database[bolteam[i]].name+"  "+to_string(bol[i][0])+"  "+"OVERS  "+to_string(bol[i][1])+"  "+"RUNS Conc  "+to_string(bol[i][2])+"  "+"  WICKETS";
                but=TTF_RenderText_Shaded(font,ss.c_str(), color2, bgcl);
                gtexture=SDL_CreateTextureFromSurface(grenderer, but);
                SDL_RenderCopy(grenderer, gtexture, NULL, &players[k++]);
                SDL_DestroyTexture(gtexture);
            }
        }
        SDL_RenderPresent(grenderer);
        SDL_Delay(8000);
        break;
    }

    return run;
}
//
//
void finall(string s)
{


    SDL_Rect play;
    play.x=550;
    play.y=450;
    play.h=150;
    play.w=250;
    bool s1=1;
    SDL_Surface *but;
    while(s1)
    {
        SDL_PollEvent(&e);
        switch(e.type)
        {
        case SDL_QUIT:
            s1=false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            int x=0,y=0;
            SDL_GetMouseState(&x,&y);
            //std::cout<<x<<','<<y<<'\n';
            if(x&&y)
            {
                exit(1);
            }
            break;
        }
        SDL_RenderClear(grenderer);
        gtexture = SDL_CreateTextureFromSurface(grenderer, bg[11]);
        SDL_RenderCopy(grenderer, gtexture, NULL, NULL);
        SDL_DestroyTexture(gtexture);

        but=TTF_RenderText_Solid(font,s.c_str(), color2);
        gtexture=SDL_CreateTextureFromSurface(grenderer,but);
        SDL_RenderCopy(grenderer, gtexture, NULL, &play);
        SDL_DestroyTexture(gtexture);

        SDL_RenderPresent(grenderer);
        SDL_Delay(17);

    }


}
