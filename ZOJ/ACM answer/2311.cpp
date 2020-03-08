#include <iostream>
#include <string>
#include <deque>
using namespace std;
string s1[21] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
     "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
	 "seventeen", "eighteen", "nineteen", "twenty"};
string s2[7] = {"thirty", "forty", "fifty", "sixty",
"seventy", "eighty", "ninety"};

int main()
{
	string str;
	int i, j;
	int a, b, c;
	while(getline(cin, str))
	{
		if(str.length() == 0) break;
		a = b = c = 0;
		int index = 0, t = 0;
		char ch[20];
		deque <string> hello;
		for(i=0; i<str.length(); i++)
		{
			if(str[i] == ' ' && t==1)
			{
				ch[index++] = '\0';
				string temp(ch);
				hello.push_back(temp);
				t = 0;
				index = 0;
			}
			else if(str[i] != ' ')
			{
				t = 1;
				ch[index++] = str[i];
			}
		}
		if(t)
		{
			ch[index++] = '\0';
			string temp(ch);
			hello.push_back(temp);
		}
		int count = 0;
		for(i=0; i<hello.size(); i++)
		{
			if(hello[i] == "negative") cout << "-";
			for(j=0; j<21; j++)
			{
				if(s1[j] == hello[i])
				{
					count += j;
				}
			}
			for(j=0; j<7; j++)
			{
				if(s2[j] == hello[i])
				{
					count += (j+3) * 10;
				}
			}
			if(hello[i] == "hundred") count *= 100;
			if(hello[i] == "thousand")
			{
				b = count;
				count = 0;
			}
			if(hello[i] == "million")
			{
				a = count;
				count = 0;
			}
		}
		c = count;
		if(a)
		{
			printf("%d%03d%03d\n", a, b, c);
		}
		else if(b)
		{
			printf("%d%03d\n", b, c);
		}
		else printf("%d\n", c);
	}
	return 0;
}
//nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine