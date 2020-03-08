#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main()
{
	int fib[43];
	fib[0] = 1;
	fib[1] = 2;
	for(int i=2; i<43; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	string s1, s2;
	int len1=0, len2=0;
	while(cin >> s1 >> s2)
	{
		int a=0, b=0;
		for(int i=0, j=s1.length()-1; j>=0; j--, i++)
		{
			if(s1[j] == '1')
			{
				a += fib[i];
			}
		}
		for(int i=0, j=s2.length()-1; j>=0; j--, i++)
		{
			if(s2[j] == '1')
			{
				b += fib[i];
			}
		}
		deque <int> left;
		deque <int> right;
		deque <int> ans;
		int c=a+b;
		int i=42;
		if(a==0)
			left.push_back(0);
		if(b==0)
			right.push_back(0);
		if(c==0)
			ans.push_back(0);
		while(fib[i] > a)
		{
			i--;
		}
		for(; i>=0; i--)
		{
			if(a>=fib[i])
			{
				left.push_back(1);
				a -= fib[i];
			}
			else left.push_back(0);
		}
		i=42;
		while(fib[i]>b)
		{
			i--;
		}
		for(; i>=0; i--)
		{
			if(b>=fib[i])
			{
				right.push_back(1);
				b -= fib[i];
			}
			else right.push_back(0);
		}
		i=42;
		while(fib[i]>c)
		{
			i--;
		}
		for(; i>=0; i--)
		{
			if(c>=fib[i])
			{
				ans.push_back(1);
				c -= fib[i];
			}
			else ans.push_back(0);
		}
		for(i=0; i<ans.size()+2-left.size(); i++)
		{
			cout << " ";
		}
		for(i=0; i<left.size(); i++)
		{
			cout << left[i];
		}
		cout << endl;
		cout << "+";
		for(i=0; i<ans.size()+1-right.size(); i++)
		{
			cout << " ";
		}
		for(i=0; i<right.size(); i++)
		{
			cout << right[i];
		}
		cout << endl;
		cout << "  ";
		for(i=0; i<ans.size(); i++)
		{
			cout << "-";
		}
		cout << endl;
		cout << "  ";
		for(i=0; i<ans.size(); i++)
		{
			cout << ans[i];
		}
		cout << endl << endl;
	}
	return 0;
}

