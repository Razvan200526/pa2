#include <iostream>
using namespace std;

inline void reverse(int a[],int n){
    for(int i = 0;i < n/2;i++){
        swap(a[i], a[n-i-1]);
    }
}
inline int* multiply(int a[], int b[],int n,int m,int size_c){

    int* c = new int[n+m]();

    reverse(a,n);
    reverse(b,m);

    for(int i = 0; i < n;i++){
        for(int j = 0; j < m ;j++){

            c[i + j] += a[i] * b[j];
            if(c[i + j] >= 10){
                c[i + j + 1] += c[i + j] /10;
                c[i + j] %= 10;
            }
        }
    }

    size_c = n + m;
    while(size_c > 1 && c[size_c - 1] == 0){
        size_c--;
    }

    reverse(c,size_c);
    return c;

}