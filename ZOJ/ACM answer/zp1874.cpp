#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
  char st1[12],st2[12];
  int ln1,ln2,i,s,t;
  scanf("%s %s",st1,st2);
  while (st1[0]!='0' || st2[0]!='0')
  {
    ln1=strlen(st1);
    ln2=strlen(st2);
    if (ln1>ln2)
    {
      for (i=0;i<ln2;i++)
        st2[ln1-i-1]=st2[ln2-i-1];
      for (i=0;i<ln1-ln2;i++)
        st2[i]='0';
      ln2=ln1;
    }
    else
    if (ln1<ln2)
    {
      for (i=0;i<ln1;i++)
        st1[ln2-i-1]=st1[ln1-i-1];
      for (i=0;i<ln2-ln1;i++)
        st1[i]='0';
      ln1=ln2;
    }
    t=0;
    s=0;
    for (i=ln1-1;i>=0;i--)
      if (t+st1[i]-'0'+st2[i]-'0'>9)
      {
        t=1;
        s++;
      }
      else
        t=0;
    if (s)
      printf("%d",s);
    else
      printf("No");
    printf(" carry operation");
    if (s>1)
      printf("s.\n");
    else
      printf(".\n");
    scanf("%s %s",st1,st2);
  }
  return 0;
}
//---------------------------------------------------------------------------
