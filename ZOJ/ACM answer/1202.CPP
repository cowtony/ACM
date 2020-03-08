 //1202.cpp
 #include<iostream.h>

 int main(){
	char str[10000];
	int N;
	int a[12];
	while(cin>>N){
		int i;int sum=0;int add[13];
		for(i=0;i<=13;i++) add[i]=1;
		for(i=0;i<N;i++){
			cin>>a[i];
			int flag=0;
			for(int j=0;j<i;j++)
				if(a[j]==a[i]){flag=1;break;}
			if(flag==1) add[i]++;
			sum=sum+a[i];
		}
		str[0]=48;
		for(i=1;i<10000;i++)
			str[i]=48;
		int j;
		for(i=2;i<=sum;i++){
			char temp[10000];
			if(i==2) temp[0]=49;else temp[0]=str[0];
			for(int t=1;t<10000;t++) temp[t]=str[t];


			int  t1=i%10;
			int leave=0;
			for(j=0;j<10000;j++){


				int ww;

				ww=(temp[j]-48)*t1;

				str[j]=ww%10+48+leave;

				leave=ww/10;
				if(str[j]>57){ leave=leave+(str[j]-48)/10;
								str[j]=(str[j]-48)%10+48;
				 }

			}

			int t2=i/10;
			if(t2>0){
			   int  t_ch[10000];
				for(int t=0;t<10000;t++) t_ch[t]=0;
				int leave=0;
				for(j=0;j<10000;j++){

					int ww;

					ww=(temp[j]-48)*t2;

					t_ch[j]=ww%10+leave;
					leave=ww/10;
					if(t_ch[j]>9){ leave+=(t_ch[j])/10;
									t_ch[j]=(t_ch[j])%10;
					}

				}
				int left=0;
				for(int tt=1;tt<10000;tt++){
						str[tt]+=t_ch[tt-1]+left;
						if(str[tt]>57) {
							left=(str[tt]-48)/10;
							str[tt]=(str[tt]-48)%10+48;
						}
						else left=0;
				}

			}


		}
		for(i=0;i<N;i++){
			int point;
			for(int j=39;j>=0;j--)
				if(str[j]!=48){ point=j;break;}

			for(int tt=2;tt<=a[i];tt++){
				int leave=0;
				for(int t=point;t>=0;t--){
					int temp=str[t]-48+leave*10;
					leave=temp%tt;
					str[t]=temp/tt+48;

				}
			}
		}
		for(i=1;i<13;i++){
			if(add[i]==1) continue;
			int point;
			for(int j=39;j>=0;j--)
				if(str[j]!=48){ point=j;break;}

			for(int tt=2;tt<=add[i];tt++){
				int leave=0;
				for(int t=point;t>=0;t--){
					int temp=str[t]-48+leave*10;
					leave=temp%tt;
					str[t]=temp/tt+48;
				}
			}
		}
		int point;
			for(int jj=39;jj>=0;jj--)
				if(str[jj]!=48){ point=jj;break;}
		for(i=point;i>=0;i--)
		cout<<str[i];
		cout<<endl;

	}
	 return 0;
 }









