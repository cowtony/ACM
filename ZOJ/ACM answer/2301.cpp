#include <iostream>
#include <string>
using namespace std;

int w[20000][3];

int main()
{
	int i, j;
	int line;
	while(cin >> line)
	{
		int a, b;
		string str;
		int temp = 0;
		for(j=0; j<line; j++)
		{
			cin >> a >> b >> str;
			if( a>b)
			{
				int shit = a;
				a = b;
				b = shit;
			}
			if(str == "w")
			{
				bool flag = false;
				int t1 = 0;
				for(i=0; i<temp; i++)
				{
                    if(w[i][2] != 1) continue;
					t1 = 1;
					if(a >= w[i][0] && a <= w[i][1] + 1 && b >= w[i][1])
					{
						a = w[i][0];
						w[i][2] = 0;
						flag = true;
					}
					else if(b >= w[i][0]-1 && b <=w[i][1] && a <= w[i][0])
					{
						b = w[i][1];
						w[i][2] = 0;
						flag = true;
					}
					else if(a <= w[i][0] && b >= w[i][1])
					{
						a = w[i][0];
						b = w[i][1];
						w[i][2] = 0;
						flag = true;
					}
					if(a > w[i][1] || b < w[i][0])
					{
						flag = true;
					}
				}
				if(flag||!t1)
				{
					w[temp][0] = a;
					w[temp][1] = b;
					w[temp++][2] = 1;
				}
			}
			else if(str == "b")
			{
				int hell = temp;
				for(i=0; i<hell; i++)
				{
					if(w[i][2] != 1) continue;
					int left, right;
                    if(a <= w[i][0] && b >= w[i][1])
					{
						w[i][2] = 0;
					}
					else if(a <= w[i][0] && b >= w[i][0] && b < w[i][1])
					{
						left = b+1;
						right = w[i][1];
                        w[i][2] = 0;
                        w[temp][0] = left;
						w[temp][1] = right;
						w[temp][2] = 1;
						temp++;
					}
					else if(b >= w[i][1] && a <= w[i][1] && a > w[i][0])
					{
						left = w[i][0];
						right = a-1;
						w[i][2] = 0;
                        w[temp][0] = left;
						w[temp][1] = right;
						w[temp][2] = 1;
						temp++;
					}
					else if(a > w[i][0] && b < w[i][1])
					{
						left = w[i][0];
						right = a-1;
						int ha = b+1;
						int he = w[i][1];
                        w[i][2] = 0;
                        w[temp][0] = left;
						w[temp][1] = right;
						w[temp][2] = 1;
						temp++;
						w[temp][0] = ha;
						w[temp][1] = he;
						w[temp][2] = 1;
						temp++;
						
					}
				}
 			}
		}
		int ca = -1;
		int t = 0;
		int index;
		for(i=0; i<temp ; i++)
		{
			if(w[i][2]) t=1;
			else continue;
			if(w[i][1] - w[i][0]>ca)
			{
				ca = w[i][1] - w[i][0];
				index = i;
			}
		}
		if(!t) cout << "Oh, my god" << endl;
		else
		{
			cout << w[index][0] << " " << w[index][1] << endl;
		}
	}
	return 0;
}