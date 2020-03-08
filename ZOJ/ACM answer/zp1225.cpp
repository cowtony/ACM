//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
//aAaAab, aaaaabb, aaaaac, aaaaab

#pragma argsused
#include <stdio.h>
#include <string.h>

int chcmp(char s1,char s2)
{
  if (s1>='A' && s1<='Z')
    s1-='A'-'a';
  if (s2>='A' && s2<='Z')
    s2-='A'-'a';
  if (s1>s2)
    return 1;
  if (s1<s2)
    return -1;
  return 0;
}
int scmp(char *s1, char *s2)
{
  int i=0;
  while (chcmp(s1[i],s2[i])==0
      && i<strlen(s1) && i<strlen(s2))
    i++;

  if (i==strlen(s1) && i==strlen(s2))
    return 0;
  else
    if (i==strlen(s1))
      return -1;
    else
      if (i==strlen(s2))
        return 1;

  return chcmp(s1[i],s2[i]);
}
int main(int argc, char* argv[])
{
  char st[1000],str[100][1000];
  int s,r,m,t,ln,k,i,j,a[100],w[100];
  while (scanf("%s",st) && st[0]!='.')
  {
    s=0;
    r=0;
    m=0;
    while (1)
    {
      ln=strlen(st);
      k=1;t=0;
      for (i=ln-2;i>0;i--)
        if (st[i]<='9' && st[i]>='0')
        {
          t+=(st[i]-'0')*k;
          k*=10;
        }
        else
          break;

      if (i==0 && (st[i]<='9' && st[i]>='0' || st[i]=='-'))
        if (st[i]=='-')
          t=-t;
        else
          t+=(st[i]-'0')*k;
      else
        i++;

      if (i==0)
        a[r++]=t;
      else
      {
        strcpy(str[s],st);
        str[s++][ln-1]='\0';
      }
      w[m++]=i;

      if (st[ln-1]=='.')
        break;
      scanf("%s",st);
    }
    for (i=0;i<r-1;i++)
      for (j=i+1;j<r;j++)
        if (a[i]>a[j])
        {
          t=a[i];
          a[i]=a[j];
          a[j]=t;
        }
    for (i=0;i<s-1;i++)
      for (j=i+1;j<s;j++)
        if (scmp(str[i],str[j])>0)
        {
          strcpy(st,str[i]);
          strcpy(str[i],str[j]);
          strcpy(str[j],st);
        }
    r=0;
    s=0;
    for (i=0;i<m-1;i++)
      if (w[i])
        printf("%s, ",str[s++]);
      else
        printf("%d, ",a[r++]);
    if (w[i])
      printf("%s.\n",str[s++]);
    else
      printf("%d.\n",a[r++]);

  }
  return 0;
}
//---------------------------------------------------------------------------
