#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

struct node
{
	int occu;
	string str;
}p;

int main()
{
	vector <struct node> shsh;
	string s;
	int i, j;
	int count = 1;
	//freopen("sample.in", "r", stdin);
	while(cin >> s)
	{
		if(s.length() == 1)
		  if(s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z' || s[0] >= '0' && s[0] <= '9');
		  else continue;
        while(1)
		{
			int right = s.length() - 1;
			if( !(s[0] >= 'a' && s[0] <= 'z' || s[0] >= 'A' && s[0] <= 'Z'
				|| s[0] >= '0' && s[0] <= '9'))
				s.erase(0,1);
			else if( !(s[right] >= 'a' && s[right] <= 'z'
				|| s[right] >= 'A' && s[right] <= 'Z'
				|| s[right] >= '0' && s[right] <= '9'))
				s.erase(right, right+1);
			else break;
		}
		int t = 0;
		for(i=0; i<s.length(); i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] += 32;
			}
			if( !(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9'))
				t = 1;
		}
		if(!t)
		{
			int flag = 0;
			for(i=0; i<shsh.size(); i++)
			{
				if(shsh[i].str == s) {flag=1; break;}
			}
			if(!flag)
			{
				p.occu = 1;
				p.str = s;
				shsh.push_back(p);
			}
			else
			{
				shsh[i].occu ++;
				if(shsh[i].occu > count) count = shsh[i].occu;
			}
		}
        else
		{
			char s1[100];
			int index = 0;
			for(i=0; i<s.length(); i++)
			{
				if( (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') && i != s.length()-1)
					s1[index++] = s[i];
				else
				{
					if(i == s.length()-1) s1[index++] = s[i];
                    s1[index++] = '\0';
					index = 0;
					string thestr(s1);
					int flag = 0;
					for(j=0; j<shsh.size(); j++)
					{
						if(shsh[j].str == thestr) {flag=1; break;}
					}
					if(!flag)
					{
						p.occu = 1;
						p.str = thestr;
						shsh.push_back(p);
					}
					else
					{
						shsh[j].occu ++;
						if(shsh[j].occu > count) count = shsh[j].occu;
					}
				}
			}
		}
	}
	vector <string> hehe;
	for(i=0; i<shsh.size(); i++)
	{
		if(shsh[i].occu == count) hehe.push_back(shsh[i].str);
	}
	
	for(i=0; i<hehe.size(); i++)
	{
		for(j=i+1; j<hehe.size(); j++)
		{
			if(hehe[i] > hehe[j])
			{
				string dd = hehe[i];
				hehe[i] = hehe[j];
				hehe[j] = dd;
			}
		}
	}
	cout << count << " occurrences" << endl;
	for(i=0; i<hehe.size(); i++)
	{
		cout << hehe[i] << endl;
	}
	return 0;
}