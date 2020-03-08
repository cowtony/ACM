//158761 2003-05-25 14:54:32 Accepted 1140 C++ 00:00.82 500K just for play 

//while not using the memset ,it last longer
//158767 2003-05-25 14:58:40 Accepted 1140 C++ 00:00.90 504K just for play 
#include<stdio.h>
#include<string.h>

const int MAXN=300;

int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, k;
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		//memset(t, 0xff, sizeof(int)*MAXN);
		for(j=0;j<n;j++)	t[j]=-1;
		for (s[p=q=0]=i; p<=q&&match1[i]<0; p++){
			for (k=s[p], j=0; j<n&&match1[i]<0; j++){
				if (mat[k][j]&&t[j]<0){
					s[++q]=match2[j];
					t[j]=k;
					if (s[q]<0){
						for (p=j; p>=0; j=p){
							match2[j]=k=t[j];
							p=match1[k];
							match1[k]=j;
						}
					}
				}
			}
		}
	}
	return ret;
}

int main()
{
	int nn;
	scanf("%d",&nn);
	while(nn--)
	{
		int p,n;
		scanf("%d%d",&p,&n);
		int map[100][300];
//		memset(map,0,sizeof(map));
		int i,j;
		for(i=0;i<p;i++)
			for(j=0;j<n;j++)
				map[i][j]=0;
		for(i=0;i<p;i++)
		{
			int tt,tin;
			scanf("%d",&tt);
			for(j=0;j<tt;j++)
			{
				scanf("%d",&tin);
				map[i][tin-1]=1;
			}
		}
		int mat1[100],mat2[300];
//		memset(mat1,0xff,sizeof(mat1));
//		memset(mat2,0xff,sizeof(mat2));
		for(i=0;i<p;i++)	mat1[i]=-1;
		for(i=0;i<n;i++)	mat2[i]=-1;
		if(hungary(p,n,map,mat1,mat2)==p)
			printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}