 #include<iostream.h>
 static int n;static int sum;
 int doing(int i,int k){
	if(i>k) return 0;
	else if(i==k) return 1;
	else {for(int j=i;j<=k;j++){
			sum=sum+doing(j+1,n-j);
		}
	}
  return 1;
 }
 int main(){

	cin>>n;
	while(n!=0){
		sum=0;
		doing(1,n);
		cout<<sum<<endl;
		cin>>n;
	}
	return 0;
 }