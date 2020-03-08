//106077 2003-04-03 23:32:54 Time Limit Exceeded 1137 C++ 00:30.00 4376K Century Ghost 
#include<vector>
#include<string.h>
#include<iostream.h>

#include<fstream.h>
ifstream fin("in.txt");
ofstream fout("out.txt");

using namespace std;
const int maxnum=1001;
int maxval;
int curval[maxnum];
int flag[maxnum][maxnum];
bool find;
int notcon[maxnum];

void maxclique(vector<int>& tt,int cursize)
{
	if(tt.size()==0)
	{
		if(cursize>maxval)
		{
			maxval=cursize;
			find=true;
		}
	}
	int len=tt.size();
	int i,j;
	for(i=0;i<len;i++)
	{
		if(len-i+cursize<=maxval)	return;
		int sel=tt[i];
		if(cursize+curval[sel]<=maxval)	return;
		vector<int>next;
		next.clear();
		for(j=i+1;j<len;j++)
			if(flag[sel][tt[j]])	next.push_back(tt[j]);
		maxclique(next,cursize+1);
		if(find)	return;
	}
}
		
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int n;
	while(fin>>n)
	{
		int i,j;
		memset(notcon,0,sizeof(notcon));
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
		{
			char ch;
			int stu=0;
			int temtot=0;
			while(fin>>ch)
			{
				if(ch==':')	break;
				stu=stu*10+ch-'0';
			}
//			fout<<stu<<endl;
			fin>>ch;
			while(fin>>ch)
			{
				if(ch==')')	break;
				temtot=temtot*10+ch-'0';
			}
			if(temtot==0)	notcon[i]=1;
//			fout<<temtot<<endl;
			for(j=0;j<temtot;j++)
			{
				int temnum;
				fin>>temnum;
				flag[stu][temnum]=1;

			}

		}
		for(i=0;i<n;i++)
			
			for(j=0;j<n;j++)
			{
				if(i==j)	continue;
				if(flag[i][j])	flag[i][j]=0;
				else	flag[i][j]=1;
			}
/*		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				fout<<flag[i][j]<<" ";
			fout<<endl;
		}
*/
		maxval=0;
		for(i=n-1;i>=0;i--)
		{
			if(notcon[i])	continue;
			find=false;
			vector<int>pointset;
			pointset.clear();
			for(j=i+1;j<n;j++)
			{
				if(notcon[j])	continue;
				if(flag[i][j])	pointset.push_back(j);
			}
			maxclique(pointset,1);
			curval[i]=maxval;
		}
		for(i=0;i<n;i++)
			if(notcon[i])	curval[0]++;
		fout<<curval[0]<<endl;
	}
	return 0;
}


