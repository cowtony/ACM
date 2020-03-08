 #include<iostream.h>
 #include<math.h>

 int main(){
	int n;
	cin>>n;float x[101],y[101];    int amount=0;
	while(n!=0){

		amount++;
		int i;
		for(i=1;i<=n;i++)
			cin>>x[i]>>y[i];
		if(amount!=1) cout<<endl;
		int flag[101];
		for(i=1;i<=n;i++) flag[i]=0;
		float sum=0;
		int point=0;int from=1;
		while(point<n-1){
			point++;
			flag[from]=1;int fl=0;int ptr;
			double min;
			for(int j=1;j<=n;j++)
			if(flag[j]==1){
			for(i=1;i<=n;i++){

				if(flag[i]==0){
					float dis;
					dis=sqrt((x[j]-x[i])*(x[j]-x[i])+
					(y[j]-y[i])*(y[j]-y[i]));

					 if(fl==0){ min=dis;ptr=i;fl=1;}
					 else if(dis<min){



						min=dis;ptr=i;

						}
				}

			}

			}
			sum=sum+min;
			from=ptr;
		}
		cout<<"Case #"<<amount<<":"<<endl;
		cout.precision(2);
		cout.setf(ios::showpoint);
		cout<<"The minimal distance is: "<<sum<<endl;
		cin>>n;
	}
	return 0;
 }


