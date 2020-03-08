#include <cstdio>
#include <math.h>
#include <string>

int zhuan(char a)
{
	int n;
	switch(a)
	{
	case 'B': 
	case 'F': 
	case 'P': 
	case 'V':
			n=1;	
			break;
	case 'C': case 'G':  case 'J': case  'K' : case 'Q':  case 'X': case 'S': case 'Z':
				n=2;
		break;
	case 'D':  case  'T': 
			   n=3;
		break;
	case  'L' :
				n=4;
			   break;
	case 'M':  case 'N':
	n=5;
	break;
	case 'R' :
	n=6;
	break;
	default : n=0;break;

	}
	return n;
}

int main()
{
	char letter[21];
	
	memset(letter,' ',sizeof(letter));
	while(scanf("%s",letter)!=EOF)
	{
		
		if(zhuan(letter[0])!=0) printf("%d",zhuan(letter[0]));
		for(int i=1;letter[i];i++)
			if(zhuan(letter[i-1])==zhuan(letter[i]))
				continue;
			else
				if(zhuan(letter[i])!=0)
				{
					printf("%d",zhuan(letter[i]));
				}
				printf("\n");
			memset(letter,' ',sizeof(letter));
	
	}
	return 0;
}