//469 2003-06-07 13:27:51 Wrong Answer 1008 C++ 00:00:01 4440K just for play 
//510 2003-06-07 13:35:59 Wrong Answer 1008 C++ 00:00:01 4440K just for play 
//803 2003-06-07 14:27:11 Accepted 1008 C++ 00:00:00 4440K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>

struct x_y
{
	int x1,y1;
	int x2,y2;
};
const int MAX=10000;
int main()
{
//	freopen("1008.in","r",stdin);
	char input[MAX][250];
	x_y record[MAX*10];
	int record_cnt;
	int nn;
	cin>>nn;
	while(nn--)
	{

		int line;
		cin>>line;

		cin.getline(input[0],250);
		int i,j;

		for(i=0;i<line;i++)

			cin.getline(input[i],250);
		int total=0;bool occur=false;
		int prex,prey;record_cnt=0;
		for(i=0;i<line;i++)
		{
			int len=strlen(input[i]);
			for(j=0;j<len;j++)
			{
				if(!occur)
				{
					if(input[i][j]=='/'&&j<len-1&&input[i][j+1]=='/')
					{	j++;break;}
				}
				if(!occur)
				{
					if(input[i][j]=='/'&&j<len-1&&input[i][j+1]=='*')
						occur=true,prex=i,prey=j,j++;							
				}

				else
				{

					if(input[i][j]=='*'&&j<len-1&&input[i][j+1]=='/')
					{	int t=record_cnt;
						record[t].x1=prex;record[t].y1=prey;
						record[t].x2=i;record[t].y2=j+1;						
						occur=false;
						total++;
						record_cnt++;
						j++;
					}
				}

			}
		}
		
		occur=false;int pt=0;
		for(i=0;i<line;i++)
		{
			int len=strlen(input[i]);
			for(j=0;j<len;j++)
			{
				if(pt<record_cnt&&record[pt].x1==i&&record[pt].y1==j)
				{	occur=true;
				}
				if(pt<record_cnt&&record[pt].x2==i&&record[pt].y2==j)
				{
					occur=false;pt++;
					continue;
				}				
				if(!occur)
				{
					if(input[i][j]=='/'&&j<len-1&&input[i][j+1]=='/')
					{	total++;break;}
				}
			}
		}
		cout<<total<<endl;
		occur=false;pt=0;
		for(i=0;i<line;i++)
		{
			int len=strlen(input[i]);
			for(j=0;j<len;j++)
			{
				if(pt<record_cnt&&record[pt].x1==i&&record[pt].y1==j)
				{	
					occur=true;
				}
				
				if(!occur)
				{
					if(input[i][j]=='/'&&j<len-1&&input[i][j+1]=='/')
					{	
						
						for(;j<len;j++)
						{
							if(input[i][j]>='a'&&input[i][j]<='z')	cout<<(char)(input[i][j]+'A'-'a');
							else	cout<<input[i][j];
						}
						break;
					}
				}
				
				if(pt<record_cnt&&record[pt].x2==i&&record[pt].y2==j)
				{
					occur=false;pt++;
					
				}
				
				if(occur)
				{
					if(input[i][j]>='a'&&input[i][j]<='z')	cout<<(char)(input[i][j]+'A'-'a');
					else	cout<<input[i][j];
				}
				else	cout<<input[i][j];			
			}
			cout<<endl;

			
		}
		cout<<endl;
	}
	return 0;
}
		
				

					


