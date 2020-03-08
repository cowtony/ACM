

#include<iostream.h>
#include<conio.h>
struct so{
  int a,b,point,sol;
};
so num[200];
int q1,q2,q3;  int A,B,N;
int same(int t){
   for(int i=1;i<t;i++){
	 if(num[i].a==num[t].a&&num[i].b==num[t].b) return 1;
   }
   return 0;
}
int result(int t1,int t2){
  for(int i=t1;i<=t2;i++)
   if(num[i].b==N) return i;
  return 0;
}
int  doing(){
   q1=1;q2=1;
   while(1){
	 int i;  q3=q2;
	 for(i=q1;i<=q2;i++){

	   if(num[i].a<A){
		 q3++;num[q3].a=A;num[q3].b=num[i].b;num[q3].point=i;num[q3].sol=1;

		 if(same(q3)) q3--;}
	   if(num[i].a!=0){
		 q3++;num[q3].a=0;num[q3].b=num[i].b;num[q3].point=i;num[q3].sol=2;

		 if(same(q3)) q3--;}
	   if(num[i].b<B){
		 q3++;num[q3].a=num[i].a;num[q3].b=B;num[q3].point=i;num[q3].sol=3;

		 if(same(q3)) q3--;}
	   if(num[i].b!=0){
		 q3++;num[q3].a=num[i].a;num[q3].b=0;num[q3].point=i;num[q3].sol=4;

		 if(same(q3)) q3--;}
	   if(num[i].a>0&&num[i].b<B){
		 q3++;
		 if(num[i].a<=B-num[i].b) {
		   num[q3].a=0;num[q3].b=num[i].b+num[i].a;num[q3].point=i;num[q3].sol=5;
		 }else{
		   num[q3].a=num[i].a-(B-num[i].b);num[q3].b=B;num[q3].point=i;num[q3].sol=5;
		 }

		 if(same(q3)) q3--;}
		 if(num[i].b>0&&num[i].a<A){
		 q3++;
		 if(num[i].b<=A-num[i].a) {
		   num[q3].b=0;num[q3].a=num[i].b+num[i].a;num[q3].point=i;num[q3].sol=6;
		 }else{
		   num[q3].b=num[i].b-(A-num[i].a);num[q3].a=A;num[q3].point=i;num[q3].sol=6;
		 }

		 if(same(q3)) q3--;}

	   int rul;
	   if((rul=result(q2+1,q3))!=0) return rul;

	 }
	 q1=q2+1;q2=q3;
 }

}
int main(){
  while(cin>>A>>B>>N){

	int tem=doing();
	int cou=0; int res[20];
	while(tem>1){ cou++;res[cou]=num[tem].sol;tem=num[tem].point;}
	for(int j=cou;j>=1;j--){


	  switch(res[j]){
		case 1: cout<<"fill A\n";break;
		case 2: cout<<"empty A\n";break;
		case 3: cout<<"fill B\n";break;
		case 4: cout<<"empty B\n";break;
		case 5: cout<<"pour A B\n";break;
		case 6: cout<<"pour B A\n";break;}}
	 cout<<"success\n";
  }
  return 0;
}




