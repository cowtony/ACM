//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
int sm;
void cal(int m, int f)
{
  int p,i;
  if (m%2)      p=m/2;
  else          p=m/2-1;
  if (f+1>p)
    sm++;
  else
    for (i=f+1;i<=p;i++)
    {
      cal(m-i,i);
    }
}
int main(int argc, char* argv[])
{
  int n;
  scanf("%d",&n);
  while (n)
  {
    sm=0;
    cal(n,0);

    printf("%d\n",sm);

    scanf("%d",&n);
  }
  return 0;
}
//---------------------------------------------------------------------------
 