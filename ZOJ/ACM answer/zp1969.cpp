//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char st[25];
  int i,j,k,a,b,c,ln;
  while (scanf("%s",st))
  {
    ln=strlen(st);
    j=0;
    while (st[j]!='+')
      j++;
    a=0;
    for (i=j-1;i>=0;i--)
    {
      a*=10;
      a+=st[i]-'0';
    }
    k=j;
    while (st[j]!='=')
      j++;
    b=0;
    for (i=j-1;i>k;i--)
    {
      b*=10;
      b+=st[i]-'0';
    }
    c=0;
    for (i=ln-1;i>j;i--)
    {
      c*=10;
      c+=st[i]-'0';
    }

    if (a+b==c)
      printf("True\n");
    else
      printf("False\n");
    if (a==0 && b==0 && c==0)
      break;
  }
  return 0;
}
//---------------------------------------------------------------------------
