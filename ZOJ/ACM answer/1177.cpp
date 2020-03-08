//数据太少太弱了
#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int num;
	int i, j;
	int cas;
	cin >> cas;
	while(cas--)
	{
		cin >> num;
		deque <int> deq[10];
		for(i=1; i<10; i++)
		{
			deq[i].push_back(i);
			int carry = 0;
			for(j=0; j<=100000; j++)
			{
				carry = deq[i][j] * num + carry;
				int f = carry % 10;
				deq[i].push_back(f);
				carry /= 10;
				if(carry == 0 && f == i) break;
			}
		}
		deque <int> temp(99999,0);
		for(i=1; i<10; i++)
		{
			if(deq[i].size() < temp.size())  temp= deq[i];
			else if(deq[i].size() == temp.size() && deq[i] < temp)
			{
				temp = deq[i];
			}
		}
		for(i=temp.size()-1; i>0; i--)
		{
			cout << temp[i];
		}
		cout << endl;
		if(cas) cout << endl;
	}
	return 0;
}