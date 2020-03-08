 #include<iostream.h>


 int fullmatch(int line[][70],int major[],int course,int student)
 {
	int link[50],linky[70];int statx[50],staty[70]; int up[70];
	int totalx=0;
	int used[70];
	int inputx[50];
	int i,j,t;
	for(i=1;i<=course;i++){	link[i]=0;statx[i]=0;}
	for(i=1;i<=student;i++){up[i]=0;linky[i]=0;staty[i]=0;used[i]=0;}
	for(i=1;i<=course;i++)
	{
		if(link[i])	continue;
		int temp=i;
		while(1){

			if(!statx[i]) inputx[++totalx]=i;
			for(j=1;j<=totalx;j++)	cout<<inputx[j]<<" ";
			cout<<endl;
			statx[i]=1;
			for(j=1;j<=totalx;j++)
			{
				int pot=inputx[j];
				int ttt;
				for(ttt=1;ttt<=major[pot];ttt++)
				{

					t=line[pot][ttt];

					if(staty[t])	continue;
					else	break;
				}
				if(ttt!=major[pot]+1)	break;
			}
			if(j==totalx+1)	return 0;
			up[t]=inputx[j];
			int uppt;
			if(used[t]==0)
			{

				while(1)
				{
					uppt=up[t];

					int tt=link[uppt];linky[t]=uppt;
					link[uppt]=t;
					used[t]=1;
					if(link[uppt]==0)	break;

					t=tt;
				}
				break;
			}
			else{

				staty[t]=1;
				i=linky[t];
			}
		}

		totalx=0;

		for(j=1;j<=student;j++)    { up[j]=0;staty[j]=0;}
		for(j=1;j<=course;j++)     {statx[j]=0;}
		i=temp;
	}
	return 1;

 }

 int main()
 {

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int course,student;
		cin>>course>>student;
		int j,t;int line[50][70];
		int major[50];int temp;int have_cour[70];
		for(j=1;j<=student;j++)	have_cour[j]=0;

		for(j=1;j<=course;j++)
		{	cin>>major[j];

			for(t=1;t<=major[j];t++)
			{	cin>>temp;
				have_cour[temp]=1;
				line[j][t]=temp;
			}
		}
		for(j=1;j<=student;j++)
			if(!have_cour[j])	break;
		if(j<=student) {cout<<"NO"<<endl;continue;}
		for(j=1;j<=course;j++)
			if(major[j]==0)	break;
		if(j<=course) {cout<<"NO"<<endl;continue;}

		int tpt=fullmatch(line,major,course,student);

		if(tpt) cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	return 0;
 }

