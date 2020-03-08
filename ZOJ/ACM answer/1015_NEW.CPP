 #include<iostream.h>

 struct node{
	int data;
	node* next;
 };



 int main(){
	int n,m;
	while(cin>>n>>m){
		node * top[1001];
		if(n==0&&m==0) break;
		int a,b;
		int i,j;
		node* cur[1001];
		for(i=1;i<=n;i++) top[i]=NULL;
		for(i=1;i<=m;i++){
			cin>>a>>b;
			node* temp=new node;
			temp->data=b;temp->next=NULL;
			if(top[a]==NULL) { top[a]=temp;cur[a]=temp;}
			else{cur[a]->next=temp;cur[a]=temp;}
			node* tt=new node;
			tt->data=a;tt->next=NULL;
			if(top[b]==NULL){top[b]=tt;cur[b]=tt;}
			else{cur[b]->next=tt;cur[b]=tt;}
		}
		int can;
		while(1){
			int t;
			for(t=1;t<=n;t++){
				if(top[t]!=NULL&&top[t]->next==NULL){
					node* temp=top[t];
					int tt=top[t]->data;
					top[t]=NULL;
					delete temp;

					node* qq=top[tt];node* pre=NULL;
					while(qq!=NULL){
						if(qq->data==t) break;
						pre=qq;qq=qq->next;
					}
					if(pre==NULL) {node* temp=top[t];top[t]=top[t]->next;delete temp;}
					else {node* temp=qq;pre->next=qq->next;delete temp;}
					break;
				}
			}
			if(t==n+1)  break;
		}

		for(i=1;i<=n;i++){
			node* tt=top[i];can=1;
			if(tt==NULL) continue;
			while(tt!=NULL){
				int qq=tt->data;int flag=0;

				node* ll=top[qq];
				while(ll!=NULL){
					int dd=ll->data;
					if(dd==i){ll=ll->next;continue;}

					node* ss=top[dd];
					while(ss!=NULL){
						if(ss->data==qq){ss=ss->next;continue;}

						if(ss->data==i){flag=1;break;}
						ss=ss->next;
					}
					if(flag==1) break;
					ll=ll->next;
				}
				if(flag==0) {can=0; break;}
				tt=tt->next;
			}
			if(can==0) break;
		}
		if(i!=n+1) cout<<"Imperfect"<<endl;
		else cout<<"Perfect"<<endl;
		cout<<endl;
		for(i=1;i<=n;i++){
			while(top[i]!=NULL){
				node* tt=top[i];
				top[i]=top[i]->next;
				delete tt;
			}
		}
	}
	return 0;
 }