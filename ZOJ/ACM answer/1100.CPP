 #include<iostream.h>


 int node[12][12];int flag[100];
 int h,w;long sum;

 void fill(int a,int b,int c){

	if(flag[node[a-1][b]]==1){
		if(flag[node[a][b-1]]==1&&a==h) return ;
		node[a][b]=node[a-1][b];flag[node[a][b]]=2;

		if(a==h&&b==w) sum++;
		else{if(b==w) {a++;b=1;}
			 else b++;

			 fill(a,b,c);
		}
		if(b==1) {a--;b=w;} else b--;
		flag[node[a][b]]=1;
	}
	else{
		if(flag[node[a][b-1]]==1&&a==h){

			node[a][b]=node[a][b-1];flag[node[a][b]]=2;

			if(a==h&&b==w) sum++;
			else{if(b==w) {a++;b=1;}
				  else b++;

				  fill(a,b,c);
			}
			if(b==1) {a--;b=w;} else b--;
			flag[node[a][b]]=1;
		}
		else{if(flag[node[a][b-1]]==1){
				node[a][b]=node[a][b-1];flag[node[a][b]]=2;

				if(a==h&&b==w) sum++;

				else{if(b==w) {a++;b=1;}
					  else b++;

					  fill(a,b,c);
				}
				if(b==1) {a--;b=w;} else b--;
				flag[node[a][b]]=1;
			}
			node[a][b]=c;flag[c]=1;

			if(a==h&&b==w) return ;
			else{if(b==w){a++;b=1;}
				 else b++;

				 fill(a,b,c+1);
			}
			if(b==1) {a--;b=w;} else b--;
			flag[c]=0;
		}
	}
 }





 int main(){
	while(cin>>h>>w){
		if(h==0&&w==0) break;
		int s=h*w;
		sum=0;
		int i,j;
		for(i=0;i<12;i++)
			for(j=0;j<12;j++) node[i][j]=0;
		for(i=0;i<=s+1;i++) flag[i]=0;
		if(s%2==0) fill(1,1,1);
		cout<<sum<<endl;
	}
	return 0;
 }
