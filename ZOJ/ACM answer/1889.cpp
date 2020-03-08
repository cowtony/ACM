#include<iostream>
using namespace std;
int main()
{
	int n;

	
	while(cin>>n)
	{
		int b=0;
		int a=1;
		while(1)
		{
			int m;
			m=a%n;	
			b++;
			if(m==0)
				break;
			a=m*10+1;
		
		}
		cout<<b<<endl;

	}
	return 0;
}
