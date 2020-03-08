#include <iostream>
#include <cmath>
using namespace std;


int a[20];
int b[20];
int n;
int index1;

bool isprime(int val)
{
	
	for(int i=2; i<=sqrt((double)val); i++)
	{
		if(val%i==0) return false;
	}
	return true;
}

void search(int i, int count)
{
	if(count == n && isprime(1+b[n]))
	{
		cout << "1";
		for(int j=2; j<=n; j++)
		{
			cout << " " << b[j];
		}
		cout << endl;
	}
	for(int j=1; j<=n; j++)
	{
		if(a[j] == 0 && isprime(i+j))
		{
			a[j] = 1;
			b[index1++] = j;
			search(j, count+1);
			index1--;
			a[j] = 0;
			
		}
	}
}

int main()
{
	int cas=1;
	while(cin >> n)
	{
		cout << "Case " << cas++ << ":" << endl;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		if(n%2==0)
		{
			index1 = 2;
			a[1] = 1;
			search(1, 1);
		}
		cout << endl;
	}
	return 0;
}