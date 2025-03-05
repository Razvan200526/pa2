#include "../headere/inmultire.h"

int main(){

    int a[] = {6,5,4,3,2,3,3,4,5,6,6,7,8};
    int b[] = {1,2,3,4,6,7,8,9,9,5,5,4,3,2};

    int n = (sizeof(a) / sizeof(a[0]));
    int m = (sizeof(b) / sizeof(b[0]));

    int size_c = n + m;
    int *c = multiply(a,b,n,m,size_c);

    for(int i = 0; i < size_c;i++){
        cout<< c[i];
    }

    delete[] c;

    return 0;

}