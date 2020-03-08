 #include<iostream.h>



 int main()
 {
	char ch[4];
	int waycol[8]={1,1,2,2,-1,-1,-2,-2};
	int wayrow[8]={2,-2,1,-1,2,-2,1,-1};
	while(cin>>ch[0])
	{
		cin>>ch[1]>>ch[2]>>ch[3];
		int begcol,begrow;int endcol,endrow;
		begcol=ch[0]-'a';begrow=ch[1]-49;endcol=ch[2]-'a';endrow=ch[3]-49;
		int temcol[100],temrow[100];
		temcol[0]=begcol;temrow[0]=begrow;
		int visit[8][8];
		int fir=0;int sec=0;int move=0;
		int i,j; int sum=0;
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				visit[i][j]=-1;
		int can=0;
		if(begcol==endcol&&begrow==endrow) ;
		else while(1)
		{
			sum++;
			for(i=fir;i<=sec;i++)
			{

				for(int  j=0;j<8;j++)
				{

					int nextcol=temcol[i]-waycol[j];
					int nextrow=temrow[i]-wayrow[j];
					if(nextcol<0||nextrow<0||nextcol>7||nextrow>7) continue;
					if(nextcol==endcol&&nextrow==endrow) {can=1;break;}
					if(visit[nextrow][nextcol]!=-1) continue;
					visit[nextrow][nextcol]=sum;
					temcol[++move]=nextcol;temrow[move]=nextrow;
				}
				if(can) break;
			}
			fir=sec+1;sec=move;
			if(can) break;
		}
		cout<<"To get from "<<ch[0]<<ch[1]<<" to "<<ch[2]<<ch[3];
		cout<<" takes "<<sum<<" knight moves."<<endl;


	}
	return 0;
 }



