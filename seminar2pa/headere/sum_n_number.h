#include <iostream>
#include <vector>
using namespace std;
inline int sum(int n){
    return n*(n + 1) / 2;
}

inline int findMissingNumber(int n,vector<int> a){
    int s = sum(n);
    int sreal = 0;
    for(int i = 0;i < a.size();i++){
        sreal += a[i];
    }

    return s - sreal;
}

inline vector<long long> findMissingandRepeating(int n,vector<int> a){
    
    long long s = sum(n);
    long long sq = n * (n+1) * (2 * n + 1)/6;

    long long ac_s = 0;
    long long ac_sq = 0;
    for(int i: a){
        ac_s += i;
        ac_sq += i * i;
    }   

    long long diff = ac_s - s;//(x - y)
    long long difq = ac_sq - sq;//(x^2 - y^2)

    long long sumxy = difq/diff;
    long long x = (diff + sumxy) / 2;
    long long y = sumxy - x;
    return {x,y};
}