#include <stdio.h>
#include <math.h>

double A , B;
double X , Y;

void swap(double& a , double& b)
{
	if(a > b)
	{
		double t = a;
		a = b;
		b = t;
	}
}


bool solve()
{
	if(A >= X && B >= Y) return 1;
	double pi = acos(0);
	double theta = 0;
	double ta , tb;
	double c , s;

	for(;theta<pi; theta+=0.003)
	{
		c = cos(theta); s = sin(theta);
		ta = X * c + Y * s;
		tb = X * s + Y * c;

		swap(ta , tb);
		if(A >= ta && B >= tb) return 1;
	}
	return 0;
}

int main()
{
	int T;

	scanf("%d" , &T);

	while(T--)
	{
		scanf("%lf%lf" , &A , &B);
		swap(A , B);
		scanf("%lf%lf" , &X , &Y);
		swap(X , Y);

		if(solve()) puts("Escape is possible.");
		else puts("Box cannot be dropped.");
	}

	return 0;
}