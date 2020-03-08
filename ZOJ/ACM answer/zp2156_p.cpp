#include<stdio.h>
int p[4]={1,5,10,25},c[4];
int compute ( int *use, int start , int price )
{
	int i,val=0;
	for (i=start;i>=0;i--)
		val+=c[i]*p[i];
	for (i=start;i>=0;i--)
	{
		val-=c[i]*p[i] ;
		if (price<val)
			use[i]=0;
		else
			use[i]=(price-val+p[i]-1)/p[i];
		if (use[i]>c[i] || use[i]*p[i]>price)
			return -1;
		price-=use[i]*p[i];
	}
	for (i=0,val=0;i<4;i++)
		val+=use[i];
	return val ;
}

int main ()
{
	int price,i,val,coins[2],use[2][4];
	while (1)
  {
		scanf ("%d%d%d%d%d",
        &price,&c[0],&c[1],&c[2],&c[3]);
		    if (!(price+c[0]+c[1]+c[2]+c[3]))  break ;
		for (i=0,val=0;i<3;i++ )
			val+=c[i]*p[i];
		if ( val > price )
			use[0][3]=0;
		else
			if ((price-val+p[3]-1)/p[3]>c[3])
        use[0][3]=c[3];
      else
        use[0][3]=(price-val+p[3]-1)/p[3];

		coins[0]=compute(use[0],2,price-use[0][3]*p[3]);
		if (use[0][3]>=c[3])
			coins[1]=-1;
		else
		{
			use[1][3]=use[0][3]+1 ;
			coins[1]=compute(use[1],2,price-use[1][3]*p[3]);
		}
		if (coins[1]==-1 && coins[0]==-1)
			puts("Charlie cannot buy coffee.");
		else
		{
			i = 0 ;
			if ( coins[1] > coins[0] )
				i = 1 ;
			printf("Throw in %d cents, %d nickels,",
        use[i][0],use[i][1]);
      printf(" %d dimes, and %d quarters.\n",
        use[i][2],use[i][3]) ;
		}
	}
	return 0 ;
}
//---------------------------------------------------------------------------
 