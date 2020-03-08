 //62058 2002-12-08 23:01:01 Accepted 1167 C++ 00:00.00 436K Century Ghost

 #include<iostream.h>
 #include<string.h>

 struct node
 {
	int val;
	node* left;
	node* right;
 };
 node* insert(node* head,int vv,char* str)
 {
	int len=strlen(str);
	if(len==1)
	{
		if(head==NULL)
		{
			node* temp=new node;
			temp->val=vv;
			temp->left=NULL;
			temp->right=NULL;
			head=temp;
			return head;
		}
		else if(head->val==-1){	head->val=vv;return head;}
		else	return NULL;
	}
	int i;
	node* pt=head;
	for(i=0;i<len-1;i++)
	{
		if(str[i]=='L')
		{
			if(pt->left==NULL)
			{
				node* temp=new node;
				temp->val=-1;
				temp->left=NULL;
				temp->right=NULL;
				pt->left=temp;
			}
			pt=pt->left;
			if(i==len-2)
			{
				if(pt->val==-1)	pt->val=vv;
				else	return NULL;
			}
		}
		else
		{
			if(pt->right==NULL)
			{
				node* temp=new node;
				temp->val=-1;
				temp->left=NULL;
				temp->right=NULL;
				pt->right=temp;
			}
			pt=pt->right;
			if(i==len-2)
			{
				if(pt->val==-1) pt->val=vv;
				else	return NULL;
			}
		}
	}
	return head;
 }



 int complete(node* head)
 {
	if(head==NULL)	return 1;
	if(head->val==-1&&(head->left||head->right))	return 0;
	if(!complete(head->left)||!complete(head->right))	return 0;
	return 1;
 }
 void output(node* head)
 {
	if(head==NULL)	return ;
	node* buffer[300];
	int beg=0;int end=0;
	buffer[0]=head;
	while(beg<=end)
	{
		if(buffer[beg]->left) buffer[++end]=buffer[beg]->left;
		if(buffer[beg]->right) buffer[++end]=buffer[beg]->right;
		beg++;
	}
	for(int i=0;i<=end;i++)
	{	if(i)	cout<<" ";
		cout<<buffer[i]->val;
	}
	cout<<endl;
 }




 int main()
 {
	char ch;
	char str[500];
	while(cin>>ch)
	{
		int flag=1;
		node* head=NULL;
		head=new node;
		head->val=-1;
		head->left=NULL;
		head->right=NULL;
		while(1)
		{
			int num;
			cin.get(ch);
			if(ch==')')	break;
			cin.putback(ch);
			cin>>num;
			cin>>ch;
			cin>>str;
			cin>>ch;
			if(flag)	head=insert(head,num,str);
			if(head==NULL)	flag=0;
		}
		if(!flag||!complete(head))	cout<<"not complete"<<endl;
		else{	output(head);}
	  }
	return 0;
 }






