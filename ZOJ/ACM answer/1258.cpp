//103231 2003-04-01 12:40:00 Accepted 1258 C++ 00:00.03 504K Century Ghost 
#include<iostream>
#include<string>

#include<vector>
#include<algorithm>
/*
#include<fstream.h>
ifstream cin("in.txt");
ofstream cout("out.txt");
*/
using namespace std;

class chtype
{
public:
	char ch[5];
	int valid;
	chtype()
	{
		valid=1;
		ch[4]='\0';
	}
};
vector<chtype>leftcharset;
vector<chtype>rightcharset;
		
char leftchar[4][4],rightchar[4][4];
char selectch[4];
int visit[4][4];

int dir[8][2]={{-1,0},{-1,-1},{-1,1},{0,1},{0,-1},{1,0},{1,-1},{1,1}};

inline bool alpha_order(const chtype& fir,const chtype& sec)
{
	if(strcmp(fir.ch,sec.ch)<0)	return true;
	return false;
}


void cind_boogle(int row,int col,char chset[][4],vector<chtype>& tt,int lev)
{
//	cout<<row<<"  "<<col<<"  "<<lev<<endl;
	int i;
	if(lev==4)
	{
		
//		for(i=0;i<4;i++)
//			cout<<selectch[i]<<"==";
//		cout<<endl;
		int total=0;
		for(i=0;i<4;i++)
			if(selectch[i]=='A'||selectch[i]=='E'||selectch[i]=='O'
				||selectch[i]=='U'||selectch[i]=='Y'||selectch[i]=='I')
					total++;
		if(total==2)
		{
			chtype temp;
			for(i=0;i<4;i++)	temp.ch[i]=selectch[i];
			tt.push_back (temp);
		}
		return ;
	}
	int nextrow,nextcol;
	for(i=0;i<8;i++)
	{
		nextrow=row+dir[i][0];nextcol=col+dir[i][1];
		if(nextrow>=0&&nextrow<4&&nextcol>=0&&nextcol<4&&!visit[nextrow][nextcol])
		{
			visit[nextrow][nextcol]=1;
			selectch[lev]=chset[nextrow][nextcol];
			cind_boogle(nextrow,nextcol,chset,tt,lev+1);
			visit[nextrow][nextcol]=0;
		}
	}
}



	

void search_boogle(char chset[][4],vector<chtype>& tt)
{
	
	memset(visit,0,sizeof(visit));
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			visit[i][j]=1;
			selectch[0]=chset[i][j];
			cind_boogle(i,j,chset,tt,0);
			visit[i][j]=0;
		}
}
/*
void exchange(char* fir,char* sec)
{
	char temp[5];
	strcpy(temp,fir);
	strcpy(fir,sec);
	strcpy(sec,temp);
}

void sort_boogle(vector<chtype>& tt)
{
	int i,j;
	for(i=0;i<tt.size();i++)
	{
		//cout<<i<<endl;
		int pt=i;
		for(j=i+1;j<tt.size();j++)
			if(strcmp(tt[j].ch,tt[pt].ch)<0)	pt=j;
		if(pt!=i)
		{
			char temp[5];
			strcpy(temp,tt[i].ch);
			strcpy(tt[i].ch,tt[pt].ch);
			strcpy(tt[pt].ch,temp);
		}
	}
}

*/

int main()
{
	char temp;int flag=0;
	while(1)
	{
		cin>>temp;
		if(temp=='#')	break;
		if(flag)	cout<<endl;
		flag=1;
		cin.putback(temp);
		int i,j;
		for(i=0;i<4;i++)
			for(j=0;j<8;j++)
			{
				cin>>temp;
				if(j<4)	leftchar[i][j]=temp;
				else	rightchar[i][j-4]=temp;
			}
		leftcharset.clear();rightcharset.clear();
		search_boogle(leftchar,leftcharset);
		search_boogle(rightchar,rightcharset);
/*
		for(i=0;i<leftcharset.size ();i++)
			cout<<leftcharset[i].ch<<endl;
		cout<<endl;
		for(i=0;i<rightcharset.size ();i++)
			cout<<rightcharset[i].ch<<endl;
		cout<<endl;
*/
//		cout<<"......."<<endl;
		sort(leftcharset.begin(),leftcharset.end(),alpha_order);
		sort(rightcharset.begin(),rightcharset.end(),alpha_order);
//			cout<<"------"<<endl;
		
		int pre=0;
		for(i=1;i<leftcharset.size();i++)
		{
			if(strcmp(leftcharset[i].ch,leftcharset[pre].ch)==0)
				leftcharset[i].valid=0;
			pre=i;
		}
		int pt=0;
		int has_output=0;
		for(i=0;i<leftcharset.size();i++)
		{
			if(!leftcharset[i].valid)	continue;
			while(pt<rightcharset.size()&&strcmp(leftcharset[i].ch,rightcharset[pt].ch)>0)	pt++;
			if(pt==rightcharset.size())	break;
			if(strcmp(leftcharset[i].ch,rightcharset[pt].ch)==0)
			{
				cout<<leftcharset[i].ch<<endl;
				has_output=1;
			}
		}
		if(has_output==0)	cout<<"There are no common words for this pair of boggle boards."<<endl;
	}
	return 0;
}

