#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct command
{
	char type;
	char op;
	char len;
	char list[30];
	char stat;
};
struct processor
{
	bool app;
	int k;
	command c[110];
	int p;
	int done;
} list[30];

int n;

string buf;

void read_command(command& a)
{
	getline(cin , buf);
	stringstream strin(buf);

	cin >> a.type >> a.op;
	a.len = 0;
	while(cin >> a.list[a.len])
	{
		a.list[a.len] -= 'A';
		a.len ++;
	}
	a.stat = a.len;
}

void init()
{
	cin >> n;

	memset(list , 0 , sizeof(list));
	char ch;
	int i , j;

	for(i=0; i<n; i++)
	{
		cin >> ch;
		ch -= 'A';
		list[ch].app = 1;
		
		cin >> list[ch].k;
		getline(cin , buf);
		for(j=0; j<n; j++)
		{
			read_command(list[ch].c[j]);
		}
		list[ch].p = 0;
		list[ch].done = -1;
	}	
}

void solve()
{
	int Time;
	for(Time=1; Time; Time++)
	{
	}

	for(i=0; i<26; i++)
		if(list[i].app)
		{
			
		}
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	int t , T;

	cin >> T;
	for(t=0; t<T; t++)
	{
		if(t) cout << endl;
		init();
		solve();
	}
	
	return 0;
}
