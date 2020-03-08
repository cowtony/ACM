//ans = (n-m+1) * (n-m)! / (n+1)

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n, m;
	int i, j;
	int cas = 1;
	while(cin >> n >> m )
	{
		if(!n && !m) break;
		cout << "Test #" << cas++ << ":" << endl;
		if(n < m) {cout << 0 << endl; continue;}
		deque <int> hello;
		hello.push_back(1);
		for(i=2; i<=m+n; i++)
		{
			if(i == n+1) continue;
			int carry = 0;
			for(j=0; j<hello.size(); j++)
			{
				hello[j] = hello[j] * i + carry;
				carry = hello[j] / 10;
				hello[j] %= 10;
			}
			while(carry)
			{
				hello.push_back(carry%10);
				carry /= 10;
			}
		}
		if(m)
		{
			int carry = 0;
			int temp = n-m+1;
			for(i=0; i<hello.size(); i++)
			{
				hello[i] = hello[i] * temp + carry;
				carry = hello[i] / 10;
				hello[i] %= 10;
			}
			while(carry)
			{
				hello.push_back(carry%10);
				carry /= 10;
			}
		}
		for(i=hello.size()-1; i>=0; i--)
		{
			cout << hello[i];
		}
		cout << endl;
	}
	return 0;
}