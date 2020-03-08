//300574 2003-09-28 00:09:02 Wrong Answer 1628 C++ 00:00.00 436K just for play 
//300598 2003-09-28 00:48:29 Accepted 1628 C++ 00:00.00 436K just for play 
#include<stdio.h>
#include<iostream.h>

char dia[9][9];
int row1,col1,row2,col2;

bool can_move()
{
	int i;
	int pt1,pt2,pt3;
	for(i=-2;i<=0;i++)
	{
		pt1=col1+i;pt2=col1+i+1;pt3=col1+i+2;
		if(pt1<1||pt1>8||pt2<1||pt2>8||pt3<1||pt3>8)	continue;
		if(dia[row1][pt1]==dia[row1][pt2]&&dia[row1][pt2]==dia[row1][pt3])	return true;
	}
	for(i=-2;i<=0;i++)
	{
		pt1=col2+i;pt2=col2+i+1;pt3=col2+i+2;
		if(pt1<1||pt1>8||pt2<1||pt2>8||pt3<1||pt3>8)	continue;
		if(dia[row2][pt1]==dia[row2][pt2]&&dia[row2][pt2]==dia[row2][pt3])	return true;
	}
	for(i=-2;i<=0;i++)
	{
		pt1=row1+i;pt2=row1+i+1;pt3=row1+i+2;
		if(pt1<1||pt1>8||pt2<1||pt2>8||pt3<1||pt3>8)	continue;
		if(dia[pt1][col1]==dia[pt2][col1]&&dia[pt2][col1]==dia[pt3][col1])	return true;
	}
	for(i=-2;i<=0;i++)
	{
		pt1=row2+i;pt2=row2+i+1;pt3=row2+i+2;
		if(pt1<1||pt1>8||pt2<1||pt2>8||pt3<1||pt3>8)	continue;
		if(dia[pt1][col2]==dia[pt2][col2]&&dia[pt2][col2]==dia[pt3][col2])	return true;
	}
	return false;
}
int main()
{
//	freopen("1628.in","r",stdin);	
	while(cin>>dia[1][1])
	{
		int i,j;
		for(i=2;i<9;i++)	cin>>dia[1][i];
		for(i=2;i<9;i++)
			for(j=1;j<9;j++)
				cin>>dia[i][j];
		
		cin>>row1>>col1>>row2>>col2;
		if((row1==row2&&(col1==col2+1||col1==col2-1))||
			(col1==col2&&(row1==row2+1||row1==row2-1)))
			;
		else	
		{
			cout<<"Illegal move!"<<endl;
			continue;
		}
		char temp=dia[row1][col1];dia[row1][col1]=dia[row2][col2];
		dia[row2][col2]=temp;
		if(can_move())
			cout<<"Ok!"<<endl;
		else	cout<<"Illegal move!"<<endl;

	}
	return 0;
}