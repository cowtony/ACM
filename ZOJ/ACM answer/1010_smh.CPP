//Area
//18615 2002-05-30 08:25:14 Accepted 1010 C++ 00:00.22 464K jet_engine
#include<iostream.h>
#include<iomanip.h>
#include<math.h>

struct point{ double x,y;};
 point plist[1001];

double distant(point s, point e)		// calc distance
{
	return (sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)));
}
double AOT(point p1, point p2, point p3)	// area of triangle
{
	return ((p2.x-p1.x)*(p3.y-p2.y)-(p2.y-p1.y)*(p3.x-p2.x))/2.0;
}
double area_cal(int sum)			// polygon area calculation
{					// not proofed but work ok
	double area=0.0;
	for (int i=1; i<sum-1; i++){
		area+=AOT(plist[0], plist[i], plist[i+1]);
	}
	return fabs(area);
}
int same(double a, double b)
{
	if (fabs(a-b)<1e-10) return 1;
	return 0;
}
int psame(point a, point b)
{
	if (same(a.x, b.x)&&same(a.y, b.y)) return 1;
	return 0;
}
int intersect(point s1, point e1,point s2, point e2)
{
	double a1, a2, b1, b2, c1, c2, d1, d2;
	a1=e1.x-s1.x;
	a2=e1.y-s1.y;
	b1=s2.x-e2.x;
	b2=s2.y-e2.y;
	if (same(a1*b2, a2*b1)){	//parallel
		if ((distant(s1,s2)+distant(s1,e2)<distant(s2,e2)+1e-10)&&(distant(e1,s2)+distant(e1,e2)<distant(s2,e2)+1e-10))
		 return 1;		//one of the vertex within the other line
		if ((distant(s2,s1)+distant(s2,e1)<distant(s1,e1)+1e-10)&&(distant(e2,s1)+distant(e2,e1)<distant(s1,e1)+1e-10))
		 return 1;
		return 0;		//not intersect
	}
	c1=s2.x-s1.x;
	c2=s2.y-s1.y;
	d1=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	d2=(c1*a2-c2*a1)/(a2*b1-a1*b2);

	if (d1>-1e-10&&d1<1.0000000001&&d2>-1e-10&&d2<1.0000000001){// within
		// the intersection happen to be on the vertex of both lines
		if ((same(d1,0)||same(d1,1))&&(same(d2,0)||same(d2,1))) return 0;
		 //
		 else return 1;
	}
	return 0;
}

int possible(int sum)
{
	point s1,s2,e1,e2;		//start ----- end
	int i, j;
	for (i=0; i<sum; i++){
		e1=plist[i];
		s1=plist[(i+sum-1)%sum];
		for (j=i; j<sum-1; j++){
			s2=plist[j];
			e2=plist[j+1];
			if (intersect(s1,e1,s2,e2))
				return 0;
		}
	}
	return 1;
}

int input()
{
	int sum, i, j, repeat=0;
	cin>>sum;
	for (i=0; i<sum; i++){
		cin>>plist[i].x>>plist[i].y;
		for (j=0; j<i; j++){
			if (same(plist[i].x,plist[j].x)&&same(plist[i].y,plist[j].y)) repeat=1;
		}
	}
	return ((repeat)? 1:sum);
}

int main()
{
	int sum, counter=1;
	while(sum=input()){
		if (counter>1) cout<<endl;
		if (sum<3||!possible(sum)) cout<<"Figure "<<counter<<": Impossible"<<endl;
		 else {
			cout.precision(2);
			cout.setf(ios::fixed|ios::showpoint);
			cout<<"Figure "<<counter<<": "<<area_cal(sum)<<endl;
		}
		counter++;
	}
	return 0;
}
