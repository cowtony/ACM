#include <cstdio>
#include <memory>

bool relation[26][26];
bool flag[26][26];
int n = 0, num = 0 ;
int nflag  ;

void floyed()
{
	int i , j, k=0; 
	for ( i = 0 ; i < num ; i++ )
		for( j = 0 ; j< num ; j ++ )
			if( i != j )
				{
				  for( k = 0 ; k < num ; k ++ )
					if( i != k )
					{
						if(relation[j][i] == 1 && relation[i][k] == 1 )
								relation[j][k] = 1 ;
					}
				}
			

}
void print()
{
	int i , j;
	for( i = 0 ; i < num ; i++)
		for( j = 0; j< num ; j++)
		{
			if( relation[i][j] == 1 && flag[i][j] == 0)
			{
				printf("%c<%c\n",i+'A',j+'A');
				nflag = 1 ;
			}

		}
}

int main()
{

	//freopen("1.txt","r",stdin);
	int N=0,j=0;
	char a[3];
	scanf("%d",&N);
	while(N--)
	{
		nflag = 0;
		memset(relation,0,sizeof(relation));
		memset(flag,0,sizeof(flag));
		int i=0;
		j++;
		scanf("%d",&n);
		for( i = 0 ; i < n ; i ++)
		{
			scanf("%s",a);
			num = num > a[0] - 'A' +1 ? num  : a[0] - 'A'+1;
			num = num > a[2]  - 'A' +1 ? num : a[2] - 'A'+1;
			if(a[1] == '>')
			{
				relation[(int)a[2] - 'A'][(int)a[0] - 'A'] = 1;
				flag[(int)a[2] - 'A'][(int)a[0] - 'A'] = 1;
			}
			else
			{
				relation[(int)a[0] - 'A'][(int)a[2] - 'A'] = 1;
				flag[(int)a[0] - 'A'][(int)a[2] - 'A'] = 1;
			}
		}
		printf("Case %d:\n",j);	
		floyed();
		print();
		if(!nflag)
			printf("NONE\n");
		
	}
	return 0 ;
}