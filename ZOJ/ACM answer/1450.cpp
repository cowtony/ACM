#include <iostream>
#include <cmath>

struct point
{
	double x,y;
};

struct line
{
 	point a,b;
};

point intersection(line u,line v)
{
	point ret=u.a;
	double t=((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
			/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
	ret.x+=(u.b.x-u.a.x)*t;
	ret.y+=(u.b.y-u.a.y)*t;
	return ret;
}


point circumcenter(point a,point b,point c)
{
	line u,v;
	u.a.x=(a.x+b.x)/2;
	u.a.y=(a.y+b.y)/2;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a.x=(a.x+c.x)/2;
	v.a.y=(a.y+c.y)/2;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return intersection(u,v);
}

double dist(point p1, point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double angle_cos(point p0, point p1, point p2)
{
	double b,c,a;
	b = dist(p0, p2);
	c = dist(p0, p1);
	a = dist(p1, p2);
	return (b*b+c*c-a*a)/(2*b*c);
}

int main()
{
	point poi[100];
	int n;
	int p1,p2,p3;
	int i,j,k;
	double radius;
	point centre,p;
	while(scanf("%d",&n) && n)
	{
		radius = 100000000;
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf",&poi[i].x, &poi[i].y);
		}
		for(i=0; i<n-2; i++)
		{
			for(j=i+1; j<n-1; j++)
			{
				for(k=j+1; k<n; k++)
				{
					p = circumcenter(poi[i],poi[j],poi[k]);
					double temp=dist(poi[i],p);
					int t = 0;
					for(int ix=0; ix<n; ix++)
					{
						if(ix==i || ix==j || ix==k) continue;
						if(dist(poi[ix],p)>temp)
						{
							t = 1;
							break;
						}
					}
					if( !t && radius>temp )
					{
						radius = temp;
						centre = p;
					}
				}
			}
		}
		for(i=0; i<n-1; i++)
		{
			for(j=i+1; j<n; j++)
			{
				p.x=(poi[i].x+poi[j].x)/2;
				p.y=(poi[i].y+poi[j].y)/2;
				int t = 0;
				double temp = dist(poi[j],poi[i])/2;
				for(k=0; k<n; k++)
				{
					if(k==i || k==j) continue;
					if(dist(p,poi[k])>temp)
					{
						t = 1;
						break;
					}
				}
				if(!t && temp<radius)
				{
					radius = temp;
					centre = p;
				}
			}
		}
		printf("%.2lf %.2lf %.2lf\n",centre.x, centre.y, radius);
	}
	return 0;
}
