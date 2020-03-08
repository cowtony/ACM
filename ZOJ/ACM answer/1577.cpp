#include <stdio.h>
#include <math.h>
long gcd(long a,long b)
{
	if(a%b!=0) return gcd(b,a%b);
	else return b;
}
int main()
{
	long x,y,count,s;
	long i,j,temp;
	double f1;
	while(scanf("%ld%ld",&x,&y)!=EOF)
	{
		if(x==y) {printf("1\n");continue;}
		count=0;
		f1=(double)x*(double)y;
		s=(long)sqrt(f1);
		for(i=x;i<=s;i+=x)
		{
			if(y%i!=0) continue;
			j=(long)(f1/(double)i);
			temp=gcd(j,i);
			if(temp==x) count++;
		}
		printf("%ld\n",count*2);
	}
	return 0;
}
