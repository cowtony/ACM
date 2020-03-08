 #include<iostream.h>
 struct node{
	int time;
	int mon[31];
 };

 int main(){
	int n,k;int point=0;
	while(cin>>n>>k){

		if(n==0&&k==0) break;
		point++;
		cout<<"Scenario #"<<point<<endl;



		node state[10][10];
		double val[10][1001];
		int i,j,t;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(i==j) continue;
				cin>>state[i][j].time;
				for(t=1;t<=state[i][j].time;t++) cin>>state[i][j].mon[t];
			}

		val[0][0]=0;
		for(i=0;i<n;i++)
			for(j=0;j<=k;j++) val[i][j]=0;



		for(i=1;i<n;i++) val[i][0]=-1;
		for(i=1;i<=k;i++){
			for(j=0;j<n;j++){
				if(i==k) j=n-1;
				for(t=0;t<n;t++){
					if(j==t) continue;
					if(val[t][i-1]==-1) continue;
					int pos=(i-1)%state[t][j].time+1;
					int money=state[t][j].mon[pos];

					if(money==0) continue;
					if(val[j][i]==0)
						val[j][i]=val[t][i-1]+money;
					else{double value=val[t][i-1]+money;
						if(value<val[j][i]) val[j][i]=value;



					}
				}

				if(val[j][i]==0) val[j][i]=-1;

			}
		}
		if(val[n-1][k]==-1)   cout<<"No flight possible."<<endl<<endl;
		else cout<<"The best flight costs "<<val[n-1][k]<<"."<<endl<<endl;
	}
	return 0;
 }






