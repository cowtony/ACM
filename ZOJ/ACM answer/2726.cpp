#include <iostream>
#include <vector>
#include <string>
using namespace std;

int temp[12];
int str[12][2];

int gcd(int n, int m)
{
	if(n%m == 0) return m;
	else return gcd(m, n-m);
}

void init()
{
	str[0][0] = 320;
	str[0][1] = 420;
	str[1][0] = 421;
	str[1][1] = 521;
	str[2][0] = 522; 
	str[2][1] = 622;
	str[3][0] = 623;
	str[3][1] = 722;
	str[4][0] = 723;
	str[4][1] = 822;
	str[5][0] = 823;
	str[5][1] = 922;
	str[6][0] = 923;
	str[6][1] = 1022;
	str[7][0] = 1023;
	str[7][1] = 1122;
	str[8][0] = 1123;
	str[8][1] = 1222;
	str[9][0] = 1223;
	str[9][1] = 121;
	str[10][0] = 122;
	str[10][1] = 220;
	str[11][0] = 221;
	str[11][1] = 319;
}

int index(string st)
{
	if(st == "January") return 100;
	if(st == "February") return 200;
	if(st == "March") return 300;
	if(st == "April") return 400;
	if(st == "May") return 500;
	if(st == "June") return 600;
	if(st == "July") return 700;
	if(st == "August") return 800;
	if(st == "September") return 900;
	if(st == "October") return 1000;
	if(st == "November") return 1100;
	if(st == "December") return 1200;
}

int main()
{
	int n;
	int i, j;
	string month;
	int date;
	int t;
	init();
	while(cin >> n && n)
	{
		memset(temp, 0, sizeof(temp));
		for(i=0; i<n; i++)
		{
			cin >> month >> date;
			int inde;
			inde = index(month) + date;
			t = 0;
			for(j=0; j<12; j++)
			{
				if(inde >= str[j][0] && inde <= str[j][1])
				{
					t = 1;
					break;
				}
			}
			if(!t) j=9;
			temp[j]++;
		}
		for(i=0; i<12; i++)
		{
			if(temp[i]) break;
		}
		int m = temp[i];
		for(j=i+1; j<12; j++)
		{
			if(temp[j])
			{
				if(temp[j] > m) m = gcd(temp[j], m);
				else m = gcd(m, temp[j]);
			}
		}
		int large = 0;
		for(i=0; i<12; i++)
		{
			if(large <temp[i]) large = temp[i];
		}
		large = large / m;
		for(i = large; i>=0; i--)
		{
			int count = 0;
			for(j=0; j<12; j++)
			{
				if(temp[j] / m >= i && temp[j]) count++;
			}
			for(j=0; j<12; j++)
			{
				if(temp[j] / m == i && temp[j])
				{
					count--;
					if(count == 0) {printf(" %2d\n", temp[j]); break;}
					else printf(" %2d ", temp[j]);
				}
				else if(temp[j] / m >i)
				{
					count--;
					if(count == 0) {printf(" XX\n");  break;}
					else printf(" XX ");
				}
				else printf("    ");
			}
		}
		printf("------------------------------------------------\n");
		printf(" Ar  Ta  Ge  Ca  Le  Vi  Li  Sc  Sa  Ca  Aq  Pi\n\n");
	}
	return 0;
}