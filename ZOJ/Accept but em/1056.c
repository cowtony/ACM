#include <stdio.h>
#include <math.h>
int main()
{
	int a[3000];
	int b[52][52];
	char c1,c2;
	int t1;
	int i,j,tmove,p2,t,p3;
	int p,l,headx,heady;
	while(1)
	{
		l=0;p3=0;
		for(i=0;i<52;i++)
		{
			for(j=0;j<52;j++)
			{
				if(i==25&&j>=11&&j<=30) b[i][j]=1;
				else b[i][j]=0;
			}
		}
		scanf("%d%*c",&tmove);
		if(tmove==0) break;
		for(i=0;i<40;i+=2)
		{
			a[i]=25;
		}
		for(i=1;i<40;i+=2)
		{
			a[i]=11+i/2;
		}
		t=40;
		headx=25;
		heady=30;
		c1='E';
		p=0;
		for(i=1;i<=tmove;i++)
		{
			scanf("%c",&c2);
			t1=fabs(c2-c1);
			if(t1==5||t1==18) continue;
			if(p==1||p==2) continue;
			c1=c2;
			p3++;
			b[a[l]][a[l+1]]=0;
			l+=2;
			if(c2=='E')
			{
				heady+=1;
				if(b[headx][heady]==1) {p=1;p2=i;}
				b[headx][heady]=1;
				a[t++]=headx;
				a[t++]=heady;
				if(heady>50) {p=2;p2=i;}
			}
			else if(c2=='N')
			{
				headx-=1;
				if(b[headx][heady]==1) {p=1;p2=i;}
				b[headx][heady]=1;
				a[t++]=headx;
				a[t++]=heady;
				if(headx<1) {p=2;p2=i;}
			}
			else if(c2=='W')
			{
				heady-=1;
				if(b[headx][heady]==1) {p=1;p2=i;}
				b[headx][heady]=1;
				a[t++]=headx;
				a[t++]=heady;
				if(heady<1) {p=2;p2=i;}
			}
			else if(c2=='S')
			{
				headx+=1;
				if(b[headx][heady]==1) {p=1;p2=i;}
				b[headx][heady]=1;
				a[t++]=headx;
				a[t++]=heady;
				if(headx>50) {p=2;p2=i;}
			}
		}
		if(p==0) printf("The worm successfully made all %d moves.\n",tmove);
		else if(p==1) printf("The worm ran into itself on move %d.\n",p3);
		else printf("The worm ran off the board on move %d.\n",p3);
	}
	return 0;
}



