#include <iostream>
#include <string>
using namespace std;

int stack[100];
int top;

string buf;

const string sign[13] = {
	"M"  , "CM" ,  "D" , "CD", "C" , "XC" , "L" , "XL", "X", "IX", "V", "IV", "I" 
//	1000 , 900  ,  500 ,  400 , 100 , 90  ,  50  , 40  , 10  ,  9 ,  5  ,  4  , 1
/*
     I                1
     V                5   
     X                10  
     L                50  
     C                100 
     D                500 
     M                1000
 */
};
const int value[13] = {
	1000 ,900,  500 ,  400 , 100 , 90  ,  50  , 40  , 10  ,  9 ,  5  ,  4  , 1
};

void printNum(int k){
	for(int i=0; i<13; i++){
		while(k >= value[i]){
			k -= value[i];
			cout << sign[i];
		}
	}
	cout << endl;
}

void modify(){
	if(buf=="="){
		if(top == 0){
			cout << "stack underflow" << endl; return;
		}
		if(stack[top] <= 0 || stack[top] >= 5000){
			cout << "out of range exception" << endl;
			return;			
		}
		printNum(stack[top]); return;		
	}
	if(buf=="+" || buf=="-" || buf=="*" || buf=="/"){
		if(top <= 1){
			cout << "stack underflow" << endl;
			return;
		}
		switch (buf[0])
		{
		case '+' :{
			stack[top - 1] += stack[top]; top--;
			break;
		}
		case '-' :{
			stack[top - 1] -= stack[top]; top--;
			break;
		}
		case '*' :{
			stack[top - 1] *= stack[top]; top--;
			break;
		}
		case '/' :{
			if(stack[top] == 0){
				cout << "division by zero exception" << endl;				
				top--;
			}else{
				stack[top - 1] /= stack[top]; top--;
			}
			break;
		}		
		} // switch

		return;
	}

	/////////////////////calc num and push it into stack
	int ret = 0 , j;
	for(int i=0; i<buf.length();){		
		for(j=0; j<13; j++)
			if(buf.substr(i , sign[j].length()) == sign[j]){
				ret += value[j]; i += sign[j].length(); break;
			}
	}
	stack[++top] = ret;

}

int main(){
//	freopen("in.txt" , "r" , stdin);
	top = 0;
	while(cin >> buf){
		modify();
	}	
	return 0;
}
