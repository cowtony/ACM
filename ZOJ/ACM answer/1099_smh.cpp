#include<iostream.h>
#include<string.h>

char  word[81];
char* br="<br>";
char* hr="<hr>";
char* blank=" ";
char* divline="--------------------------------------------------------------------------------";
char* end="\0";
struct line {
	char c[81];
	line* nextline;
};

line headline;

void newline(line** lineptr)
{
	(*lineptr)->nextline =new line;
	(*lineptr)=(*lineptr)->nextline;
	strcpy((*lineptr)->c,end);
	(*lineptr)->nextline=NULL;
}

void print()
{
	line* lineptr=&headline;
//	line* temp;
	while (lineptr!=NULL) {
		cout<<(lineptr->c)<<endl;
//		if (strlen(lineptr->c)<80) cout<<endl;
//		temp=lineptr;
		lineptr=lineptr->nextline;
//		delete temp;
	}
	return;
}

int main()
{
	headline.nextline=NULL;
	line* current=&headline;
	int len;

	while (cin>>word) {

		if     (!strcmp(word,br)) {
				newline(&current);
		} else if (!strcmp(word,hr)) {
			if (strlen(current->c)==0) {
				strcpy(current->c,divline);
				newline(&current);
			} else {
				newline(&current);
				strcpy(current->c,divline);
				newline(&current);
			}
		} else {
			len=strlen(word);
			if (strlen(current->c)+len+1>79) {
				newline(&current);
				strcpy(current->c, word);
			} else {
				len=strlen(current->c);
				if (len!=0)
					strcat(current->c,blank);
				strcat(current->c,word);
			}
		}
	}
	print();
	cout<<endl;
	return 0;
}














