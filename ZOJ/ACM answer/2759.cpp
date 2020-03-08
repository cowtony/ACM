#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int temp[19][2];
	int i, n;
	int count = 0;
	for(i=0; i<19; i++)
	{
		temp[i][0] = (int)pow((double)3,(double)i);
		count = temp[i][0] + count;
		temp[i][1] = count;
	}
	while( cin >> n)
	{
		vector <int> left, right;
		bool flag = true;
		while(n)
		{
			for(i=0; i<19; i++)
			{
				if(temp[i][1] >= n) break;
			}
			if(flag)
			{
				right.push_back(temp[i][0]);
				n = n - temp[i][0];
				if(n < 0)
				{
					n = - n;
					flag = false;
				}
			}
			else
			{
				left.push_back(temp[i][0]);
				n = n - temp [i][0];
				if(n < 0)
				{
					n = -n;
					flag = true;
				}
			}
		}
		if(left.empty()) cout << "-1" << endl;
		else 
		{
			for(i=left.size()-1; i>0; i--)
			{
				cout << left[i] << " ";
			}
			cout << left[0] << endl;
		}
		if(right.empty()) cout << "-1" << endl;
		else 
		{
			for(i=right.size()-1; i>0; i--)
			{
				cout << right[i] << " ";
			}
			cout << right[0] << endl;
		}
		cout << endl;
	}
	return 0;
}
