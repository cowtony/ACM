#include <iostream>

int main()
{
    int n,m;
	double p,r,s;
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%lf%d%lf%lf",&n,&p,&m,&r,&s);
		int k=(int)(p*(double)n+(double)m*s)/(2.0*(double)m*p);
		double total=0;
		double total1;
		int haha;
		for(int i=k-10;i<k+10;i++)
		{
            total1=((double)(i+1)*p-0.01-s)*(n-i*m)-r;
            if(total1-total>0)
            {
                  total=total1;
                  haha=i;
            }
        }
        k=haha; 
		double price=(double)(k+1)*p-0.01;
		printf("price = %.2lf\naudiences = %d\nrevenue = %.2lf\n",price,n-k*m,total);
	    if(cas) printf("\n"); 
    }
	return 0;
}
