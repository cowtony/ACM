 //accepted

 #include<iostream.h>

 int main(){
	int a[1001],b[1001],point[1001];
	int max[1001];
	int po=0;
	while(cin>>a[++po]) cin>>b[po];
	po--;
	int i;
	for(i=1;i<=po;i++) point[i]=i;
	for(i=1;i<po;i++){
		int qq=i;
		for(int j=i+1;j<=po;j++)
			if(a[j]<a[qq]) qq=j;
		if(qq!=i){int temp1=a[i];int temp2=point[i];
				   a[i]=a[qq];point[i]=point[qq];
				   a[qq]=temp1;point[qq]=temp2;
		}
	}
	max[po]=1;
	for(i=po-1;i>=1;i--){
		max[i]=1;
		int mm=0;
		for(int j=po-1;j>i;j--)
			if(b[point[i]]>b[point[j]]&&a[i]!=a[j]){if(max[j]>mm) mm=max[j]; }

		if(mm!=0) max[i]=mm+1;

	}


	int mx=0;   int pt;
	for(i=po;i>=1;i--)
		if(max[i]>mx){mx=max[i];pt=i;}
	cout<<mx<<endl;
	cout<<point[pt]<<endl;
	int num=max[pt];
	int cur=pt;
	for(i=pt+1;i<=po;i++)
		if(num-max[i]==1&&a[cur]!=a[i]){cur=i;cout<<point[i]<<endl;  num=max[i];}
	return 0;
 }





