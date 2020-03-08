//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include<iostream>
#include<fstream>
using namespace std;

int l,t[7][8],g[7][8],ans[7][8];
   ifstream fin("problemf.in");
   ofstream fout("output.txt");

void moven(int x,int y,int z)
{
  g[x][y]=(g[x][y]+z)%2;
  g[x-1][y]=(g[x-1][y]+z)%2;
  g[x+1][y]=(g[x+1][y]+z)%2;
  g[x][y-1]=(g[x][y-1]+z)%2;
  g[x][y+1]=(g[x][y+1]+z)%2;
}

void overcome(void)
{
  int a[7];
  int i,j,k;
  bool b;
//  void moven(int,int,int);
  k=1;
  a[k]=-1;
  while(k>0)
    {
      a[k]++;
      if (a[k]>1)
        k--; else
        {
          if (k<6)
          {
            k++;
            a[k]=-1;
          } else
          {
            for(i=1;i<=5;i++)
              for(j=1;j<=6;j++)
                g[i][j]=t[i][j];
            for(i=1;i<=6;i++)
              moven(1,i,a[i]);
            for(i=2;i<=5;i++)
              for(j=1;j<=6;j++)
              {
                ans[i][j]=g[i-1][j];
                moven(i,j,g[i-1][j]);
              }
            b=true;
            for(i=1;i<=6;i++)
              if (g[5][i]==1)
              {
                b=false;
                break;
              }
            if (b)
            {
              fout << "PUZZLE #" << l << endl;
              for(i=1;i<=6;i++)
                fout << a[i] << ' ';
              fout << endl;
              for(i=2;i<=5;i++)
              {
                for(j=1;j<=6;j++)
                 fout << ans[i][j] << ' ';
                fout << endl;
              }
              return;
            }
          }
       }
    }
}
int main(int argc, char* argv[])
{
   void overcome(void);
   int n,i,j;
   fin >> n;
   for(l=1;l<=n;l++)
   {
     for(i=1;i<=5;i++)
       for(j=1;j<=6;j++)
         fin >> t[i][j];
     overcome();
   }
   return 0;
}



//---------------------------------------------------------------------------
