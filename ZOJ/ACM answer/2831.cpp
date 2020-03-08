#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s[10][8]=
	{" XXXX ", "XX  XX", "XX  XX", "XX  XX", "XX  XX", "XX  XX", "XX  XX", " XXXX ",
	 "  XX  ", "XXXX  ", "  XX  ", "  XX  ", "  XX  ", "  XX  ", "  XX  ", "XXXXXX",
	 " XXXX ", "XX  XX", "XX  XX", "    XX", "   XX ", "  XX  ", " XX   ", "XXXXXX",
	 " XXXX ", "X   XX", "    XX", "  XXX ", "    XX", "    XX", "X   XX", " XXXX ",
	 "   XX ", "  XXX ", "  XXX ", " X XX ", "X  XX ", "XXXXXX", "   XX ", " XXXXX",
	 " XXXXX", " XX   ", " XXXX ", " X  XX", "    XX", "    XX", "X   XX", " XXXX ",
	 "  XXXX", " XX   ", "XX    ", "XXXXX ", "XX  XX", "XX  XX", "XX  XX", " XXXX ",
	 "XXXXXX", "X   XX", "    XX", "   XX ", "   XX ", "   XX ", "  XX  ", "  XX  ",
	 " XXXX ", "XX  XX", "XX  XX", " XXXX ", "XX  XX", "XX  XX", "XX  XX", " XXXX ",
	 " XXXX ", "XX  XX", "XX  XX", "XX  XX", " XXXXX", "    XX", "   XX ", "XXXX  "};



bool vali(string str)
{
	for(int i=0; i<str.length(); i++)
	{
		if(str[i] == 'X')
			return true;
	}
	return false;
}


int main()
{
	int cas;
	cin >> cas;
	string str[8];
	while(cas--)
	{
		int in=0;
		string strinput;
		int len=10000000;
		while(in<8)
		{
			getline(cin, strinput);
			if(vali(strinput))
			{
				if(strinput.length() < len)
					len = strinput.length();
				str[in++]=strinput;
			}
		}
		int a=0, b=0;
		bool aorb=false;
		for(int col=0; col<len;)
		{
			bool flag=false;
			for(int row=0; row<8; row++)
			{
				if(str[row][col] == 'X')
				{
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				col++;
				continue;
			}
			bool found=false;
			for(int s_n=0; s_n<10; s_n++)
			{
				bool ff=false;
				for(int x1=0,r=0; x1<8; x1++, r++)
				{
					for(int y1=0, c=col; y1<6; y1++,c++)
					{
						if(c>=str[r].length())
							break;
						if(s[s_n][x1][y1] != str[r][c])
						{
							ff = true;
							break;
						}
					}
					if(ff)
						break;
				}
				if(!ff)
				{
					found = true;
					if(!aorb) a = a*10+s_n;
					else b=b*10+s_n;
					col += 6;
					break;
				}
			}
			if(!found)
			{
				col += 7;
				aorb = true;
				continue;
			}
		}
		int ans=a+b;
		vector <int> answer;
		do
		{
			answer.push_back(ans%10);
			ans/=10;
		}while(ans!=0);
		for(int ll=0; ll<8; ll++)
		{
			for(int kk=answer.size()-1; kk>=0; kk--)
			{
				cout << " ";
				cout << s[answer[kk]][ll];
				cout << " ";
			}
			cout << endl;
		}
		if(cas>0)
			cout << endl;

	}
	return 0;
}
