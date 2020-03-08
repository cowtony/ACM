#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int n , m;
struct name_define
{
	short type;
	char left , right;
	short int len , list[40];	
} list[26];

int mark[26];

void path(char k , unsigned int lab)
{
	if(list[k].type == 0)
	{
		memset(mark , 0 , sizeof(mark));
		if(lab % 2 == 0) path(list[k].left , lab / 2);
		else path(list[k].right , lab / 2);
	}
	else
	{
		if(mark[k] && lab + lab >= mark[k]) lab = lab % (mark[k] - lab);
		mark[k] = lab;

		if(lab < list[k].len) cout << list[k].list[lab];
		else path(list[k].left , lab - list[k].len);
	}
}

void work()
{
	string buf;	
	
	cin >> n >> m;
	getline(cin , buf);

	char ch , op , ch1 , ch2;

	while(n--)
	{
		getline(cin , buf);
		stringstream strin(buf);

		strin >> ch >> op;
		ch -= 'A';
		while(strin.peek() == ' ') strin.get();
		if(strin.peek() == 'z')
		{
			strin >> buf;
			strin >> ch1 >> ch2;
			list[ch].type = 0;
			list[ch].left = ch1 - 'A';
			list[ch].right = ch2 - 'A';
		}
		else
		{
			list[ch].type = 1;
			list[ch].len = 0;
			while(1)
			{
				while(strin.peek() == ' ') strin.get();
				ch1 = strin.peek();
				if(ch1 <= 'Z' && ch1 >= 'A')
				{
					list[ch].left = ch1 - 'A';
					break;
				}
				strin >> list[ch].list[list[ch].len++];
			}
		}
	}

	unsigned int st , ed;

	while(m--)
	{
		
		cin >> ch >> st >> ed;
		ch -= 'A';
		
		for(; st<=ed; st++)
		{
			memset(mark , 0 , sizeof(mark));
			path(ch , st);
			if(st != ed) cout << " ";
		}
		cout << endl;
	}	
}

int main()
{
//	freopen("in.txt" , "r" , stdin);
	int T , t;

	cin >> T;
	for(t=0; t<T; t++)
	{
		if(t) cout << endl;
		work();
	}
	
	return 0;
}
