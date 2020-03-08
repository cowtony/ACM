#include <memory.h>
#include <stdio.h>
#include <time.h>

  int n,s,t,i,j,a[33813],b[3010];

int main(int argc, char* argv[])
{
    clock_t __start__ = clock();

  memset(a,-1,sizeof(a));
  n=33811;
  s=0;
  i=2;
  b[++s]=i;
  j=4;
  while (j<n)
  {
    a[j]=0;
    j+=2;
  }

  for (i=3;i<n;i+=2)
    if (a[i])
    {
      b[++s]=i;
      j=i;
      while (j+1<n)
      {
        t=0;
        while (t<i && j+1<n)
        {
          j+=2;
          if (a[j])
            t++;
        }
        a[j]=0;
      }
    }
    printf("time: %.3f\n",
        ((double)clock()-__start__) / CLOCKS_PER_SEC);
  //printf("%d\n",s);
  while (scanf("%d",&n) && n)
    printf("%d\n",b[n]);
  return 0;
}
//---------------------------------------------------------------------------
