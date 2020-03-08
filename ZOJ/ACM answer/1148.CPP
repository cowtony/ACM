 #include<iostream.h>
 #include<conio.h>

 static int status[77][77],visit[77][77];
 static int minway,curway;
 static int w,h,begx,begy,endx,endy;


 void findway(int posx,int posy)
 {
	cout<<posx<<"==="<<posy<<"=="<<curway<<endl;getch();
	if(minway!=0&&curway>minway){return ;}
	if(posx<0||posx>h+1||posy<0||posy>w+1) return;

	if(posx==endx&&posy==endy)
	{
		if(minway==0) minway=curway;
		else if(minway>curway) minway=curway;

	}
	if(visit[posx][posy]) {return;}

	if((posx!=begx||posy!=begy)&&status[posx][posy]) return;

	visit[posx][posy]=curway;

	curway++;

	findway(posx-1,posy);

	findway(posx,posy+1);

	findway(posx+1,posy) ;

	findway(posx,posy-1);


	curway--;

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
				for(j=0;j<=w+1;j++) visit[i][j]=0;
			amountpair++;minway=0;curway=0;
			cout<<"Pair "<<amountpair<<": ";
			if(((begx-endx==1||endx-begx==1)&&(begy==endy))||
			((begy-endy==1||endy-begy==1)&&(begx==endx)))
			{cout<<"0 elegments."<<endl;continue;}

			findway(begx,begy);

			if(minway==0) cout<<"impossible."<<endl;
			else cout<<(minway-1)<<" segments."<<endl;
		}
		cout<<endl;
	}
	return 0;
 }




