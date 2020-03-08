//1163.cpp

#include<iostream.h>
 static long add;static long a[501];
 static long N,sum;

 void doing(long n){

   sum=sum+a[n];
   for(long i=a[n]+1;i<=N-sum;i++){

	if(n>0&&i==N-sum){ add++;break;}

	a[n+1]=i;

	doing(n+1);

	}
   sum=sum-a[n];

 }
 int main(){
   cin>>N;
   while(N!=0){
       sum=0;add=0;a[0]=0;
      doing(0);
      cout<<add<<endl;
      cin>>N;
   }
   return 0;
}
