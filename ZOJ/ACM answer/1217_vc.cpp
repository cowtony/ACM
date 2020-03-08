#include<iostream.h>
#include<string.h>

#include<fstream.h>
ifstream fin("in.txt");
ofstream fout("out2.txt");
ofstream fout3("out3.txt");
struct eight
{
	char flag[3][3];
	int up;
	char move;
	int row,col;
	void print()
	{
		int j,t;
		for(j=0;j<3;j++)
		{
			for(t=0;t<3;t++)
				fout3<<char(flag[j][t]+48)<<" ";
			fout3<<endl;
		}
	}

};

eight node[30000];
char visit[50000];
int max;
char mark[8]={1,2,4,8,16,32,64,128};
long fact[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
long convert(eight& tt)
{
	int i,j;int t,l;
	long k[3][3];
	for(i=2;i>=0;i--)
		for(j=2;j>=0;j--)
		{
			k[i][j]=0;
			for(t=0;t<j;t++)	if(tt.flag[i][t]<tt.flag[i][j])	k[i][j]++;
			for(t=0;t<i;t++)
				for(l=0;l<3;l++)
					if(tt.flag[t][l]<tt.flag[i][j])	k[i][j]++;
		}
	long total=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			total+=k[i][j]*fact[i*3+j];
	return total;
}
				
void setmark(long num)
{
	long pt=num/8;
	long set=num%8;
	visit[pt]=visit[pt]|mark[set];
}
int getmark(long num)
{
	long pt=num/8;
	long set=num%8;
	return visit[pt]&mark[set];
}

int same(eight& fir,eight& sec)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(fir.flag[i][j]!=sec.flag[i][j])	return 0;
	return 1;
}
int occur(eight& tt,int end)
{
	int i;
	for(i=0;i<end;i++)
		if(same(tt,node[i]))	return 1;
	return 0;
}
void mcopy(eight& fir,eight& sec)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			fir.flag[i][j]=sec.flag[i][j];
}
void bfs()
{
	long beg=0;long end=0;
	
	node[0].flag[0][0]=1;node[0].flag[0][1]=2;node[0].flag[0][2]=3;
	node[0].flag[1][0]=4;node[0].flag[1][1]=5;node[0].flag[1][2]=6;
	node[0].flag[2][0]=7;node[0].flag[2][1]=8;node[0].flag[2][2]=0;
	node[0].up=-1;node[0].row=2;node[0].col=2;
	while(1)
	{
		if(beg>end)	break;
		int j,t;
		node[beg].print();
		fout<<"---------"<<beg<<"--------------"<<endl;
		int frow=node[beg].row;int fcol=node[beg].col;
		int i;
		for(i=0;i<4;i++)
		{
			int nextrow=frow+dir[i][0];int nextcol=fcol+dir[i][1];
			if(nextrow>=0&&nextrow<3&&nextcol>=0&&nextcol<3)
			{
				end++;
				mcopy(node[end],node[beg]);
				node[end].flag[frow][fcol]=node[beg].flag[nextrow][nextcol];
				node[end].flag[nextrow][nextcol]=node[beg].flag[frow][fcol];
				node[end].move=i;
				node[end].up=beg;
				node[end].row=nextrow;
				node[end].col=nextcol;
				node[end].print();
				long temp=convert(node[end]);
				fout3<<end<<"---"<<temp<<"======";
				if(getmark(temp)!=0)	fout3<<"1"<<endl,	end--;
				else	fout3<<"0"<<endl,setmark(temp);
			}
		}
		beg++;
	}
	max=end;
}
			

int main()
{
	bfs();
	
	fout<<max<<endl;
	memset(visit,0,sizeof(visit));
	int i,j,t;
	eight temp;
/*	while(1)
	{
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				fin>>temp.flag[i][j];
		if(temp.flag[0][0]<0)	break;
		long marknum=convert(temp);
		fout<<marknum<<endl;
	}
*/		


	return 0;
}
