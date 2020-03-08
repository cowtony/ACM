 #include<iostream.h>

 int main()
 {
	int n;
	cin>>n;
	for(int t=1;t<=n;t++)
	{
		int flag[32][32];
		int i,j;
		for(i=0;i<32;i++)
			for(j=0;j<32;j++)	flag[i][j]=0;

		char ch;
		int x,y;
		cin>>x>>y;
		while(1)
		{
			cin>>ch;
			if(ch=='.')	break;
			else if(ch=='E')  {  flag[x][y-1]=1;x=x+1;}
			else if(ch=='W')  {  flag[x-1][y]=1;x=x-1;}
			else if(ch=='N')  {  flag[x][y]=1;y=y+1;}
			else if(ch=='S')  {  flag[x-1][y-1]=1;y=y-1;}

		}

		cout<<"Bitmap #"<<t<<endl;
		for(i=31;i>=0;i--)
		{
			for(j=0;j<32;j++)
			{	if(flag[j][i]==1)	cout<<'X';
				else	cout<<'.';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
 }


