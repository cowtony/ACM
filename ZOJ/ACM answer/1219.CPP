 #include<iostream.h>

 int main(){
	int a[16];int want[1000][16];
	char ch[25];
	while(cin>>ch){
	int point=0;
	point++;
	for(int j=0;j<16;j++) want[point][j]=0;
	for(int ii=0;;ii+=2){
			if(ch[ii]==59) break;
			if(ch[ii]=='+') want[point][ch[ii+1]-65]=1;
			if(ch[ii]=='-') want[point][ch[ii+1]-65]=-1;
	}
	while(cin>>ch){
		point++;
		if(ch[0]=='.') break;
		for(int j=0;j<16;j++) want[point][j]=0;
		for(int i=0;;i+=2){
			if(ch[i]==59) break;
			if(ch[i]=='+') want[point][ch[i+1]-65]=1;
			if(ch[i]=='-') want[point][ch[i+1]-65]=-1;
		}
	}

	long i;
	for(i=0;i<16;i++) a[i]=0;
	long mm=1;for(i=0;i<16;i++) mm=mm*2;
	for(i=0;i<mm;i++){

		int j;
		for(j=1;j<point;j++){
			int tt;
			for(tt=0;tt<16;tt++){

				if(want[j][tt]==1&&a[tt]==1) break;
				if(want[j][tt]==-1&&a[tt]==0) break;
			}
			if(tt==16) break;
		}



		if(j==point) break;

		int next=1;
		for(j=0;j<16;j++){
			int temp=next+a[j];
			a[j]=temp%2;
			next=temp/2;
			if(next==0) break;
		}
	}
	if(i==mm) cout<<"No pizza can satisfy these requests."<<endl;

	else{cout<<"Toppings: ";
	for(int pp=0;pp<16;pp++)
		if(a[pp]==1) cout<<char(pp+65);
	cout<<endl;
	}
	}
	return 0;
 }



