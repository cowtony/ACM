//95829 2003-03-23 10:47:32 Wrong Answer 1208 C++ 00:00.01 436K Century Ghost 
//95878 2003-03-23 11:52:25 Accepted 1208 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
//#include<fstream.h>
//ofstream cout("out.txt");
//ifstream cin("in.txt");

int up,face;
int curx,cury;

int side[6][4]={{2,3,5,4},{6,3,1,4},{1,2,6,5},
				{5,6,2,1},{4,1,3,6},{4,5,3,2}};
void orientate(int& curup,int& curface,char ch)
{
	int i=0;
	if(ch=='E')
	{
		curx++;		
		for(i=0;i<4;i++)
			if(side[curup-1][i]==curface)	break;			
		curup=side[curup-1][(i+3)%4];
	}
	if(ch=='N')
	{
		cury++;
		int temp=curup;
		curup=curface;
		curface=7-temp;
	}
	if(ch=='W')
	{
		curx--;
		for(i=0;i<4;i++)
			if(side[curup-1][i]==curface)	break;
		curup=side[curup-1][(i+1)%4];
	}
	if(ch=='S')
	{
		cury--;
		int temp=curface;
		curface=curup;
		curup=7-temp;
	}
}





int main()
{
	cout<<"Problem 2 by team x"<<endl;
	while(cin>>up>>face)
	{
		cout<<endl;
		char move[100];char temp;
		int pt=0;curx=0,cury=0;
		int curup=up;int curface=face;
		int needcon=1;
		if(up+face==7||up==face)	needcon=0;
		while(cin.get(temp))
		{
			if(temp=='\n')	break;
			cin.get(temp);			
			if(!needcon)	continue;
			move[pt++]=temp;
			orientate(curup,curface,temp);
		}
//		for(int j=0;j<pt;j++)	cout<<move[j]<<" ";
//		cout<<endl;
		if(!needcon)
		{
			cout<<"Invalid initial orientation:     top = "<<up<<"  front = "<<face<<endl;
			continue;
		}
		cout<<"Initial orientation:             ";
		cout<<"top = "<<up<<"  "<<"front = "<<face<<endl;
		cout<<"Moves:";
		int i;
		for(i=0;i<pt;i++)	cout<<" "<<move[i];
		cout<<endl;
		cout<<"Final orientation and position:  top = "<<curup<<"  front = "<<curface;
		cout<<"  x = ";
		if(curx>=0&&curx<10)	cout<<"  ";
		else if(curx>=10||(curx<0&&curx>-10))	cout<<" ";
		cout<<curx;
		cout<<"  y = ";
		if(cury>=0&&cury<10)	cout<<"  ";
		else if(cury>=10||(cury<0&&cury>-10))	cout<<" ";
		cout<<cury<<endl;
	}
	cout<<"End of problem 2 by team x"<<endl;
	return 0;
}



