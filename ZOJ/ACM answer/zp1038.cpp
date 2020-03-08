#include <stdio.h>
#include <string.h>

struct chrtp
{
  int dt;
  struct chrtp* pt[26];
};

int ln,k,f;
char st[110];

void addtotree(int m,struct chrtp* cur)
{
  if (m<ln)
  {
    int i,t=st[m]-'a';
    if (cur->pt[t]==NULL)
    {
      cur->pt[t]=new(struct chrtp);
      for (i=0;i<26;i++)
        cur->pt[t]->pt[i]=NULL;
      cur->pt[t]->dt=k;
    }
    else
      cur->pt[t]->dt+=k;
    addtotree(m+1,cur->pt[t]);
  }
}
char smx[110],sm[110];
int r,
    loc[8]={0,3,6,9,12,15,19,22},
    col[8]={3,3,3,3,3,4,3,4};

void scantree(int m,int n,int d,struct chrtp* cur)
{
  if (m)
  {
    int i,t=st[n-m]-'2';
    for (i=loc[t];i<loc[t]+col[t];i++)
      if (cur->pt[i]!=NULL)
      {
        sm[n-m]=i+'a';
        scantree(m-1,n,cur->pt[i]->dt,cur->pt[i]);
      }
  }
  else
    if (d>r)
    {
      int i;
      for (i=0;i<n;i++)
        smx[i]=sm[i];
      smx[i]='\0';
      r=d;
    }
}

int main(int argc, char* argv[])
{
  struct chrtp* root;
  int N,I,n,i,j;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    printf("Scenario #%d:\n",I+1);

    root=new(struct chrtp);
    for (i=0;i<26;i++)
      root->pt[i]=NULL;

    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
      scanf("%s%d",st,&k);
      ln=strlen(st);
      addtotree(0,root);
    }

    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
      scanf("%s",st);
      ln=strlen(st);
      for (j=1;j<ln;j++)
      {
        r=-1;
        scantree(j,j,-1,root);
        if (r==-1)
          printf("MANUALLY\n");
        else
          printf("%s\n",smx);
      }
      printf("\n");
    }

    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
