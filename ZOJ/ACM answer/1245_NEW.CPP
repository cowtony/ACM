 #include<iostream.h>

 int main()
 {
	int n;                      int amount=0;
	while(cin>>n)
	{
		if(n==0)	break;
		amount++;
		int up[101][201];int i,j;

		char ch;
		for(i=n;i>0;i--)
			for(j=1;j<2*i;j++)
			{
				cin>>ch;
				if(ch=='#')	up[i][j]=0;
				else up[i][j]=1;

			}
		for(i=4;i<=n;i++)
			for(j=4;j<2*i-3;j++)
			{
				if(j%2==1)	continue;
				if(!up[i][j]) continue;
				if(!up[i-1][j-2]||!up[i-1][j-1]||!up[i-1][j]) continue;
				int min;
				if(up[i-1][j-2]<up[i-1][j])	min=up[i-1][j-2];
				else min=up[i-1][j];
				up[i][j]=min+1;
			}
		for(i=n-1;i>0;i--)
			for(j=1;j<2*i;j++)
			{
				if(j%2==0) continue;
				if(!up[i][j]) continue;



				if(!up[i+1][j]||!up[i+1][j+1]||!up[i+1][j+2]) continue;
				int min;
				if(up[i+1][j]>up[i+1][j+2])	min=up[i+1][j+2];
				else min=up[i+1][j];
				up[i][j]=min+1;
			}



		int max=0;
		for(i=n;i>0;i--)
			for(j=1;j<2*i;j++)
				if(up[i][j]>max)	max=up[i][j];
		int count=0;
		for(i=1;i<=max;i++)
			count=count+2*i-1;
		cout<<"Triangle #"<<amount<<endl;
		cout<<"The largest triangle area is "<<count<<"."<<endl;
		cout<<endl;
	}
	return 0;
 }



