//accepted

#include<iostream.h>
#include<string.h>
static char ch1[70],ch2[20][70];
static int num1[70],num2[70];

int  main(){
	 int key; int point=0;
	 while(cin>>key){
	   if(key==0) break;
	   point=1;
	   cin>>ch1;
	   int n=strlen(ch1);
	   int i;
	   for(i=0;i<n;i++){
		 if(ch1[i]==95) num1[i]=0;
		 else if(ch1[i]==46) num1[i]=27;
		 else num1[i]=ch1[i]-96;

	   }

	  for(i=0;i<n;i++){
		 int temp=key*i%n;
		 int t_k=0;
		 while(num1[i]+i+28*t_k>27) t_k--;

		  num2[temp]=num1[i]+i+28*t_k;

	  }
	  for(i=0;i<n;i++){

		 if(num2[i]==0) ch2[point][i]=95;
		 else if(num2[i]==27) ch2[point][i]=46;
		 else ch2[point][i]=num2[i]+96;
	  }
	  ch2[point][n]='\0';

	  int j=1;
	  cout<<ch2[j]<<endl;
	 }
	return 1;
}
