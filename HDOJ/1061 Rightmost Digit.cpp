/*
求N^N的最右边一位数

找规律，首先只有个位起作用，其他的全部舍掉
然后发现末尾的幂最大是以四为循环的，可以打印regular数组看一下

关键词：数学题，简单题 
*/
#include<iostream>
using namespace std;

int main()
{
	int regular[10][5];
	for(int i=0;i<10;i++)
	{
	    regular[i][0]=1;
	    for(int j=1;j<5;j++)
	        regular[i][j]=(regular[i][j-1]*i)%10;
	}
	
	int N;
	cin>>N;
	while(N--)
	{
		int n;
		cin>>n;
		cout<<regular[n%10][(n+3)%4+1]<<endl;
	}
}
