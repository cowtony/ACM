#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	int num;
	int i, j;
	while(getline(cin, str))
	{
		num = 1;
		while(1)
		{
			if(str[0] != ' ') break;
			str.erase(str.begin(), str.begin()+1);
		}
		while(1)
		{
			if(str[str.length()-1] != ' ') break;
			str.erase(str.end()-1, str.end());
		}
		if(str == "0") break;
		int t = 0;
		int left = 0, right = 0;
		for(i=0; i<str.length(); i++)
		{
			if(str[i] == ' ')
			{
				if(t==0) t=1;
				else
				{
					num *= (int)pow((double)left, (double)right);
					left = right = 0;
					t = 0;
				}
			}
			else if(t==0) 
			{
				left = left * 10 + (str[i] - '0');
			}
			else
			{
				right = right * 10 + (str[i] - '0');
			}
		}
		num *= (int)pow((double)left, (double)right);
		num--;
		int sem[100][2];
		memset(sem, 0, sizeof(sem));
		int index = 0;
		while(1)
		{
			int prim = 0;
			for(i=2; i<=(int)sqrt((double)num); i++)
			{
				if(num % i == 0)
				{
					prim = 1;
					int flag = 0;
					for(j=0; j<100; j++)
					{
						if(sem[j][0] == i)
						{
							sem[j][1]++;
							num /= i;
							flag = 1;
							break;
						}
						if(!sem[j][0]) break;
					}
					if(!flag) {sem[index][0] = i; sem[index++][1] = 1; num  /= i;}
					break;
				}
			}
			if(prim == 0) break;
		}
		if(num>1)
		{
			int p = 0;
			for(i=0; i<100; i++)
			{
				if(sem[i][0] == num)
				{
					sem[i][1] ++;
					p = 1;
					break;
				}
			}
			if(!p)
			{
				sem[index][0] = num;
				sem[index++][1] = 1;
			}
		}
		for(i=index-1; i>=0; i--)
		{
			if(i != 0)
			{
				cout << sem[i][0] << " " << sem[i][1] << " ";
			}
			else cout << sem[i][0] << " " << sem[i][1] << endl;
		}
	}
	return 0;
}