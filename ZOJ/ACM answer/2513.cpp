#include <iostream>
#include <string>
#include <deque>
using namespace std;

struct node
{
	string team;
	int solve;
	string str;
	int time;
};

int main()
{
	node hello[3000];
	int i, j, k;
	int n, m, tn;
	int forget;
	int p=0;
	while(cin >> n >> m)
	{
		int index = 0;
		if(p==0) p = 1;
		else cout << endl;
		for(i=0; i<n; i++)
		{
			cin >> tn;
			for(j=0; j<tn; j++)
			{
				cin >> forget;
				cin >> hello[index].team;
				cin >> hello[index].solve;
				getline(cin, hello[index].str);
				for(k=hello[index].str.length()-1; k>=0; k--)
				{
					if(hello[index].str[k] != ' ') break;
				}
				hello[index].time = ((hello[index].str[k-7] - '0') * 10 + hello[index].str[k-6] - '0')*3600 + 
					((hello[index].str[k-4] - '0') * 10 + (hello[index].str[k-3] - '0')) * 60 + (hello[index].str[k-1] - '0') * 10 + 
					(hello[index].str[k] - '0');
				index++;
			}
		}
		for(i=0; i<index; i++)
		{
			for(j=i+1; j<index; j++)
			{
				if(hello[i].solve < hello[j].solve)
				{
					node kitty;
					kitty = hello[i];
					hello[i] = hello[j];
					hello[j] = kitty;
				}
				else if(hello[i].solve == hello[j].solve && hello[i].time > hello[j].time)
				{
					node kitty;
					kitty = hello[i];
					hello[i] = hello[j];
					hello[j] = kitty;
				}
				else if(hello[i].solve == hello[j].solve && hello[i].time == hello[j].time && 
					hello[i].team > hello[j].team)
				{
					node kitty;
					kitty = hello[i];
					hello[i] = hello[j];
					hello[j] = kitty;
				}
			}
		}
		int rank = 1;
		deque <int> sol;
		deque <int> kill;
		for(i=0; i<index; i++)
		{
			if(hello[i].solve)
			{
				int tt = 0;
				for(j=0; j<sol.size(); j++)
				{
					if(sol[j] == hello[i].solve) {tt=1; break;}
				}
				if(tt)
					kill[j] ++;
				else
				{
					sol.push_back(hello[i].solve);
					kill.push_back(1);
				}
			}
			if(i==0)
			{
				cout << 1 << " " << hello[i].team << " " << hello[i].solve << hello[i].str << endl;
			}
			else
			{
				if(hello[i].solve == hello[i-1].solve && hello[i].time == hello[i-1].time)
				{
					cout << rank << " " << hello[i].team << " " << hello[i].solve << hello[i].str << endl;
				}
				else
				{
					rank++;
					cout << rank << " " << hello[i].team << " " << hello[i].solve << hello[i].str << endl;
				}
			}
		}
		cout << "Total Teams: " << index;
		if(sol.size() == 0) {cout << "." << endl; continue;}
		cout << "; ";
		for(i=0; i<sol.size(); i++)
		{
			cout << "Solved " << sol[i] << ": " << kill[i];
			if(i<sol.size()-1) cout << "; ";
			else cout << "." << endl;
		}
	}
	return 0;
}