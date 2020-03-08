#include<iostream.h>
#include<string.h>
#include<fstream.h>

struct Node
{
  char url[71];
  Node* next;
};

class Stack
{
  public:
	Stack()
	{
	  top=NULL;
	}
	void push(char* current)
	{
	  Node* temp=new Node;
	  strcpy(temp->url,current);
	  temp->next=top;
	  top=temp;
	}
	void pop(char* current)
	{
	  Node* temp;
	  strcpy(current,top->url);
	  temp=top;
	  top=top->next;


	  delete temp;
	}
	void clear()
	{
	  Node* temp;
	  if(top!=NULL)
	  {
		temp=top;
		top=top->next;
		delete temp;
	  }
	}
	int is_empty()
	{
	  return (top==NULL);
	}
  private:
	Node* top;
};



int main()
{
  ofstream fout("fout.txt");
  ifstream fin("fin.txt");
  int N;
  fin>>N;
  while(N>0)
  {
	char input[80];
	char current[71]="http://www.acm.org/";
	Stack backward;
	Stack forward;
	fin.get();
	do{

	 fin.getline(input,80,'\n');


	  if(input[0]=='V')
	  {
		backward.push(current);
		strcpy(current,strchr(input,'h'));
		forward.clear();
		fout<<current<<endl;
	  }
	  else if(input[0]=='B')
	  {
		if(backward.is_empty())
		 fout<<"Ignored"<<endl;
		else{
		forward.push(current);
		backward.pop(current);
		fout<<current<<endl;
		}
	  }
	  else if(input[0]=='F')
	  {
		if(forward.is_empty())
		  fout<<"Ignored"<<endl;
		else{
		backward.push(current);
		forward.pop(current);
		fout<<current<<endl;
		}
	  }

   }while(input[0]!='Q');

	N--;
	if(N>0) fout<<endl;
  }
  return 0;
}

