#include <cstdio>
#include <memory>
int N ;
int a[21][21];

void read()
{
	int j,i = 0;
	for ( i = 1 ; i <= 19 ; i ++)
	{
		int temp;
		if( 1  == i)
			for( j = 0 ; j < N ; j ++ )
			{
				scanf("%d",&temp);
				a[i][temp] = 1 ;
				a[temp][i] = 1 ;				
			}
			else{
				int n;
				scanf("%d",&n);
				for( j = 0  ; j < n ; j++)
				{scanf("%d",&temp);
				a[i][temp] = 1 ;
				a[temp][i] = 1 ;		
				}
			}

	}
	for(i = 1 ; i <=20  ; i ++)
		for( j = 1 ;  j <=20 ; j ++)
		{
			if( i != j) 
				if(a[i][j] == 0 )
					a[i][j] = 41;
		}

}
void floyed()
{
	int i , j , k; 
	for ( i  = 1 ; i <=  20 ;  i ++ )
		for ( j= 1 ; j <= 20 ; j ++ )
			if( j!= i )
				for( k = 1; k <= 20 ; k++)
					if( i != k && j!= k)
					{
						if( a[j][k] > a[j][i] + a[i][k] )
							a[j][k] = a[j][i] + a[i][k];
					}
}

int main()
{
	int the_num=0;
	//freopen("1.txt","r",stdin);

	while( scanf("%d",&N) == 1)
	{
		the_num++;
		printf("Test Set #%d\n",the_num);
		memset(a, 0 , sizeof(a));
		read();
		floyed();
		int i=0,num = 0 , a1,a2;
		scanf("%d",&num);
		for(i = 0 ; i < num ; i++)
		{
			scanf("%d%d",&a1,&a2);
			printf("%d to %d: %d\n",a1,a2,a[a1][a2]);

		}
		printf("\n");



		

	}
	return 0 ;
}