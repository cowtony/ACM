#include<iostream.h>

 struct num{
	 int a[8];



 };
 int main(){
   int lasttime;int sum;
   cin>>lasttime;int kk=0;
   while(lasttime!=0){

	 kk++; sum=0;
	 if(kk!=1) cout<<endl;



	 int cpu,mem,N; int time=0;int s_point=0;
	 cin>>cpu>>mem>>N;
	 num come[500],sus[500],temp,next;next.a[3]=0;
	 for(int qq=1;qq<500;qq++){ come[qq].a[1]=0;sus[qq].a[1]=0;}
	 for(int i=0;i<=N;){

		if(lasttime<time) {
			while(i<N) {
				i++;for(int tt=1;tt<8;tt++) cin>>temp.a[tt];}
			break;
		}
		int t_cpu=cpu,t_mem=mem;

		int c_p=0;
		if(next.a[3]==time){
			if(time!=0){c_p++;
					for(int kj=1;kj<8;kj++)  come[c_p].a[kj]=next.a[kj];}
			i++;for(int kj=1;kj<8;kj++) cin>>temp.a[kj];

			while(temp.a[3]==time){
				if(i==N) break;
				c_p++;int kj;
				for(kj=1;kj<8;kj++) come[c_p].a[kj]=temp.a[kj];
				i++;for(kj=1;kj<8;kj++) cin>>temp.a[kj];
			}
			if(i==N){c_p++;
				for(int tt=1;tt<8;tt++) come[c_p].a[tt]=temp.a[tt];
				next.a[1]=0;}
			else {
				for(int tt=1;tt<8;tt++) next.a[tt]=temp.a[tt];}
		}
		if(lasttime==time){
			int tt;
			for(tt=1;tt<=c_p;tt++) sum=sum-(come[tt].a[4]-time)*come[tt].a[7];
			for( tt=1;tt<=s_point;tt++){
				if(sus[tt].a[4]>=time) sum=sum-(sus[tt].a[4]-time)*sus[tt].a[7];}
			time++;continue;
		}
		int t_point=1;
		while(sus[t_point].a[1]!=0){

			if(sus[t_point].a[1]<=t_cpu&&sus[t_point].a[2]<=t_mem){
				t_cpu=t_cpu-sus[t_point].a[1];t_mem=t_mem-sus[t_point].a[2];
				sum=sum+sus[t_point].a[5];
				if(sus[t_point].a[4]<time+1) sum=sum-(time+1-sus[t_point].a[4])*sus[t_point].a[7];
				if(sus[t_point].a[4]>time+1) sum=sum+(sus[t_point].a[4]-time-1)*sus[t_point].a[6];
				sus[t_point].a[1]=0;
			}
			t_point++;}
		int kj;int t_kj=s_point;s_point=0;
		for( kj=1;kj<=t_kj;kj++){
			if(sus[kj].a[1]==0){int temp;
				for( temp=kj+1;temp<=t_kj;temp++)
				if(sus[temp].a[1]!=0){
					s_point++;
					for(int jj=1;jj<8;jj++){ sus[kj].a[jj]=sus[temp].a[jj];
						sus[temp].a[jj]=0;}
						break;}
				if(temp==t_kj+1) break;}
			else s_point++;
		}
		int temp_c=c_p;
		while(c_p!=0){
			int max=0;int point;
			for(kj=1;kj<=temp_c;kj++)
				if(come[kj].a[5]>max) {max=come[kj].a[5];point=kj;}

			if(come[point].a[1]<=t_cpu&&come[point].a[2]<=t_mem){
				t_cpu=t_cpu-come[point].a[1];t_mem=t_mem-come[point].a[2];

				sum=sum+come[point].a[5];
				if(come[point].a[4]<time+1) sum=sum-(time+1-come[point].a[4])*come[point].a[7];
				if(come[point].a[4]>time+1) sum=sum+(come[point].a[4]-time-1)*come[point].a[6];
			}
			else {s_point++;
				for(int tt=1;tt<8;tt++) sus[s_point].a[tt]=come[point].a[tt];}

			int tt;

			for( tt=1;tt<8;tt++) come[point].a[tt]=0;
			c_p--;
		}
		time++;

	}
	 cout<<"Case "<<kk<<": "<<sum<<endl;
	cin>>lasttime;
  }

  return 0;
 }















