#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

struct node
{
	char s;
	int x, y;
}a[26];

int main()
{
	int points;
	int i, j, k, l;
	int cas = 0;
	while(cin >> points && points)
	{
		cas++;
		for(i=0; i<points; i++)
		{
			cin >> a[i].s >> a[i].x >> a[i].y;
		}
		for(i=0; i<points; i++)
		{
			for(j=i+1; j<points; j++)
			{
				if(a[i].x > a[j].x || (a[i].x == a[j].x && a[i].y < a[j].y))
				{
					struct node temp;
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
		deque <string> hello;
		for(i=0; i<points-3; i++)
		{
			for(j=i+1; j<points-2; j++)
			{
				if(a[i].x == a[j].x)
				{
					for(k=j+1; k<points-1; k++)
					{
						for(l=k+1; l<points; l++)
						{
							if(a[k].x == a[l].x && a[k].x != a[i].x && a[k].y == a[i].y && a[l].y == a[j].y)
							{
								char c[5];
								c[0] = a[i].s;
								c[1] = a[k].s;
								c[2] = a[l].s;
								c[3] = a[j].s;
								c[4] = '\0';
								string sh(c);
								hello.push_back(sh);
							}
						}
					}
				}
			}
		}
		sort(hello.begin(), hello.end());
		cout << "Point set " <<cas << ":";
		if(hello.empty()) cout << " No rectangles";
		else
		{
			cout << endl;
			int t = 0;
			for(i=0; i<hello.size(); i++)
			{
				if(i % 10 == 0 && t == 1)
				{
					cout << endl;
				}
				cout << " " << hello[i];
				t = 1;
			}
		}
		cout << endl;
	}
	return 0;
}
