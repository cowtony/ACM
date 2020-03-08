//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  double d=720/11.0;
  int a[15],i,h1,h2,m1,m2,p;

  a[12]=0;a[11]=60; a[0]=0;
  for (i=1;i<11;i++)
    a[i]=d*i-60*i+1;

  printf("Program 3 by team X\n");
  printf("Initial time  Final time  Passes\n");

  while (scanf("%d%d%d%d",&h1,&m1,&h2,&m2)!=EOF)
  {
    printf("       ");
    if (h1<10) printf("0");printf("%d:",h1);
    if (m1<10) printf("0");printf("%d       ",m1);
    if (h2<10) printf("0");printf("%d:",h2);
    if (m2<10) printf("0");printf("%d",m2);

    h1%=12; h2%=12;
    if (h1*60+m1>h2*60+m2) h2+=12;

    p=h2-h1-1;

    if (h2>11) p--;
    if (m1<a[h1]) p++;
    h2%=12;
    if (m2>=a[h2]) p++;

    printf("      ");
    if (p<10)
      printf(" ");
    printf("%d\n",p);
  }
  printf("End of program 3 by team X\n");

  return 0;
}
//---------------------------------------------------------------------------
