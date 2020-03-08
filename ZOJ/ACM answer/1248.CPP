 #include<iostream.h>
 struct node{
	int x,y;
 };
 int main(){
	int n;node bond[101];int point=0;
	while(cin>>n){
		point++;
		if(n==0) break;
		cout<<"Floor #"<<point<<endl;
		int i,j,t;
		for(i=0;i<n;i++) cin>>bond[i].x>>bond[i].y;
		for(i=0;i<n;i++){
			if(i==n-1) t=0;
			else t=i+1;
			int max,min;
			if(bond[i].x==bond[t].x){
				if(bond[i].y<bond[t].y){
					int flag1=0,flag2=0;
					for(j=0;j<n;j++){
						if((bond[j].x<bond[i].x&&bond[j].y<=bond[i].y)||
							(bond[j].x<bond[i].x&&bond[j].y>=bond[t].y)){
								if(flag1==0) flag1=1;
								else flag2=1;
							}
						if(flag2==1) break;
					}
					if(j<n) break;
				}
				if(bond[i].y>bond[t].y){
					int flag1=0,flag2=0;
					for(j=0;j<n;j++){
						if((bond[j].x>bond[i].x&&bond[j].y>=bond[i].y)||
							(bond[j].x>bond[i].x&&bond[j].y<=bond[t].y)){
								if(flag1==0) flag1=1;
								else flag2=1;
							}
						if(flag2==1) break;
					}
					if(j<n) break;
				}
			}




			else{if(bond[i].x<bond[t].x){
					int flag1=0,flag2=0;
					for(j=0;j<n;j++){
						if((bond[j].y>bond[i].y&&bond[j].x<=bond[i].x)||
							(bond[j].y>bond[i].y&&bond[j].x>=bond[t].x)){
								if(flag1==0) flag1=1;
								else flag2=1;
							}
						if(flag2==1) break;
					}
					if(j<n) break;
				 }
				 else{
					int flag1=0,flag2=0;
					for(j=0;j<n;j++){
						if((bond[j].y<bond[i].y&&bond[j].x>=bond[i].x)||
							(bond[j].y<bond[i].y&&bond[j].x<=bond[t].x)){
								if(flag1==0) flag1=1;
								else flag2=1;
							}
						if(flag2==1) break;
					}
					if(j<n) break;
				 }
			}
		}
		if(i<n) cout<<"Surveillance is impossible."<<endl;
		else cout<<"Surveillance is possible."<<endl;
		cout<<endl;
	}
	return 0;
 }












