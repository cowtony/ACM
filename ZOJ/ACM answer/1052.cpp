//115903 2003-04-11 12:29:55 Wrong Answer 1052 C++ 00:00.00 452K just for play 
//115945 2003-04-11 12:53:00 Wrong Answer 1052 C++ 00:00.01 452K just for play 
//116002 2003-04-11 13:12:57 Accepted 1052 C++ 00:00.01 452K just for play 

/*



		a wrong program!!!!!!!!!!!!!!!!!


*/
#include<iostream.h>
#include<string.h>
#include<stdio.h>

struct node_type
{
	bool visit;
	int change[26];
	bool out[26];
	void clear()
	{
		int i;
		for(i=0;i<26;i++)
		{
			change[i]=0;out[i]=false;
		}
		visit=false;
	}
};

node_type table[51];
int flag[51][51];
int n;

void search(int pt,bool temp_flag[],bool temp_visit[])
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		
		if(flag[i][pt])
		{
			if(temp_visit[i])	continue;
		//	if(i==pt)	continue;
			temp_visit[i]=true;
			if(table[i].visit)
			{
				for(j=0;j<26;j++)	if(table[i].out[j])	temp_flag[j]=true;
			}
			else
			{				
				search(i,temp_flag,temp_visit);
				for(j=0;j<26;j++)
					if(table[i].change[j]==1)	temp_flag[j]=true;
				for(j=0;j<26;j++)
					if(table[i].change[j]==-1)	temp_flag[j]=false;
			}
		}
	}

}

			

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int nn;int t;
	cin>>nn;
	for(t=0;t<nn;t++)
	{
		if(t)	cout<<endl;
		
		cin>>n;
		int i,j;
		for(i=1;i<=n;i++)	table[i].clear();
		memset(flag,0,sizeof(flag));
		char str[27];
		for(i=1;i<=n;i++)
		{
			cin>>str;
			if(!(strcmp(str,".")==0))
			{
				for(j=0;j<(int)strlen(str);j++)
					table[i].change[str[j]-'A']=1;
			}
			cin>>str;
			if(!(strcmp(str,".")==0))
			{
				for(j=0;j<(int)strlen(str);j++)
					table[i].change[str[j]-'A']=-1;
			}
		}

		int fir,sec;
		while(cin>>fir>>sec)
		{
			if(fir==0&&sec==0)	break;
			flag[fir][sec]=1;
		}
		for(i=1;i<=n;i++)
		{
			bool temp_flag[26];bool temp_visit[51];
			for(j=0;j<26;j++)	temp_flag[j]=false;
			for(j=1;j<=n;j++)	temp_visit[j]=false;
			temp_visit[i]=true;
			search(i,temp_flag,temp_visit);
			for(j=1;j<=n;j++)
			{
				if(flag[j][i])
				{
					int t;
					for(t=0;t<26;t++)
						if(table[j].change[t]==true)	temp_flag[t]=true;
				}
			}
			for(j=0;j<26;j++)
			{
				if(table[i].change[j]==1)	temp_flag[j]=true;
				if(table[i].change[j]==-1)	temp_flag[j]=false;
			}
			for(j=0;j<26;j++)
				if(temp_flag[j])	table[i].out[j]=true;
			table[i].visit=true;
		}
		for(i=1;i<=n;i++)
		{
			cout<<":";
			for(j=0;j<26;j++)
				if(table[i].out[j])	cout<<char(j+'A');
			cout<<":"<<endl;
		}
	}
	return 0;
}



