#include <stdio.h>
#include <string.h>

int ln,a[1000],b[1000],c[1000];

bool div(int d)
{
  int i;
  for (i=1;i<ln;i++)
    c[i]=a[i];
  c[ln]=0;
  for (i=1;i<ln;i++)
  {
    c[i+1]+=c[i]%d*10;
    c[i]/=d;
  }
  if (c[ln]==0)
  {
    for (i=1;i<ln;i++)
      a[i]=c[i];
    for (i=1;i<ln;i++)
    {
      b[i+1]+=b[i]%d*10;
      b[i]/=d;
    }
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[])
{
  char st[1000];
  int i,t;
  while (scanf("%s",st) && st[1]!='\0')
  {
    ln=strlen(st)-4;

    t=st[ln]-'0';
    st[ln]='\0';

    a[1]=0;
    for (i=2;i<ln;i++)
      a[i]=st[i]-'0';

    b[1]=9;
    for (i=2;i<ln;i++)
      b[i]=0;

    for (i=ln-1;i>0;i--)
    {
      a[i]*=9;
      a[i]+=t;
      t=0;
      if (a[i]>9)
      {
        t=a[i]/10;
        a[i]%=10;
      }
    }

    for (i=0;i<2;i++)
      if (div(3)==0)
        break;
    for (i=0;i<ln-2;i++)
      if (div(2)==0)
        break;
    for (i=0;i<ln-2;i++)
      if (div(5)==0)
        break;

    t=a[1];
    for (i=1;i<ln;t+=a[++i])
      if (t)
        printf("%d",a[i]);
    printf("/");
    t=b[1];
    for (i=1;i<ln;t+=b[++i])
      if (t)
        printf("%d",b[i]);
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------

