/*
令d(n)为n与n的各位数字的和，则称n为d(n)生成元。要求顺序输出1000000内没有生成元的数字

用数组标记记下有生成元的数字，没有标记的就是需要输出的
从1开始，在判断该数是否有生成元的同时，标记下该数的后继 

关键词：简单题 
*/
#include<iostream>
using namespace std;

bool self[1000001]={false};

int main()
{
    int sum,temp;
    
	for(int i=1;i<=1000000;i++)
    {
		if(self[i]==false)cout<<i<<endl;

		sum=temp=i;
		while(temp>0)
        {
			sum+=temp%10;
			temp/=10;
		}
		if(sum<=1000000)self[sum]=true;
	}
	return 0;
}
