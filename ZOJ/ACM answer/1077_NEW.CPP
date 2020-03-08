 #include<iostream.h>
 #include<conio.h>


 int main()
 {
	struct node
	{
		int ch[4];
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
		for(i=0;i<20;i++)
		{	pos[i].vis=0;
			for(j=0;j<4;j++)	pos[i].ch[j]=-1;
		}
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
							if(pos[temp].ch[t]==(small[i][k]-97)) break;
						if(k==4)	pos[temp].ch[t]=-1;
					}
				}else
				{
					pos[temp].vis=1;
					for(t=0;t<4;t++)
						pos[temp].ch[t]=small[i][t]-97;
				}
			}
		int match[20];int matched[20];int from[5];int to[5];int visited[20];
		for(i=0;i<20;i++)	visited[i]=0;
		for(i=0;i<n;i++)	for(j=0;j<4;j++)	visited[small[i][j]-97]=1;
		for(i=0;i<20;i++){match[i]=-1;matched[i]=-1;}
		for(i=0;i<5;i++) {from[i]=-1;to[i]=-1;}
		while(1)
		{

			int flag=1;
			for(i=0;i<20;i++)
			{
				if(pos[i].vis==0) continue;
				if(match[i]!=-1) continue;
				int add=0; int pt;
				for(j=0;j<4;j++)
				{
					int tt=pos[i].ch[j];
					if(matched[tt]!=-1) continue;
					add++; pt=j;
				}
				if(add==1)
				{
				       from[i/5]=pos[i].ch[pt]/5;to[pos[i].ch[pt]/5]=i/5;

					flag=0;match[i]=pos[i].ch[pt];matched[pos[i].ch[pt]]=i;
				}
			}
			for(i=0;i<20;i++)
			{
				if(pos[i].vis==0) continue;
				if(match[i]!=-1) continue;
				if(from[i/5]!=-1)
				{

					for(j=0;j<4;j++)
					{

						int tt=pos[i].ch[j];
						if(matched[tt]!=-1) continue;
						if(tt/5>=from[i/5]&&tt/5<from[i/5]+4)
						{
							flag=0;match[i]=tt;matched[tt]=i;break;
						}
					}
				}
			}

			for(i=0;i<20;i++)
				if(match[i]!=-1)
				{
					int t,k;    int temp=match[i];
					for(t=5*i/5;t<5*(i/5+1);t++)
					{	if(match[t]!=-1) continue;
						if(pos[t].vis)
							for(k=0;k<4;k++)
							{
								int tt=pos[t].ch[k];
								if(tt>=5*(temp/5)&&tt<5*(temp/5+1))
								{
								       from[t/5]=tt/5;to[tt/5]=t/5;
								       flag=0;	match[t]=tt;matched[tt]=t;
								}
							}
					}

				}
			int t_add=0;int t_pt;
			for(i=0;i<4;i++)
				if(from[i]==-1){ t_add++;t_pt=i;}
			if(t_add==1)
			{
				for(i=0;i<4;i++)
					if(to[i]==-1) break;

				from[t_pt]=i;
				flag=0;
			}
			t_add=0;
			for(i=0;i<20;i++)
				if(pos[i].vis==0||match[i]==-1){t_add++;t_pt=i;}
			if(t_add==1)
			{
				for(j=0;j<20;j++)
					if(matched[j]==-1||visited[j]==0) break;

				match[t_pt]=j;matched[j]=t_pt;flag=0;
				from[t_pt/5]=j/5;to[j/5]=t_pt/5;
			}



			for(i=0;i<4;i++)
			{	int add=0;int pt;
				for(j=i*5;j<(i+1)*5;j++)
					if(match[j]==-1){add++;pt=j;}

				if(add==1)
				{
					flag=0;
					for(j=i*5;j<(i+1)*5;j++)
						if(pt!=j) break;
					int temp=match[j];
					for(j=5*(temp/5);j<5*(temp/5+1);j++)
						if(matched[j]==-1) break;

					match[pt]=j;matched[j]=pt;
					from[pt/5]=j/5;to[j/5]=pt/5;
				}
			}

			if(flag)	break;
		}


		cout<<"Test #"<<amount<<":";
		for(i=0;i<20;i++)
		{
			if(i%5==0) cout<<endl;
			else cout<<" ";
			cout<<char(i+65)<<"-";
			if(match[i]!=-1) cout<<char(match[i]+97);
			else cout<<"?";
		}
		cout<<endl;
	}
	return 0;
 }





