#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int a[8889];
	bool flag[8889];
	int i, j;
	int cas;
	for(i=0; i<8889; i++)
	{
		a[i] = i + 1111;
	}
	cin >> cas;
	while(cas--)
	{
		int ini, pass;
		vector <int> svec;
		memset(flag,false,sizeof(flag));
		cin >> ini >> pass;
		if(ini == pass)
		{
			cout << "0" << endl;
			continue;
		}
		int num = 1;
		svec.push_back(ini);
		flag[ini-1111] = 1;
		int index = 0;
		int step = 0;
		int h = 0;
		while(1)
		{
			int add = 0;
			step++;
			int t = 0;
			for(i=0; i<num; i++)
			{
				int temp = svec[h++];
				int haha;
				for(j=3; j>=0; j--)
				{
					haha = temp;
					int zhon = temp % (int)pow(10.0, j+1) / (int)pow(10.0, j);
					if(zhon ==9)//1Î»¼Ó1
					{
						haha -= 8*(int)pow(10.0,(double)j);
					}
					else
					{
						haha += (int)pow(10.0, (double)j);
					}
					if(haha == pass) {t=1; break;}
					if(!flag[haha-1111])
					{
						flag[haha-1111] = 1;
						svec.push_back(haha);
						add++;
					}
					haha = temp;
					if(zhon ==1)//1Î»¼õ1
					{
						haha = temp + 8*(int)pow(10.0, (double)j);
					}
					else haha -= (int)pow(10.0, (double)j);
					if(haha == pass) {t=1; break;}
					if(!flag[haha-1111])
					{
						flag[haha-1111] = 1;
						svec.push_back(haha);
						add++;
					}

				}
				int a, b, c;
				a = temp / 1000;
				b = (temp % 1000) /100;
				c = temp % 100;
				haha = a * 100 + b * 1000 + c;
				if(haha == pass) {t=1; break;}
				if(!flag[haha-1111])
				{
					flag[haha-1111] = 1;
					svec.push_back(haha);
					add++;
				}
				a = temp / 1000;
				b = (temp % 1000) / 100;
				c = (temp % 100) / 10;
				haha = a * 1000 + b * 10 + c * 100 + temp % 10;
				if(haha == pass) {t=1; break;}
				if(!flag[haha-1111])
				{
					flag[haha-1111] = 1;
					svec.push_back(haha);
					add++;
				}

				a = temp / 100;
				b = (temp % 100) /10;
				c = temp % 10;
				haha = a * 100 + c * 10 + b;
				if(haha == pass) {t=1; break;}
				if(!flag[haha-1111])
				{
					flag[haha-1111] = 1;
					svec.push_back(haha);
					add++;
				}
			}
			if(t) break;
			num = add;
		}
		cout << step << endl;
	}
	return 0;
}