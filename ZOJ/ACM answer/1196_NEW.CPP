 #include<iostream.h>
 static int pot[2][31];int to[201];
 static int distance[201];
 void sort(int a[],int len){
	for(int i=1;i<len;i++){
		int point=i;
		for(int j=i+1;j<=len;j++)
			if(a[point]<a[j]) point=j;



		if(point!=i){
			int temp=a[point];
			int temp2=to[point];
			to[point]=to[i];a[point]=a[i];
			to[i]=temp2;a[i]=temp;



		}
	}
 }
 int add(int from,int to){
	int min=0;int j;
	for(j=from;j<=to;j++){
		int total=0;
		for(int i=from;i<=to;i++){
			if(i<=j) total=total+distance[j]-distance[i];
			else total=total+distance[i]-distance[j];
		}

		if(j==from) min=total;
		else if(total<min) min=total;

	}
	return min;
 }


 int main(){
	int n,k;
	cin>>n>>k;int point=0;
	while(n!=0||k!=0){
		point++;
		int i;
		for( i=1;i<=n;i++)
			cin>>distance[i];
		for(i=1;i<n;i++)
			to[i]=i;

		int len[200];
		for(i=1;i<n;i++){

			len[i]=distance[i+1]-distance[i];

		}
		sort(len,n-1);
		int flag[201];
		for(i=1;i<=n;i++) flag[i]=0;
		for(i=1;i<k;i++){

			flag[to[i]]=1;
		}
		int next=1;int sum=0;
		for(i=1;i<=n;i++){

			if(flag[i]==1){

				sum=sum+add(next,i);

				next=i+1;
			}
		}

		cout<<"Chain "<<point<<endl;
		cout<<"Total distance sum = "<<sum<<endl;
		cout<<endl;
		cin>>n>>k;
	}
	return 0;

 }

