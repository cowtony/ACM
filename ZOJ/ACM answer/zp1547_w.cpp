//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
  char st[210],sm[210];
  int ln,i,j,r,p;
  while (scanf("%s",&st)>0)
  {
    ln=strlen(st);
    for (i=1;i<ln;i++)
    {
      r=i;
      for (k=0;k<i;k++)
      {
        for (j=0;j<i;j++)
          sm[i-j-1]=st[j+k];
        sm[0]--;
        for (j=0;j<r;j++)
          if (sm[j]<'0')
          {
            sm[j+1]--;
            sm[j]='9';
          }
          else
            break;
        if (j==r)
          continue;
        for (j=0;j<k;j++)
          if (st[k-j-1]!=sm[j])
            break;
        if (j<k)
          continue;
        //---------------;

        for (j=0;j<i;j++)
          sm[i-j-1]=st[j+k];
        p=i+k;
        while (1)
        {
          sm[0]++;
          for (j=0;j<r;j++)
            if (sm[j]>'9')
            {
              sm[j+1]++;
              sm[j]='0';
            }
            else
              break;
          if (j==r)
            sm[r++]='1';

          for (j=p;j<p+r;j++)
            if (sm[p+r-j-1]!=st[j])
              break;
          if (j<p+r)
            break;
          p+=r;
        }
        if (j==ln)
          break;
      }
      if (k<i)
        break;
    }
    for (j=0;j<i;j++)
      printf("%c",st[j]);
    printf("\n");

    for (j=0;j<ln;j++)
      sm[j]='0';
  }
  return 0;
}
//---------------------------------------------------------------------------
