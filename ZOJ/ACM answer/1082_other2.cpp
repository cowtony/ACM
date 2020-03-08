 #include<iostream.h>

 int main()
 {
	int n;int i,j,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i>0)	cout<<endl;
		int m;//tt;
		cin>>m>>tt;

		for(j=0;j<m;j++)
			for(t=0;t<m;t++)
				line[j][t]=0;
		int tems,temto;
		while(cin>>tems>>temto)
		{
			line[tems][temto]=1;
		}
		int route[max];int visit[max];flag[max];
		for(j=0;j<m;j++) {visit[j]=0;flag[j]=0;route[j]=0;}
		flag[0]=0;
		test(0,visit,route,m);
		for(j=0;j<m;j++)
			cout<<j<<"---"<<flag[j]<<"=="<<route[j]<<endl;
		int min=-1;int pt=0;
		for(j=0;j<m;j++)
		{
			if(j==tt)	continue;
			if(route[j]==route[tt])
			{
				if(min==-1||visit[j]<min)
				{	min=visit[j];pt=j;}
			}
		}
		cout<<"Put guards in room "<<pt<<"."<<endl;
	}
	return 0;
 }

