 #include<iostream.h>
 int n;int line[101][101];int dfn[101];int low[101];
 int sum;int used[101][10];int isroot[101];int father[101];
 int sumroot;int lev;
 void dfs(int note)
 {
	int i;lev++;
	dfn[note]=lev;
	low[note]=lev;

	for(i=0;i<n;i++)
		if(line[note][i]&&!used[note][i])
		{
			used[note][i]=1;
			if(dfn[i]){low[note]=(low[note]<dfn[i])?low[note]:dfn[i];continue;}
			father[i]=note;
			dfs(i);
		}
	if(note==0)	return;
	if(dfn[father[note]]==0)	sumroot++;
	else
	{
		int temp=father[note];
		if(low[note]<dfn[temp])
			low[temp]=(low[temp]<low[note])?low[temp]:low[note];
		else if(!isroot[temp]){isroot[temp]=1;cout<<temp<<"=="<<endl;sum++;}
	}
 }





 int main()
 {
	int m;
	cin>>m;
	while(m--)
	{
		int robotin;int i,j;
		cin>>n>>robotin;
		int temfrom,temto;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{line[i][j]=0;used[i][j]=0;}
		for(i=0;i<n;i++){dfn[i]=0;isroot[i]=0;low[i]=0;}
		sum=0;sumroot=0;lev=0;

		cin.get();char ch;
		while(1)
		{
			cin.get(ch);
			if(ch=='\n')	break;
			cin.putback(ch);
			cin>>temfrom>>temto;
			line[temfrom][temto]=1;
			cin.get(ch);
		}
		cin.get();
		dfs(0);
		if(!sumroot>1&&!isroot[0])	sum++;
	}
	return 0;
 }



