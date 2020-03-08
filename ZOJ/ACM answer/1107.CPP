 //accepted

 #include<iostream.h>

 static long max[101][101];int flag[101][101];
 static int nnn,kkk;
 static long core[101][101];

 long doing(int i,int j){
	if(flag[i][j]==1) {return max[i][j];}

	if(i==0&&j==0){max[i][j]=core[i][j];flag[i][j]=1; return core[i][j];}

	int tt,qq;long mx=0;
	for(tt=i-kkk;tt<=i+kkk;tt++){
		if(tt<0) continue;
		if(tt>=nnn) break;
		if(core[tt][j]<core[i][j]){
			long sum=doing(tt,j);
			if(sum>mx) mx=sum;

		}
	}

	for(qq=j-kkk;qq<=j+kkk;qq++){
		if(qq<0) continue;
		if(qq>=nnn) break;
		if(core[i][qq]<core[i][j]){
			long sum=doing(i,qq);
			if(sum>mx) mx=sum;

		}
	}

	if(mx==0) max[i][j]=0;
	else	max[i][j]=mx+core[i][j];
	flag[i][j]=1;

	return max[i][j];
 }


  int main(){
	cin>>nnn>>kkk;

	while(nnn!=-1||kkk!=-1){

		int tt,qq;
		for(tt=0;tt<nnn;tt++)
			for(qq=0;qq<nnn;qq++)
				flag[tt][qq]=0;

		for(tt=0;tt<nnn;tt++)
			for(qq=0;qq<nnn;qq++)
				cin>>core[tt][qq];
		for(tt=0;tt<nnn;tt++)
			for(qq=0;qq<nnn;qq++)
				doing(tt,qq);
		long mx=0;
		for(tt=0;tt<nnn;tt++)
			for(qq=0;qq<nnn;qq++){

				if(max[tt][qq]>mx) mx=max[tt][qq];
			}

		 cout<<mx<<endl;
		 cin>>nnn>>kkk;
	 }
	 return 0;
}
