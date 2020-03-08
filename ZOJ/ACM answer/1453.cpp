#include <iostream>
#include <cmath>
#include <iomanip>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;

typedef struct point
{
	double x,y;
};

point convex[101];
point p1,p2;

double xmult(point p1,point p2,point p0)
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int graham_cp(const void* a,const void* b)
{
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}

void _graham(int n,point* p,int& s,point* ch)
{
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
	{
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
		{
			p1=p[k=i];
		}
	}
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
	{
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
	}
}
 
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1)
{
	point* temp=new point[n];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
	{
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
		{
			convex[n++]=temp[i];
		}
	}
	delete []temp;
	return n;
}

int main()
{
	int n;
	int i;
	point p[101];
	int temp;
	double len;
	while(cin>>n&&n)
	{
		
        for(i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
        if(n==1) {cout<<"0.00"<<endl;continue;}
        if(n==2) {cout<<setiosflags(ios::fixed)<<setprecision(2)<<2*sqrt((p[0].x-p[1].x)*(p[0].x-p[1].x)+(p[0].y-p[1].y)*(p[0].y-p[1].y))<<endl;;continue;}
		temp=graham(n,p,convex,1,1);
		len=0;
		for(i=0;i<temp-1;i++)
		{
			len+=sqrt((convex[i].x-convex[i+1].x)*(convex[i].x-convex[i+1].x)+(convex[i].y-convex[i+1].y)*(convex[i].y-convex[i+1].y));
		}
		len+=sqrt((convex[temp-1].x-convex[0].x)*(convex[temp-1].x-convex[0].x)+(convex[temp-1].y-convex[0].y)*(convex[temp-1].y-convex[0].y));
		cout<<setiosflags(ios::fixed)<<setprecision(2)<<len<<endl;
	}
	return 0;
}

