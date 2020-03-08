 #include<iostream.h>

 void add(int result[],int a[],int len1,int b[],int len2){

	while(len1>len2) {
			b[len2]=0;
			len2++;
	}
	if(len2>len1) {
			a[len1]=0;
			len1--;
	}
	for(int i=0;i<len1;i++)
		result[i]=(a[i]+b[i])%2;
 }

 void multiply(int result[],int a[],int len1,int b[],int len2){
	int i,j;
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			result[i+j]=0;
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			if(a[i]==1&&b[j]==1) result[i+j]=(result[i+j]+1)%2;

 }


 int main(){
	int m;
	cin>>m;
	int i;
	for(i=0;i<m;i++){
		int num[3][1000];
		int n[3];int j;
		for(j=0;j<3;j++){
			cin>>n[j];
			for(int tt=0;tt<n[j];tt++)
				cin>>num[j][tt];
		}
		int result[2000];
		multiply(result,num[0],n[0],num[1],n[1]);
		for(j=n[0]+n[1]-2;j>=0;j--)
			cout<<result[j]<<"\t";
		cout<<endl;
	}
	return 0;
 }








