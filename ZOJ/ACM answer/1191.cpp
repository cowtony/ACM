//92301 2003-03-19 13:30:53 Wrong Answer 1191 C++ 00:00.01 548K Century Ghost 
//92478 2003-03-19 17:12:16 Accepted 1191 C++ 00:00.01 544K Century Ghost 
#include<iostream.h>
#include<string.h>
#ifdef DEBUG
#include<fstream.h>
ofstream fout;
#endif

const int max=51;
int width,heigh;
char point[max][max];
int die[max][max],dot[max][max];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void search(int h,int w,int pt)
{
	die[h][w]=pt;
	int i;
	for(i=0;i<4;i++)
	{
		int nex_h,nex_w;
		nex_h=h+dir[i][0];
		nex_w=w+dir[i][1];
		if(nex_h>=0&&nex_h<heigh&&nex_w>=0&&nex_w<width&&
			point[nex_h][nex_w]!='.'&&!die[nex_h][nex_w])
				search(nex_h,nex_w,pt);
	}
}
void  search_dot(int h,int w,int t,int pt)
{
	dot[h][w]=pt;
	int i;
	for(i=0;i<4;i++)
	{
		int nex_h,nex_w;
		nex_h=h+dir[i][0];
		nex_w=w+dir[i][1];
		if(nex_h>=0&&nex_h<heigh&&nex_w>=0&&nex_w<width&&
			point[nex_h][nex_w]=='X'&&die[nex_h][nex_w]==t&&!dot[nex_h][nex_w])
				search_dot(nex_h,nex_w,t,pt);
	}
	
}


int main()
{
//	fout.open("result.txt");
	int count=0;
	while(1)
	{
		cin>>width>>heigh;
		if(width==0&&heigh==0)	break;
		count++;
		int i,j;
		for(i=0;i<heigh;i++)
			for(j=0;j<width;j++)	cin>>point[i][j];
		memset(die,0,sizeof(die));
		memset(dot,0,sizeof(dot));
		int pt=1;
		for(i=0;i<heigh;i++)
			for(j=0;j<width;j++)
			{
				if(point[i][j]!='.'&&!die[i][j])
				{	search(i,j,pt);
					pt++;
				}
			}
#ifdef	DEBUG
		fout<<pt<<endl;
		for(i=0;i<heigh;i++)
		{	fout<<endl;
			for(j=0;j<width;j++)
				fout<<die[i][j];
		}
		fout<<endl;
#endif
		int total[7];
		memset(total,0,sizeof(total));
		for(int t=1;t<pt;t++)
		{	int dotpt=1;
			for(i=0;i<heigh;i++)
				for(j=0;j<width;j++)
				{
					if(die[i][j]==t&&point[i][j]=='X'&&!dot[i][j])
					{
						search_dot(i,j,t,dotpt);												
						dotpt++;
					}
				
				}
			total[dotpt-1]++;
		}
#ifdef DEBUG
		
		for(i=0;i<heigh;i++)
		{	fout<<endl;
			for(j=0;j<width;j++)
				fout<<dot[i][j];
		}
		fout<<endl;
#endif
		int flag=0;
		cout<<"Throw "<<count<<endl;
		for(i=1;i<=6;i++)		
			for(j=1;j<=total[i];j++)
			{
				if(flag)	cout<<" ";
				cout<<i;
				flag=1;
//注意输出格式的控制，WA是由于前面多输了几个空格

			}
		cout<<endl<<endl;
	}
	return 0;
}





