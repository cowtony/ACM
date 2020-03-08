//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int main(int argc, char* argv[])
{
  int n,i,j,p[26],cs=0;
  char st1[2],ste[2],st2[2];
  while (scanf("%d",&n) && n)
  {
    for (i=1;i<26;i++)
      p[i]=0;
    p[0]=1;
    for (i=0;i<n;i++)
    {
      scanf("%s%s%s",st1,ste,st2);
      p[st1[0]-'a']=p[st2[0]-'a'];
    }
    i=0;
    while (p[i]==0 && i<26)
      i++;
    printf("Program #%d\n",++cs);
    if (i==26)
      printf("none\n");
    else
    {
      for (j=i;j<26;j++)
        if (p[j])
          printf("%c ",'a'+j);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
