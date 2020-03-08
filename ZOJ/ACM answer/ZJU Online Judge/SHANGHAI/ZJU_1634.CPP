#include <iostream.h>

typedef unsigned long long MyLong;

MyLong gcd(MyLong a , MyLong b){
	return b==0?a :gcd(b , a % b);
}

int main(){
	MyLong a , m , n , k;
	int T;
	cin >> T;
	while(T--){
		cin >> a >> m >> n;
		while(n--){
			cin >> k;
			a = gcd(a , k);
		}

		if(m % a == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	

	return 0;
}
