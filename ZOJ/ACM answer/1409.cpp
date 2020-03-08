#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Communication
{
	double band;
	double price;
};

int main()
{
	int cas;
	//freopen("D:\\C.IN", "r", stdin);
	//freopen("D:\\c.txt","w",stdout);
	cin >> cas;
	while(cas--)
	{
		int n;
		vector <Communication> com[100];
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int mi;
			cin >> mi;
			for(int j=0; j<mi; j++)
			{
				Communication temp;
				cin >> temp.band >> temp.price;
				com[i].push_back(temp);
			}
		}
		double ans = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<com[i].size(); j++)
			{
				double min = com[i][j].band;
				double price=0;
				int count = 0;
				for(int k=0; k<n; k++)
				{
					double tempprice = 10000000000.0;
					bool flag = false;
					for(int l=0; l<com[k].size(); l++)
					{						
						if(com[k][l].band - min > -1e-6)
						{
							flag = true;
							if(com[k][l].price < tempprice)
							{
								tempprice = com[k][l].price;
							}	
						}
					}
					if(flag == true)
						count++;
					price += tempprice;
				}
				if(count == n)
				{
					if(min/price > ans)
						ans = min/price;
				}
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}

