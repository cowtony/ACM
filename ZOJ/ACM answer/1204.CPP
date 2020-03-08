 //1204.cpp
  //accepted

 #include<iostream.h>
 long a[31];long temp[31];int nn;int flag;
 void doing(int k,int max){


	for(temp[k]=temp[k-1]+1;temp[k]<=nn;temp[k]++){
		if((max-k+1)*a[temp[k]]+1>a[nn]) break;
		if(k==max+1) {
			long sum=0;
			for(int pp=1;pp<=max;pp++)
				sum=sum+a[temp[pp]];
			if(sum==a[temp[k]]){ flag=1;
				for(int pp=1;pp<max;pp++)
				cout<<a[temp[pp]]<<"+";
				cout<<a[temp[max]]<<"="<<a[temp[k]]<<endl;
			}

		 }
		 else doing(k+1,max);
	}
  }


 int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
	int j;flag=0;temp[0]=0;
	cin>>nn;
	for(j=1;j<=nn;j++) cin>>a[j];

	for(j=1;j<nn;j++){
		int point;int t;
		point=j;
		for(t=j+1;t<=nn;t++)
			if(a[t]<a[point]) point=t;
		long tem;

			tem=a[point];
			a[point]=a[j];
			a[j]=tem;

	}

	for(j=2;j<nn;j++)
	   doing(1,j);
	if(flag==0) cout<<"Can't find any equations."<<endl;
	cout<<endl;
    }
    return 0;
  }


