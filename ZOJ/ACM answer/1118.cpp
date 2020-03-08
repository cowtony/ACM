#include <iostream>
#include <deque>
using namespace std;


struct node
{
	bool flag;
	deque <int> inside;
};

int main()
{
	int n;
	int cas=1;
	while(cin >> n && n)
	{
		deque <int> start;
		deque <int> end;
		int a;
		for(int i=0; i<2*n; i++)
		{
			cin >> a;
			if(i<n) start.push_back(a);
			else end.push_back(a);
		}
		deque <node> ver[2];
		while(1)
		{
			node temp1,temp2;
			temp1.flag=false;
			temp2.flag=false;
			int a;
			cin >> a;
			if(a==-1)
				break;
			temp1.inside.push_back(a);
			for(int i=0; i<2*n-1; i++)
			{
				cin >> a;
				if(i<n-1)
					temp1.inside.push_back(a);
				else temp2.inside.push_back(a);
			}
			if(temp1.inside == start)
				temp1.flag = true;
			if(temp2.inside == start)
				temp2.flag = true;
			ver[0].push_back(temp1);
			ver[1].push_back(temp2);
		}

		deque <deque<int> > out;
		out.push_back(start);
		bool flag = false;
		while(!out.empty())
		{
			deque <int> temp;
			temp = out.front();
			out.pop_front();
			for(int i=0; i<ver[0].size(); i++)
			{
				if(ver[0][i].inside == temp)
				{
					if(ver[1][i].flag == false)
					{
						if(ver[1][i].inside == end)
						{
							flag = true;
							break;
						}
						ver[1][i].flag =true;
						out.push_back(ver[1][i].inside);
					}
				}
				if(ver[1][i].inside == temp)
				{
					if(ver[0][i].flag = false)
					{
						if(ver[0][i].inside == end)
						{
							flag = true;
							break;
						}
						ver[0][i].flag = true;
						out.push_back(ver[0][i].inside);
					}
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout << "Maze #" << cas++ << " can be travelled" << endl;
		else
			cout << "Maze #" << cas++ << " cannot be travelled" << endl;

	}
	return 0;
}