//89950 2003-03-16 16:12:13 Accepted 1503 C++ 00:00.00 380K Century Ghost 
#include<stdio.h>

long val[31][31];
long search(int guess,int high)
{
	if(val[guess][high]!=-1)	return val[guess][high];
	long temp=0;
	temp=search(guess-1,high)+search(guess-1,high-1)+1;
	val[guess][high]=temp;
	return temp;
}
int main()
{
	
	int i,j;
	for(i=0;i<31;i++)
		for(j=0;j<31;j++)	val[i][j]=-1;
	for(i=0;i<31;i++)
	{
		val[i][0]=i;val[0][i]=0;
	}
	int guess,highguess;
	int count=0;
	while(scanf("%ld%ld",&guess,&highguess))
	{
		if(guess==0&&highguess==0)	break;
		long temp=search(guess,highguess);
		count++;
		printf("Case %d: %ld\n",count,temp);
	}
	return 0;
}

		

	