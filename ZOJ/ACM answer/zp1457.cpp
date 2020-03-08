//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream>

#include <fstream>
#include <time.h>

using namespace std;

ifstream fin("zp1457.in");
ofstream fout("zp1457.out");


int n,d,p[22],r[22],a[42],w[22][10];
void dfs(int d,int t)
{
  int i,j;
  if (d<n)
  {
    for (i=1;i<=w[t][0];i++)
    {
      j=w[t][i];
      if (j<=n && p[j])
      {
        p[j]=0;
        r[d]=j;
        dfs(d+1,j);
        p[j]=1;
      }
    }
  }
  else
  if (a[t+1])
  {
    //fout<<"    cout<<\"";
   printf("%d",1);
   for(i=1;i<n;i++)
      printf(" %d",r[i]);
   printf("\n");
  }
}
int main(int argc, char* argv[])
{
	//clock_t __start__ = clock();

  int i,j,s,cs;
  a[1]=0;a[2]=1;a[3]=1;a[4]=0;a[5]=1;a[6]=0;a[7]=1;
  for (i=8;i<36;i++)
    a[i]=(i%2&&i%3&&i%5&&i%7 );
  for (i=2;i<19;i++)
  {
    s=0;
    j=3-i%2;
    while (j<19)
    {
      if (a[j+i])
        w[i][++s]=j;
      j++;
    }
    w[i][0]=s;
  }
  	//cout<<"time:"<< ((double)clock()-__start__) / CLOCKS_PER_SEC <<endl;

  cs=0;
  while (cin>>n)
  {
    printf("Case %d:\n",++cs);
    //fout<<"Case "<<++cs<<':'<<endl;
    //fout<<"  case "<<n<<" :{"<<endl;
    if (n%2==0)
    {
      for (i=2;i<=n;i++)
        p[i]=1;

      for (i=2;i<=n;i++)
        if (a[i+1])
        {
          p[i]=0;
          r[1]=i;
          dfs(2,i);
          p[i]=1;
        }
    //fout<<"   }\n   break;";
    }
    printf("\n");
  }

  	//cout<<"time:"<< ((double)clock()-__start__) / CLOCKS_PER_SEC <<endl;
  return 0;
}
//---------------------------------------------------------------------------
