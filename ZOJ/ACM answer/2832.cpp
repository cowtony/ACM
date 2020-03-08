#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

bool flag[105][105];
int num;
deque <string> ans;
deque <string> all_header;

void proce(deque <string> &all_header)
{
	bool ff[105];
	memset(ff, false, sizeof(ff));
	for(int i=0; i<num; i++)
	{
		if(ff[i])
			continue;
		deque <int> pare;
		pare.push_back(i);
		ff[i] = true;
		while(!pare.empty())
		{
			int do_it=pare.front();
			pare.pop_front();
			deque <int> son;
			son.push_back(do_it);
			while(!son.empty())
			{
				int findson=son.front();
				son.pop_front();
				for(int col=0; col<num; col++)
				{
					if(flag[findson][col]==true && ff[col] == false)
					{
						son.push_back(col);
						ff[col] = true;
					}
				}
			}
			bool foundpar = false;
			for(int row=0; row<num; row++)
			{
				if(flag[row][do_it] == true)
				{
					foundpar = true;//好阴险，，把这句加到下面的循环去了!!!
				}
				if(flag[row][do_it]==true&&ff[row] == false)
				{
					pare.push_back(row);
					ff[row] = true;
				}
			}
			if(!foundpar)
				ans.push_back(all_header[do_it]);
		}
	}
	sort(ans.begin(), ans.end());
}

int main()
{
	int p=0;
	while(cin >> num)
	{
		if(p==0)
			p=1;
		else printf("\n");
		memset(flag, false, sizeof(flag));
		string strheader;
		all_header.erase(all_header.begin(), all_header.end());
		deque <deque <string> > push;
		for(int i=0; i<num; i++)
		{
			cin >> strheader;
			all_header.push_back(strheader);
			int includefile;
			cin >> includefile;
			deque <string> temp;
			for(int j=0; j<includefile; j++)
			{
				cin >> strheader;
				temp.push_back(strheader);
			}
			push.push_back(temp);
		}
		for(int i=0; i<num; i++)
		{
			for(int j=0; j<push[i].size(); j++)
			{
				bool vali=false;
				int ind;
				for(int k=0; k<num; k++)
				{
					if(all_header[k] == push[i][j])
					{
						vali = true;
						ind = k;
						break;
					}
				}
				if(vali)
					flag[i][ind] = true;
			}
		}
		ans.erase(ans.begin(), ans.end());
		proce(all_header);
		for(int i=0; i<ans.size(); i++)
		{
			cout << ans[i] << endl;
		}

	}
	return 0;
}

