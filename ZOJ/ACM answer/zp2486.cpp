#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int n,i,ln;
  double x,r,k;
  char st[100];

  while (scanf("%d%s",&n,st)>0)
  {
    r=st[0]-'0';
    ln=strlen(st);
    x=ln-1;
    k=1.0/10;
    for (i=1;i<ln && i<16;i++)
    {
      r+=(st[i]-'0')*k;
      k/=10;
    }
    x+=log(r)/log(10);
    x/=n;
    x=pow(10,x);
    printf("%.0lf\n",x);
  }
  return 0;
}
//---------------------------------------------------------------------------
