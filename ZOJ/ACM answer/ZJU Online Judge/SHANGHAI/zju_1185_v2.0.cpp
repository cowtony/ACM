#include <stdio.h>
#include <string.h>
#include <math.h>

int n , m , k;

struct point
{
	double x , y;
} list[10];

struct line
{
	double A , B , C;
} f[20];

point cross[20][20];

int c;

bool cut[10];

double reco[1<<8];

void init()
{
	scanf("%d%d" , &n , &m);
	scanf("%d" , &k);

	for(int i=0; i<k; i++)
	{
		scanf("%lf%lf" , &list[i].x , &list[i].y);
	}
}

inline double dist(const point& a , const point& b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline int PREV(int u)
{
	return (u + k - 1) % k;
}

inline int NEXT(int u)
{
	return (u + 1) % k;
}

void calc_cross(line L1 ,line L2 , point& p)
{
	
	if(L1.A * L2.B - L1.B * L2.A == 0)
	{
		p.x = p.y = -1;
		return ;
	}

	if(L1.A == 0)
	{
		p.y = - L1.C / L1.B;
		p.x = - (L2.C + p.y * L2.B) / L2.A;
		return;
	}

	if(L2.A == 0)
	{
		p.y = - L2.C / L2.B;
		p.x = - (L1.C + p.y * L1.B) / L1.A;
		return;
	}

	if(L1.B == 0)
	{
		p.x = - L1.C / L1.A;
		p.y = - (L2.C + p.x * L2.A) / L2.B;
		return;
	}

	if(L2.B == 0)
	{
		p.x = - L2.C / L2.A;
		p.y = - (L1.C + p.x * L1.A) / L1.B;
		return;
	}

	double t = L1.A;
	L1.A *= L2.A; L1.B *= L2.A; L1.C *= L2.A;
	L2.A *= t; L2.B *= t; L2.C *= t;

	L1.A -= L2.A; L1.B -= L2. B; L1.C -= L2.C;	
	
	p.y = - L1.C / L1.B;
	p.x = - (L2.C + L2.B * p.y) / L2.A;	
}

void calc()
{
	int i , j;
	for(i=0; i<k; i++)
	{
		j = NEXT(i);
		f[i].A = list[i].y - list[j].y;
		f[i].B = list[j].x - list[i].x;
		f[i].C = list[i].x * list[j].y - list[i].y * list[j].x;
	}
	f[i].A = 1; f[i].B = 0; f[i].C = 0; i++;
	f[i].A = 0; f[i].B = 1; f[i].C = 0; i++;
	f[i].A = 1; f[i].B = 0; f[i].C = -n; i++;
	f[i].A = 0; f[i].B = 1; f[i].C = -m; i++;

	for(i=0; i<k+4; i++)
		for(j=0; j<k+4; j++)
			if(i != j)
				calc_cross(f[i] , f[j] , cross[i][j]);
}

double best ;


double t , dx , dy , ta , tb;
point a , b;

double current_cost(int i)
{
	dx = list[NEXT(i)].x - list[i].x;
	dy = list[NEXT(i)].y - list[i].y;
	
	ta = -1e20;
	tb = 1e20;

	for(int j=0; j<k+4; j++)
		if(cut[j] && j != i)
		{
			if(cross[i][j].x >= 0 && cross[i][j].x <= n && cross[i][j].y >= 0 && cross[i][j].y <= m)
			{
				if(dx == 0) t = (cross[i][j].y - list[i].y) / dy;
				else t = (cross[i][j].x - list[i].x) / dx;
				if(t <= 0 && t > ta) ta = t , a = cross[i][j];
				if(t > 0 && t < tb) tb = t , b = cross[i][j];
			}
		}
	return dist(a , b);
}

void search(int c , double cost , int stat)
{
	if(cost >= reco[stat]) return;
	reco[stat] = cost;
	if(c == k)
	{
		best = cost;
		return;
	}

	for(int i=0; i<k; i++)
		if(!cut[i])
		{
			cut[i] = 1;
			search(c + 1 , cost + current_cost(i) , stat | (1<<i));
			cut[i] = 0;
		}
}

void solve()
{
	int i;
	for(i=0; i<(1<<k); i++)
	{
		reco[i] = 1e20;
	}
	memset(cut , 0 , sizeof(cut));
	cut[k] = cut[k+1] = cut[k+2] = cut[k+3] = 1;
	best = 1e20;
	
	search(0 , 0 , 0);
	printf("Minimum total length = %.3lf\n" , best);
}

int main()
{
	int T , t;

	scanf("%d" , &T);
	for(t=0; t<T; t++)
	{
		if(t) putchar('\n');
		init();
		calc();
		solve();
	}
	
	
	return 0;
}
