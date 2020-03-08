#include <stdio.h>

struct Rect{
	int x1,x2,y1,y2;	
};
Rect rect[200];
int rn;

int min(int &x ,int &y){
	if(x<y)
		return x;
	else
		return y;
}

int max(int &x ,int &y){
	if(x>y)
		return x;
	else
		return y;
}

void swap(Rect &x, Rect& y){
	Rect t=x;
	x=y;
	y=t;
}

int istact(int i, int j){
	if(rect[j].x1>rect[i].x2 || rect[j].x2<rect[i].x1 || rect[j].y1>rect[i].y2	|| rect[j].y2<rect[i].y1){
		return 0;
	}
	else
		return 1;
}

void imerge(int i,int j){
	rect[i].x1=min(rect[i].x1, rect[j].x1);
	rect[i].y1=min(rect[i].y1, rect[j].y1);
	rect[i].x2=max(rect[i].x2, rect[j].x2);
	rect[i].y2=max(rect[i].y2, rect[j].y2);
	swap(rect[j], rect[rn-1]);
	rn--;
}

main(){
	int width, height, n, i, j;
	int x, y, r;
	
//	freopen("data.txt", "r", stdin);
	while (scanf("%d%d%d", &width, &height, &n)>0)
  {

  	rn=0;
	  for( i=0; i<n; i++){
		  scanf("%d%d%d", &x, &y, &r);

  		rect[i].x1=x-r;
	  	rect[i].x2=x+r;
		  rect[i].y1=y-r;
  		rect[i].y2=y+r;
	  }

  	rn=n;
	  int ind=1;
  	while(ind==1)
    {
	  	ind=0;
  		for(i=0;i<rn;i++){
	  		for(j=i+1;j<rn;j++){
		  		if(istact(i,j)==1){
			  		imerge(i,j);
				  	ind=1;
  				}
	  		}
		  }
  	}

  	int ans=width*height;
	  for(i=0;i<rn;i++)
		  ans-=(rect[i].x2-rect[i].x1)*(rect[i].y2-rect[i].y1);

	  printf("%d\n", ans);
  }
	return 0;
}

