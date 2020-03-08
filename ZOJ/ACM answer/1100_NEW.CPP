 #include<iostream.h>
 #include<conio.h>
 long val[12][12];int flag[12][12];
 int h,w;

 int can(int a,int b){

	if(flag[a][b]==1) return 1;
	if(a==1||b==1){val[a][b]=a*b/2;flag[a][b]=1;return 1;}
	int i,j;

	if(b%2==0){
		for(i=1;i<a;i++)

			if(flag[i][b]==0) return 0;
		for(i=1;i<a;i++) val[a][b]+=val[i][b]+val[a-i][b];
			flag[a][b]=1;
	 }
	else {
		for(i=1;i<b;i++) if(flag[a][i]==0) return 0;

		for(i=1;i<b;i++) val[a][b]+=val[a][i]+val[a][b-i];
		flag[a][b]=1;
	}
	return 1;
 }
 long work(int a,int b){

	while(1){

		if(flag[a][b]==1) return val[a][b];
		int i,j;
		for(i=1;i<=11;i++)
			for(j=1;j<=11;j++){
				if(!can(i,j)) break;

				if(flag[a][b]==1) return val[a][b];
			}
	}
 }

 int main(){
	int i,j;
	for(i=1;i<12;i++)
		for(j=1;j<12;j++){
			val[i][j]=0;
			if(i*j%2==0) flag[i][j]=0;
			else flag[i][j]=1;
		}

	while(cin>>h>>w){
		if(h==0&&w==0) break;
		cout<<work(h,w)<<endl;
	}
	return 0;
 }



