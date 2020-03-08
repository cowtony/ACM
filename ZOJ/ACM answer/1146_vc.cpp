//117116 2003-04-12 02:14:41 Accepted 1146 C++ 00:00.00 436K just for play 
#include<iostream.h>
#include<string.h>
#include<stdio.h>

int size;
void draw(int num,int row)
{
	int i;
	if(row==1)
	{
		if(num==1||num==4)
		{
			for(i=1;i<=size+2;i++)
				cout<<" ";
		}
		else	
		{
			cout<<" ";
			for(i=1;i<=size;i++)
				cout<<"-";
			cout<<" ";
		}
	}
	else if(row==size+2)
	{
		if(num==0||num==1||num==7)
		{
			for(i=1;i<=size+2;i++)
				cout<<" ";
		}
		else	
		{
			cout<<" ";
			for(i=1;i<=size;i++)
				cout<<"-";
			cout<<" ";
		}
	}
	else if(row==2*size+3)
	{
		if(num==1||num==7||num==4)
		{
			for(i=1;i<=size+2;i++)
				cout<<" ";
		}
		else	
		{
			cout<<" ";
			for(i=1;i<=size;i++)
				cout<<"-";
			cout<<" ";
		}
	}
	else if(row>1&&row<size+2)
	{
		if(num==1||num==2||num==3||num==7)
		{
			for(i=1;i<=size+1;i++)
				cout<<" ";
			cout<<"|";
		}
		else if(num==5||num==6)
		{
			cout<<"|";
			for(i=1;i<=size+1;i++)
				cout<<" ";
		}
		else
		{
			cout<<"|";
			for(i=1;i<=size;i++)
				cout<<" ";
			cout<<"|";
		}
	}
	else
	{
		if(num==1||num==3||num==4||num==5||num==7||num==9)
		{
			for(i=1;i<=size+1;i++)
				cout<<" ";
			cout<<"|";
		}
		else if(num==2)
		{
			cout<<"|";
			for(i=1;i<=size+1;i++)
				cout<<" ";
		}
		else
		{
			cout<<"|";
			for(i=1;i<=size;i++)
				cout<<" ";
			cout<<"|";
		}
	}
}


	

		
	
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char str[10];
	while(cin>>size>>str)
	{
		int i,j;
		if(size==0&&strcmp(str,"0")==0)	break;
		int len=strlen(str);
		for(j=1;j<=2*size+3;j++)
		{
			for(i=0;i<len;i++)
			{
				if(i)	cout<<" ";
				draw(str[i]-'0',j);
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
