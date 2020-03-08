 //56024 2002-11-22 00:07:06 Accepted 1311 C++ 00:00.05 520K Century Ghost
 #include<iostream.h>


 int line[101][101];int n;
 int used[101][101]; int father[101];
 int dfn[101];	int low[101];int isroot[101];
 int sum;
 int sumroot;int lev;

 void dfs(int note)
 {
	int i;lev++;
	dfn[note]=lev;
	low[note]=lev;
	for(i=1;i<=n;i++)
		if(line[note][i]&&!used[note][i])
		{
			used[note][i]=1;used[i][note]=1;
			if(dfn[i]){low[note]=(low[note]<dfn[i])?low[note]:dfn[i];continue;}
			father[i]=note;
			dfs(i);
		}
	if(note==1)	return;
	if(dfn[father[note]]==1)	sumroot++;
	else
	{
		if(low[note]<dfn[father[note]])
			low[father[note]]=(low[father[note]]<low[note])?low[father[note]]:low[note];
		else if(!isroot[father[note]]){isroot[father[note]]=1;sum++;}
	}
 }



 int main()
 {

	while(1)
	{
		int i,j;
		cin>>n;
		if(n==0)	break;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{line[i][j]=0;used[i][j]=0;}
		for(i=1;i<=n;i++){dfn[i]=0;isroot[i]=0;low[i]=0;}
		sum=0;sumroot=0;lev=0;
		while(1)
		{
			int beg,temp;char ch;
			cin>>beg;
			if(beg==0)	break;
			while(1)
			{
				cin>>temp;
				line[beg][temp]=1;
				line[temp][beg]=1;
				cin.get(ch);
				if(ch=='\n')	break;
			}
		}
		dfs(1);
		if(sumroot>1&&!isroot[1])	sum++;
		cout<<sum<<endl;
	}
	return 0;
 }







