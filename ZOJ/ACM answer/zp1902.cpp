//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>
char st[1010][18];

int main(int argc, char* argv[])
{
  int m,n,i,j,s,a[1010];
  char word[18];
  scanf("%d%d",&m,&n);
  for (i=0;i<m;i++)
    scanf("%s %d",st[i],&a[i]);
  for (i=0;i<n;i++)
  {
    s=0;
    scanf("%s",word);
    while (word[0]!='.')
    {
      for (j=0;j<m;j++)
        if (strcmp(word,st[j])==0)
        {
          s+=a[j];
          break;
        }
      scanf("%s",word);
    }
    printf("%d\n",s);
  }
  return 0;
}
//---------------------------------------------------------------------------
