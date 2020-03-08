 #include<iostream.h>
 char value[2][5];
 char suit[2][5];

 int s_f(int k){
	for(int i=1;i<5;i++)
		if(suit[k][i-1]!=suit[k][i]) return 0;


 int win(){
	int m,n;
	m=s_f(0);n=s_f(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger();return big;}

	m=fourking(0);n=fourking(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger2(); return big;}

	m=fullhouse(0);n=fullhouse(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n) { int big=bigger3();return big;}

	m=flush(0);n=flush(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger4();return big;}

	m=straight(0);n=straight(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger5();return big;}

	m=threeking(0);n=threeking(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger6();return big;}

	m=twopair(0);n=twopair(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger7();return big;}

	m=pair(0);n=pair(1);
	if(m&&!n) return 0;
	if(n&&!m) return 1;
	if(m&&n){ int big=bigger8();return big;}

	int big=bigger();
	return big;
 }


  void sort(){
	for(int i=0;i<4;i++){
		int point1=i;int point2=i;
		for(int j=i;j<5;j++){
			if(value[0][point1]<value[0][j]) point1=j;
			if(value[1][point2]<value[1][j]) point=j;
			if(point1!=i) {int temp=value[0][i];int temp2=suit[0][i];
							value[0][point1]=value[0][i];suit[0][point1]=suit[0][i];
							vlaue[0][i]=temp;suit[0][i]=temp2;
			}
			if(point2!=i) {int temp=value[1][i];int temp2=suit[1][i];
							value[1][point2]=value[1][i];suit[1][point2]=suit[1][i];
							value[1][i]=temp;suit[1][i]=temp2;
			}
		}
	}
  }




 int main(){
	while(cin>>value[0][0]){
		int i;
		cin>>suit[0][0];
		for(i=1;i<5;i++) cin>>value[0][i]>>suit[0][i];
		for(i=0;i<5;i++) cin>>value[1][i]>>suit[1][i];
		sort();
		int ww=win();
		if(ww=0) cout<<"Black wins."<<endl;
		else cout<<"White wins."<<endl;
	}
	return 0;
 }


