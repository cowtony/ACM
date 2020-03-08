#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int cas;
	int i, j, n;
	char c;
	char buf[100];
	int hash[10000];
	string str;
	cin >> cas;
	while(scanf("%c",&c) && c != '\n');
	while(cas--)
	{
		gets(buf);
		cin >> n;
		while(scanf("%c", &c) && c != '\n');
		memset(hash, 0, sizeof(hash));
		while(n--)
		{
			cin >> str;
			if(str == "+")
			{
				int ai, bi, ci;
				cin >> ai >> bi >> ci;
				for(i=ai; i<=bi; i+=ci)
				{
					if(hash[i] != -1) hash[i] = 1;
				}
				while(scanf("%c",&c) && c != '\n');
			}
			else if(str == "-")
			{
				int ai, bi, ci;
				cin >> ai >> bi >> ci;
				for(i=ai; i<=bi; i+=ci)
				{
					hash[i] = -1;
				}
				while(scanf("%c",&c) && c != '\n');
			}
			else
			{
				int temp = 0;
				for(i=0; i<str.length(); i++)
				{
					temp = temp * 10 + (str[i]-'0');
				}
				if(hash[temp] != -1) hash[temp] = 1;
				while(scanf("%c",&c) && c != '\n');
			}
		}
		int a[10];
		int addre = 0;
		memset(a, 0, sizeof(a));
		for(i=1; i<10000; i++)
		{
			if(hash[i] == 1)
			{
				addre++;
				int temp = i;
				while(temp)
				{
					a[temp % 10] ++;
					temp /= 10;
				}
			}
		}
		cout << buf << endl;
		if(addre == 1) cout << "1 address" << endl;
		else cout << addre << " addresses" << endl;
		int ans = 0;
		for(i=0; i<10; i++)
		{
			cout << "Make " << a[i] <<" digit " << i << endl;
			ans += a[i];
		}
		cout << "In total " << ans;
		if(ans==1) cout << " digit" << endl;
		else cout << " digits" << endl;
	}
	return 0;
}