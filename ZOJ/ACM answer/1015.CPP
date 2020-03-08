 #include<iostream.h>

 int main(){
	int n,m;
	while(cin>>n>>m){
		if(n==0&&m==0) break;
		int* map;
		struct node{
			int data;int up;
		};
		node type[1001];
		map=new int[(n+1)*(n+1)+1];


		memset(map,0,sizeof(int)*(n+1)*(n+1)+1);

		int i,j; int a,b;


		for(i=1;i<=m;i++){
			cin>>a>>b;
			map[a*(n+1)+b+1]=1;
			map[b*(n+1)+a+1]=1;

		}

		type[1].data=1;type[1].up=0;int q1=1,q2=1,q3=1;
		int flag=1;
		while(1){
			for(i=q1;i<=q2;i++){
				cout<<type[i].data<<"\t"<<type[i].up<<endl;
				int j;
				for(j=1;j<=n;j++){
					if(map[(n+1)*type[i].data+j+1]==1){
						cout<<j<<"===="<<endl;
						if(j==type[type[i].up].data) continue;
						int t;
						for(t=0;t<=q3;t++)
							if(type[t].data==j) break;
						cout<<type[t].data<<"------"<<t<<endl;
						if(t==q3+1){
							q3++;type[q3].data=j;type[q3].up=i;
						}
						else{int up1=type[t].up;int up2=type[i].up;
							 if(up1==up2||map[type[up1].data*(n+1)+type[i].data+1]==1||
								map[type[up2].data*(n+1)+type[t].data+1]==1);
							 else flag=0;
						}
				   }
				if(flag==0) break;
				}

			}
			if(flag==0) break;
			if(q2==q3) break;
			q1=q2+1;q2=q3;
		}
		if(flag==0) cout<<"Imperfect"<<endl;
		else cout<<"Perfect"<<endl;
		delete map;
		cout<<"=========="<<endl;

	}
	return 0;
 }










