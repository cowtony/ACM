//177094 2003-06-22 10:04:27 Accepted 1601 C++ 00:00.00 376K just for play 
#include<stdio.h>
#include<math.h>

const double epison=1.0e-17;
int main()
{
	double num;
	int limit;
	int ni,di;int sel_n,sel_d;
	while(scanf("%lf",&num)!=EOF)
	{
		scanf("%d",&limit);
		double min_mat=1;
		ni=1,di=1;sel_n=ni,sel_d=di;
		while(ni<=limit&&di<=limit)
		{
			double cur_mat=ni*1.0/di;
			if(fabs(cur_mat-num)+epison<fabs(min_mat-num))
			{		min_mat=cur_mat;sel_n=ni,sel_d=di;}
			if(cur_mat+epison<num)	ni++;
			else	di++;
			
		}
		printf("%d %d\n",sel_n,sel_d);
	}
	return 0;
}
		

