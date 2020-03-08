//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------


#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int t,n,w,b,s,e,i,a,m;
  char st[5];
  while (scanf("%d",&m) && m)
  {
    t=1;  b=6;
    n=2;  s=5;
    w=3;  e=4;
    for (i=0;i<m;i++)
    {
      scanf("%s",st);
      switch (st[0])
      {
        case 'n':{a=n;n=t;t=s;s=b;b=a; break;}
        case 's':{a=s;s=t;t=n;n=b;b=a; break;}
        case 'w':{a=w;w=t;t=e;e=b;b=a; break;}
        case 'e':{a=e;e=t;t=w;w=b;b=a; break;}
      }
    }
    printf("%d\n",t);
  }
  return 0;
}
//---------------------------------------------------------------------------
 