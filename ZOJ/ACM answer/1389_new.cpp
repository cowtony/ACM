//109191 2003-04-06 15:48:36 Wrong Answer 1389 C++ 00:03.06 2500K Century Ghost 
//109209 2003-04-06 16:02:42 Wrong Answer 1389 C++ 00:06.25 2500K Century Ghost 
//112126 2003-04-08 22:18:21 Time Limit Exceeded 1389 C++ 00:10.00 2500K Century Ghost 
//112159 2003-04-08 22:30:22 Accepted 1389 C++ 00:02.63 2500K Century Ghost 
#include<stdio.h>
#include<vector>
#include<math.h>


using namespace std;
double epison=1.0e-15;
struct rect
{
	double base;
	double height;
	double width;
	double depth;
	double cal_v()
	{
		return height*width*depth;
	}
	double cal_lev_v(double lev)
	{
		if(lev<base)	return 0;
		if(lev>base+height)	return cal_v();
		return (width*depth*(lev-base));
	}


};
vector<rect>cistern;
long n;
double rect_v;

double cal_total_v(double lev)
{
	long i;
	double temp=0;
	for(i=0;i<n;i++)
		temp+=cistern[i].cal_lev_v(lev);
	return temp;
}


double sel_lev(double max_sel,double min_sel)
{
	while(min_sel<max_sel)
	{
		
		double middle=(min_sel+max_sel)/2;
		if(max_sel-min_sel<0.005)	return middle;
		double temp=cal_total_v(middle);
		if(fabs(temp-rect_v)<epison)	return middle;
		if(temp<rect_v)	min_sel=middle;
		else	max_sel=middle;
	}
	return 0;
}


int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int nn;
	scanf("%ld",&nn);
	while(nn--)
	{
		
		scanf("%ld",&n);
		long i;double sum=0;
		cistern.clear();
		double max_sel=-1,min_sel=10000000;
		for(i=0;i<n;i++)
		{
			rect temp;
			scanf("%lf%lf%lf%lf",&temp.base,&temp.height,&temp.width,&temp.depth);
			cistern.push_back(temp);
			sum+=temp.cal_v();
			if(temp.base<min_sel)	min_sel=temp.base;
			if(temp.base+temp.height>max_sel)	max_sel=temp.base+temp.height ;
		}		
		
		scanf("%lf",&rect_v);
//		printf("%lf   %lf\n",max_sel,min_sel);
		if(rect_v-sum>epison)
		{
			printf("OVERFLOW\n");
			continue;
		}
		double res=sel_lev(max_sel,min_sel);
		
		for(i=0;i<n;i++)
			if(res>cistern[i].base&&res<(cistern[i].base+cistern[i].height))	break;
		if(i==n)
		{	
			max_sel=-1;
			for(i=0;i<n;i++)
				if(cistern[i].base<res&&(cistern[i].base+cistern[i].height)>max_sel)	max_sel=cistern[i].base+cistern[i].height ;
			res=max_sel;
		}
		printf("%.02lf\n",res);
	}
	return 0;
}

