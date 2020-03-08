//84987 2003-03-08 21:51:11 Accepted 1056 C++ 00:00.00 436K Century Ghost 
#include<iostream.h>
#include<string.h>
int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}};

int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)	break;
		char move[101];
		cin>>move;
		int len=strlen(move);int i,j;
		int wormx[20],wormy[20];
		for(i=0;i<20;i++){wormx[i]=25;wormy[i]=30-i;}
		int flag=0;
		for(i=0;i<len;i++)
		{
			int pt;
			switch(move[i])
			{
			case 'W':pt=0;break;
			case 'N':pt=1;break;
			case 'E':pt=2;break;
			case 'S':pt=3;break;
			}
			for(j=19;j>0;j--){	wormx[j]=wormx[j-1];wormy[j]=wormy[j-1];}
			wormx[0]+=dir[pt][0];wormy[0]+=dir[pt][1];
			if(wormx[0]<1||wormx[0]>50||wormy[0]<1||wormy[0]>50)	{flag=1;break;}
			for(j=1;j<20;j++)
				if(wormx[0]==wormx[j]&&wormy[0]==wormy[j]){break;}
			if(j<20){flag=2;break;}
		}
		if(flag==1)
			cout<<"The worm ran off the board on move "<<(i+1)<<"."<<endl;
		else if(flag==2)
			cout<<"The worm ran into itself on move "<<(i+1)<<"."<<endl;
		else
			cout<<"The worm successfully made all "<<i<<" moves."<<endl;

	}
	return 0;
}




	



	