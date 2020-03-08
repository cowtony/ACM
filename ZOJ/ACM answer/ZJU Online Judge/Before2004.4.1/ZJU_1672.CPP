#include <stdio.h>
#include <string.h>

int Len , keylen;
char buf[1000001];
char* pointor;
char key[60] , dust[10];
bool Iskey[256];
int app[256];


inline int Calcmin(){
	int ret = Len + 1;
	for(int i=0; i<keylen; i++)
		if(app[key[i]] < ret) ret = app[key[i]];
	return ret;
}

void solve(){
	memset(app , 0 , sizeof(app));
	int min = 0;
	int i;
	int shortest = Len + 1, head , c = 0;
	int Count = keylen;

	for(i=0; i<Len; i++){
		if(Iskey[buf[i]]){
			if(app[ buf[i] ] == 0) Count--;
			if(app[ buf[i] ] == min){
				app[ buf[i] ] = i;
				min = Calcmin();
			}
			else app[ buf[i] ] = i;
			if(Count <= 0){
				if(i - min + 1 < shortest){
					shortest = i - min + 1;
					head = min; c = 1;
				}
				else if(i - min + 1 == shortest){
					c++;
				}
			}
		}
	}
	if(shortest > Len){
		printf("0\n\n"); 
	}else{
		printf("%d\n\n" , c);
		int p = 0;
		//printf("%.*s", lengthOfYourExpectation, yourString);
		pointor = buf + head;		
		for(; shortest>=72; shortest -=72){
			printf("%.*s\n" , 72 , pointor);
			pointor += 72;
		}
		if(shortest){
			printf("%.*s\n" , shortest , pointor);
		}
		printf("\n");
		/*

		for(i = head; shortest > 0; shortest-- , i ++){
			printf("%c" , buf[i]);  p = (p + 1) % 72;
			if (p == 0) putchar('\n');
		}
		
		printf("\n");
		if(p != 0) putchar('\n');
		*/
	}
}

int main(){
	//freopen("in.txt" , "r" , stdin);
	int plen , i;
	pointor = buf;
	while(gets(pointor) , strcmp(pointor , "") != 0){
		plen = strlen(pointor);
		Len = plen;
		pointor += plen;
		while(gets(pointor) , strcmp(pointor , "") != 0){		
			plen = strlen(pointor);		
			Len += plen;
			pointor += plen;
		}		
		gets(key);
		memset(Iskey , 0  ,  sizeof(Iskey));
		for(keylen = strlen(key) ,i = keylen - 1; i >= 0; i--)
			Iskey[ key[i] ] = 1;
		gets(dust);
		solve();
		pointor = buf;
	}
	
	return 0;
}
