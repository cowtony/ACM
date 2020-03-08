#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int cas;
	int i, j, k;
	int a[7][8], b[7][8];
	int hello = 1;
	cin >> cas;
	while(cas--)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(i=1; i<6; i++)
		{
			for(j=1; j<7; j++)
			{
				cin >> a[i][j];
			}
		}
		int ans[7][8];
		for(i=0; i<32; i++)
		{
			int ta[6] = {0};
			int temp = 16;
			int tem = i;
			for(j = 1; j<6; j++)
			{
				if(tem >= temp)
				{
					ta[j] = 1;
					tem -= temp;
				}
				temp /= 2;
			}
			for(j=1; j<6; j++)
			{
				for(k=1; k<7; k++)
				{
					b[j][k] = a[j][k];
				}
			}
			memset(ans, 0, sizeof(ans));
			for(j=1; j<6; j++)
			{
				ans[j][1] = ta[j];
			}
			for(j=1; j<6; j++)
			{
				if(ta[j])
				{
					b[j][1] = abs(b[j][1] - 1);
					b[j][2] = abs(b[j][2] -1);
					b[j-1][1] = abs(b[j-1][1] - 1);
					b[j+1][1] = abs(b[j+1][1] - 1);
				}
			}
			for(j=2; j<7; j++)
			{
				for(k=1; k<6; k++)
				{
					if(b[k][j-1] == 1)
					{
						b[k][j] = abs(b[k][j] - 1);
						b[k][j-1] = abs(b[k][j-1] - 1);
						b[k-1][j] = abs(b[k-1][j] - 1);
						b[k+1][j] = abs(b[k+1][j] - 1);
						b[k][j+1] = abs(b[k][j+1] - 1);
						ans[k][j] = 1;
					}
					else ans[k][j] = 0;
				}
			}
			int t = 0;
			for(j=1; j<6; j++)
			{
				if(b[j][6] == 1) {t=1; break;}
			}
			if(!t) break;
		}
		cout << "PUZZLE #" << hello++ << endl;
		for(i=1; i<6; i++)
		{
			for(j=1; j<7; j++)
			{
				if(j == 1) cout << ans[i][j];
				else cout << " " << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}