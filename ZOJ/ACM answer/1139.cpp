//z1139
//begin date:03.3.13
#include<iostream.h>
#include<vector>
using namespace std;

struct rect
{
	int minx,maxx;
	int miny,maxy;
	int flag;
	rect()
	{flag=0;}
};
int main()
{
	int n;
	vector<rect>input;
	while(cin>>n)
	{
		int i;
		for(i=0;i<n;i++)
		{
			rect temp;
			cin>>temp.minx>>temp.maxx>>temp.miny>>temp.maxy;
			input.push_back(temp);
		}
		
	}
	return 0;
}


