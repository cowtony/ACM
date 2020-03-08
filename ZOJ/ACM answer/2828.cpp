#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int cas;
	cin >> cas;
	while(cas--)
	{
		int n;
		string str;
		vector <string> dic;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			cin >> str;
			dic.push_back(str);
		}
		int num;
		cin >> num;
		for(int i=0; i<num; i++)
		{
			cin >> str;
			vector <string> out;
			if(find(dic.begin(), dic.end(), str) != dic.end())
				out.push_back(str);
			if(out.empty())
			{
				for(int j=0; j<str.length()-1; j++)
				{
					string ss(str);
					swap(ss[j], ss[j+1]);
					if(find(dic.begin(), dic.end(), ss) != dic.end())
						out.push_back(ss);
				}
				sort(out.begin(), out.end());
			}
			if(out.empty())
			{
				out.push_back(str);
			}
			cout << out[0];
			for(int j=1; j<out.size(); j++)
			{
				cout << "," << out[j];
			}
			cout << endl;
		}
		if(cas>0)
			cout << endl;
	}
	return 0;
}