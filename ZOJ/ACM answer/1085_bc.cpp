 #include<iostream.h>
 const int max=100;
 int line[max][max];
 int dfn[max],low[max];
 
 int dfs(int node,int lev)
 {
        dfn[node]=lev;
        low[node]=lev;
        
 int main()
 {
	int n;int i,j,t;
	cin>>n;
	for(i=0;i<n;i++)
	{
		if(i>0)	cout<<endl;
		int m;tt;
		cin>>m>>tt;

		for(j=0;j<m;j++)
			for(t=0;t<m;t++)
				line[j][t]=0;
		int tems,temto;
		while(cin>>tems>>temto)
		{
			line[tems][temto]=1;
		}


		for(j=0;j<m;j++) {dfn[j]=0;low[j]=0;}
                int room=dfs(tt,1);
		cout<<"Put guards in room "<<pt<<"."<<endl;
	}
	return 0;
 }

