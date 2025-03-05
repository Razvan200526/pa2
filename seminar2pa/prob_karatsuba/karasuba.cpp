#include "../headere/karatsuba.h"
int main(){
	string x, y;
	getline(cin, x);
	getline(cin, y);
	if(x == "0" || y == "0"){
		cout << "0" << endl;
	}else{
		if(x.length() > y.length()){
			y = appendZero(y, x.length() - y.length());
		}else{
			x = appendZero(x, y.length() - x.length());
		}
		cout << removeZero(karatsuba(x,y))<< endl;
	}
	return 0;
}
