#include <iostream>
#include <string>
using namespace std;

int main()
{
	int row, col , h, w;
	char str[60][70];
	char fstr[60][70];
	//freopen("D:\\in.txt", "r", stdin);
	while(scanf("%d%d%d%d", &row, &col, &h, &w) != EOF)
	{
		for(int i=0; i<row; i++)
			scanf("%s", str[i]);
		for(int i=0; i<h; i++)
			scanf("%s", fstr[i]);
		int a[3600][3];
		int indexx=0;
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				if(fstr[i][j] == 'X')
				{
					a[indexx][0] = i;
					a[indexx][1] = j;
					a[indexx][2] = 0;
					indexx++;
				}
				if(fstr[i][j] == 'O')
				{
					a[indexx][0] = i;
					a[indexx][1] = j;
					a[indexx][2] = 1;
					indexx++;
				}
			}
		}
		int ans=0;
		for(int i=0; i<=row-h; i++)
		{
			for(int j=0; j<=col-w; j++)
			{
				bool flag=false;
				for(int k=0; k<indexx; k++)
				{
					if(a[k][2] == 0)
					{
						if(str[i+a[k][0]][j+a[k][1]] != 'X')
						{
							flag = true;
							break;
						}
					}
					else
					{
						if(str[i+a[k][0]][j+a[k][1]] != 'O')
						{
							flag = true;
							break;
						}
					}
				}
				if(!flag)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
