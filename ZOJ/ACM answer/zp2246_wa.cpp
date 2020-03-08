//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

int main(int argc, char* argv[])
{
  int n,i,j,k,c,s,max,min,sum,t[21],p[21],v[21],r[21][21];
  cin>>n;
  while (n)
  {
    s=0;
    for (i=0;i<n;i++)
    { cin>>v[i]; s+=v[i]; }

    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
      { cin>>r[i][j]; s+=r[i][j]; }

    max=0;
    for (k=0;k<n;k++)
    {
      sum=v[k];
      if (sum>420) continue;
      for (i=0;i<n;i++)
        p[i]=1;
      p[k]=0;
      c=k;
      for (j=1;j<n;j++)
      {
        for (i=0;i<n;i++)
          if (p[i])
            t[i]=r[c][i]+v[i];
        min=s;
        for (i=0;i<n;i++)
          if (p[i] && t[i]<min)
          { min=t[i]; c=i; }
        p[c]=0;
        sum+=min;
        if (sum>420) break;
      }
      if (j>max) max=j;
      if (max==n) break;
    }
    cout<<max<<endl;
    cin>>n;
  }

  return 0;
}
//---------------------------------------------------------------------------
