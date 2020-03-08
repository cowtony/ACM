#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;


void program(int n)
{
	deque <int> speed;
	int unispeed;
	int total(0);
	while(n--)
	{
		cin >> unispeed;
		speed.push_back(unispeed);
	}
	sort(speed.begin(), speed.end());
	if(speed.size() == 1)
	{
		cout << speed[0] << endl;
		cout << speed[0] << endl;
		return;
	}
	else if(speed.size() == 2)
	{
		cout << speed[1] << endl;
		cout << speed[0] << " " << speed[1] << endl;
		return;
	}
	else if(speed.size() == 3)
	{
		cout << speed[0] + speed[1] + speed[2] << endl;
		cout << speed[0] << " " << speed[1] << endl;
		cout << speed[0] << endl;
		cout << speed[0] << " " << speed[2] << endl;
		return;
	}
	else
	{
		int lea1 = speed.front();
		speed.pop_front();
		int lea2 = speed.front();
		speed.pop_front();
		deque <int> result;
		while(!speed.empty())
		{
			if((2 * lea2 - lea1 - speed[speed.size()-2])>0)
			{
				total += 2 * lea1 + speed[speed.size()-1] + speed[speed.size()-2];
				result.push_back(lea1);
				result.push_back(speed[speed.size()-1]);
				result.push_back(lea1);
				result.push_back(lea1);
				result.push_back(speed[speed.size()-2]);
				result.push_back(lea1);
				speed.pop_back();
				speed.pop_back();
			}
			else
			{
				total += lea1 + 2*lea2 + speed[speed.size()-1];
				result.push_back(lea1);
				result.push_back(lea2);
				result.push_back(lea1);
				result.push_back(speed[speed.size()-2]);
				result.push_back(speed[speed.size()-1]);
				result.push_back(lea2);
				speed.pop_back();
				speed.pop_back();
			}
			if(speed.size() == 1)
			{
				total += (speed[0] + lea1);
				result.push_back(lea1);
				result.push_back(speed[0]);
				result.push_back(lea1);
				speed.pop_back();
			}
		}
		result.push_back(lea1);
		result.push_back(lea2);
		total += lea2;
		cout << total << endl;
		bool flag = true;
		while(!result.empty())
		{
			if(flag)
			{
				cout << result[0] << " " << result[1] << endl;
				result.pop_front();
				result.pop_front();
				flag = false;
			}
			else
			{
				cout << result[0] << endl;
				result.pop_front();
				flag = true;
			}
		}
	}
}


int main()
{
	int n;
	while(cin >> n)
	{
		program(n);
	}
	return 0;
}