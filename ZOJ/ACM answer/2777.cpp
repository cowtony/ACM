#include <iostream>
using namespace std;


int gcd(int m, int n)
{
	if(m<n)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	if(n==0) return m;
	else
		return gcd(n, m%n);
}

int main()
{
	int a[1001];
	a[1] = 3;
	for(int i=2; i<1001; i++)
	{
		a[i] = a[i-1];
		for(int j=1; j<=i; j++)
		{
			if(gcd(i, j) == 1) a[i]+=2;
		}
	}
	int cas;
	cin >> cas;
	for(int i=1; i<=cas; i++)
	{
		int n;
		cin >> n;
		cout << i << " " << n << " " << a[n] << endl;
	}
	return 0;
}

