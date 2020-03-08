#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int a[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,79, 83, 89, 97,101};
	string s1, s2;
	int i;
	while(cin >> s1 >> s2)
	{
		vector <int> svec;
		vector <int> ivec;
		int temp = 0;
		for(i=0; i<s1.length(); i++)
		{
			if(s1[i]==',')
			{
				svec.push_back(temp);
				temp = 0;
			}
			else if(s1[i] >= '0' && s1[i] <= '9')
			{
				temp = temp * 10 + s1[i]-'0';
			}
		}
		svec.push_back(temp);
		temp = 0;
		for(i=0; i<s2.length(); i++)
		{
			if(s2[i]==',')
			{
				ivec.push_back(temp);
				temp = 0;
			}
			else if(s2[i] >= '0' && s2[i] <= '9')
			{
				temp = temp * 10 + s2[i]-'0';
			}
		}
		ivec.push_back(temp);
		reverse(svec.begin(), svec.end());
		reverse(ivec.begin(), ivec.end());
		int len1 = svec.size();
		int len2 = ivec.size();
		if(len1 < len2)
		{
			for(i=0; i<len2-len1; i++)
			{
				svec.push_back(0);
			}
		}
		else if(len1 > len2)
		{
			for(i=0; i<len1-len2; i++)
			{
				ivec.push_back(0);
			}
		}
		int carry = 0;
		vector <int> ans;
		int haha;
		for(i=0; i<ivec.size(); i++)
		{
			haha = svec[i] + ivec[i] + carry;
			if(haha >= a[i])
			{
				haha -= a[i];
				carry = 1;
			}
			else carry = 0;
			ans.push_back(haha);
		}
		if(carry) ans.push_back(carry);
		for(i=ans.size()-1; i>0; i--)
		{
			cout << ans[i] << ",";
		}
		cout << ans[0] << endl;
	}
	return 0;
}
