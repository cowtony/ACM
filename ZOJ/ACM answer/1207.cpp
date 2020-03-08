//96373 2003-03-23 22:22:12 Wrong Answer 1207 C++ 00:00.01 436K Century Ghost 
//96426 2003-03-23 22:57:42 Accepted 1207 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
#include<string.h>
/*#include<fstream.h>
ifstream cin("in.txt");
ofstream cout("out.txt");
*/
char ch[15][15];int len;
char move[82];
int row,col;
	
void cindfirst(int& currow,int& curcol)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(ch[i][j]=='K')
			{
				currow=i;curcol=j;return;
			}
}

void change()
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
		{
			if(ch[i][j]>='0'&&ch[i][j]<='9')
			{
				if(ch[i][j]=='0')	ch[i][j]='9';
				else ch[i][j]--;
			}
		}
}
				

int main()
{
	int visit[15][15];
	cout<<"Problem 1 by team x"<<endl;
	while(cin>>ch[0])
	{
		cout<<endl;
		col=strlen(ch[0]);
		int i,j;char temp[100];int pt=1;
		while(1)
		{
			cin>>temp;
			if(temp[0]!='#'){strcpy(move,temp);break;}
			strcpy(ch[pt++],temp);
		}
		row=pt;
//		for(i=0;i<row;i++)
//			cout<<ch[i]<<endl;

			
		int currow,curcol;
		cindfirst(currow,curcol);
		int movelen=strlen(move);
		int state=0;int nextrow,nextcol;
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)	visit[i][j]=-1;
		for(i=0;i<movelen;i++)
		{
			nextrow=currow;nextcol=curcol;			
			if(move[i]=='.')	;
			else if(move[i]=='^')			
				nextrow--;
			else if(move[i]=='v')
				nextrow++;
			else if(move[i]=='<')
				nextcol--;
			else if(move[i]=='>')
				nextcol++;
			if(ch[nextrow][nextcol]=='#')
			{
				state=3;break;
			}
			else if(move[i]!='.'&&visit[nextrow][nextcol]!=-1)
			{
				state=2;break;
			}
			else if(ch[nextrow][nextcol]=='P')
			{
				state=1;break;
			}
			else if(ch[nextrow][nextcol]>='0'&&ch[nextrow][nextcol]<='9'&&
					ch[nextrow][nextcol]!='1')
			{
				state=4;break;
			}
			if(visit[currow][curcol]==-1)	visit[currow][curcol]=i;
			currow=nextrow;curcol=nextcol;
			change();
/*			for(int t=0;t<row;t++)
			{
				for(int tt=0;tt<col;tt++)
					cout<<ch[t][tt]<<" ";
				cout<<endl;
			}
*/
		}
		cout.setf(ios::right);
		cout<<"Day";
		cout.width(3);
		if(i<movelen)
			cout<<(i+1);
		else	cout<<(i);
		cout<<": ";
		if(state==2||state==3)			
			cout<<"attempt to enter room (";
		else	cout<<"entered room          (";			
			cout.width(2);
			cout<<nextrow<<",";
			cout.width(3);
			cout<<nextcol<<"); ";
		if(state==0)	cout<<"actions performed, princess not found"<<endl;
		else if(state==1)	cout<<"princess found"<<endl;
		else if(state==2){
			cout<<"previously entered on day";
			cout.width(3);
			cout<<visit[nextrow][nextcol];
			cout<<endl;
		}
		else if(state==3)
			cout<<"permanently blocked"<<endl;
		else if(state==4)
			cout<<"will be killed by dragons"<<endl;
	}
	cout<<"End of problem 1 by team x"<<endl;
	return 0;
}




