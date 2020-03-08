#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a[100][102];
	int N;
	cin >> N;
	while(N--)
	{
		int n, p;
		cin >> n >> p;
		for(int i=0; i<n; i++)
		{
			int min = 10000000;
			int max = 0;
			for(int j=0; j<p; j++)
			{
				scanf("%d", &a[i][j]);
				if(a[i][j] < min)
					min = a[i][j];
				if(a[i][j] > max)
					max = a[i][j];
			}
			a[i][p] = min;
			a[i][p+1] = max;
		}
		vector <int> result;
		for(int j=0; j<p; j++)
		{
			int account(0);
			bool flag = false;
			for(int i=0; i<n; i++)
			{
				if(a[i][j] == a[i][p] && a[i][j] < a[i][p+1])
					account++;
				if(a[i][j] == a[i][p+1]) {flag = true;break;}
			}
			if(account>n/2&&!flag) result.push_back(j+1);
		}
		if(result.size()==0)
			cout << 0 << endl;
		else
		{
			cout << result[0];
			for(int i=1; i<result.size(); i++)
			{
				cout << " " << result[i];
			}
			cout << endl;

		}
		if(N>0) cout << endl;
	}
	return 0;
}

