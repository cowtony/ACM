 #include<iostream.h>

 #include<string.h>

 void swap(char* ch1,char* ch2){
	char temp[8];
	strcpy(temp,ch1);strcpy(ch1,ch2);strcpy(ch2,temp);
 }

 long partion(char* ch[],long from,long to){
	long i=from;
	long j=to+1;
	char temp[8];
	strcpy(temp,ch[from]);
	while(1){
		while(strcmp(ch[++i],temp)<0){if(i==to) break;}
		while(strcmp(ch[--j],temp)>0){if(j==from) break;}
		if(i>=j) break;
		swap(ch[i],ch[j]);
	}
	strcpy(ch[from],ch[j]);
	strcpy(ch[j],temp);
	return j;
 }

 void sort(char* ch[],long from,long to){
	if(from<to){
		long p=partion(ch,from,to);
		sort(ch,from,p-1);
		sort(ch,p+1,to);
	}
 }

 void output( char tt[],long add){
	int t;
	for( t=0;t<3;t++) cout<<tt[t];
	cout<<"-";
	for(t=3;t<7;t++) cout<<tt[t];
	cout<<" "<<add<<endl;
 }


 int main(){
	long nn;long i;
	cin>>nn;
	int flag[28]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,
				  7,7,7,7,8,8,8,9,9,9,9};

	for(i=1;i<=nn;i++){
		if(i!=1) cout<<endl;
		long n;long j;
		cin>>n;
		char* ch[100001];long ptr=0;



		char str[50];
		for(j=1;j<=n;j++){
			cin>>str;
			int len=strlen(str);
			char change[10];int point=0;
			for(int t=0;t<len;t++){
				if(str[t]==45) continue;
				else if(str[t]<65) change[point++]=str[t];
				else change[point++]=flag[str[t]-65]+48;
			}
			change[point]='\0';
			ch[ptr]=new char[8];
				strcpy(ch[ptr],change);
			ptr++;
		}
		sort(ch,0,ptr-1);
		char temp[8];long add=0;
		int flag=0;
		for(j=0;j<ptr;j++){
			if(j==0) {strcpy(temp,ch[j]);add=1;}
			else{if(strcmp(ch[j],temp)==0) add++;
				 else {if(add!=1) {flag=1;output(temp,add);}

						strcpy(temp,ch[j]);add=1;
				 }
			}
		}
		if(add!=1){ output(temp,add);flag=1;}
		if(flag==0) cout<<"No duplicates."<<endl;
		for(j=0;j<ptr;j++) delete ch[j];
	}
	return 0;
 }




