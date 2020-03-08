 #include<iostream.h>

 #include<string.h>


 float chcur[30][30];
 const float EP=0.00000001;
 int n,visit[30];float val[30];int lev=0;
 int backtract(int cur,float sum)
 {


	int i;
	for(i=0;i<n;i++)
	{
		if(chcur[cur][i]>EP)
		{
			if(visit[i])
			{
				if(sum*chcur[cur][i]-val[i]>EP) return 1;
				continue;
			}
			visit[i]=1;val[i]=sum*chcur[cur][i];
			if(backtract(i,sum*chcur[cur][i])) return 1;
			visit[i]=0;val[i]=0;
		}
	}

	return 0;

 }


 int possible( )
 {
	int i,j;
	i=0;
	float sum;
	for(j=0;j<n;j++){ visit[j]=0;val[j]=0;}
	sum=1.0;val[i]=1.0;visit[i]=1;
	if(backtract(i,sum)) return 1;


	return 0;
 }



 int main()
 {
	int amount=0;
	while(1)
	{
		int m;int i,j,t;
		char money[30][30];
		cin>>n;if(n==0) break;


		amount++;
		for(i=0;i<n;i++)	cin>>money[i];
		char temstr1[30],temstr2[30];float temcur;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++) chcur[i][j]=0;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>temstr1>>temcur>>temstr2;
			for(j=0;j<n;j++)
				if(strcmp(temstr1,money[j])==0) break;
			for(t=0;t<n;t++)
				if(strcmp(temstr2,money[t])==0) break;
			chcur[j][t]=temcur;
		}
		if(possible()) cout<<"Case "<<amount<<": Yes"<<endl;
		else cout<<"Case "<<amount<<": No"<<endl;
	}
	return 0;
 }


