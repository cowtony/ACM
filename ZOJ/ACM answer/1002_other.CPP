#include <stdio.h>
#include <math.h>
#include <iostream.h>

struct point 
{
	double x;
	double y;
};

void D(int n,double x1, double y1,double x2,double y2);
void f(int n,double x1, double y1,double x2,double y2);
point f1(double x1,double y1,double x2,double y2);

int main()
{	
	int times;
	double x1,y1,x2,y2;
	while(cin>>times>>x1>>y1>>x2>>y2)
	{  
		D(times,x1,y1,x2,y2);
		cout.setf(ios::fixed|ios::showpoint);
		cout.precision(2);
		cout<<x2<<" "<<y2<<endl<<endl;
	}	
	return 0;
}
void D(int n,double x1, double y1,double x2,double y2)
{
	if(n==0)
	{
		cout.setf(ios::fixed);
		cout.precision(2);
		cout<<x1<<" "<<y1<<endl;
		return;
	}
	D(n-1,x1,y1, x1+(x2-x1)/3, y1+(y2-y1)/3);
	f( n,x1+(x2-x1)/3, y1+(y2-y1)/3, x1+2*(x2-x1)/3, y1+2*(y2-y1)/3 );
	D(n-1,  x1+2*(x2-x1)/3, y1+2*(y2-y1)/3, x2,y2);
	return;
}
void f(int n,double x1, double y1,double x2,double y2)
{
	point mid=f1(x1,y1,x2,y2);
	D(n-1,x1,y1, mid.x, mid.y);
	D(n-1,mid.x,mid.y,x2,y2);
	return;
}
point f1(double x1,double y1,double x2,double y2)
{
	point node;
	double s1,c1,s2,c2,p;
	p=sqrt( (y2-y1)*(y2-y1)+ (x1-x2)*(x1-x2) );
	s1=(y2-y1)/p;
	c1=(x2-x1)/p;
	s2=0.5*(s1+1.732*c1);
	c2=0.5*(c1-1.732*s1);
	node.x=x1+p*c2;
	node.y=y1+p*s2;	
	return node;
}
