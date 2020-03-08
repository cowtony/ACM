#include <stdio.h>
#include <string.h>

char st[120000][30];
int p[20000],r[20000];

int cal(char s[])
{
  int t=27*27*(s[0]-'a');

  if (s[1]!='\0')
  {
    t+=27*(s[1]-'a'+1);
    if (s[2]!='\0')
      t+=s[2]-'a'+1;
  }

  return t;
}

int main(int argc, char* argv[])
{
//   FILE *in=fopen("zp1825.in","r");
//   FILE *out=fopen("output.txt","w");


  int n,t,k,i,ln,j,l;
  char rt[4]="\0\0\0";
  memset(p,-1,sizeof(p));
  memset(r,0,sizeof(r));

  n=0;
  while (scanf("%s",st[n])>0)
  {
    t=cal(st[n]);
    if (p[t]==-1)
      p[t]=n;
    else
      r[t]++;

    t-=t%27;
    if (p[t]==-1)
      p[t]=n;
    else
      r[t]++;

    t-=t%729;
    if (p[t]==-1)
      p[t]=n;
    else
      r[t]++;

    n++;
  }

  for (i=1;i<n;i++)
  {
    rt[0]=st[i][0];

    ln=strlen(st[i]);

    for (j=p[cal(rt)],t=strlen(st[j]);
         j<i && j>=0;j++,t=strlen(st[j]))
      if (ln>t && memcmp(st[j],st[i],t)==0)
      {
        k=cal(st[i]+t);

        if (p[k]>=0)
        {
          for (l=0;l<=r[k];l++)
            if (ln-t==int(strlen(st[p[k]+l])))
              if (memcmp(st[p[k]+l],st[i]+t,ln-t)==0)
                break;
          if (l<=r[k])
            break;
        }
      }

    if (j<i && j>=0)
      printf("%s\n",st[i]);
  }

  //scanf("%s",st[0]);

  return 0;
}
//---------------------------------------------------------------------------
