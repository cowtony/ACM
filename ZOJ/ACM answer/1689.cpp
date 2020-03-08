//331053 2003-10-30 22:18:19 Time Limit Exceeded 1689 C++ 00:01.00 424K just for play 
#include<stdio.h>
#include<math.h>

bool is_prime(int tn)
{
	int i;
	for(i=2;i<=sqrt(tn);i++)
		if(tn%i==0)	return false;
	return true;
}

int main()
{
	int m,a,b;
	int i,j,t;
	int num[10001];
	int pt[10001];
	pt[1]=0;pt[2]=0;
	int pre=0;
	num[0]=2;
	int num_cnt=1;
	for(i=3;i<=10000;i++)
	{
		if(is_prime(i)){	num[num_cnt++]=i;pre=i;}
		pt[i]=pre;
	}
	printf("%d\n",num_cnt);
	while(scanf("%d %d %d",&m,&a,&b)!=EOF)
	{
		if(m==0&&a==0&&b==0)	break;
		int cur_max=-1;
		int sel_a,sel_b;
		for(i=num_cnt-1;i>=0;i--)
		{
			if(num[i]>=m)	continue;
			if(num[i]*num[i]<=cur_max)	break;
			int t=(int)(num[i]*b*1.0/a);
			int at=(int)(m*1.0/num[i]);
			if(t<at)	at=t;
			if(at>10000)	at=10000;
			at=pt[at];
			if(i<at)	at=i;
			for(j=at;j>=0;j--)
			{
				if(num[i]*a>num[j]*b)	continue;
				if(num[i]*num[j]>=m)	continue;				
				if(num[i]*num[j]>cur_max)
				{
					cur_max=num[i]*num[j];
					sel_a=num[i];sel_b=num[j];
				}
				else	break;
			}
		}
		printf("%d %d\n",sel_b,sel_a);
	}
	return 0;
}
				

			
