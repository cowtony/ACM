#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int num;
	int i,j;
	while(getline(cin,s)&&s!="00e0")
	{
		num=0;
		num+=(10*(s[0]-'0')+(s[1]-'0'));
		int tal=s[3]-'0';
		while(tal--)
		{
			num*=10;
		}
		int temp=1;
		while(num>temp)
		{
			num-=temp;
			temp*=2;
		}
		cout<<1+(num-1)*2<<endl;
	}
	return 0;
}
