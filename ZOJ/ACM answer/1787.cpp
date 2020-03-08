#include <iostream>
using namespace std;


void process(int n)
{
	int a[101][101];
	memset(a, 0, sizeof(a));
	int ai, bi;
	while(n--)
	{
		cin >> ai >> bi;
		a[ai][bi]++;
	}
	int max[101][101];
	memset(max, 0, sizeof(max));
	for(int i=1; i<101; i++)
	{
		for(int j=1; j<101; j++)
		{
			if(max[i-1][j] > max[i][j-1])
				max[i][j] = max[i-1][j] + a[i][j];
			else
				max[i][j] = max[i][j-1] + a[i][j];
		}
	}
	cout << max[100][100] << endl;
}

int main()
{
	int n;
	while(cin >> n && n!= 0)
	{
		process(n);
	}
	cout << "*" << endl;
	return 0;
}