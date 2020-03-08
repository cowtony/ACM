#include <stdio.h>
int main()
{
	float k,l,s,w,temp,v2;
	while(scanf("%f%f%f%f",&k,&l,&s,&w))
	{
		if(k<10e-6&&l<10e-6&&s<10e-6&&w<10e-6) break;
		if(s-l<10e-6)
		{
			v2=2.0*9.81*s;
			if(v2>100) printf("Killed by the impact.\n");
			else printf("James Bond survives.\n");
		}
		else
		{
			temp=2.0*9.81*w*s-k*(s-l)*(s-l);
			if(temp<0) printf("Stuck in the air.\n");
			else
			{
				v2=temp/w;
				if(v2>100) printf("Killed by the impact.\n");
				else printf("James Bond survives.\n");
			}
		}
	}
	return 0;
}
