#include<iostream.h>

struct linkch
{
	char ch;
	linkch* next;
};
struct node
{
	int num;
	node* next;
};

class tabletype
{
public:
	linkch* dump;
	linkch* out;
	node* head;
	int father;
	table()
	{
		dump=NULL;out=NULL;head=NULL;father=0;
	}
};


int main()
{
	int tt;int i;
	cin>>tt;
	for(i=0;i<tt;i++)
	{
		tabletype table[51]; 
		if(i)	cout<<endl;
		int n;int j,t;
		cin>>n;
		for(j=0;j<n;j+)
		{

		