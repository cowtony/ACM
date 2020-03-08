//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma argsused
//#define cout fout
//#include <fstream.h>
#include <stdio.h>
#include <iostream.h>
#include <iomanip.h>
#include <string.h>

//ofstream fout("output.txt");

const int mm=20000;
const int dx[7]={1,1,2,0,0,0,-1};
const int dy[7]={0,-1,-1,1,0,-1,2};
const double dz[7]={3.0/16,2.0/16,1.0/16,2.0/16,6.0/16,1.0/16,1.0/16};

struct node
{
  int x,y;
  double z;
};

node p[mm],q[mm];
int o,i,j,k,m,n,r,t;
bool b1,b2,b3;
double win,lost,tie;

int main(int argc, char* argv[])
{
   cout<<"Round   A wins    B wins    Tie\n";
   cout<<setiosflags(ios::fixed)<<setprecision(4);
   r=1;
   p[0].x=0;
   p[0].y=0;
   p[0].z=100;
   t=0;
   for (o=1;o<21;o++)
   {
     for (i=0;i<r;i++)
     {
       for (j=0;j<7;j++)
       {
         m=p[i].x+dx[j];
         n=p[i].y+dy[j];
         b1=true;
         for (k=0;k<t;k++)
           if (q[k].x==m && q[k].y==n)
           {
             b1=false;
             q[k].z+=p[i].z*dz[j];
             break;
           }
         if (b1)
         {
           q[t].x=m;
           q[t].y=n;
           q[t].z=p[i].z*dz[j];
           t++;
         }
       }
     }
     win=0;
     lost=0;
     tie=0;
     for (i=0;i<t;i++)
       if (q[i].x>q[i].y) win+=q[i].z;
       else if (q[i].x<q[i].y) lost+=q[i].z;
       else tie+=q[i].z;
     cout<<setw(5)<<o<<setw(10)<<win<<"%"
         <<setw(9)<<lost<<"%"<<setw(9)<<tie<<"%"<<endl;
     memcpy(p,q,sizeof(node)*mm);
     r=t; t=0;
   }
   return 0;
}
//---------------------------------------------------------------------------
