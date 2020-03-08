#include<stdio.h>
const double PE=1.0e-8;
const int MAX=1000000;
struct POINT
{
	double x,y;
	POINT(double tx,double ty)
	{x=tx;y=ty;}
};
struct RECT
{
	POINT up,down;
	POINT Ldown,Rup;
	bool avail;
	RECT(POINT tup,POINT tdown)
	{
		up.x=tup.x;up.y=tup.y;
		down.x=tdown.x;down.y=tdown.y;
		Ldown.x=tup.x;Ldown.y=tdown.y;
		Rup.x=tdown.x;Rdown.y=tup.y;
	}
	void setRECT(POINT tup,POINT tdown)
	{
		up.x=tup.x;up.y=tup.y;
		down.x=tdown.x;down.y=tdown.y;
		Ldown.x=tup.x;Ldown.y=tdown.y;
		Rup.x=tdown.x;Rdown.y=tup.y;
	}
	bool point_in(POINT test)
	{
		if(up.x+PE<test.x&&test.x+PE<down.x
			&&down.y+PE<test.y&&test.y+PE<up.y)
				return true;
		return false;
	}
};

struct MAP
{
	RECT rect[MAX];
	int used;
	MAP()
	{used=0;}
	void insert(RECT added)
	{rect[used]=added;rect[used].avail=true;used++;}
	void test_insert(RECT added)
	{
		if(used==0)	insert(added);
		int i;
		for(i=0;i<used;i++)
		{
			bool ULin,URin,DLin,DRin;
			ULin=test[i].point_in(added.up);URin=test[i].point_in(added.Rup);
			DLin=test[i].point_in(added.Ldown);DRin=test[i].point_in(added.down);
			if(ULin&&URin&&DLin&&DRin)	;
			else if(ULin&&URin)
			{
				POINT temp(added.up.x,test[i].down.y);
				RECT extra(temp,added.down);
				test_insert(extra);
			}
			else if(ULin&&DLin)
			{
				POINT temp(test[i].down.x,added.up.y);
				RECT extra(temp,added.down);
				test_insert(extra);
			}
			else if(DRin&&DLin)
			{
				POINT temp(

			






	
int main()
{
