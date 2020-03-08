 #include<iostream.h>
 #include<string.h>
 #include<math.h>

 int main(){
	double ff=sqrt(2)/2;

	double pos[5]={0,1,-1,ff,-ff};

	char ch[205];int point=0;
	while(cin>>ch){
		if(strcmp(ch,"END")==0) break;
		point++;
		cout<<"Map #"<<point<<endl;
		int len=strlen(ch);int pre=0;double x=0;double y=0;
		for(int i=0;i<len;i++){
			if(ch[i]==44||ch[i]==46){
				int num=0;int j;
				for(j=pre;j<i;j++){

					if(ch[j]<58) num=num*10+ch[j]-48;
					else {pre=i+1;break;}
				}
				int fir,sec;
				if(j==i-1){
					if(ch[j]==69) {fir=1,sec=0;}
					if(ch[j]==78) {fir=0,sec=1;}
					if(ch[j]==83) {fir=0,sec=2;}
					if(ch[j]==87) {fir=2,sec=0;}
				}
				else{if(ch[j]==78) sec=3;
						else sec=4;
					if(ch[j+1]==69) fir=3;
						else fir=4;
				}

				x+=num*pos[fir];y+=num*pos[sec];
			}
		}
		double dis=sqrt(x*x+y*y);
		cout.precision(3);
		cout.setf(ios::fixed|ios::showpoint);
		if(x<0.0001&&-x<0.0001) x=0;
		if(y<0.0001&&-y<0.0001) y=0;
		if(dis<0.0001&&-dis<0.0001) dis=0;
		cout<<"The treasure is located at ("<<x<<","<<y<<")."<<endl;

		cout<<"The distance to the treasure is "<<dis<<"."<<endl;
		cout<<endl;



	}
	return 0;
 }


