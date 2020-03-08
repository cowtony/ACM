//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int N,I,n,m,i,j,k,l,t,cs,p[26][26],r[26][26],q[26][26],v[26][26];
  char st[5];
  cs=0;
  scanf("%d",&N);
  m=26;
  for (I=0;I<N;I++)
  {
    scanf("%d",&n);
    for (i=0;i<m;i++)
      for (j=0;j<m;j++)
        p[i][j]=0;
    m=0;
    for (i=0;i<n;i++)
    {
      scanf("%s",st);
      if (st[1]=='<')
        p[st[0]-'A'][st[2]-'A']=1;
      else
        p[st[2]-'A'][st[0]-'A']=1;
      if (st[0]-'A'>m)
        m=st[0]-'A';
      if (st[2]-'A'>m)
        m=st[2]-'A';
    }
    m++;

    //printf("%d\n",m);
    for (i=0;i<m;i++)
      for (j=0;j<m;j++)
      {
        r[i][j]=p[i][j];
        v[i][j]=p[i][j];
      }


    for (k=1;k<m;k++)
    {
      for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
          q[i][j]=0;
          for (l=0;l<m;l++)
            q[i][j]+=p[i][l]*r[l][j];
        }
      for (i=0;i<m;i++)
        for (j=0;j<m;j++)
        {
          v[i][j]+=q[i][j];
          p[i][j]=q[i][j];
        }
    }
    printf("Case %d:\n",++cs);

    t=1;
    for (i=0;i<m;i++)
      for (j=0;j<m;j++)
        if (r[i][j]==0 && v[i][j]>0)
        {
          printf("%c<%c\n",i+'A',j+'A');
          t=0;
        }
    if (t)
      printf("NONE\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
