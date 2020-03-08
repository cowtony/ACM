//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <stdio.h>

int now[3003],pre[3003],rec[3003];
int main(int argc, char* argv[])
{
  int n,i,j,k,l,s,sm,sn;
  while (scanf("%d",&n)!=EOF)
  {
    for (j=0;j<n;j++)
      now[j]=-1;

    sm=0;
    sn=0;
    for (i=0;i<n;i++)
    {
      for (j=0;j<n;j++)
      {
        pre[j]=now[j];
        scanf("%d",&now[j]);
        if (now[j])
          now[j]=-1;
      }
      now[n]=-1;
      j=0;
      while (j<n)
      {
        if (now[j]==0)
        {
          k=j;
          while (now[k]==0)
            k++;
          k--;
          s=1;
          rec[0]=0;
          for (l=j;l<=k;l++)
            if (pre[l]>0)
              if (pre[l]!=rec[s-1])
                rec[s++]=pre[l];
          sn+=s-1;
          sm++;
          for (l=j;l<=k;l++)
            now[l]=sm;
          j=k;
        }
        j++;
      }

      pre[n]=-1;
      j=0;
      while (j<n)
      {
        if (pre[j]>0)
        {
          k=j;
          while (pre[k]>0)
            k++;
          k--;
          s=1;
          rec[0]=0;
          for (l=j;l<=k;l++)
            if (now[l]>0)
              if (now[l]!=rec[s-1])
                rec[s++]=now[l];
          if (s>1)
            sn-=s-2;
          j=k;
        }
        j++;
      }
    }
    printf("%d\n",sm-sn);
  }
  return 0;
}
//---------------------------------------------------------------------------
