//101295 2003-03-29 02:11:33 Runtime Error SIGSEGV 1229 C++ 00:00.22 836K Century Ghost 
//101296 2003-03-29 02:12:42 Time Limit Exceeded 1229 C++ 00:01.00 4348K Century Ghost 
//101765 2003-03-29 21:03:52 Wrong Answer 1229 C++ 00:00.22 8264K Century Ghost 
#include<iostream.h>
#include<string.h>
#include<queue>

#include<fstream.h>
ifstream fin("in.txt");
ofstream fout("out.txt");
			  
using namespace std;

long total,pos;
long visit[1000002];
long maxlev[1000002];
long maxnum=1000000;
int search()
{
	queue<long>middle;
	middle.push(0);
	visit[0]=1;
	maxlev[0]=0;
	while(!middle.empty())
	{
		
		long tt=middle.front();
		middle.pop();
		long lev=visit[tt];
//		fout<<tt<<"========="<<lev<<"==========="<<maxlev[tt]<<endl;
		for(int i=0;i<2;i++)
		{
			long temp;
			if(i==0)	temp=tt+2*lev-1;
			else temp=tt-2*lev+1;
			if(temp<=0||temp>maxnum)	continue;	
//			fout<<temp<<"------>";
			if(visit[temp])
			{	
				
				if(maxlev[temp]>temp&&maxlev[tt]>temp&&maxlev[tt]<maxlev[temp])
				{	//fout<<"change maxlev"<<maxlev[temp]<<"    ";
					maxlev[temp]=maxlev[tt];
				}
				
			}
			else 
			{	
				
				middle.push(temp);visit[temp]=lev+1;
				if(maxlev[tt]>temp)	maxlev[temp]=maxlev[tt];
				else maxlev[temp]=temp;
//				fout<<"change value "<<visit[temp]<<"  "<<maxlev[temp]<<"   ";
			}
//			fout<<endl;
		}
	}
	return 0;
}

	

int main()
{
	memset(visit,0,sizeof(visit));
	search();
	while(cin>>total>>pos)
	{
		if(total==0&&pos==0)	break;
		if(visit[pos]&&maxlev[pos]<=total)	cout<<"Let me try!"<<endl;
		else	cout<<"Don't make fun of me!"<<endl;
	}
	return 0;
}


