#include <stdio.h>
#include <string.h>

int n;
double x0 , y0 , x1 , y1 , x2 , y2;
double px , py , qx , qy;
double m0 , m1;

void solve()
{	
	scanf("%d" , &n);
	scanf("%lf%lf%lf%lf" , &x0 , &y0 , &x1 , &y1);
	px = px = m0 = 0;

	for(int i=2; i<n; i++)
	{
		scanf("%lf%lf" , &x2 , &y2);
		qx = (x0 + x1 + x2) / 3.0;
		qy = (y0 + y1 + y2) / 3.0;
		m1 = x0 * y1 - y0 * x1 + x1 * y2 - y1 * x2 + x2 * y0 - y2 * x0;
		if(m0 + m1 == 0) m1 += 1e-10;
		px = (px * m0 + qx * m1) / (m0 + m1);
		py = (py * m0 + qy * m1) / (m0 + m1);

		m0 += m1; x1 = x2; y1 = y2;
	}
	printf("%.2lf %.2lf\n" , px + 1e-10 , py + 1e-10);
}

int main()
{
	int T;
	scanf("%d" , &T);

	while(T--)
	{
		solve();
	}

	return 0;
}
