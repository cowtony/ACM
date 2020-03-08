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
  int N,I,ln,i,j,s,t,d,r[20010],v[20010];
  char st[20010],ch;
  scanf("%d",&N);
  for (I=0;I<N;I++)
  {
    scanf("%s",st);
    ln=strlen(st);
    for (i=0;i<ln;i++)
      st[i+ln]=st[i];
    st[ln+ln]='\0';
    ch='z'+1;
    for (i=0;i<ln;i++)
      if (st[i]<ch)
      {
        ch=st[i];
        s=1;
        r[0]=i;
      }
      else
        if (st[i]==ch)
          r[s++]=i;
    d=1;
    while (s>1)
    {
      ch='z'+1;
      for (i=0;i<s;i++)
        if (st[r[i]+d]<ch)
        {
          ch=st[r[i]+d];
          t=1;
          v[0]=r[i];
        }
        else
          if (st[r[i]+d]==ch)
            v[t++]=r[i];
      s=t;
      for (i=0;i<s;i++)
        r[i]=v[i];
      d++;
      if (d>ln)
        break;
    }
    printf("%d\n",r[0]+1);
  }
  return 0;
}
//---------------------------------------------------------------------------
