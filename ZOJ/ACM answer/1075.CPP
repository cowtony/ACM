 #include<iostream.h>

 int main()
 {
	char card[12][4];
	int flag=0;
	while(cin>>card[0][0])
	{
		cin>>card[0][1]>>card[0][2]>>card[0][3];
		if(flag) cout<<endl;
		if(flag==0) flag=1;
		int i,j,t;
		for(i=1;i<12;i++)
			for(j=0;j<4;j++)	cin>>card[i][j];
		int found=0;
		cout<<"CARDS:  ";
		for(i=0;i<12;i++)
		{
			for(j=0;j<4;j++)	cout<<card[i][j];
			if(i!=11) cout<<" ";
		}
		cout<<endl;
		cout<<"SETS:   ";
		for(i=0;i<12;i++)
			for(j=i+1;j<12;j++)
				for(t=j+1;t<12;t++)
				{

					if(((card[i][0]==card[j][0]&&card[i][0]==card[t][0])||
					    (card[i][0]!=card[j][0]&&card[i][0]!=card[t][0]&&card[j][0]!=card[t][0]))
					 &&((card[i][1]==card[j][1]&&card[i][1]==card[t][1])||
					    (card[i][1]!=card[j][1]&&card[i][1]!=card[t][1]&&card[j][1]!=card[t][1]))
					 &&((card[i][2]==card[j][2]&&card[i][2]==card[t][2])||
					    (card[i][2]!=card[j][2]&&card[i][2]!=card[t][2]&&card[j][2]!=card[t][2]))
					 &&((card[i][3]==card[j][3]&&card[i][3]==card[t][3])||
					    (card[i][3]!=card[j][3]&&card[i][3]!=card[t][3]&&card[j][3]!=card[t][3])))
					 {
						if(found!=0) cout<<"        ";
						cout<<(++found)<<".  ";
						int tt;
						for(tt=0;tt<4;tt++) cout<<card[i][tt];
						cout<<" ";
						for(tt=0;tt<4;tt++) cout<<card[j][tt];
						cout<<" ";
						for(tt=0;tt<4;tt++) cout<<card[t][tt];
						cout<<endl;
					 }
				}
		if(found==0) cout<<"*** None Found ***"<<endl;
	}
	return 0;
 }




