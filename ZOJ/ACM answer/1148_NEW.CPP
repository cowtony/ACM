 #include<iostream.h>



 static int status[80][80],visit[80][80][5];
 static int w,h,begx,begy,endx,endy;
 static int minway=0;

 struct node
 {	int x,y;
	int up;

 };

 int calway(node fir,node sec)
 {
	if(fir.x==sec.x)
	{
		if(fir.y>sec.y) return 2;
		else return 4;
	}
	else
	{
		if(fir.x>sec.x) return 3;
		else return 1;
	}
 }
 void findway()
 {
	node pos[110000];minway=0;
	pos[0].x=begx;pos[0].y=begy;  pos[0].up=-1;
	for(int l=1;l<=4;l++) visit[begx][begy][l]=1;
	int fir,sec;
	fir=0;sec=0; int flag=0;
	while(1)
	{
		int i,j;int move=sec+1;
		if(fir>sec){return ;}

		for(i=fir;i<=sec;i++)
		{
			int tempx=pos[i].x;int tempy=pos[i].y;


			if(tempx==endx&&tempy==endy)
			{
				int add=1;int pt=pos[i].up;int way=calway(pos[i],pos[pt]);
				while(pos[pt].up!=-1)
				{
					int tt=pos[pt].up;
					int tempway=calway(pos[pt],pos[tt]);
					if(tempway!=way){add++;way=tempway;}
					pt=tt;
				}

				if(minway==0) minway=add;
				else if(add<minway) minway=add;
			}



			if(tempx<0||tempx>h+1||tempy<0||tempy>w+1) continue;
			int tempway;
			if(i!=0) tempway=calway(pos[i],pos[pos[i].up]);
			if(i!=0&&visit[tempx][tempy][tempway]) continue;
			if(flag&&status[tempx][tempy]) continue;
			if(i!=0)
			visit[tempx][tempy][tempway]=1;flag=1;
			pos[move].x=tempx-1;pos[move].y=tempy;pos[move].up=i;
			move++;
			pos[move].x=tempx;pos[move].y=tempy+1;pos[move].up=i;
			move++;
			pos[move].x=tempx+1;pos[move].y=tempy;pos[move].up=i;
			move++;
			pos[move].x=tempx;pos[move].y=tempy-1;pos[move].up=i;
			move++;
		}
		fir=sec+1;sec=move-1;
	}
 }








 int main()
 {      int amountboard=0;
	while(1)
	{
		cin>>w>>h;
		if(w==0&&h==0) break;

		char ch;amountboard++;
		cout<<"Board #"<<amountboard<<":"<<endl;
		int i,j;
		for(i=1;i<=h;i++)
		{       cin.get(ch);
			for(j=1;j<=w;j++)
			{
				cin.get(ch);
				if(ch=='X') status[i][j]=1;
				else status[i][j]=0;
			}
		}
		for(i=0;i<=w+1;i++) {status[0][i]=0;status[h+1][i]=0;}
		for(i=0;i<=h+1;i++) {status[i][0]=0;status[i][w+1]=0;}
		int amountpair=0;
		while(1)
		{
			cin>>begy>>begx>>endy>>endx;
			if(begx==0&&endy==0&&begy==0&&endx==0) break;
			for(i=0;i<=h+1;i++)
				for(j=0;j<=w+1;j++)
				for(int t=1;t<=4;t++) visit[i][j][t]=0;
			amountpair++;minway=0;
			cout<<"Pair "<<amountpair<<": ";

			findway();

			if(minway==0) cout<<"impossible."<<endl;
			else cout<<(minway)<<" segments."<<endl;
		}
		cout<<endl;
	}
	return 0;
 }
