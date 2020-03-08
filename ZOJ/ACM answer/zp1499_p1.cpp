//--------------------------------------------------------

#include<stdio.h>
#include<string.h>

char s[81],temp1[81][81],temp2[81][81];
int len1,len2,et;

int getfirst(char *t)
{
  int i=strlen(t)-1;

  while (i>=0 && t[i]=='0')
    i--;

  return i;
}
int compare(char*t1,char *t2)
{
  int t1f,t2f;
  t1f=getfirst(t1);
  t2f=getfirst(t2);

  if (t1f>t2f)
    return 1;
  else
    if (t2f>t1f)
      return 2;

  while (t1f>=0 && t1[t1f]==t2[t1f])
    t1f--;

  if(t1f==-1)
    return 0;
  else
    return (t2[t1f]>t1[t1f])+1;
}
int check()
{
  int i=len1,j=len2,k;
  while (i>=0 && j>=0 && !(k=compare(temp1[i],temp2[j])))
  {
    i--;
    j--;
  }
  return k;
}
void overmatch()
{
  int i;
  for(i=0;i<=len2;i++)
    strcpy(temp1[i],temp2[i]);

  len1=len2;
  et=1;
}
void confirm()
{
  if(et)
  {
    if (check()==2)
      overmatch();
  }
  else
    overmatch();
}
void find(int p,int k)
{
  if (k==-1)
  {
    len2=p;
    confirm();
    return ;
  }
  int i,j=0;
  for(i=k;i>=0;i--,j++)
  {
    temp2[p+1][j]=s[i];
    temp2[p+1][j+1]='\0';
    if (compare(temp2[p],temp2[p+1])==1)
      find(p+1,i-1);
    else
      return ;
  }
}
int main()
{
  int i,j,len;
  while (1)
  {
    scanf("%s",s);
    len=strlen(s);
    if (s[0]=='0' && len==1)
      return 1;
    et=0;
    for (i=len-1,j=0;i>=0;i--,j++)
    {
      if (et&&s[i]!='0')
        break;
      temp2[0][j]=s[i];
      temp2[0][j+1]='\0';
      find(0,i-1);
    }
    for (i=len1;i>=0;i--)
    {
      len=strlen(temp1[i]);
      for (j=len-1;j>=0;j--)
        printf("%c",temp1[i][j]);
      if (i)
        printf(",");
      else
        printf("\n");
    }
  }
}
//--------------------------------------------------------

