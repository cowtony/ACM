#include <stdio.h>

int main(int argc, char* argv[])
{
  unsigned long long t,c,p,i,j,s,I,N;
  scanf("%Ld",&N);
  for (I=1;I<=N;I++)
  {
    scanf("%Ld%Ld%Ld",&t,&c,&p);
    printf("Case %d:",I);
    if (c+p-1>t)
    {
      printf(" It cannot be solved.\n");
      continue;
    }
    for (i=p;i<c+p;i++)
    {
      j=i;s=1;
      while (j>1)
      {
        s+=j%2;
        j/=2;
      }
      printf(" %ld",s);
    }
    printf("\n");
  }
  return 0;
}
//---------------------------------------------------------------------------
