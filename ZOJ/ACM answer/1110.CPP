 //1110.cpp
 //accepted

 #include<iostream.h>

 int main(){
	int s,p,y,j;
	while(cin>>s>>p>>y>>j){

		int x;int year1,year2,year3;
		if((j+12-y-p)%3==0){
			x=(j+12-y-p)/3;
			year1=y+x;year2=p+x;year3=x;
		}

		else if((j+12-y-p-1)%3==0){
			x=(j+12-y-p-1)/3;
			year3=x;
			if(y-s>p){
				year1=y+x;
				year2=p+x+1;
			}else {
				year1=y+x+1;year2=p+x;
			}
		}
		else{ x=(j+12-y-p-2)/3;
			year3=x;
			year1=y+x+1;
			year2=p+x+1;
		}
		cout<<year1<<" "<<year2<<" "<<year3<<endl;
	}
	return 0;
 }

