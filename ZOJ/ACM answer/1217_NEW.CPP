 #include<iostream.h>


 struct status
 {
	char a[9];
	int mov;
	int up;
	int white;
 };

 status state[2][1000];

 long secto=0;long secbeg=0;
 long firpoint,secpoint;int can;

 int same(int pt,long n)
 {
	long i;int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<9;j++)
			if(state[pt][i].a[j]!=state[pt][n].a[j]) break;
		if(j==9) return 1;
	}
	return 0;
 }

 int invalid(long n,long to)
 {
	for(long j=0;j<=to;j++)
	{
		int add=0;int i;
		if(state[0][n].white!=state[1][j].white) continue;
		for(i=0;i<8;i++)
			if(state[0][n].a[i]!=state[1][j].a[i])	add++;
		if(add==2) return 1;
	}
	return 0;
 }
 int valid(long n,int pt,int ptsec,long fir,long sec)
 {
	long i;int j;
	for(i=fir;i<=sec;i++)
	{
		for(j=0;j<9;j++)
			if(state[pt][n].a[j]!=state[ptsec][i].a[j]) break;
		if(j==9)	return i;
	}
	return 0;
 }
 void doing()
 {
	long i,j;
	for(i=0;i<secto;i++)
	{
		for(j=0;j<9;j++)
			if(state[0][0].a[j]!=state[1][i].a[j])	break;
		if(j==9)
		{	firpoint=0;secpoint=i;return;}
	}
	long first[2],second[2];
	first[1]=secbeg;second[1]=secto;
	first[0]=0;second[0]=0;
	while(1)
	{
		long beg,end,move;int pt;int ptsec;
		if(second[1]<second[0])
		{beg=first[1];end=second[1];move=second[1]+1;pt=1;ptsec=0;}
		else{beg=first[0];end=second[0];move=second[0]+1;pt=0;ptsec=1;}
		if(pt==0&&beg>end){can=0;secbeg=first[1];secto=second[1];return;}
		for(i=beg;i<=end;i++)
		{

			if(same(pt,i))	continue;
			int tt=valid(i,pt,ptsec,first[ptsec],second[ptsec]);
			if(tt){
				if(pt==0){firpoint=i;secpoint=tt;}
				else{firpoint=tt;secpoint=i;}
				secbeg=first[1];secto=second[1];
				return;
			}
			if(invalid(i,second[1]))
			{secbeg=first[1];secto=second[1]; can=0;return;}
			int t_wh=state[pt][i].white;
			int t_mov=state[pt][i].mov;
			if(t_wh>2&&t_mov!=3)
			{
				for(j=0;j<9;j++)
				{	if(j==t_wh||j==t_wh-3) continue;
					state[pt][move].a[j]=state[pt][i].a[j];
				}
				state[pt][move].a[t_wh]=state[pt][i].a[t_wh-3];
				state[pt][move].a[t_wh-3]=48;
				state[pt][move].white=t_wh-3;
				state[pt][move].up=i;
				state[pt][move].mov=1;
				move++;
			}
			if((t_wh+1)%3!=0&&t_mov!=4)
			{
				for(j=0;j<9;j++)
				{	if(j==t_wh||j==t_wh+1) continue;
					state[pt][move].a[j]=state[pt][i].a[j];
				}
				state[pt][move].a[t_wh]=state[pt][i].a[t_wh+1];
				state[pt][move].white=t_wh+1;
				state[pt][move].a[t_wh+1]=48;
				state[pt][move].up=i;
				state[pt][move].mov=2;
				move++;
			}
			if(t_wh<7&&t_mov!=1)
			{
				for(j=0;j<9;j++)
				{	if(j==t_wh||j==t_wh+3) continue;
					state[pt][move].a[j]=state[pt][i].a[j];
				}
				state[pt][move].a[t_wh]=state[pt][i].a[t_wh+3];
				state[pt][move].white=t_wh+3;
				state[pt][move].up=i;
				state[pt][move].a[t_wh+3]=48;
				state[pt][move].mov=3;
				move++;
			}
			if(t_wh%3!=0&&t_mov!=2)
			{
				for(j=0;j<9;j++)
				{	if(j==t_wh||j==t_wh-1) continue;
					state[pt][move].a[j]=state[pt][i].a[j];
				}
				state[pt][move].a[t_wh]=state[pt][i].a[t_wh-1];
				state[pt][move].white=t_wh-1;
				state[pt][move].up=i;
				state[pt][move].a[t_wh-1]=48;
				state[pt][move].mov=4;
				move++;
			}
		}
		first[pt]=second[pt]+1;second[pt]=move-1;
	}
 }



 int main()
 {
	char input;long i,j;
	for(i=0;i<8;i++)	state[1][0].a[i]=i+1+48;
	state[1][0].a[8]=48;state[1][0].mov=0;state[1][0].up=-1;
	state[1][0].white=8;
	while(cin>>input)
	{
		can=1;
		if(input=='x') {state[0][0].a[0]=48;state[0][0].white=0;}
		else state[0][0].a[0]=input;
		for(i=1;i<9;i++)
		{
			cin>>input;
			if(input=='x') {state[0][0].a[i]=48;state[0][0].white=i;}
			else state[0][0].a[i]=input;
		}
		state[0][0].mov=0;state[0][0].up=-1;
		doing();
		if(can==0){cout<<"unsolvable"<<endl;continue;}
		int temp[1000];int ppp=0;
		while(state[0][firpoint].mov!=0)
		{
			temp[ppp++]=state[0][firpoint].mov;
			firpoint=state[0][firpoint].up;
		}
		for(i=ppp-1;i>=0;i--)
		{
			switch(temp[i])
			{
				case 1:cout<<"u";break;
				case 2:cout<<"r";break;
				case 3:cout<<"d";break;
				case 4:cout<<"l";break;
			}
		}
		int result[1000];int ttt=0;

		while(state[1][secpoint].mov!=0)
		{

			result[ttt++]=state[1][secpoint].mov;
			secpoint=state[1][secpoint].up;
		}
		for(i=0;i<ttt;i++)
		{	switch(result[i])
			{
				case 1:cout<<"d";break;
				case 2:cout<<"l";break;
				case 3:cout<<"u";break;
				case 4:cout<<"r";break;
			}
		}
		cout<<endl;
	}
	return 0;
 }







