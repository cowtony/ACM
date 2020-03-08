/*
A+B problem

¹Ø¼ü´Ê£º¼òµ¥Ìâ  
*/
#include<iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
	    int a,sum=0;
		for(int i=0;i<N;i++)
		{
		    cin>>a;
		    sum+=a;
		}
		cout<<sum<<endl;
	}
}
