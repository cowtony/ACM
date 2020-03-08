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
  char st[20010];
  int N,I,ln,i,k,p;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%s",st);
    ln=strlen(st);
    for (i=0;i<ln;i++)
      st[i+ln]=st[i];
    st[ln+ln]='\0';

    p=0;
    for (i=1;i<ln;i++)
    {
      k=0;
      while (st[p+k]==st[i+k] && k<ln)
        k++;
      if (k==ln)
        break;
      if (st[p+k]>st[i+k])
        p=i;
      else
        i+=k;
    }
    printf("%d\n",p+1);
  }
  return 0;
}
//---------------------------------------------------------------------------
