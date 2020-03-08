#include<iostream.h>
#include<vector>
#include<stdio.h>
#include<math.h>

using namespace std;
struct position
{
	char name[31];
	double lat;
	double lon;
};
vector<position>input;

const double radius=6378;
const double pi=3.1415926535897;


double dou(double x)
{
	return x*x;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(1)
	{
		position temp;
		cin>>temp.name;
		if(strcmp(temp.name,"#")==0)	break;
		cin>>temp.lat>>temp.lon ;
		input.push_back (temp);
	}
	int i;
	for(i=0;i<input.size();i++)
	{
		input[i].lon=input[i].lon*pi/180;
		input[i].lat=input[i].lat*pi/180;
	}
	char from[31],to[31],middle[31];
	while(cin>>from)
	{
		if(strcmp(from,"#")==0)	break;
		cin>>to>>middle;
		int total=0;int pt1,pt2,pt3;
		for(i=0;i<input.size();i++)
		{
			if(strcmp(from,input[i].name)==0)	pt1=i,total++;
			if(strcmp(to,input[i].name)==0)	pt2=i,total++;
			if(strcmp(middle,input[i].name)==0)	pt3=i,total++;
		}
		if(total<3)
		{	
			cout<<middle<<" is ? km off "<<from<<"/"<<to<<" equidistance."<<endl;
			continue;
		}
		double r_from,r_to,r_total;
		double c_2;double temp;double angle;
		position another;
		another.lat=(input[pt1].lat+input[pt2].lat)/2;
		another.lon=(input[pt1].lon+input[pt2].lon)/2;
		
		r_from=dou(radius)*dou(cos(another.lat))/(dou(cos(another.lat))*dou(cos(another.lon))+dou(sin(another.lon)));
		r_to=dou(radius)*dou(cos(input[pt3].lat))/(dou(cos(input[pt3].lat))*dou(cos(input[pt3].lon))+dou(sin(input[pt3].lon)));
		r_from=sqrt(r_from);
		r_to=sqrt(r_to);
		r_total=r_from*r_from+r_to*r_to-2*r_from*r_to*cos(fabs(another.lon-input[pt3].lon));
		
		//temp=radius*fabs(sin(another.lat))-sin(input[pt3].lat);
		temp=fabs(r_from*fabs(sin(another.lon))*tan(another.lat)-r_to*fabs(sin(input[pt3].lon)*tan(input[pt3].lat)));

		c_2=r_total+temp*temp;
		
		angle=acos((2*radius*radius-c_2)/(2*radius*radius));
		double res1;
		res1=radius*angle;
		
/*
		r_from=radius*radius*cos(another.longtitude*pi/180)*cos(another.longtitude*pi/180)/
			(
		r_to=radius*fabs(cos(input[pt3].latitude*pi/180));
		
		cout<<"r_from :"<<r_from<<endl;
		cout<<"r_to   :"<<r_to<<endl;
		cout<<"r_tot  :"<<r_total<<endl;
		cout<<"temp   :"<<temp<<endl;
		cout<<"c_2    :"<<c_2<<endl;
		cout<<"angle  :"<<angle<<endl;

	
/*
		r_from=radius*fabs(cos(input[pt2].latitude*pi/180));
		r_to=radius*fabs(cos(input[pt3].latitude*pi/180));
		r_total=r_from*r_from+r_to*r_to-2*r_from*r_to*cos(fabs(input[pt2].longtitude-input[pt3].longtitude)*pi/180);
		
		temp=radius*fabs(sin(input[pt2].latitude*pi/180))-sin(input[pt3].latitude*pi/180);
		c_2=r_total+temp*temp;
		
		angle=acos((2*radius*radius-c_2)/(2*radius*radius));
		double res2;
		res2=radius*angle;
		
		double res=fabs(res2-res1)/2;

*/
		cout<<middle<<" is "<<(long)res1<<" km off "<<from<<"/"<<to<<" equidistance."<<endl;
	}
	return 0;
}

		

		


