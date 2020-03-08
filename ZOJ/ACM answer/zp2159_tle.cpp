#include <stdio.h>
#include <string.h>

int s;
int scmp(char s1[],char s2[],int ln)
{
  int i=0;
  while (s1[i]==s2[i] && i<ln) i++;
  if (i==ln)
    return 0;
  if (s1[i]>s2[i])
    return 0;
  return 1;
}
void cal(char str[],int stlen,char base[],int baslen)
{
  if (stlen==0)
    s++;
  else
  {
    int i;
    for (i=0;i<baslen-1 && i<stlen;i++)
      cal(str,stlen-i-1,base,baslen);
    if (baslen<=stlen)
      if (scmp(str+stlen-baslen,base,baslen))
        cal(str,stlen-baslen,base,baslen);
  }
}
int main(int argc, char* argv[])
{
  char st[40];
  int i,ln;
  while (scanf("%s",st) && st[0]!='#')
  {
    s=0;
    ln=strlen(st);
    for (i=1;i<ln;i++)
      if (st[i]!='0')
        cal(st,i,st+i,ln-i);

    printf("The code %s ",st);
    if (s)
      printf("can represent %d numbers.\n",s);
    else
      printf("is invalid.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
