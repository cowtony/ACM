//86211 2003-03-10 23:36:07 Wrong Answer 1122 C++ 00:00.00 436K Century Ghost 
//86235 2003-03-11 00:05:33 Wrong Answer 1122 C++ 00:00.01 436K Century Ghost 
//86319 2003-03-11 12:03:48 Accepted 1122 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
struct time
{
	int hour;
	int min;
};

int front(time cur)
{
	float thour,tmin;
	
	thour=(float)cur.hour;
	tmin=(float)cur.min;
	if((float)tmin>(float)(thour*5+tmin*5.0/60))	return 1;
	return 0;
}
void print(time cur)
{
	if(cur.hour==0)	cur.hour=12;
	if(cur.hour<10)	cout<<"0";
	cout<<cur.hour;
	cout<<":";
	if(cur.min<10)	cout<<"0";
	cout<<cur.min;
}
int main()
{
	time begin,end;
	cout<<"Program 3 by team X"<<endl;
	cout<<"Initial time  Final time  Passes"<<endl;
	while(cin>>begin.hour>>begin.min>>end.hour>>end.min)
	{
		
		if(end.hour==12)	end.hour=0;
		time temp=end;
		if(begin.hour==12)	begin.hour=0;
		if(temp.hour<begin.hour||(temp.hour==begin.hour&&temp.min<begin.min))	temp.hour+=12;
		int hourlap=temp.hour-begin.hour;
		
		if(front(begin)&&!front(end))	hourlap--;
		else if(front(end)&&!front(begin))	hourlap++;
		if(temp.hour>=12)	hourlap--;
		cout<<"       ";
		print(begin);
		cout<<"       ";
		print(end);
		cout.setf(ios::right);
		cout.width(8);
		cout<<hourlap<<endl;
	}
	cout<<"End of program 3 by team X"<<endl;
	return 0;
}
