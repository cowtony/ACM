#include <stdio.h>

int main()
{
  int i,p[33],j,m,a,t,r;
	char s[10];
	while (scanf("%s",s)>0)
	{
  	for (i=0;i<32;i++)
  	{
  		if (i)
  			scanf("%s",s);
  		p[i]=0;
  		for (j=0;j<8;j++)
  			p[i]=p[i]*2+s[j]-'0';
   	}
   	m=0;
    a=0;
    t=0;
    while (!t)
    {
      r=p[m];
      m=(m+1)%32;
      switch (r>>5)
      {
        case 0: p[r & 31]=a;        break;
        case 1: a=p[r & 31];        break;
        case 2: if (a==0) m=r & 31; break;
        case 3:                     break;
        case 4: a=(a+255)%256;      break;
        case 5: a=(a+1)%256;        break;
        case 6: m=r & 31;           break;
        case 7: t=1;                break;
      }
    }

    for (i=0;i<8;i++)
      printf("%d",(a>>(7-i))&1);
    printf("\n");
  }
}

