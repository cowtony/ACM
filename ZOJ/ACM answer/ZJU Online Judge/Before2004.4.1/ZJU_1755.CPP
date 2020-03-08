#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	int min , max;
	string Min , Max , buf;
	int a , b , c;
	while(cin >> n , n > 0){
		min = 1000; max = 0;
		for(int i=0; i<n; i++){
			cin >> a >> b >> c >> buf;
			a = a * b * c;
			if(a > max){
				max = a; Max = buf;
			}
			if(a < min){
				min = a; Min = buf;
			}
		}
		cout << Max << " took clay from " << Min << "." << endl;
	}
	
	return 0;
}

