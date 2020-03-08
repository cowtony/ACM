#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> row(50,0);

int main(void) 
{
 int i;
    for(;;) 
 {
        int dataNum;
        cin>>dataNum;     
        if(dataNum==0) 
  {
            break;
        }       
        vector<vector<int> > box(50,row);
        vector<int>&worm=box[24];
        for(i=10;i<30;++i) 
  {
            worm[i]=2;
        }   
        int headX=24,headY=29;
        int tailX=24,tailY=10;
        string str;
        cin>>str;    
        dataNum=str.length();

        for(i=1;i<=dataNum;++i) 
  {
            int direct=box[tailX][tailY];
            box[tailX][tailY]=0;
            switch(direct) 
   {
   case 1:--tailX;break;
   case 2:++tailY;break;
   case 3:++tailX;break;
   case 4:--tailY;break;
            } 
            switch(str[i-1]) 
   {
   case'N':
    box[headX][headY]=1;
    if(--headX<0) 
    {
     cout<<"The worm ran off the board on move "<<i<< "." <<endl;
     goto ENDINPUT;
    }   
    if(box[headX][headY]!=0) 
    {
     cout<<"The worm ran into itself on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }         
    box[headX][headY]=1;
    break;  
   case'E':
    box[headX][headY]=2;
    if(++headY>49) 
    {
     cout<<"The worm ran off the board on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }           
    if(box[headX][headY]!=0) 
    {
     cout<<"The worm ran into itself on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }            
    box[headX][headY]=2;
    break;        
   case'S':
    box[headX][headY]=3;
    if(++headX>49) 
    {
     cout<<"The worm ran off the board on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }  
    if(box[headX][headY]!=0) 
    {
     cout<<"The worm ran into itself on move "<<i<<"." <<endl;
     goto ENDINPUT;
    }
    box[headX][headY]=3;
    break;
   case'W':
    box[headX][headY]=4;
    if(--headY<0) 
    {
     cout<<"The worm ran off the board on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }                  
    if(box[headX][headY]!=0) 
    {
     cout<<"The worm ran into itself on move "<<i<<"."<<endl;
     goto ENDINPUT;
    }                  
    box[headX][headY]=4;
    break;
            }
        }
        cout<<"The worm successfully made all "<<dataNum<<" moves."<<endl;
ENDINPUT:;
    }
    return 0;
}
