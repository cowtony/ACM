//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <iostream.h>

struct typec
{
  int num,pas[21];
};

typec a[21][21][21];
int main(int argc, char* argv[])
{
  int n,i,j,k,l,q,t,s,p[21],v[21],r[21][21];
  cin>>n;
  while (n)
  {
    q=0;
    for (i=0;i<n;i++)
    {
      cin>>v[i];
      if (v[i]>420) p[i]=0; else p[i]=1;
      q+=p[i];
    }
    for (i=0;i<n;i++)
      for (j=0;j<n;j++)
        cin>>r[i][j];

    if (q<2)
    {
      cout<<q<<endl;
      cin>>n;
      continue;
    }

    for (k=0;k<n-1;k++)
      for (i=0;i<n;i++)
        for (j=0;j<n;j++)
          a[k][i][j].num=0;

    for (i=0;i<n;i++)
      if (p[i])
      for (j=0;j<n;j++)
        if (i!=j && p[j])
          a[0][i][j].num=r[i][j]+v[i]+v[j];

    for (k=0;k<n-1;k++)
    {
      q=0;
      for (i=0;i<n;i++)
        if (p[i])
        for (j=0;j<n;j++)
          if (i!=j && p[j])
            if (a[k][i][j].num<=420)
              q=1;

      if (q==0) break;
      if (k==n-2)
      { k++; break; }

      for (i=0;i<n;i++)
        if (p[i])
        for (j=0;j<n;j++)
          if (i!=j && p[j] && a[k][i][j].num<=420)
          {
            for (l=0;l<n;l++)
              if (l!=i && l!=j && p[l])
              {
                for (q=0;q<k;q++)
                  if (l==a[k][i][j].pas[q]) break;
                if (q==k)
                  if (a[k+1][i][l].num==0
                   || a[k+1][i][l].num>=a[k][i][j].num+v[l]+r[j][l])
                  {
                    if (a[k+1][i][l].num!=0
                    && a[k+1][i][l].num==a[k][i][j].num+v[l]+r[j][l])
                    {
                      s=v[j];
                      for (t=0;t<k;t++)
                      {
                        s+=v[a[k+1][i][l].pas[t]];
                        s-=v[a[k][i][j].pas[t]];
                      }
                      s-=v[l];
                      if (s<=0) continue;
                    }
                    a[k+1][i][l].num=a[k][i][j].num+v[l]+r[j][l];
                    a[k+1][i][l].pas[k]=j;
                  }
              }
          }
    }
    cout<<k+1<<endl;
    cin>>n;
  }

  return 0;
}
//---------------------------------------------------------------------------
