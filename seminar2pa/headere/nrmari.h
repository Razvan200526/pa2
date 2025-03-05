#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
inline std::vector<int> adunare(std::vector<int>a ,std::vector<int> b){
    std::vector<int> res(std::max(a.size(),b.size()) + 1, 0);

    if(a.size() < b.size()){
        std::swap(a,b);
    }
    int overflow = 0;
    int i = a.size() - 1, j = b.size() - 1, k = res.size() - 1;
    while(i >= 0 || j >= 0 || overflow){
        int sum = overflow;
        if(i >= 0) sum += a[i--];
        if(j >= 0) sum += b[j--];

        res[k--] = sum % 10;
        overflow = sum / 10;
    }

    if(res[0] == 0){
        res.erase(res.begin());
    }
    return res;
}


inline std::vector <int> multiply(std::vector<int> a,std::vector<int> b){

    std::vector <int> res(a.size()+b.size() , 0);//vector resultat

    std::reverse(a.begin(),b.begin());//inversam pentru a face inmultirea de la stanga la dreapta pt usurinta
    std::reverse(b.begin(),b.end());

    for(int i = 0;i < a.size();i++){//iteram prin fiecare cifra din fiecare numar
        for(int j = 0;j < b.size();j++){
            res[i+j] += a[i] * b[j];//cifra rez e prod cifrelor curente
            if(res[i+j] >= 10){//overflow
                res[i + j + 1] += res[i + j] % 10;//cifra urmatoare primeste overflowul
                res[i + j] %= 10;//cif curenta primeste ult cifra a produsului cif curente
            }
        }
    }

   std::reverse(res.begin(),res.end());//inversam res pt a lua nr

   return res;
}

/*std::vector<int> karatsuba(const std::vector<int>& a,const std::vector<int> b){
    
    int n = std::max(a.size(), b.size());
    if(n == 1){
        std::vector <int> res(1 , a[0] * b[0]);
        return res;
    }

    int half = n / 2;

    std::vector <int> a_firsthalf(a.begin(), a.begin() + half);
    std::vector <int> a_otherhalf(a.begin() + half, a.end());
    std::vector <int> b_firsthalf(b.begin(), b.begin() + half);
    std::vector <int> b_otherhalf(b.begin() + half, b.end());

    std::vector <int> bd = karatsuba(a_firsthalf,b_firsthalf);
    std::vector <int> ac = karatsuba(a_otherhalf,b_otherhalf);
    std::vector <int> ad_bc = karatsuba(adunare(a_firsthalf, a_otherhalf), adunare(b_firsthalf, b_otherhalf));

    for (int i = 0; i < ad_bc.size(); i++) {
        if (i < ac.size()) ad_bc[i] -= ac[i];
        if (i < bd.size()) ad_bc[i] -= bd[i];
    }
    std::vector<int> result; 
    result = adunare(result , ac);
    result = adunare(result, ad_bc);
    result = adunare(result, bd);

    return result;
}*/
