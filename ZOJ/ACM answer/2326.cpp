#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
#define lnf 2000000000.0
using namespace std;

double prime(deque <string> &str, deque <deque <double> > &temp)
{
	int size = str.size();
	deque <double> max(size, lnf);
	int loop = str.size();
	double ans=-lnf;
	while(loop--)
	{
		double min = lnf+2.0;
		int indexx;
		for(int i=0; i<max.size(); i++)
		{
			if(max[i] < min && max[i] > -1)
			{
				min = max[i];
				indexx=i;
			}
		}
		ans += min;
		max[indexx] = -2;
		for(int i=0; i<str.size(); i++)
		{
			if(temp[indexx][i] < max[i])
				max[i] = temp[indexx][i];
		}
	}
	return ans;
}

int main()
{
	double cable;
	while(cin >> cable)
	{
		int house;
		cin >> house;
		deque <string> str;
		string instr;
		for(int i=0; i<house; i++)
		{
			cin >> instr;
			str.push_back(instr);
		}
		deque <deque<double> > temp;
		for(int i=0; i<str.size(); i++)
		{
			deque <double> intemp;
			for(int j=0; j<str.size(); j++)
			{
				intemp.push_back(lnf);
			}
			temp.push_back(intemp);
		}
		int links;
		cin >> links;
		for(int i=0; i<links; i++)
		{
			string start, end;
			double num;
			cin >> start >> end >> num;
			int row, col;
			for(int j=0; j<str.size(); j++)
			{
				if(start == str[j])
					row = j;
				if(end == str[j])
					col = j;
			}
			temp[row][col] = temp[col][row] = num;
		}
		double need = prime(str, temp);
		if(need > cable)
		{
			printf("Not enough cable\n");
		}
		else
			printf("Need %.1lf miles of cable\n", need);
	}
	return 0;
}