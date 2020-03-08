#include <stdio.h>

int w[50010],h[50010];
int main()
{
  int i,j,n;

	int max,tmax;
  while(scanf("%d",&n) && n>=0)
  {
    max = 0;
    for(i=0;i<n;i++)
	    scanf("%d%d",w+i,h+i);
    for(i=0;i<n;i++)
    {
      tmax = 0;
  	  for(j=i;j>=0;j--)
	      if(h[j]>=h[i])
		      tmax+=w[j]*h[i];
	      else break;
  	  for(j=i+1;j<n;j++)
	      if(h[j]>=h[i])
			    tmax+=w[j]*h[i];
  	   	else break;
	    if(tmax>max) max=tmax;
    }
    printf("%d\n",max);
  }
  return 0;
}

