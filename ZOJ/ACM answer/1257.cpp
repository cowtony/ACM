//104482 2003-04-02 12:52:26 Accepted 1257 C++ 00:00.00 444K Century Ghost 
#include<iostream>
#include<string>
#include<queue>

using namespace std;
int way[21],belong[21];

int main()
{
    queue<int>input;   
    memset(way,0,sizeof(way));
    memset(belong,0,sizeof(belong));
    int temp;
    while(cin>>temp)
    {
        if(temp==99)    break;
        way[temp]=temp;
        input.push(temp);
    }
    while(cin>>temp)
    {
      
        int tt=temp;
        int has_put=0;
        int advan=0;
        while(1)
        {
                if(way[tt]&&!has_put)
                {                                                         
                             belong[way[tt]]=temp;
                             way[tt]=0;
                             advan=temp-tt;
                             if(advan<0)   advan+=20;
                             has_put=1;
                 } 
                 if(way[tt]&&has_put&&advan!=0)
                 {

                              int nexttt=tt+advan;
                              if(nexttt>20)     nexttt-=20;

                              way[nexttt]=way[tt];                               
                              way[tt]=0;
                 }
                 tt--;
                 if(tt==0)     tt=20;
                 if(tt==temp)  break;
         }
     }
     while(!input.empty())
     {
          cout<<"Original position "<<input.front();
          if(belong[input.front()])
                    cout<<" parked in "<<belong[input.front()]<<endl;
          else                    cout<<" did not park"<<endl;
          input.pop();
      }
     
      
      return 0;
  }    
    
