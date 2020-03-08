 //accepted

 #include<iostream.h>

 int main()
 {
	int nn;
	cin>>nn;
	while(nn!=0)
	{
		int num[1001];int is_out[1001];int put[1001];
		cin>>num[0];
		while(num[0]!=0)
		{
			int i;  int can=1;
			for(i=1;i<nn;i++)    	cin>>num[i];
			for(i=1;i<=nn;i++)	is_out[i]=0;
			int top=0;int point=0; put[point]=0;
			for(i=0;i<nn;i++)
			{

				if(num[i]<top)
				{
					can=0;break;
				}
				if(num[i]==top)
				{
					if(point!=0) point--;
				}
				for(int j=top+1;j<num[i];j++)
				{
					if(is_out[j]==0)
					{
						put[++point]=j;
					}
				}
				is_out[num[i]]=1;
				top=put[point];
			}


			if(can==0) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
			cin>>num[0];
		}
		cout<<endl;
		cin>>nn;
	}
	return 0;
 }







