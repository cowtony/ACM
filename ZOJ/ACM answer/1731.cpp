//2088048 2006-10-02 13:01:58 Accepted 1731 C++ 00:07.75 952K hellokitty 
//好慢，没优化
#include <iostream>
using namespace std;
int main()
{
	int a[10000][2];
	int flag[10000];
	int num;
	int i, j;
	while( cin >> num)
	{
		for(i=0; i<num; i++)
		{
			cin >> a[i][0] >> a[i][1];
		}
		for(i=0; i<num; i++)
		{
			for(j=i+1; j<num; j++)
			{
				if(a[i][1] > a[j][1])
				{
					swap(a[i][0], a[j][0]);
					swap(a[i][1], a[j][1]);
				}
				else if(a[i][1] == a[j][1] && a[i][0] > a[j][0])
				{
					swap(a[i][0], a[j][0]);
					swap(a[i][1], a[j][1]);
				}
			}
		}
		memset(flag, 0, sizeof(int) * num);
		int ans = 0;
		int dx = a[num-1][1];
		for(; dx>=1; dx--)
		{
			int max = 0;
			int index;
			for(j=num-1; j>=0; j--)
			{
				if(flag[j] == 0 && a[j][0] > max && a[j][1] >= dx)
				{
					max = a[j][0];
					index = j;
				}
				if(a[j][1] < dx) break;
			}
			if(max >0)
			{
				flag[index] = 1;
				ans += max;
			}
		}
		cout << ans << endl;
	}
	return 0;
}