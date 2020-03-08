 #include<iostream.h>
 int block[25][4];int flag[25];int used[25][25];int count;int left[25];
 int n;	int cur[25][4];int occur[10];
 int doing(int lev)
 {

	if(lev==n*n)	return 1;

	int i,j;
	for(i=0;i<n*n;i++)
	{
		if(!left[i])	continue;
		if(used[lev][flag[i]])	continue;
		used[lev][flag[i]]=1;
		if(lev%n!=0&&block[i][3]!=cur[lev-1][1])	continue;
		if(lev>=n&&block[i][0]!=cur[lev-n][2])	continue;
		if((lev+1)%n!=0&&occur[block[i][1]]==1)	continue;
		if(lev<n*(n-1)&&occur[block[i][2]]==1)	continue;
		for(j=0;j<4;j++)	occur[block[i][j]]--;
		left[i]=0;
		for(j=0;j<4;j++)	cur[lev][j]=block[i][j];
		if(doing(lev+1))	return 1;
		left[i]=1;
		for(j=0;j<4;j++)	occur[block[i][j]]++;
	}
	for(j=0;j<count;j++)	used[lev][j]=0;
	return 0;
 }

 int main()
 {

	  int game=0;
	while(1)
	{
		cin>>n;
		if(n==0)	break;
		int i,j,t;
		game++;
		for(i=0;i<10;i++)	occur[i]=0;
		for(i=0;i<n*n;i++)
			for(j=0;j<4;j++){
				cin>>block[i][j];
				occur[block[i][j]]++;
			}
		count=0;
		for(i=0;i<n*n;i++)
		{
			for(j=0;j<i;j++)
			{
				for(t=0;t<4;t++)
					if(block[i][t]!=block[j][t])	break;
				if(t==4)	break;
			}
			if(j<i)	flag[i]=flag[j];
			else	flag[i]=count++;
		}
		for(i=0;i<n*n;i++)
			for(j=0;j<count;j++)
				used[i][j]=0;
		for(i=0;i<n*n;i++)	left[i]=1;
		if(game!=1)	cout<<endl;

		cout<<"Game "<<game<<": ";
		if(doing(0))
			cout<<"Possible"<<endl;
		else	cout<<"Impossible"<<endl;
	}
	return 0;
 }


