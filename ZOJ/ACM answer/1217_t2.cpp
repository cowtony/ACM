//97509 2003-03-25 11:59:38 Time Limit Exceeded 1217 C++ 00:10.00 768K Century Ghost 
#include<iostream.h>
#include<math.h>
#include<vector>
/*
#include<fstream.h>
ofstream fout2("out_2.txt");
ofstream fout("out.txt");
ifstream fin("in.txt");
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
	int value;
	int depth;
	int used;
/*
	void print()
	{
		int i,j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				fout<<char(ch[i][j]+'0')<<" ";
			fout<<endl;
		}
		fout<<"value "<<value<<"   depth  "<<depth<<"  father  "<<father<<endl;
		fout<<"------------------------------"<<endl;

	}
*/
	eight()
	{
		used=0;
	}
/*	eight(eight& tt)
	{
		int i,j;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				ch[i][j]=tt.ch[i][j];
		used=0;
	}
*/
};
eight final;eight initial;
vector<eight>move;
int compute(eight& tt)
{
	int i,j;
	int total=0;
	int differ=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(tt.ch[i][j]!=0)
			{
				int temp=(abs(i-pos[tt.ch[i][j]][0])+abs(j-pos[tt.ch[i][j]][1]));								
				if(temp!=0)	differ++;
				total+=temp;
			}
	if(tt.ch[pos[0][0]][pos[0][1]]==0&&differ==2)	return -2;
	if(total==0)	return -1;
	if(tt.ch[pos[0][0]][pos[0][1]]!=0)	total+=5;
	total+=tt.depth;
	return total;
}
int same(eight& fir,eight& sec)
{
	int t,k;
	for(t=0;t<3;t++)	
		for(k=0;k<3;k++)
			if(fir.ch[t][k]!=sec.ch[t][k])	return 0;		
	return 1;
}
		
int canpush(eight& tt)
{
	int i;int len=move.size();
	for(i=0;i<len;i++)
	{
		if(same(move[i],tt))
		{
			if(move[i].depth>tt.depth )
			{
				move[i].value+=tt.depth-move[i].depth;
				move[i].depth=tt.depth;
				move[i].used=0;
			}
			return 0;
		}
	}
	return 1;
}

inline void copyeight(eight& from,eight& to)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			to.ch[i][j]=from.ch[i][j];
}
int bfs()
{
	while(1)
	{
		int min=1000;
		int i;int len=move.size();int pt;
		for(i=0;i<len;i++)
			if(!move[i].used&&move[i].value<min)
			{ 
				min=move[i].value;pt=i;
			}
		move[pt].used=1;
	//	fout<<pt<<"---->"<<len<<endl;
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
				temp.depth=move[pt].depth+1;
				if(canpush(temp))
				{
					temp.father=pt;
					temp.move=i;
					int tvalue=compute(temp);
					temp.value=tvalue;
					move.push_back (temp);
					if(tvalue==-1)	return (move.size()-1);
					if(tvalue==-2){	return -1;}
				}
			}
		}
	}
	return -1;
}
				
			
void changepos(eight& tt)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			pos[tt.ch[i][j]][0]=i;
			pos[tt.ch[i][j]][1]=j;
		}
}
	
int main()
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			initial.ch[i][j]=i*3+j+1;
	initial.ch[2][2]=0;
	initial.row=2;initial.col=2;
		
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
//		final.print();
		changepos(final);
		initial.father=-1;
		initial.depth=1;
		int tvalue=compute(initial);
		if(tvalue==-1)	{cout<<endl;continue;}
		if(tvalue==-2)	{cout<<"unsolvable"<<endl;continue;}
		initial.value=tvalue;

//		initial.print();
		move.clear();
		move.push_back(initial);
		int pp=bfs();
		if(pp==-1)
			cout<<"unsolvable"<<endl;
		else
		{
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
	return 0;
}


