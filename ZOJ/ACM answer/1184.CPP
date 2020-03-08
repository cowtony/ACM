 //1184.cpp
 //accepted

 #include<iostream.h>
 #include<string.h>

 int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char left[3][7],right[3][7],end[3][5];
		int j;
		for(j=0;j<3;j++)
			cin>>left[j]>>right[j]>>end[j];
		int a[3];int b[3][2][7];
		int len[2][3];
		for(j=0;j<3;j++){
			len[0][j]=strlen(left[j]);
			int tt;
			for(tt=0;tt<len[0][j];tt++){
				b[j][0][tt]=left[j][tt]-64;

			}

			len[1][j]=strlen(right[j]);
			for(tt=0;tt<len[1][j];tt++){
				b[j][1][tt]=right[j][tt]-64;

			}

			if(strcmp(end[j],"up")==0) a[j]=1;
			else if(strcmp(end[j],"down")==0) a[j]=2;
			else a[j]=3;


		}
		int value[13];
		for(int qq=1;qq<=12;qq++)
			value[qq]=1;
		for(j=1;j<=12;j++){
		  int count=0;int flag=0;
		  while(count<2){
			count++;
			int vv;
			if(count==1) vv=0;
			else vv=2;
			value[j]=vv;
			int sum1=0,sum2=0;int tt,qq;
			for(tt=0;tt<len[0][0];tt++){
				sum1+=value[b[0][0][tt]];

			}
			for(qq=0;qq<len[1][0];qq++)
				sum2+=value[b[0][1][qq]];


			if(a[0]==1) if(sum1<=sum2) {value[j]=1;continue;}
			if(a[0]==2) if(sum1>=sum2) {value[j]=1;continue;}
			if(a[0]==3) if(sum1!=sum2) {value[j]=1;continue;}
			sum1=0;sum2=0;
			for(tt=0;tt<len[0][1];tt++)
				sum1+=value[b[1][0][tt]];
			for(qq=0;qq<len[1][1];qq++)
				sum2+=value[b[1][1][qq]];

			if(a[1]==1) if(sum1<=sum2) {value[j]=1;continue;}
			if(a[1]==2) if(sum1>=sum2) {value[j]=1;continue;}
			if(a[1]==3) if(sum1!=sum2) {value[j]=1;continue;}
			sum1=0;sum2=0;
			for(tt=0;tt<len[0][2];tt++)
				sum1+=value[b[2][0][tt]];
			for(qq=0;qq<len[1][2];qq++)
				sum2+=value[b[2][1][qq]];

			if(a[2]==1) if(sum1<=sum2) {value[j]=1;continue;}
			if(a[2]==2) if(sum1>=sum2) {value[j]=1;continue;}
			if(a[2]==3) if(sum1!=sum2) {value[j]=1;continue;}
			flag=1;break;
		  }

		  if(flag==1) break;

		}
		char temp=j+64;
		cout<<temp<<" is the counterfeit coin and it is ";
		if(value[j]==0) cout<<"light."<<endl;
		else cout<<"heavy."<<endl;

	}
	return 0;
 }







