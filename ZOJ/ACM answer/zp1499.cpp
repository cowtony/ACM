//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

char *strmov(char *s)
{
  int i,k=0,ln=strlen(s);
  while (s[k]=='0' && k<ln)
    k++;
  for (i=k;i<=ln;i++)
    s[i-k]=s[i];
  return s;
}
int strlens(char *s)
{
  int i=0,ln=strlen(s);
  while (s[i]=='0' && i<ln)
    i++;
  ln-=i;
  return ln;
}
int sintcmp(char *s1, char *s2)
{
  int ln1,ln2;
  ln1=strlens(s1);
  ln2=strlens(s2);

  if (ln1>ln2)
    return 1;
  else
    if (ln1<ln2)
      return -1;
  if (ln1==0)
    return 0;
  int k=0,l=0;;
  while (s1[k]=='0')
    k++;
  ln1=strlen(s1);
  while (s2[l]=='0')
    l++;
  for (int i=k;i<=ln1;i++)
    if (s1[i]>s2[i-k+l])
      return 1;
    else
      if (s1[i]<s2[i-k+l])
        return -1;
  return 0;
}
void ladd(char *s1,const char s2)
{
  int l=strlen(s1);
  for (int i=l+1;i>0;i--)
    s1[i]=s1[i-1];
  s1[0]=s2;
}
void radd(char *s1,const char s2)
{
  int l=strlen(s1);
  s1[l]=s2;
  s1[l+1]='\0';
}
void ldec(char *s)
{
  int l=strlen(s);
  for (int i=0;i<l;i++)
    s[i]=s[i+1];
}
void strlet(char *s1,const char *s2)
{
  int k=0,l=strlen(s2);
  while (s2[k]=='0' && k<l)
    k++;
  for (int i=k;i<=l;i++)
    s1[i-k]=s2[i];
}
int main(int argc, char* argv[])
{
  char st[81],a[81][81]={0},tm[81],mx[81];
  int ln,i,j,t,l,v;
  //long  k,kk,mx,a[81]={0};
  while (scanf("%s",st) && strcmp(st,"0")!=0)
  {
    ln=strlen(st);
    for (i=0;i<=ln;i++)
      a[i][0]='\0';
    a[1][0]=st[0];
    a[1][1]='\0';
    for (i=2;i<=ln;i++)
    {
      j=i-1;
      tm[0]=st[j];
      tm[1]='\0';
      while (j>=0)
      {
        if (sintcmp(tm,a[j])>0 || strlens(a[j])==0)
        {
          if (sintcmp(tm,a[i])<0 || strlens(a[i])==0)
            strlet(a[i],tm);
        }
        j--;
        ladd(tm,st[j]);
      }
    }
    l=strlens(a[ln]);
    strlet(mx,a[ln]);

    for (i=0;i<=ln;i++)
      a[i][0]='\0';
    t=ln-l;
    strlet(a[t],mx);

    for (i=t;i>0;i--)
    {
      v=i-l;
      if (v<0)
        v=0;

      while (v<i && st[v]=='0')
        v++;
      if (v==i)
      {
        v--;
        while (st[v]=='0' && v>0)
          v--;
      }//100101001
      tm[0]=st[v];
      tm[1]='\0';

      for (j=v;j<i-1;j++)
        radd(tm,st[j+1]);
      //while (st[j+1]=='0')
        //radd(tm,st[++j]);

      while (strlen(tm))
      {
        if (sintcmp(tm,a[i])<0)
        {
          if (sintcmp(tm,a[v])>0 || strlens(a[v])==0)
            strlet(a[v],tm);
          if (st[v]=='0')
            strlet(a[v],a[i]);
        }
        v++;
        ldec(tm);
      }
    }
    i=0;
    while (i<ln)
    {
      while (st[i]=='0')
      {
        printf("0");
        i++;
      }
      printf("%s",a[i]);
      if (i<t)
        printf(",");
      i+=strlens(a[i]);
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
