#include<iostream>
#include<cstdio>
using namespace std;
#define M 1000000000;
int main()
{
	int x,y;	
	cin>>x>>y;
	while(1)
	{
		int min1=M;
		int min2=M;
		int max1=0;
		int max2=0;
		if(x==0&&y==0)
			break;
		while(1)
		{
			if(min1>=x)
				min1=x;
			if(min2>=y)
				min2=y;
			if(max1<x)
				max1=x;
			if(max2<y)
				max2=y;
			cin>>x>>y;
			if(x==0&&y==0)
			{
				printf("%d %d %d %d\n",min1,min2,max1,max2);
				break;
			}			
		}
		cin>>x>>y;
	}
	
	return 0;
}