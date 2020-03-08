//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char ch;
int card[4][52];
int i,j,k,n,m,o,p,q;
int main(int argc, char* argv[])
{
        char s1[500],cc,s2[500];
        do
        {
          cin>>ch;
          if (ch!='#')
          {
            cin.getline(s1,500);
            cin.getline(s1,500);
            cin.getline(s2,500);
            memset(card,0,sizeof(int)*4*52);
            switch(ch)
            {
              case 'N':o=3;break;
              case 'E':o=0;break;
              case 'S':o=1;break;
              case 'W':o=2;break;
            }
            strcat(s1,s2);
            
            k=strlen(s1);
            for (i=0;i<k;i++)
            {
              switch (s1[i++])
              {
                case 'C':p=0;break;
                case 'D':p=1;break;
                case 'S':p=2;break;
                case 'H':p=3;break;
              }
              if (s1[i]>='2' && s1[i]<='9') q=s1[i]-50;
              else
              switch (s1[i])
              {
                case 'T':q=8;break;
                case 'J':q=9;break;
                case 'Q':q=10;break;
                case 'K':q=11;break;
                case 'A':q=12;break;
              }
              j=p*13+q;
              card[o][j]++;
              o++;
              if (o>3) o-=4;
            }
            for (i=0;i<4;i++)
            {
              switch (i)
              {
                case 0:cout<<"South";break;
                case 1:cout<<"West";break;
                case 2:cout<<"North";break;
                case 3:cout<<"East";break;
              }
              cout<<" player:\n";
              cout<<"+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
              cout<<"|";
              for (j=0;j<52;j++)
              if (card[i][j]>0)
              {
                if (j % 13<8) cc=(j%13)+50;
                else
                switch (j%13)
                {
                  case 8:cc='T';break;
                  case 9:cc='J';break;
                  case 10:cc='Q';break;
                  case 11:cc='K';break;
                  case 12:cc='A';break;
                }
                cout<<cc<<' '<<cc<<'|';
              }
              cout<<endl;
              cout<<'|';
              for (j=0;j<52;j++)
              if (card[i][j]>0)
              {
                switch (int(j/13))
                {
                  case 0:cc='C';break;
                  case 1:cc='D';break;
                  case 2:cc='S';break;
                  case 3:cc='H';break;
                }
                cout<<' '<<cc<<" |";
              }
              cout<<endl;
              cout<<"|";
              for (j=0;j<52;j++)
              if (card[i][j]>0)
              {
                if (j % 13<8) cc=(j%13)+50;
                else
                switch (j%13)
                {
                  case 8:cc='T';break;
                  case 9:cc='J';break;
                  case 10:cc='Q';break;
                  case 11:cc='K';break;
                  case 12:cc='A';break;
                }
                cout<<cc<<' '<<cc<<'|';
              }
              cout<<endl;
              cout<<"+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
            }
          }
          cout<<endl;
        }while(ch!='#');
        return 0;
}
//---------------------------------------------------------------------------
 