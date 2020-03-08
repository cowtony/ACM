#include <stdio.h>
#include <math.h>
int main()
{
	float whei,daydis,nidis,percen;
	float sum,w,min;
	int p;
	int i;
	while(1)
	{
		scanf("%f%f%f%f",&whei,&daydis,&nidis,&percen);
		if(whei<10e-6) break;
		min=daydis*percen/100.0;
		w=daydis+min;
		sum=0;
		for(i=1;;i++)
		{
			w-=min;
			if(w>0)
				sum+=w;
			if((sum-whei)>10e-6) {p=1;break;}
			sum-=nidis;
			if(sum<10e-6) 
			{
				if(fabs(sum)<10e-6) 
					{p=2;break;}
				else {p=3;break;}
			}
		}
		if(p==1) printf("success on day %d\n",i);
		else if(p==2) printf("failure on day %d\n",i+1);
		else printf("failure on day %d\n",i);
	}
	return 0;
}
