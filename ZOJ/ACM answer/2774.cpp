#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int cas;
	int i, j, k;
	int c;
	scanf("%d",&cas);
	for(i=1; i<=cas; i++)
	{
		scanf("%d", &c);
		string s1, s2, s3;
		deque <string> hello;
		getline(cin, s1);
		getline(cin, s1);
		getline(cin, s2);
		s1 += s2;
		hello.push_back(s1);
		getline(cin, s3);
		char s[206];
		int haha = 0;
		int count = 0;
		for(int index= 0; ; index++)
		{
			int te = 0;
			for(j=0, k=c; j<c; j++, k++)
			{
				s[te++] = hello[index][k];
				s[te++] = hello[index][j];
			}
			s[te++] = '\0';
			string temp(s);
			count++;
			if(temp == s3) break;
			for(j=1; j<hello.size(); j++)
			{
				if(hello[j] == temp) {haha= 1; break;}
			}
			if(haha) break;
			hello.push_back(temp);
		}
		if(haha) cout << i << " " << "-1" << endl;
		else cout << i << " " << count << endl;
	}
	return 0;
}