 #include<stream.h>
 #include<string.h>
 struct node{
	node*up;
	char ch[100];
	node*next;
 };

 int main(){
	int nn;int i;
	cin>>nn;
	for(i=1;i<=nn;i++){
		if(i!=1) cout<<endl;

		char str[10];
		node* top;
		top=new node;
		top->up=NULL;
		strcpy(top->ch,"http://www.acm.org/");
		top->next=NULL;
		node* cur=top;
		while(cin>>str){
			if(strcmp(str,"QUIT")==0) break;
			if(strcmp(str,"VISIT")==0){
				node* temp=new node;
				temp->up=cur;
				cin>>temp->ch;
				 temp->next=NULL;
				 cur->next=temp;
				cur=cur->next;
				cout<<cur->ch<<endl;
			}
			if(strcmp(str,"BACK")==0){
				if(cur->up==NULL) cout<<"Ignored"<<endl;
				else{
					cur=cur->up;
					cout<<cur->ch<<endl;
				}
			}
			if(strcmp(str,"FORWARD")==0){
				if(cur->next==NULL) cout<<"Ignored"<<endl;
				else{
					cur=cur->next;
					cout<<cur->ch<<endl;
				}
			}
		}
	}
	return 0;
 }




