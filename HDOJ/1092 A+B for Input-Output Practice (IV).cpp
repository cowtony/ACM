/*
A+B problem

¹Ø¼ü´Ê£º¼òµ¥Ìâ 
*/
#include<iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n && n!=0)
	{
		int sum=0;
		while(n--)
		{
		    int a;
		    cin>>a;
		    sum+=a;
		}
		cout<<sum<<endl;
	}
}
