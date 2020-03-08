 //77919 2003-02-23 16:09:48 Wrong Answer 1103 C++ 00:00.31 2212K Century Ghost

 #include<iostream.h>

 const int max=51;

 char flag[max][max];
 int way[max][max][max];
 int visit[max][max][max];
 int n;

 int hike(int fir,int sec,int thi)
 {

	if(way[fir][sec][thi]>=0)	return way[fir][sec][thi];
	if(visit[fir][sec][thi])	return -1;
	visit[fir][sec][thi]=1;visit[fir][thi][sec]=1;visit[sec][fir][thi]=1;
	visit[sec][thi][fir]=1;visit[thi][fir][sec]=1;visit[thi][sec][fir]=1;
	int min=-1;
	int i,j;
	for(j=0;j<3;j++)
	{
		for(i=1;i<=n;i++)
		{

			if(i!=fir&&flag[i][fir]==flag[sec][thi])
			{
				int temp=hike(i,sec,thi);
				if(temp>=0&&(min<0||min>temp+1))	min=temp+1;

			}
		}
		int tt=fir;fir=sec,sec=thi,thi=tt;
	}
	if(min>=0) {
		way[fir][sec][thi]=min;way[fir][thi][sec]=min;way[sec][fir][thi]=min;
		way[sec][thi][fir]=min;way[thi][fir][sec]=min;way[thi][sec][fir]=min;
	}
	return min;
 }


 int main()
 {
	int fir,sec,thi;
	while(cin>>n)
	{
		if(n==0)	break;
		int i,j,t;
		cin>>fir>>sec>>thi;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)	cin>>flag[i][j];
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				for(t=1;t<=n;t++) {visit[i][j][t]=0;way[i][j][t]=-1;}
		for(i=1;i<=n;i++)	way[i][i][i]=0;
		hike(fir,sec,thi);
		if(way[fir][sec][thi]==-1)	cout<<"impossible"<<endl;
		else	cout<<way[fir][sec][thi]<<endl;
	}
	return 0;
 }

