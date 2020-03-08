 //accepted

 #include<iostream.h>
 #include<math.h>

 int main(){
	double x[101],y[101];
	double len[101][101];
	int flag[101];
	int n;int amount=0;
	cin>>n;
	while(n!=0){
		amount++;
		int i;
		for(i=1;i<=n;i++)
			cin>>x[i]>>y[i];
		for(i=1;i<n;i++)


			for(int j=i+1;j<=n;j++)
				len[i][j]=sqrt((double)(x[i]-x[j])*(double)(x[i]-x[j])+
								(double)(y[i]-y[j])*(double)(y[i]-y[j]));
		for(i=1;i<=n;i++) flag[i]=0;
		double sum=0;
		for(int t=1;t<n;t++){
			double min=-1.0;int ptr1,ptr2;
			for(int q=1;q<n;q++)
				for(int tt=q+1;tt<=n;tt++)
					if(t==1||((flag[q]==0)^(flag[tt]==0))){
						if(min<-0.9) {min=len[q][tt];ptr1=q;ptr2=tt;}
						else{ double temp=min-len[q][tt];
							 if(temp>0.0000000001){
							min=len[q][tt];ptr1=q;ptr2=tt;}
						}
					}

			flag[ptr1]=1;flag[ptr2]=1;
			sum=sum+min;
		}

		if(amount!=1) cout<<endl;
		cout<<"Case #"<<amount<<":"<<endl;
		cout.precision(2);
		cout.setf(ios::showpoint|ios::fixed);

		cout<<"The minimal distance is: "<<sum<<endl;
		cin>>n;
	}
	return 0;
 }

