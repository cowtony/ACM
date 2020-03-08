//ACCEPTED	
//by just for play

#include<iostream.h>

int a[10][5][5];int sol[10];int count;
int n[10];  int point;  int t_cou=0;

int can(int poi,int p,int q){
	int i,j;
	for(i=1;i<=n[poi];i++)
		if(a[poi][p][i]==1) {
		int t1,t2,tt;
		if(i>q) {t1=q;t2=i;}else{ t1=i;t2=q;}
		for(tt=t1;tt<=t2;tt++) if(a[poi][p][tt]==-1) break;
		if(tt==t2+1) return 0;}
	for(i=1;i<=n[poi];i++)
		if(a[poi][i][q]==1){
		int t1,t2,tt;
		if(p>i) {t1=i;t2=p;} else {t1=p;t2=i;}

		for(tt=t1;tt<=t2;tt++) if(a[poi][tt][q]==-1) break;
		if(tt==t2+1) return 0;
	 }
	 return 1;
}

void doing(int poi,int i,int j){


	int p,q;


	for(p=1;p<=n[poi]; p++){
	for(q=1;q<=n[poi];q++){
		if(i==1&&j==1);else if(p==i&&q==j) continue;
		if(a[poi][p][q]!=0) continue;


		if(!can(poi,p,q)) continue;
		a[poi][p][q]=1;
				count++;if(count>sol[poi]) sol[poi]=count;
		doing(poi,p,q);
		 a[poi][p][q]=0;   count--;
	}}

}

int main(){
  point=1;
  cin>>n[point];
  while(n[point]!=0){


	count=0;
	int q,p;char t_ch;
	for(p=1;p<=n[point];p++)
	 for(q=1;q<=n[point];q++){
		cin>>t_ch;
		if(t_ch=='X') {a[point][p][q]=-1;}
		else a[point][p][q]=0;
   }
   doing(point,1,1);
	point++;
   cin>>n[point];
  }
  for(int i=1;i<point;i++) cout<<sol[i]<<endl;


return 1;
}
