// 电容的阻抗1/jwc,电阻的阻抗r,电容和电阻的相位角为90度，所以总阻抗为
// sqrt(r*r+1/(w*w*c*c))
// 所以这题的式子为
// vr=vs/sqrt(r*r+1/(w*w*c*c))*r;

#include <stdio.h>
#include <math.h>
int main()
{
	float vr,vs,r,w,c;
	int cas;
	scanf("%f%f%f%d",&vs,&r,&c,&cas);
	while(cas--)
	{
		scanf("%f",&w);
		vr=vs/sqrt(r*r+1/(w*w*c*c))*r;
		printf("%.3f\n",vr);
	}
	return 0;
}
