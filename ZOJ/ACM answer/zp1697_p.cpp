//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

#include <iostream.h>
#include <string.h>
#include <fstream.h>

ifstream fin("triangle.in");
ofstream fout("output.txt");

int a[6][3],v[6],i,j,k,t,n[6],w,m;
bool b[6];
char ch;

void rotate(int *x)
{
  int w;
  w=x[0];
  x[0]=x[1];
  x[1]=x[2];
  x[2]=w;
}

void test(int x)
{
   int i,j,k;
   if (x==6)
   {
     if (a[v[5]][1]==a[0][2])
     {
       j=0;
       for (i=0;i<6;i++) j+=a[v[i]][0];
       if (j>t) t=j;
     }
   }
   else
   if (x==0)
   {
      n[0]--;
      v[0]=0;
      for (i=0;i<3;i++)
      {
         rotate(&a[0][0]);
         test(1);
      }
      n[0]++;
   }
   else
   for (k=1;k<6;k++)
   if (b[k])
   {
      b[k]=false;
      v[x]=k;
      for (i=0;i<3;i++)
      {
         j=a[k][0];
         a[k][0]=a[k][1];
         a[k][1]=a[k][2];
         a[k][2]=j;
         if (a[v[x-1]][1]==a[k][2]) test(x+1);
      }
      b[k]=true;
   }
}

int main(int argc, char* argv[])
{
   bool tb;
   do
   {
       memset(n,0,sizeof(int)*6);
       for (i=0;i<6;i++)
       {
         fin>>a[i][0]>>a[i][1]>>a[i][2];
         tb=true;
         for (j=0;tb && j<i;j++)
         {
            for (k=0;tb && k<3;k++)
            {
               rotate(&a[j][0]);
               if (a[i][0]==a[j][0] && a[i][1]==a[j][1] && a[i][2]==a[j][2])
               {
                   tb=false;
                   n[j]++;
               }
            }
         }
         if (tb) n[i]=1;
       }
       t=0;
       memset(b,true,sizeof(bool)*6);
       test(0);
       if (t>0) fout<<t<<endl; else fout<<"none\n";
       fin>>ch;
   } while (ch!='$');
   fin.close();
   fout.close();
   return 0;
}
//---------------------------------------------------------------------------
