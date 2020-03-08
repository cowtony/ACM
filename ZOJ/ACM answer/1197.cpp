//158574 2003-05-25 10:29:16 Accepted 1197 C++ 00:00.00 384K just for play 

//use the algorithm of hungry to calculate the max-match
#include<stdio.h>
#include<string.h>

const int MAXN=26;
struct rect
{
	int minx,maxx,miny,maxy;
};

struct point
{
	int x,y;
};

rect slide[26];
point coord[26];
int n;
int map[26][26];
int slidemat[26];
int nummat[26];
int in_rect(int j,int k)
{
	if(coord[j].x>slide[k].minx&&coord[j].x<slide[k].maxx
		&&coord[j].y>slide[k].miny&&coord[j].y<slide[k].maxy)
			return 1;
	return 0;
}
int hungary(int m, int n, int mat[][MAXN], int* match1, int* match2)
{
	int s[MAXN], t[MAXN], p, q, ret=0, i, j, k;
	memset(match1, 0xff, sizeof(int)*MAXN);
	memset(match2, 0xff, sizeof(int)*MAXN);
	for (i=0; i<m; ret+=(match1[i++]>=0) ){
		memset(t, 0xff, sizeof(int)*MAXN);
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


void mainproc()
{
	int i;
	hungary(n, n, map, slidemat, nummat);
/*
	for(i=0;i<n;i++)
		printf("%c   %d\n",i+'A',slidemat[i]+1);
	printf("======================\n\n");
*/
	int match[MAXN];
	int m2[MAXN];
	for (i=0; i<n; i++){
		if(slidemat[i]<0)	continue;
		map[i][slidemat[i]]=0;
		memset(match,0xff,sizeof(match));
		memset(m2,0xff,sizeof(m2));
		if (hungary(n, n, map, match, m2)==n){

			map[i][slidemat[i]]=1;
			nummat[slidemat[i]]=-1;
			slidemat[i]=-1;
			continue;
		}
		map[i][slidemat[i]]=1;
	}
}

int main()
{
//	freopen("1197.in","r",stdin);
//	freopen("1197.out","w",stdout);
	int count=0;
	while(scanf("%d",&n))
	{
		if(n==0)	break;
		count++;
		int i,j;

		for(i=0;i<n;i++)
			scanf("%d%d%d%d",&slide[i].minx,&slide[i].maxx,&slide[i].miny,&slide[i].maxy);
		for(i=0;i<n;i++)
			scanf("%d%d",&coord[i].x,&coord[i].y);
		memset(map,0,sizeof(map));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)			
				if(in_rect(j,i))
					map[i][j]=1;
		memset(slidemat,0xff,sizeof(slidemat));
		memset(nummat,0xff,sizeof(nummat));
		mainproc();
		int output=0;
		printf("Heap %d\n",count);
		int first=1;
		for(i=0;i<n;i++)
		{
			if(slidemat[i]>=0)
			{
				if(!first)	printf(" ");
				printf("(%c,%d)",i+'A',slidemat[i]+1);
				first=0;output=1;
			}
		}
		if(!output)	printf("none");
		printf("\n\n");
	}
	return 0;
}
		
	
