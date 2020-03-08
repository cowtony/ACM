#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int calculator(char ch)
{
	if(ch>='0' && ch<='9')
		return ch - '0';
	if(ch=='A')
		return 10;
	if(ch=='B')
		return 11;
	if(ch=='C')
		return 12;
	if(ch=='D')
		return 13;
	if(ch=='E')
		return 14;
	if(ch=='F')
		return 15;
}

char write(int i)
{
	if(i==10)
		return 'A';
	if(i==11)
		return 'B';
	if(i==12)
		return 'C';
	if(i==13)
		return 'D';
	if(i==14)
		return 'E';
	if(i==15)
		return 'F';
	return i+'0';
}

int main()
{
	string stemp;
	while(cin >> stemp)
	{
		string str;
		str += stemp;
		while(str.length() < 256)
		{
			cin >> stemp;
			str+= stemp;
		}
		int index=0;
		int a, b;
		if(str[0] == '8')
			return 0;
		while(str[index] != '8')
		{
			if(str[index] == '0')
			{
				int num=0;
				num = calculator(str[index+1]) * 16 + calculator(str[index+2]);
				a = calculator(str[num]);
				index += 3;
				continue;
			}
			if(str[index] == '1')
			{
				int num=0;
				num = calculator(str[index+1]) * 16 + calculator(str[index+2]);
				str[num] = write(a);
				index+=3;
				continue;
			}
			if(str[index] == '2')
			{
				swap(a, b);
				index++;
				continue;
			}
			if(str[index] == '3')
			{
				int sum = a+b;
				a=sum%16;
				b=sum/16;
				index++;
				continue;
			}
			if(str[index] == '4')
			{
				if(a==15)
					a=0;
				else a++;
				index++;
				continue;
			}
			if(str[index] == '5')
			{
				if(a==0)
					a=15;
				else a--;
				index++;
				continue;
			}
			if(str[index] == '6')
			{
				if(a==0)
				{
					int num=0;
					num = calculator(str[index+1]) * 16 + calculator(str[index+2]);
					index = num;
					continue;
				}
				else
				{
					index+=3;
					continue;
				}
			}
			if(str[index] == '7')
			{
				int num=0;
				num = calculator(str[index+1]) * 16 + calculator(str[index+2]);
				index = num;
				continue;
			}
		}
		for(int i=0; i<str.length(); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}