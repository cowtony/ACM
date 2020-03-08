 #include<iostream.h>
 #include<string.h>

 int main()
 {
	int n;
	cin>>n;
	while(n--)
	{
		int m;int i,j;
		char name[21][21];char id[21][21];
		int con[21][21];
		int adj[21];
		int flag[21];
		int iddec[21],namdec[21];
		cin>>m;
		for(i=0;i<m;i++)
			cin>>name[i];
		for(i=0;i<21;i++)
		{
			flag[i]=0;iddec[i]=0;namdec[i]=0;adj[i]=-1;
		}
		for(i=0;i<21;i++)
			for(j=0;j<21;j++)	con[i][j]=0;

		char ch,temp[21]; int idcount=0;
		while(cin>>ch)
		{
			if(ch=='Q')	break;
			cin>>temp;
			if(ch=='E')
			{
				for(i=0;i<idcount;i++)
					if(strcmp(id[i],temp)==0){flag[i]=1;break;}
				if(i==idcount)
				{	strcpy(id[idcount],temp);flag[idcount]=1;idcount++;}
			}
			if(ch=='L')
			{
				for(i=0;i<idcount;i++)
					if(strcmp(id[i],temp)==0){flag[i]=0;break;}
			}
			if(ch=='M')
			{
				for(i=0;i<m;i++)
					if(strcmp(name[i],temp)==0)	break;
				int namept=i;
				if(namdec[namept])	break;
				for(i=0;i<idcount;i++)
					if(con[namept][i])	break;
				if(i<idcount)
				{
					for(j=0;j<idcount;j++)
						if(con[namept][j]&&!flag[j])
							con[namept][j]=0;
				}
				else{
					for(j=0;j<idcount;j++)
						if(!iddec[j]&&flag[j])	con[namept][j]=1;
				}
				while(1)
				{
					int chgflag=0;
					for(j=0;j<m;j++)
					{
						if(namdec[j])	continue;
						int count=0;int pointpt;
						for(i=0;i<idcount;i++)
							if(con[j][i])  pointpt=i,count++;
						if(count==1)
						{
							chgflag=1;
							adj[pointpt]=j;
							namdec[j]=1;iddec[pointpt]=1;
							for(i=0;i<m;i++)
								con[i][pointpt]=0;
							for(i=0;i<idcount;i++)
								con[j][i]=0;
						}
					}
					if(!chgflag)	break;
				}
			}

		}
		int count1=0,count2=0;int pt1,pt2;
		for(i=0;i<m;i++)
			if(!namdec[i]){pt1=i;count1++;}
		for(i=0;i<idcount;i++)
			if(!iddec[i]){pt2=i;count2++;}
		if(count1==1&&count2==1)	adj[pt2]=pt1;

		for(i=0;i<idcount;i++)
		{
			int pt=i;
			for(j=i+1;j<idcount;j++)
				if(strcmp(id[j],id[pt])<0)	pt=j;
			if(j!=i)
			{
				char temp[21];
				strcpy(temp,id[i]);strcpy(id[i],id[pt]);
				strcpy(id[pt],temp);
				int tt=adj[i];adj[i]=adj[pt];adj[pt]=tt;
			}
		}
		for(i=0;i<idcount;i++)
		{
			cout<<id[i]<<":";
			if(adj[i]==-1)	cout<<"???"<<endl;
			else	cout<<name[adj[i]]<<endl;
		}
		if(n>=1)	cout<<endl;
	}
	return 0;
 }









