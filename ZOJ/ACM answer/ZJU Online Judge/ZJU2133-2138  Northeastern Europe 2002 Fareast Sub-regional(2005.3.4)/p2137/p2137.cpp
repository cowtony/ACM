#include <cstdio>
#include <cstring>
#include <cmath>

struct Point
{
	double x , y;
};
struct Rect
{
	Point p1 , p2;
	Point p3 , p4;
	double dx , dy;
};

const int maxn = 110;
const double pi = acos(0) * 2.0;
const double EPS = 1e-2;

int n;
double H , W;
Rect list[maxn];

void init()
{
	scanf("%d%lf" , &n , &H);
	
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%lf%lf%lf%lf" , &list[i].p1.x , &list[i].p1.y , &list[i].p2.x , &list[i].p2.y);
	}
	W = sqrt((list[0].p1.x - list[0].p2.x) * (list[0].p1.x - list[0].p2.x) 
		+ (list[0].p1.y - list[0].p2.y) * (list[0].p1.y - list[0].p2.y));
}

bool Standing[maxn];

void Rotate(double& x , double& y , double theta)
{
	double r = sqrt(x * x + y * y);
	theta += atan2(y , x);

	x = r * cos(theta);
	y = r * sin(theta);
}

void Gen_2p(Rect& a , double theta)
{
	double dx = (a.p2.x - a.p1.x) / W * H;
	double dy = (a.p2.y - a.p1.y) / W * H;
	
	Rotate(dx , dy , theta);

	a.p3.x = a.p1.x + dx; a.p3.y = a.p1.y + dy;
	a.p4.x = a.p2.x + dx; a.p4.y = a.p2.y + dy;

	a.dx = dx; a.dy = dy;
}

double Area(const Point& a , const Point& b , const Point& c)
{
	return	 (a.x * b.y - a.y * b.x
			+ b.x * c.y - b.y * c.x
			+ c.x * a.y - c.y * a.x) / 2.0;
}

bool Inside_Point(const Rect& a , const Point& p)
{
	double aa = fabs(Area(p , a.p1 , a.p2));
	double bb = fabs(Area(p , a.p2 , a.p4));
	double cc = fabs(Area(p , a.p4 , a.p3));
	double dd = fabs(Area(p , a.p3 , a.p1));
	double area = aa+bb+cc+dd;
	return fabs(area - W * H) <= EPS && aa >= 0 && bb >= 0 && cc >= 0 && dd >= 0;
}

double Cross_Product(const Point& p0 , const Point& p1 , const Point& p2)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool Segment_Cross(const Point& A , const Point& B , const Point& U , const Point& V)
{
	return ( Cross_Product(V , U , A) * Cross_Product(V , U , B) < 0 ) &&
		   ( Cross_Product(A , B , U) * Cross_Product(A , B , V) <= 0 );
}

bool Touch(const Rect& a , Rect& b)
{
	bool ret = 0;

	ret = Inside_Point(a , b.p1) || Inside_Point(a , b.p2)
		|| Segment_Cross(b.p1 , b.p2 , a.p1 , a.p3) || Segment_Cross(b.p1 , b.p2 , a.p2 , a.p4)
		|| Segment_Cross(b.p1 , b.p2 , a.p3 , a.p4) || Segment_Cross(b.p1 , b.p2 , a.p1 , a.p2);

	if(ret == 0) return 0;

	///////// cause new falling
	
	double px , py , qx , qy;
	px = qx = b.p2.x - b.p1.x;
	py = qy = b.p2.y - b.p1.y;

	Rotate(px , py , + pi / 2.0);
	Rotate(qx , qy , - pi / 2.0);

	if(px * a.dx + py * a.dy > 0) Gen_2p(b , + pi / 2.0);
	else Gen_2p(b , - pi / 2.0);

	return 1;
}

void solve()
{
	int i;
	for(i=0; i<n; i++)
		Standing[i] = 1;

	int Falling = 0;
	Gen_2p(list[0] , pi / 2.0);
	
	while(1)
	{
		Standing[Falling] = 0;		
		for(i=0; i<n; i++)
			if(Standing[i] && Touch(list[Falling] , list[i]))
			{
				Falling = i; break;
			}
		if(i == n) break;
	}

	bool first = 1;
	for(i=0; i<n; i++)
		if(!Standing[i])
		{
			if(first) first=0; else putchar(' ');
			printf("%d"  , i + 1);
		}
	putchar('\n');	
}

int main()
{
//	freopen("in.txt" , "r" , stdin);

	int T;
	scanf("%d" , &T);

	while(T--)
	{
		init();
		solve();
		if(T) putchar('\n');
	}
	return 0;
}