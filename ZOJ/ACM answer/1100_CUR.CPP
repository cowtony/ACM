  #include<iostream.h>
  #include<conio.h>

  int taken[12][12];int h,w;
  long sum;
  inline void change(int&a,int& b){
	if(b==w) {a=a+1;b=1;}
	else b++;
  }
  inline void upchange(int& a,int& b){

	if(b==1) {a--;b=w;}
	else b--;
  }
  void print(){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++)
			cout<<taken[i][j]<<"\t";
		cout<<endl;
	 }
  }
  void fill(int a,int b){
//	cout<<a<<"======"<<b<<endl;
  //		print();getch();
	if(taken[a][b]==1){
		if(a==h&&b==w){ sum++;}
		else{change(a,b);
			 fill(a,b);
			upchange(a,b);
		}
	}
	else{
		 if(a==h){

			if(taken[a][b+1]) return;
			else{taken[a][b]=1;taken[a][b+1]=1;
				 change(a,b);
				 fill(a,b);
				 upchange(a,b);
				 taken[a][b]=0;taken[a][b+1]=0;
			}
		 }
		 else{
			 if(b==w){
				taken[a+1][b]=1;taken[a][b]=1;
				change(a,b);
				fill(a,b);
				upchange(a,b);
				taken[a][b]=0;taken[a+1][b]=0;
			 }
			 else{if(taken[a][b+1]==0){
					taken[a+1][b]=1;taken[a][b]=1;
					change(a,b);
					fill(a,b);
					upchange(a,b);
					taken[a][b]=0;taken[a+1][b]=0;
				}
				taken[a][b]=1;taken[a+1][b]=1;
				change(a,b);
				fill(a,b);
				upchange(a,b);
				taken[a][b]=0;taken[a+1][b]=0;
			 }
		 }
	}
  }






  int main(){
	while(cin>>h>>w){
		if(h==0&&w==0) break;
		int s=h*w;
		sum=0;
		int i,j;
		for(i=0;i<12;i++)
			for(j=0;j<12;j++) taken[i][j]=0;

		if(s%2==0) fill(1,1);
		cout<<sum<<endl;
	}
	return 0;
 }
