#include <stdio.h>
#include <string.h>

long long s;
void cal(char str[],int stlen,char base[],int baslen)
{
  int i,j,p[40];

  memset(p,0,sizeof(p));

  p[stlen]=1;
  for (i=stlen;i>0;i--)
  {
    for (j=1;j<baslen && j<=i;j++)
      if (j==1 || str[i-j]!='0')
        p[i-j]+=p[i];
    if (i>=baslen && (str[i-baslen]!='0' || baslen==1)
     && memcmp(str+i-baslen,base,baslen)<0)
      p[i-baslen]+=p[i];
  }
//  printf("%s %d\n",base,p[0]);
  s+=p[0];
}
int main(int argc, char* argv[])
{
//   FILE *in=fopen("zp2159.in.txt","r");
//   FILE *out=fopen("output.txt","w");

  char st[40];
  int i,ln;
  while (scanf("%s",st) && st[0]!='#')
  {
    s=0;
    ln=strlen(st);
    if (st[0]=='0')
      if (st[1]=='0' || st[1]=='\0')
        s=0;
      else
        s=1;
    else
      for (i=1;i<ln;i++)
        if (st[i]!='0')
          cal(st,i,st+i,ln-i);

    printf("The code %s ",st);
    if (s)
      printf("can represent %Ld numbers.\n",s);
    else
      printf("is invalid.\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
