 #include<iostream.h>
 #include<conio.h>

 int main()
 {
	struct node
	{
		char ch[4];
		int vis;
	};
	int amount=0;
	while(1)
	{
		amount++;
		node pos[20];
		int n;cin>>n;
		if(n==0) break;
		int i,j;
		char big[65][4];char small[65][4];
		for(i=0;i<20;i++)	pos[i].vis=0;
		for(i=0;i<n;i++)
			for(j=0;j<4;j++)	cin>>big[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<4;j++)	cin>>small[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<4;j++)
			{
				int temp=big[i][j]-65;int t,k;
				if(pos[temp].vis)
				{

					for(t=0;t<4;t++)
					{
						for(k=0;k<4;k++)
							if(pos[temp].ch[t]==small[i][k]) break;
						if(k==4)	pos[temp].ch[t]=48;
					}
				}else
				{
					pos[temp].vis=1;
					for(t=0;t<4;t++)
						pos[temp].ch[t]=small[i][t];
				}
			}
		int visit[20]; int to[20];
		int match[20];
		for(i=0;i<20;i++)	visit[i]=0;
		for(i=0;i<20;i++)	match[i]=-1;
		getch();
		while(1)
		{
			int flag=1;
			for(i=0;i<20;i++)
			{
				int sum=0;int pt;
				if(pos[i].vis==0) continue;
				for(j=0;j<4;j++){
					if(pos[i].ch[j]==48) continue;
					if(visit[pos[i].ch[j]-97]&&to[pos[i].ch[j]-97]!=i){ pos[i].ch[j]=48;continue;}
					if(visit[pos[i].ch[j]-97]&&to[pos[i].ch[j]-97]==i)  continue;

					sum++;pt=j;
				}
				if(sum==1)
				{	flag=0;visit[pos[i].ch[pt]-97]=1;
					to[pos[i].ch[pt]-97]=i;
					match[i]=pos[i].ch[pt]-97;
					cout<<(char)(i+65)<<"====="<<pos[i].ch[pt]<<endl;getch();
				}
			}
			for(i=0;i<20;i++)
			if(match[i]!=-1)
				for(j=5*i/5;j<5*(i/5+1);j++)
					if(pos[j].vis)
						for(int t=0;t<4;t++)
						{
							int temp=pos[j].ch[t]-97;
							if(temp>=5*match[i]/5&&temp<5*(match[i]/5+1))
							{       flag=1;
								match[j]=temp;to[temp]=j;
								visit[temp]=1;
								cout<<(char)(j+65)<<"------"<<(char)(temp+97)<<endl;getch();
								break;
							}
						}

			if(flag) break;
		}

		cout<<"Test #"<<amount<<":";
		for(i=0;i<20;i++)
		{
			if(i%5==0) cout<<endl;
			else cout<<" ";
			cout<<(char)(i+65)<<"-";
			if(match[i]==-1) cout<<"?";
			else cout<<(char)(match[i]+97);

		}
		cout<<endl;
	}
	return 0;
 }




