#include<iostream.h>
#include<string.h>
struct termtype
{
	char* word;
	termtype* next;
};
termtype* head;
int main()
{
	int tt;int i;
	cin>>tt;
	char input[251];
	cin.getline(input,251);

	for(i=0;i<tt;i++)
	{	cin.getline(input,251);
		while(1)
		{
			if(i)	cout<<endl;
			head=NULL;
			while(1)
			{
				cin.getline(input,251);
				if(endofline(input))	break;
				sprit(input);
				cin.getline(input,251);
			}
			cin.getline (input,251);
			cin.getline(input,251);
			if(endofline(input))	break;
		}

		
		
	