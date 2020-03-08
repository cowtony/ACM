#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	char ch[730][730];
	int a[8] = {0, 1, 3, 9, 27, 81, 243, 729};
	int i, j, n, k;
	while(cin >> n && n != -1)
	{
		memset(ch, ' ', sizeof(ch));
		ch[1][1] = 'X';
		for(i=2; i<=n; i++)
		{
			int temp = a[i] * 2/3;
			for(j=1; j<=a[i]/3; j++)
			{	
				for(k=a[i]*2/3+1; k<=a[i]; k++)
				{
					ch[j][k] = ch[j][k-temp];
				}
			}
			int row = a[i]/3, col = a[i]/3;
			for(j=a[i]/3+1; j<=a[i]*2/3; j++)
			{
				for(k=a[i]/3+1; k<=a[i]*2/3; k++)
				{
					ch[j][k] = ch[j-row][k-col];
				}
			}
			temp = a[i]*2/3;
			for(j=a[i]*2/3+1; j<=a[i]; j++)
			{
				for(k=1; k<=a[i]/3; k++)
				{
					ch[j][k] = ch[j-temp][k];
				}
			}
			row = a[i]*2/3;
			col = a[i]*2/3;
			for(j=a[i]*2/3+1; j<=a[i]; j++)
			{
				for(k=a[i]*2/3+1; k<=a[i]; k++)
				{
					ch[j][k] = ch[j-row][k-col];
				}
			}
		}
		for(i=1; i<=(int)pow(3.0, (double)(n-1)); i++)
		{
			for(j=a[n]; ; j--)
			{
				if(ch[i][j] == 'X') break;
			}
			for(k=1; k<=j; k++)
			{
				cout << ch[i][k];
			}
			cout<<endl;
		}
		cout << "-" << endl;
	}
	return 0;
}