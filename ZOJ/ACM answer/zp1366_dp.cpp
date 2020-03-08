//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>
#include <string.h>
int b[100010],p[100010],w[100010];
int main(int argc, char* argv[])
{

  int c,n,i,j,k;
  int a[12],d[12];
  while(cin>>c)
  {
    cin>>n;
    for (i=0;i<n;i++)
      cin>>a[i]>>d[i];
    memset(b,0,sizeof(int)*100010);
    b[0]=1;
    for (k=0;k<n;k++)
    {
      memset(p,0,sizeof(int)*100010);
      for (i=0;i<c;i++)
        if (b[i])
          for (j=0;j<=a[k];j++)
            if (i+j*d[k]<=c)
              p[i+j*d[k]]=1;
      memcpy(b,p,sizeof(int)*(c+1));
    }
    for (i=c;i>0;i--)
      if (b[i])
        break;
    cout<<i<<endl;
  }
  return 0;
}
//---------------------------------------------------------------------------
 