#include <iostream>
#include <string>
#include <deque>
using namespace std;

struct node
{
	string name;
	deque <int> lower;
	deque <int> upper;
	int base, size, D;
}p;


int total(int index, deque <struct node> hello, deque <int> kitty)
{
	int i, j;
	int ans = 0;
	for(i=0; i<hello[index].lower.size(); i++)
	{
		ans += (kitty[i] - hello[index].lower[i]);
		if(i < hello[index].lower.size() - 1) ans *= (hello[index].upper[i+1] - hello[index].lower[i+1] + 1);
	}
	return ans;
}


int main()
{
	int N,R;
	string str;
	int base,D;
	int size;
	int i, j;
	int low,up, nk;
	int tota;
	while(cin >> N >> R)
	{
		deque <struct node> hello;
		for(i=0; i<N; i++)
		{
			cin >> p.name >> p.base >> p.size >> p.D;
			p.lower.erase(p.lower.begin(), p.lower.end());
			p.upper.erase(p.upper.begin(), p.upper.end());
			for(j=0; j<p.D; j++)
			{
				cin >> low >> up;
				p.lower.push_back(low);
				p.upper.push_back(up);
			}
			hello.push_back(p);
		}
		for(i=0; i<R; i++)
		{
			cin >> str;
			int index;
			for(j=0; j<hello.size(); j++)
			{
				if(str==hello[j].name)
				{
					index = j;
					break;
				}
			}
			deque <int> kitty;
			for(j=0; j<hello[index].lower.size(); j++)
			{
				cin >> nk;
				kitty.push_back(nk);
			}
			int tota = total(index, hello, kitty);
			int ans = tota * hello[index].size + hello[index].base;
			cout << str << "[";
			for(j=0; j<kitty.size(); j++)
			{
				if(j<kitty.size()-1) cout << kitty[j] << ", ";
				else cout << kitty[j] << "] = " << ans << endl;
			}
		}
	}
	return 0;
}