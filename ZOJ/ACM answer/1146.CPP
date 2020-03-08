
 //1146.cpp
 //accepted

 #include<iostream.h>
 #include<string.h>
 int  main(){
	int s;char dig[11];
	char char1=45,char2=124,char3=32;
	cin>>s;
	while(s!=0){


		 cin>>dig;
		 int len=strlen(dig);
		 int i;int j;
		 for(i=0;i<len;i++){
			switch(dig[i]){
				case 49:case 52:
					for(j=1;j<=s+2;j++)
					cout<<char3;
					break;
				default:
					cout<<char3;
					for(j=1;j<=s;j++)
					cout<<char1;
					cout<<char3;
					break;
			}
			if(i==len-1) cout<<endl;
			else cout<<char3;
		 }
		 for(int k=1;k<=s;k++)
			 for(i=0;i<len;i++){
				switch(dig[i]){
					case 48:case 52:case 56:case 57:
						cout<<char2;
						for(j=1;j<=s;j++)
						cout<<char3;
						cout<<char2;
						break;
					case 53:case 54:
						cout<<char2;
						for(j=1;j<=s+1;j++) cout<<char3;
						break;
					default:
						for(j=1;j<=s+1;j++) cout<<char3;
						cout<<char2;
						break;
				}
				if(i==len-1) cout<<endl;
				else cout<<char3;
			 }
		 for(i=0;i<len;i++){
			switch(dig[i]){
				case 48:case 49:case 55:
					for(j=1;j<=s+2;j++) cout<<char3;
					break;
				default:
					cout<<char3;
					for(j=1;j<=s;j++) cout<<char1;
					cout<<char3;
					break;
			}
			if(i==len-1) cout<<endl;
			else cout<<char3;
		 }
		 for(int t=1;t<=s;t++)
			for(i=0;i<len;i++){
				switch(dig[i]){
					case 50:
						cout<<char2;
						for(j=1;j<=s+1;j++) cout<<char3;
						break;
					case 48:case 54:case 56:
						cout<<char2;
						for(j=1;j<=s;j++) cout<<char3;
						cout<<char2;
						break;
					default:

						for(j=1;j<=s+1;j++) cout<<char3;
						cout<<char2;
						break;
				}
				if(i==len-1) cout<<endl;
				else cout<<char3;
			}
		 for(i=0;i<len;i++){
			switch(dig[i]){
				case 49:case 52:case 55:
					for(j=1;j<=s+2;j++) cout<<char3;
					break;
				default:
					cout<<char3;
					for(j=1;j<=s;j++) cout<<char1;
					cout<<char3;
					break;
			}
			if(i==len-1) cout<<endl;
			else cout<<char3;
		 }
		 cout<<endl;
		 cin>>s;
	}
	return 0;
 }











