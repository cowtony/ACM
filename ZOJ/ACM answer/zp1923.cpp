//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
  int w[8]={9,8,6,4,2,3,5,7};
  char st[1010];
  int ln,i,j,s,t,k,a[1010],b[1010],r[1010];
  scanf("%s",st);
  while (st[0]!='-')
  {
    ln=strlen(st);
    if (ln==1)
    {
      printf("1%d\n",st[0]-'0');
      scanf("%s",st);
      continue;
    }
    for (i=0;i<ln;i++)
      a[i]=st[i]-'0';

    s=0;
    for (i=0;i<8;i++)
    {
      while (1)
      {
        t=1;
        for (j=0;j<ln;j++)
          b[j]=a[j];
        for (j=0;j<ln-1;j++)
        {
          b[j+1]+=b[j]%w[i]*10;
          b[j]/=w[i];
        }
        if (b[j]%w[i]==0)
        {
          r[s++]=w[i];
          t=0;
          for (j=0;j<ln;j++)
          {
            a[j+1]+=a[j]%w[i]*10;
            a[j]/=w[i];
          }
          k=0;
          while (a[k]==0)
            k++;
          for (j=k;j<ln;j++)
            a[j-k]=a[j];
          ln-=k;
          if (ln==1)
          {
            r[s++]=a[0];
            ln--;
            break;
          }
        }
        if (t)
          break;
      }
      if (ln==0)
        break;
    }
    if (ln)
    {
      printf("There is no such number.\n");
      scanf("%s",st);
      continue;
    }

    for (i=0;i<s-1;i++)
      for (j=i+1;j<s;j++)
        if (r[i]>r[j])
        {
          t=r[i];
          r[i]=r[j];
          r[j]=t;
        }
    if (s)
      for (i=0;i<s;i++)
        printf("%d",r[i]);
    else
      printf("There is no such number.");
    printf("\n");
    scanf("%s",st);
  }
  return 0;
}
//---------------------------------------------------------------------------
