 //accepted

 #include<iostream.h>





 int main(){
	int n[100]; int a[100][14];
	int point=0;
	cin>>n[++point];
	while(n[point]!=0){
		for(int i=1;i<=n[point];i++)
			cin>>a[n[point]][i];

		cin>>n[++point];
	}

	for(int k=1;k<point;k++){
		int min=15;int cur;

		for(int j=1;j<point;j++){

			if(n[j]<min) {min=n[j];cur=j;}
		}



		int num[7];

		for(num[1]=1;num[1]<=n[cur]-5;num[1]++)
		for(num[2]=num[1]+1;num[2]<=n[cur]-4;num[2]++)
		for(num[3]=num[2]+1;num[3]<=n[cur]-3;num[3]++)
		for(num[4]=num[3]+1;num[4]<=n[cur]-2;num[4]++)
		for(num[5]=num[4]+1;num[5]<=n[cur]-1;num[5]++)
		for(num[6]=num[5]+1;num[6]<=n[cur];num[6]++){
		 for(int j=1;j<6;j++)


		 cout<<a[n[cur]][num[j]]<<" ";
		 cout<<a[n[cur]][num[6]]<<endl;
		}
		n[cur]=15;
		if(k!=point-1) cout<<endl;
	}
	return 0;
 }