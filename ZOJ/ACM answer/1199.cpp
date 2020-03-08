//1199.cpp

#include<iostream.h>

#include<math.h>




int main(){
   int N;int x[2],y[2],r[2];
   cin>>N;
   for(int i=1;i<=N;i++){

	 cin>>x[0]>>y[0]>>r[0];
	 cin>>x[1]>>y[1]>>r[1];

   double sol_x,sol_y;

	 if(r[1]==r[0]) {cout<<"Impossible."<<endl;continue;}
	 double temp;
	 temp=sqrt((x[0]-x[1])*(x[0]-x[1])+(y[0]-y[1])*(y[0]-y[1]));
	 double tt;
	 if(r[1]<r[0]) tt=temp+(double)r[1]-(double)r[0];
	 else tt=temp-(double)r[1]+(double)r[0];

	 if(tt<0.000000001) {cout<<"Impossible."<<endl;continue;}
	 sol_x=(r[1]*x[0]-r[0]*x[1])*1.0/(double)(r[1]-r[0]);
	 sol_y=(r[1]*y[0]-r[0]*y[1])*1.0/(double)(r[1]-r[0]);
	 cout.precision(2);



	 cout.setf(ios::showpoint|ios::fixed);
	 if(fabs(sol_x)<0.000001) cout<<"0.00";
	 else cout<<sol_x;
	 cout<<" ";
	 if(fabs(sol_y)<0.000001) cout<<"0.00";
	 else cout<<sol_y;
	 cout<<endl;

   }
  return 0;
}
