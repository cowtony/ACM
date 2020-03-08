
//97925 2003-03-25 18:36:04 Time Limit Exceeded 1217 C++ 00:10.00 14836K Century Ghost 
//98407 2003-03-26 00:02:08 Time Limit Exceeded 1217 C++ 00:10.00 7668K Century Ghost 
//98624 2003-03-26 11:26:24 Accepted 1217 C++ 00:00.84 2292K Century Ghost 

#include<iostream.h>
//#include<time.h>
#include<vector>
/*
#include<fstream.h>
ofstream cout("out_3.txt");
ifstream cin("in.txt");
*/
using namespace std;
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int pos[9][2]={{2,2},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2}};

class eight
{
public:
	char ch[3][3];
	long father;
	char move;
	int row,col;
/*
	void print()
	{
		int i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				cout<<char(ch[i][j]+'0')<<" ";
			cout<<endl;
		}
		cout<<father<<"---->"<<char(move+'0')<<endl;
	}
*/
};
eight final;eight initial;
vector<eight>move;
char visit[50000];
long label[400000];
long fact[9]={1,1,2,6,24,120,720,5040,40320};
char mark[8]={1,2,4,8,16,32,64,128};

long convert(eight& tt)
{
	int i,j;int t,l;
	long k[3][3];
	for(i=2;i>=0;i--)
		for(j=2;j>=0;j--)
		{
			k[i][j]=0;
			for(t=0;t<j;t++)	if(tt.ch[i][t]<tt.ch[i][j])	k[i][j]++;
			for(t=0;t<i;t++)
				for(l=0;l<3;l++)
					if(tt.ch[t][l]<tt.ch[i][j])	k[i][j]++;
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
	int t,k;
	for(t=0;t<3;t++)	
		for(k=0;k<3;k++)
			if(fir.ch[t][k]!=sec.ch[t][k])	return 0;		
	return 1;
}
inline void copyeight(eight& from,eight& to)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			to.ch[i][j]=from.ch[i][j];
}
void bfs()
{
	int pt=0;
	while(1)
	{
		if(pt>=move.size())	break;
		int i;
//		cout<<"-------"<<pt<<"---------"<<endl;
//		move[pt].print ();
		
		int currow=move[pt].row;
		int curcol=move[pt].col;
		int nextrow,nextcol;
		for(i=0;i<4;i++)
		{
			nextrow=currow+dir[i][0];
			nextcol=curcol+dir[i][1];
			if(nextrow>=0&&nextrow<3&&nextcol>=0&&nextcol<3)
			{
				eight temp;
				copyeight(move[pt],temp);
				temp.ch[currow][curcol]=move[pt].ch[nextrow][nextcol];
				temp.ch[nextrow][nextcol]=0;
				temp.row=nextrow;temp.col=nextcol;
				temp.father=pt;
				temp.move=i;
				long ttt=convert(temp);
				if(!getmark(ttt)){	move.push_back (temp);	label[ttt]=move.size()-1;setmark(ttt);}	
				
			}
		
		}
		pt++;
	}

}
	
int main()
{
	/*
	time_t beg,end;
	time(&beg);
	cout<<beg<<endl;
*/
	long i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			initial.ch[i][j]=i*3+j+1;
	initial.ch[2][2]=0;
	initial.row=2;initial.col=2;
	initial.father=-1;
	for(i=0;i<400000;i++)	label[i]=-1;
	move.clear();
	long temp=convert(initial);
	label[temp]=0;
	move.push_back(initial);
	setmark(convert(initial));

	bfs();

	
	i=0;long len=move.size();
//	cout<<len<<endl;
//	move[len-1].print();
/*
	for(i=0;i<len;i++)
	{
		if(i%80==0)	cout<<endl;
		long temp=convert(move[i]);
		cout<<"{"<<temp<<","<<(char)(move[i].move+'0')<<","<<move[i].father<<"}"<<",";
	}
	cout<<"end"<<endl;
*/
	while(cin>>final.ch[0][0])
	{
		cin>>final.ch[0][1]>>final.ch[0][2];
		for(i=1;i<3;i++)
			for(j=0;j<3;j++)
				cin>>final.ch[i][j];
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
				if(final.ch[i][j]=='x')
				{
					final.ch[i][j]=0;
					final.row=i;
					final.col=j;
				}
				else	final.ch[i][j]-='0';
			}
		
		long ttt=convert(final);
		if(label[ttt]==-1)
			cout<<"unsolvable"<<endl;
		else
		{
			long len=move.size();
			long pp=label[ttt];					
			while(move[pp].father>=0)
			{
				if(move[pp].move==0)	cout<<"d";
				else if(move[pp].move==1)	cout<<"l";
				else if(move[pp].move==2)	cout<<"u";
				else if(move[pp].move==3)	cout<<"r";
				pp=move[pp].father;
			}
			cout<<endl;
		}
	}
/*
	time(&end);
	cout<<end<<endl;
	cout<<(end-beg)<<endl;
*/
	return 0;
}


