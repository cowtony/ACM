

 #include<iostream.h>


 #include<string.h>

 int main(){
	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++){
		char ch[100];
		int point=1; double flag[12];double mul[12];mul[0]=1;int pp=0;int ll=0;
		cin>>ch; int temp[12];int ii;
		for(ii=0;ii<12;ii++) flag[ii]=0;
		for(ii=0;ii<12;ii++) temp[ii]=0;
		while(point!=0){
			cin>>ch;
			char num[20];
			if(strcmp(ch,"LOOP")==0){
				point++;
				cin>>num;
				if(num[0]==110){temp[point]=1;	pp++;}
				else{int len=strlen(num);



					temp[point]=-1;
					ll++;double tt=0;mul[ll]=0;
					for(int j=0;j<len;j++)
						tt=tt*10+num[j]-48;
					mul[ll]=tt*mul[ll-1];
				}
			}
			if(strcmp(ch,"OP")==0){
				cin>>num;
				if(num[0]==110) {pp++;flag[pp]=flag[pp]+mul[ll];pp--;}
				else{

					int len=strlen(num);
					double tt=0;
					for(int j=0;j<len;j++)
						tt=tt*10+num[j]-48;
					flag[pp]=flag[pp]+tt*mul[ll];

				}
			}
			if(strcmp(ch,"END")==0){
				if(temp[point]==1) pp--;
				if(temp[point]==-1) ll--;
				point--;
			}
		}
		int ff=0;
		cout<<"Program #"<<i<<endl;
		cout<<"Runtime = ";


		for(ii=11;ii>0;ii--){
				double temp=flag[ii];
				if(temp<0) temp=-temp;
				if(temp<0.001) continue;

				if(ff==1) cout<<"+";
				ff=1;

				if(flag[ii]==1){if(ii==1) cout<<"n";
								 else cout<<"n^"<<ii;
				}
				else {  if(ii==1) cout<<flag[ii]<<"*n";
						else cout<<flag[ii]<<"*n^"<<ii;
				}



			}
			if(ff==0) cout<<flag[0]<<endl;
			else {if(flag[0]!=0) cout<<"+"<<flag[0]<<endl;
				  else cout<<endl;
				}
			cout<<endl;

	}
	return 0;
 }











