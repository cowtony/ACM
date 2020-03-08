 //1016.cpp
 //accepted

 #include<iostream.h>

 int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		long a[100],b[100];a[0]=-1;long c[100];
		int j;
		for(j=1;j<=m;j++)
			cin>>c[j];
		 a[1]=c[1];
		for(j=2;j<=m;j++)
			a[j]=c[j]-c[j-1];

		for(j=1;j<=m;j++){
			int temp=j;
			long count=1;
			long left=a[temp];long right=1;
			while(left<right){
				count++;
				temp--;
				right++;
				left=left+a[temp];




			}
			b[j]=count;
		}
		for(j=1;j<=m;j++){
			if(j==m) cout<<b[j]<<endl;
			else cout<<b[j]<<" ";
		}
	}
	return 0;
 }
