#include<iostream.h>


int square(int num){
	long result;

	for(int i=1;i<=num;i++){
		result=i*i;
		if(result==num) return 1;
	}
	return 0;
}

int main(){
	int N;
	cin>>N;
	for(int j=1;j<=N;j++){
		int max;
		cin>>max;
		int a[2][50];int t[50];
		for(int temp=0;temp<50;temp++) t[temp]=0;
		int i;
		for( i=1;;i++){

			int point;
			for(point=0;point<max;point++){


				int flag;
				if(t[point]%2==0) flag=0;
				else flag=1;
				if(t[point]==0) {a[flag][point]=i;t[point]++;break;}
				else{
					int pp;
					if(flag==0) pp=1;else pp=0;
					if(square(a[pp][point]+i)){

						 a[flag][point]=i;

						t[point]++;
						break;
					}
				}
			}
			if(point==max) break;

		}
		cout<<(i-1)<<endl;
	}
	return 0;
}






