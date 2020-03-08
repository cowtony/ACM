 //83263 2003-03-05 17:19:57 Accepted 1047 C++ 00:00.00 456K Century Ghost
 #include<iostream.h>

 int visit[21][21];
 int flag[21][21];

 int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
 int perimeter(int m,int n,int x,int y)
 {


	int count=0;
	visit[x][y]=1;
	int i;
	for(i=1;i<8;i+=2)
	{
		int nextx=x+dir[i][0],nexty=y+dir[i][1];
		if(nextx<1||nextx>m||nexty<1||nexty>n||!flag[nextx][nexty])	count++;
	}
	for(i=0;i<8;i++)
	{
		int nextx=x+dir[i][0],nexty=y+dir[i][1];
		if(nextx>0&&nextx<=m&&nexty>0&&nexty<=n&&flag[nextx][nexty]&&!visit[nextx][nexty])
			count+=perimeter(m,n,nextx,nexty);
	}
	return count;

 }
 int main()
 {
	int m,n,x,y;
	while(1)
	{       cin>>m>>n>>x>>y;
		if(m==0&&n==0&&x==0&&y==0)	break;
		int i,j;char temp;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				visit[i][j]=0;
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
			{	cin>>temp;
				if(temp=='X')	flag[i][j]=1;
				else flag[i][j]=0;

			}
		int count=perimeter(m,n,x,y);
		cout<<count<<endl;
	}
	return 0;
 }


