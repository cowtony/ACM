 //accepted

 #include<iostream.h>
 #include<string.h>


 char str1[201],str2[201];
 static int len;static int q1,q2;

 int po[400]; int point1,point2;
 char tac1[200],tac2[200];

 void doing(int j){


  if(j==2*len){


	for(int q=0;q<len*2;q++){
		if(po[q]==0) cout<<"i ";
		else cout<<"o ";


	}
	cout<<endl;
  }
  else{for(int i=0;i<=1;i++){
	if(i==0){

	   if(point1>=len) continue;
	   po[j]=0;tac1[q1]=str1[point1];

	   q1++;point1++;

	   doing(j+1);
	   q1--;point1--;}
	else{
		  if(q1>0) tac2[q2]=tac1[q1-1];else continue;

		  if(tac2[q2]!=str2[point2]) continue;
		  po[j]=1;

		  q2++;point2++;q1--;char t_ch=tac1[q1];
		  doing(j+1);
		  tac1[q1]=t_ch;q1++;point2--;q2--;
		}
	 } }

}


int  main(){




   while(cin>>str1>>str2){
   cout<<"["<<endl;

   int len1,len2;
   q1=0;q2=0;point1=0;point2=0;

   len=len1=strlen(str1);len2=strlen(str2);
   if(len1==len2) doing(0);
	cout<<"]"<<endl;
  }
	 return 1;
 }