#pragma once

#include <iostream>
inline int euclid_scaderi(int a,int b){

    while(a != b){
        if(a > b){
            a -= b;
        }else{
            b -=a;
        }
    }
    return a;
}

inline int euclid_divide(int a,int b){

    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}