#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

inline string appendZero(string s, int n){
    while(n > 0){
        s = "0" + s;
        n--;
    }
    return s;
}

inline string removeZeros(string s){
    reverse(s.begin(),s.end());
    //presupunem ca vom avea zero uri inaintea numarului

    for(int i = s.size() - 1;i >=0;i--){
        if(s[i] == '0'){
            s.pop_back();
        }else{
            break;
        }
    }
    if(s.empty()){
        return "0";
    }else{
        reverse(s.begin(),s.end());
        return s;
    }
}
inline string addStrings(string x,string y){
    string res = "";
    if(x.size() > y.size()){
        y = appendZero(y , x.size() - y.size());
    }
    if(y.size() > x.size()){
        x = appendZero(x , y.size() - x.size());
    }

    int carry = 0 , sum;

    for(int i = x.size() - 1;i >= 0;i--){
        sum = ((int)x[i] - '0') + ((int)y[i] - '0') + carry;

        if(sum > 9){
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }else{
            res = to_string(sum % 10) + res;
            carry = 0;
        }
    }
    if(carry){
        res = to_string(carry) + res;
    }
    return removeZeros(res);
}


inline string substractString(string x, string y){
    if(x.size() > y.size()){
        y = appendZero(y , x.size() - y.size());
    }
    if(y.size() > x.size()){
        x = appendZero(x , y.size() - x.size());
   }
//aducem la ac lenght ca sa putem folosi un singur indice
    string res = "";
    int borrow = 0;
    for(int i = x.size() - 1;i >= 0;i--){
        int a = (int)x[i] - '0';
        int b = (int)y[i] - '0';

        if(borrow == 1){
            a--;//daca borrow e 1 atunci scadem 1 din rezultat
        }
        if(a >= b){
            res = to_string(a - b) + res;
            borrow = 0;
        }else{
            a += 10;
            res = to_string(a - b) + res;
            borrow = 1;
        }
    }
    return removeZeros(res);
}

inline string multiply10(string s,int n){
    while(n > 0){
        s = s + '0';
        n--;
    }
    return s;
}

inline int multiplyXY(string x,string y){
    int p;
    p = ((int)x[0] - '0') * ((int)y[0] - '0');
    return p;
}//pentru cazul de baza


inline string karatsuba(string x,string y){
    if(x.size() == 1 && y.size() == 1){
        return to_string(multiplyXY(x,y));//caz de baza pentru stringuri de o litera 
    }

    if(x.size() > y.size()){
        y = appendZero(y , x.size() - y.size());//aducem stringurile la acelasi lenght
    }
    if(y.size() > x.size()){
        x = appendZero(x , y.size() - x.size());
    }
    if(x.size() % 2 != 0){//daca lenght e impar atunci mai punem un 0 ca sa nu crape recursia
        x = "0" + x;
        y = "0" + y;
    }

    int n = x.size();
    int half = x.size() / 2;
    string xl = x.substr(0, half);//impartim fiecare string in left si right 
    string xr = x.substr(half);
    string yl = y.substr(0, half);
    string yr = y.substr(half);

    string p1 = karatsuba(xl, yl);//xl * yl
    string p2 = karatsuba(xr, yr);//xr * yr
    string p3 = karatsuba(addStrings(xl,xr),addStrings(yl,yr));//(xl + xr) * (yl + yr)
    //p3 pentru a putea scoate in formula (xl + xr)(yl + yr) - (xl * yl + xr * yr)

    return addStrings(addStrings(multiply10(p1, n),p2),multiply10(substractString(substractString(p3, addStrings(p1, p2)), p1),half));
    //formula x = xl * 10^n/2 + xr practic,unde n = nr de cifre ale lui x
}