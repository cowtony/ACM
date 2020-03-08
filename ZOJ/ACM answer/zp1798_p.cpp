#include <string.h>
#include <iostream.h>
int a[11][11],b[11][11],u[11];
int n,m,i,j,k,t;
char c;

void search(int p,int dp)
{
   if (dp>=n && b[p][0])
   {
     k=1;
     return;
   }
   int s;
   for (s=1;s<=a[p][0];s++)
     if (u[a[p][s]]==0)
     {
       u[a[p][s]]=1;
       search(a[p][s],dp+1);
       u[a[p][s]]=0;
     }
   return;
}

int main()
{
  cin>>n;

  t=0;
  while (n)
  {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(u,0,sizeof(u));
    c=getchar();
    for (i=1;i<=n;i++)
    {
      cin>>k;
      c=getchar();
      while (c!='\n')
      {
        b[i][k]=1;
        b[k][i]=1;
        cin>>k;
        c=getchar();
      }
      b[i][k]=1;
      b[k][i]=1;
    }
    for (i=0;i<=n;i++)
      for (j=0;j<=n;j++)
        if (b[i][j])
        {
          a[i][0]++;
          a[i][a[i][0]]=j;
        }

    k=0;
    u[0]=1;
    search(0,0);

    cout<<"Case "<<++t<<": Granny can ";
    if (k==0)
      cout<<"not ";
    cout<<"make the circuit.\n";

    cin>>n;

  }
  return 0;
}
//-----------------------------------------------------------------------

