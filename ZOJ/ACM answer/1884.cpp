//字符" ' "用" \' "表示
//字符" \ "用" \\ "表示

#include <stdio.h>
#include <string.h>
int main()
{
	char str[200];
	int i;
	while(gets(str))
	{
		for(i=0;i<strlen(str);i++)
		{
			switch(str[i])
			{
			case 'W':str[i]='Q';break;
			case 'S':str[i]='A';break;
			case 'X':str[i]='Z';break;

			case 'E':str[i]='W';break;
			case 'D':str[i]='S';break;
			case 'C':str[i]='X';break;

			case 'R':str[i]='E';break;
			case 'F':str[i]='D';break;
			case 'V':str[i]='C';break;

			case 'T':str[i]='R';break;
			case 'G':str[i]='F';break;
			case 'B':str[i]='V';break;

			case 'Y':str[i]='T';break;
			case 'H':str[i]='G';break;
			case 'N':str[i]='B';break;

			case 'U':str[i]='Y';break;
			case 'J':str[i]='H';break;
			case 'M':str[i]='N';break;

			case 'I':str[i]='U';break;
			case 'K':str[i]='J';break;
			case ',':str[i]='M';break;

			case 'O':str[i]='I';break;
			case 'L':str[i]='K';break;
			case '.':str[i]=',';break;

			case 'P':str[i]='O';break;
			case ';':str[i]='L';break;
			case '/':str[i]='.';break;

			case '[':str[i]='P';break;
			case ']':str[i]='[';break;
			case '-':str[i]='0';break;
			
			case '=':str[i]='-';break;
			case '\\':str[i]='=';break;
			case'\'': str[i]=';'; break;
			case '1':str[i]='`';break;
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':str[i]-=1;break;
			case '0':str[i]='9';break;
			default:break;
			}
		}
		puts(str);
	}
	return 0;
}





