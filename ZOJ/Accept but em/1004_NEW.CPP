#include<iostream.h>
#include<string.h>


char str1[51],str2[51];
static int len[5];static int q1,q2;
int sol[5][10][100];static int sum[20];
int po[100]; int point1,point2;
char tac1[50],tac2[50];

void doing(int tt,int j){


  if(j==2*len[tt]){
	sum[tt]++;

	for(int q=0;q<len[tt]*2;q++){
	  sol[tt][sum[tt]][q]=po[q];
	}
  }
  else{for(int i=0;i<=1;i++){
	if(i==0){

	   if(point1>=len[tt]) continue;
	   po[j]=0;tac1[q1]=str1[point1];

	   q1++;point1++;

	   doing(tt,j+1);
	   q1--;point1--;}
	else{
		  if(q1>0) tac2[q2]=tac1[q1-1];else continue;

		  if(tac2[q2]!=str2[point2]) continue;
		  po[j]=1;

		  q2++;point2++;q1--;char t_ch=tac1[q1];
		  doing(tt,j+1);
		  tac1[q1]=t_ch;q1++;point2--;q2--;
		}
	 } }

}


int  main(){


   int tt=0;
   char ch;
   while(cin>>str1>>str2){
	tt=1;
   int len1,len2;
   q1=0;q2=0;sum[tt]=0;point1=0;point2=0;

   len[tt]=len1=strlen(str1);len2=strlen(str2);
   if(len1==len2) doing(tt,0);


   int qq=1;
	cout<<"[\n";
	for(int q=1;q<=sum[qq];q++){
	 for(int p=0;p<len[qq]*2-1;p++){
	  if(sol[qq][q][p]==0) cout<<"i ";
	  else if(sol[qq][q][p]==1) cout<<"o ";sol[qq][q][p]=0;}
	if(sol[qq][q][len[qq]*2-1]==1) cout<<"o ";
	else cout<<"i ";sol[qq][q][len[qq]*2-1]=0;
	cout<<endl;}
	cout<<"]\n";
  }
	 return 1;
}