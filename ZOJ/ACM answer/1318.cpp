//266611 2003-08-20 23:46:47 Wrong Answer 1318 C++ 00:00.01 456K just for play 
//266626 2003-08-21 00:01:39 Wrong Answer 1318 C++ 00:00.02 456K just for play 
//266638 2003-08-21 00:07:30 Accepted 1318 C++ 00:00.01 456K just for play 
#include<iostream.h>
#include<string.h>

char ver=(char)179,right_end=(char)180,up_right=(char)191,down_left=(char)192;
char down_end=(char)193,up_end=(char)194,left_end=(char)195,hor=(char)196,mid=(char)197;
char down_right=(char)217,up_left=(char)218;

int main()
{
//	ifstream cin("1318.in");
//	ofstream cout("1318.out");
	char table[101][257];
	int n;char temp[257];	
	cin>>n;
	cin.getline(temp,257);
	while(n--)
	{
		
		cin.getline(temp,257);
		int pt=0;
		while(cin.getline(table[pt],257))
		{			
			if(table[pt][0]==down_left)	break;
			pt++;			
		}
		
		int len[200];int len_pt=0;
		int i,j,t;

		for(i=0;i<=pt;i++)
		{
			int b_pt=0;
			while(table[i][b_pt]==32)	b_pt++;
			for(j=b_pt;j<=strlen(table[i]);j++)
				table[i][j-b_pt]=table[i][j];
			b_pt=strlen(table[i])-1;
			while(table[i][b_pt]==32)	b_pt--;
			table[i][b_pt+1]=table[i][strlen(table[i])];
		}
		for(i=0;i<strlen(table[0]);i++)
			if(table[0][i]==up_end)	len_pt++;
		len_pt++;
		memset(len,0,sizeof(len));
		for(i=1;i<pt;i++)
		{
			if(table[i][0]==left_end)	continue;
			int begin=-1,last_space=-1;
			int t_pt=0;
			for(j=1;j<strlen(table[i]);j++)
			{
				if(table[i][j]==ver)
				{
					if(begin>0)
					{
						if(last_space<0)	last_space=j;
						if(last_space-begin>len[t_pt])
							len[t_pt]=last_space-begin;
					}
					begin=-1,last_space=-1;t_pt++;
					continue;
				}
				if(table[i][j]!=32)
				{
					if(begin<0)	begin=j;
					last_space=-1;
				}
				if(table[i][j]==32)
				{
					if(last_space<0)	last_space=j;
				}
			}
		}
		cout<<(char)(up_left);
		for(i=0;i<len_pt;i++)
		{
			for(j=0;j<len[i]+2;j++)	cout<<(char)(hor);
			if(i<len_pt-1)	cout<<(char)(up_end);
			else	cout<<(char)(up_right);
		}
		cout<<endl;
		for(i=1;i<pt;i++)
		{
			if(table[i][0]==left_end)
			{
				cout<<(char)(left_end);
				for(j=0;j<len_pt;j++)
				{
					for(t=0;t<len[j]+2;t++)	cout<<(char)(hor);
					if(j<len_pt-1)	cout<<(char)(mid);
					else	cout<<(char)(right_end);
				}
			}
			else
			{
				cout<<(char)(ver);
				int t_pt=0;
				int begin=-1;int t_count=0;
				for(j=1;j<strlen(table[i]);j++)
				{
					if(table[i][j]==ver)
					{
						if(begin<0)	cout<<(char)(32);
						while(t_count<len[t_pt]){cout<<(char)(32);t_count++;}
						cout<<(char)(32)<<(char)(ver);
						begin=-1;t_count=0;
						t_pt++;
						continue;
					}
					if(table[i][j]!=32)
					{
						if(begin==-1)	cout<<(char)(32);
						begin=1;
					}
					if(begin>0)
					{
						
						if(t_count<len[t_pt]){t_count++; cout<<table[i][j];}
					}
				}
			}
			cout<<endl;
		}
		cout<<(char)(down_left);
		for(i=0;i<len_pt;i++)
		{
			for(j=0;j<len[i]+2;j++)	cout<<(char)(hor);
			if(i<len_pt-1)	cout<<(char)(down_end);
			else	cout<<(char)(down_right);
		}
		cout<<endl;
		if(n>0)	cout<<endl;
	}
	
	return 0;
}


						

				

		

















