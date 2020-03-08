#include<iostream>//计算给出的一列数有几组连续的数想加能除m
using namespace std;
int main()
{
	int n,m;
	int tem;
	int x;
	while(cin>>n>>m)
	{
		int a[5001]={0};
		a[0]=1;
		tem=0;
		while(n--)
		{
			cin>>x;
			tem+=x;//以余数相加在取余
			tem=tem%m;
			a[tem]++;//记录相同的余数的个数
		}
		int i;
		int sum=0;
		for(i=0;i<m;i++)
		{
			if(a[i]>=2)
				sum+=a[i]*(a[i]-1)/2;//利用取余的性质,余数相等只见一定有一个满足条件的一组
		}
		cout<<sum<<endl;
	}
}