//#include <iostream>
//#include <string>
//using namespace std;
//#include <stdio.h>

int pre[3001], now[3001];

int main()
{
	int n, sum = 0, i, j, k, deta = 0, total;
    while (scanf("%d",&n)!=EOF)
	{
		sum = 0;
		total = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			scanf("%d",&now[j]);
		deta = 0;
		for (j=0; j<n; j++)
		{
			if (i == 0)
			{
				if (now[j] == 0 && (j == 0 || j > 0 && now[j - 1] == 1))
				{
					total ++;
					sum ++;
					now[j] = total + 1;
				}
				else if (now[j] == 0 && j > 0 && now[j - 1] != 1)
						now[j] = total + 1;
			}
			else if (i != 0)
			{
				if (now[j] == 0)
				{
					if ((j == 0 || j > 0 && now[j - 1] == 1) && pre[j] == 1)
					{
						total ++;
						sum ++;
						now[j] = total + 1;
					}
					else if ((j == 0 || j > 0 && now[j - 1] == 1) && pre[j] != 1)
						now[j] = pre[j];
					else if (now[j - 1] != 1 && pre[j] == 1)
						now[j] = now[j - 1];
					else if (now[j - 1] != 1 && pre[j] != 1)
					{
						if (now[j - 1] == pre[j])
							now[j] = pre[j];
						else if (now[j - 1] > pre[j])
						{
							sum --;
							now[j] = pre[j];
							for (k=0; k<j; k++)
								if (now[k] == now[j - 1])
									now[k] = now[j];
						}
					
						else
						{
							sum --;
							now[j] = now[j - 1];
							for (k=n - 1; k>=j; k--)
								if (pre[k] == pre[j])
									pre[k] = now[j];
						}
					}
				}
			}
		}
	
		for (j=0; j<n; j++)
			pre[j] = now[j];
	}
    printf("%d\n",sum);
	}
}
//--------------------------------------------------------
/*					else if (j > 0)
					{
						if (now[j - 1] == 1)
						{
							if (pre[j] != 1)
								now[j] = pre[j];
							else
							{
								sum ++;
								now[j] = sum + 1;
							}
						}
						else if (now[j - 1] != 1)
						{
							now[j] = now[j - 1];
							if (now[j] > pre[j] && pre[j] != 1)
							{
								for (k=j; k>=0; k--)
								{
									if (now[k] != 1)
										now[k] = pre[j];
									if (now[k] == 1)
										break;
								}
									sum --;
							}
							else if (now[j] < pre[j] && pre[j] != 1 && pre[j] - now[j] > deta)
							{
								deta = pre[j] - now[j];
								int temp = pre[j];
								for (k=0; k<n; k++)
									if (pre[k] == temp)
										pre[k] = now[j];
								sum --;
							}
						}
					}
				}
			}
		}
		for (k=0; k<n; k++)
			pre[k] = now[k];
	}
*/	//cout << sum << endl;

