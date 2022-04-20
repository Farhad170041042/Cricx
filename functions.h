#include<bits/stdc++.h>
using namespace std;
vector<int> defaultteam()
{
    vector<int>v;
    srand (time(NULL));
    map<int, int>mp;
    for(int j=0; j<4; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=25;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    int f=1;
    while(f)
    {
        int i=rand();
        i%=5;
        i+=25;
        if(mp[i]==0)
        {
            v.push_back(i);
            mp[i]=1;
            f=0;
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=15;
            i+=30;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=20;
            i+=45;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }

    for(int j=0; j<4; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=25;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    f=1;
    while(f)
    {
        int i=rand();
        i%=5;
        i+=25;
        if(mp[i]==0)
        {
            v.push_back(i);
            mp[i]=1;
            f=0;
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=15;
            i+=30;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=20;
            i+=45;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    return v;

}

//new function
vector<int> createteam()
{
    vector<int>v;
    map<int, int>mp;
    srand(time(NULL));
    for(int j=0; j<4; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=25;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    int f=1;
    while(f)
    {
        int i=rand();
        i%=5;
        i+=25;
        if(mp[i]==0)
        {
            v.push_back(i);
            mp[i]=1;
            f=0;
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=15;
            i+=30;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    for(int j=0; j<3; j++)
    {
        int f=1;
        while(f)
        {
            int i=rand();
            i%=20;
            i+=45;
            if(mp[i]==0)
            {
                v.push_back(i);
                mp[i]=1;
                f=0;
            }
        }
    }
    return v;

}
