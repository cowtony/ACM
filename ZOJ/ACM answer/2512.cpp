#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int i, j, k, l;
	while(cin >> str)
	{
		int len = str.length();
		int flag = 0;
		for(i=0; i<len; i++)
		{
			j = (i-1+len)%len;
			k = (i+1)%len;
			int t = 0;
			for(l=0; l<len/2; l++)
			{
				if(str[j] != str[k]) {t=1; break;}
				j = (j-1+len)%len;
				k = (k+1)%len;
			}
			if(t==0) { cout << "Symmetric" << endl; cout << i+1 << endl; flag = 1; break;;}
			j = i;
			k = (i+1)%len;
			t = 0;
			for(l=0; l<len/2; l++)
			{
				if(str[j] != str[k]) {t=1; break;}
				j = (j-1+len)%len;
				k = (k+1)%len;
				
			}
			if(t==0) {cout << "Symmetric" << endl; cout << i+1 << "-" << (i+2)%(len+1) << endl; flag = 1; break;}
		}
		if(flag == 0)
			cout << "Not symmetric" << endl;
	}
	return 0;
}