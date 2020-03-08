#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int i, j;
	int cas;
	int left1, left2, right1, right2;
	cin >> cas;
	while(cas--)
	{
		cin >> str;
		left1 = 0;
		left2 = 0;
		right1 = 0;
		right2 = 0;
		int temp = 0;
		int num = 0;
		int flag = 0;//表常数
		int fuhao = 0;//表正
		while(str[temp] != '=')
		{
			if(str[temp] == '-' || str[temp] == '+')
			{
				if(!fuhao)
				{
					if(flag)
					{
						left2 += num;
					}
					else
					{
						left1 += num;
					}
				}
				else
				{
					if(flag)
					{
						left2 -= num;
					}
					else
					{
						left1 -= num;
					}
				}
				num = 0;
				if(str[temp] == '-') fuhao = 1;
				else if(str[temp] == '+') fuhao = 0;
				flag = 0;
			}
			else if(str[temp] >= '0' && str[temp] <= '9')
			{
				num = num * 10 + (str[temp]-'0');
			}
			else if(str[temp] == 'x')
			{
				flag = 1;
				if(!num)
				{
					num = 1;
				} 
			}
			temp++;
		}
		temp++;
		if(!fuhao)
		{
			if(flag)
			{
				left2 += num;
			}
			else
			{
				left1 += num;
			}
		}
		else
		{
			if(flag)
			{
				left2 -= num;
			}
			else
			{
				left1 -= num;
			}
		}
		num = 0;
		fuhao = 0;
		flag = 0;
		while(temp < str.length())
		{
			if(str[temp] == '-' || str[temp] == '+')
			{
				if(!fuhao)
				{
					if(flag)
					{
						right2 += num;
					}
					else
					{
						right1 += num;
					}
				}
				else
				{
					if(flag)
					{
						right2 -= num;
					}
					else
					{
						right1 -= num;
					}
				}
				num = 0;
				if(str[temp] == '-') fuhao = 1;
				else if(str[temp] == '+') fuhao = 0;
				flag = 0;
			}
			else if(str[temp] >= '0' && str[temp] <= '9')
			{
				num = num * 10 + (str[temp]-'0');
			}
			else if(str[temp] == 'x')
			{
				flag = 1;
				if(!num)
				{
					num = 1;
				}
			}
			temp++;
		}
		if(!fuhao)
		{
			if(flag)
			{
				right2 += num;
			}
			else
			{
				right1 += num;
			}
		}
		else
		{
			if(flag)
			{
				right2 -= num;
			}
			else
			{
				right1 -= num;
			}
		}
		if(left1 == right1 && left2 == right2)
		{
			cout << "IDENTITY" << endl;
		}
		else if(left2 == right2)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			double ans = (double)(left1 - right1) / (double)(right2 - left2);
			if(ans<0 && (left1-right1)%(right2-left2) != 0)
			{
				cout << (left1-right1)/(right2-left2)-1 << endl;
			}
			else cout << (left1-right1)/(right2-left2) << endl;
		}
	}
	return 0;
}