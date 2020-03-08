 #include<iostream.h>
 #include<string.h>

 int main()
 {
	long val[101][101];
	int n;int i;
	int visit[101];
	long cur[101];
	long cost;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if(i!=1) cout<<endl;
		int j,k;
		int nn;cin>>nn;
		for(j=2;j<=nn;j++)
			for(k=1;k<j;k++)
			{       char ch[20];
				cin>>ch;
				if(ch[0]==120) val[j][k]=-1;
				else {
					val[j][k]=0;
					int len=strlen(ch);
					for(int tt=0;tt<len;tt++)
						val[j][k]=val[j][k]*10+ch[tt]-48;
				}


				val[k][j]=val[j][k];

			}
		for(j=1;j<=nn;j++)	val[j][j]=0;
		for(j=1;j<=nn;j++)	visit[j]=0;
		for(j=1;j<=nn;j++)	cur[j]=0;
		visit[1]=1;
		int point=1;
		while(1)
		{
			long small_val=-1;int small_num;
			int flag=0;
			for(k=1;k<=nn;k++)
			{
				if(visit[k]) continue;
				if(val[point][k]==-1) continue;
				flag=1;
				if(cur[k]==0)
				{
					cur[k]=cur[point]+val[point][k];
				}
				else if(cur[point]+val[point][k]<cur[k])
				{
					cur[k]=cur[point]+val[point][k];
				}
			}
			if(flag==0) break;
			for(k=1;k<=nn;k++)
			{
				if(visit[k]) continue;
				if(cur[k]==0) continue;
				if(small_val==-1||small_val>cur[k])
				{
					small_val=cur[k];
					small_num=k;
				}
			}

			point=small_num;
			visit[small_num]=1;
		}
		cost=0;
		for(j=1;j<=nn;j++)
		{

			 if(cost<cur[j]) cost=cur[j];
		}
		cout<<cost<<endl;
	}
	return 0;
 }






