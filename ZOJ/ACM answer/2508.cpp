#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n, h, mh, mw;
	int a[5][5];
	int b[30][2];
	int m;
	int clx, cly;
	int i, j, k;
	while(cin >> n >> h >> mw >> mh)
	{
		deque <int> hello;
		for(i=0; i<n; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
			a[i][4] = i;
		}
		cin >> m;
		for(i=0; i<m; i++)
		{
			cin >> b[i][0] >> b[i][1];
		}
		int t = 0; //没最大化
		for(i=0; i<m; i++)
		{
			if(t==1)
			{
				hello.push_back(a[n-1][4]);
				int count = 0;
				int count2 = 0;
				for(j=i; j>=0; j--)
				{
					if(b[j][0] != b[i][0] || b[j][1] != b[i][1]) break;
					count++;
					if(b[j][1] >= mh-h && b[j][1] <= mh) count2 = 1;
				}
				if(count%2==0 && count2) t=0;
				continue;
			}
			int flag = 0;
			for(j=n-1; j>=0; j--)
			{
				if(b[i][0] >= a[j][0] && b[i][0] <= a[j][2] && b[i][1] >= a[j][3] && b[i][1] <= a[j][1])
				{
					hello.push_back(a[j][4]);
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				hello.push_back(-1);
				continue;
			}
			if(j == n-1)
			{
				int count1 = 0;
				for(k=i; k>=0; k--)
				{
					if(b[k][0] != b[i][0] ||b[k][1] != b[i][1]) break;
					count1++;
				}
				if(count1%2 == 0 && b[i][0] >= a[n-1][0] && b[i][0] <= a[n-1][2] && b[i][1] >= a[n-1][1]-h && b[i][1] <= a[n-1][1])
				{
					t = 1;
				}
			}
			else
			{
				int temp[5];
				temp[0] = a[j][0];
				temp[1] = a[j][1];
				temp[2] = a[j][2];
				temp[3] = a[j][3];
				temp[4] = a[j][4];
				for(k=j+1; k<n; k++)
				{
					a[k-1][0] = a[k][0];
					a[k-1][1] = a[k][1];
					a[k-1][2] = a[k][2];
					a[k-1][3] = a[k][3];
					a[k-1][4] = a[k][4];
				}
				a[n-1][0] = temp[0];
				a[n-1][1] = temp[1];
				a[n-1][2] = temp[2];
				a[n-1][3] = temp[3];
				a[n-1][4] = temp[4];
			}
		}
		for(i=0; i<hello.size(); i++)
		{
			if(i<hello.size()-1) cout << hello[i] << " ";
			else cout << hello[i] << endl;
		}
	}
	return 0;
}