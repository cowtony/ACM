 #include<iostream.h>

 static int a[31],distance[201],min,n,k;

 int minum(int tt,int q){
	int len1=distance[tt]-distance[a[q-1]];
	int len2=distance[a[q]]-distance[tt];
	if(len1<len2) return len1;
	else return len2;
 }

 int length(int tt){

	if(tt>=a[k]) return (distance[tt]-distance[a[k]]);
	else if(tt<=a[1]) return (distance[a[1]]-distance[tt]);
	else{for(int pp=1;pp<=k;pp++){
			if(tt==a[pp]) return 0;
			else if(tt<a[pp]) return (minum(tt,pp));
		 }
	}

  return 0;
 }


 void func(int cur){

	if(cur==k+1){long sum=0;
				for(int tt=1;tt<=n;tt++){
					sum=sum+length(tt);
				}
				if(min==-1) min=sum;
				else if(min>sum) min=sum;
	}

	else{for(int i=a[cur-1]+1;i<=n+cur-k;i++){
		a[cur]=i;
		func(cur+1);
	}
	}
 }



 int main(){
	cin>>n>>k;int point=0;
	while(n!=0||k!=0){
		for(int pp=1;pp<=n;pp++)
			cin>>distance[pp];
		min=-1;a[0]=0;point++;
		func(1);
		cout<<"Chain "<<point<<endl;
		cout<<"Total distance sum = "<<min<<endl;
		cout<<endl;
		cin>>n>>k;
	}
	return 0;
 }
