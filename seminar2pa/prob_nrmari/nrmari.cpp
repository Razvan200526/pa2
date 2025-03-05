#include "../headere/nrmari.h"
using namespace std;
int main(){

    vector<int> a = {9,7,6,4,8,6,3,4,0,7,5,0,5,6};
    vector<int> b = {4,3,5,6,8,0,8,6,5,4,2,0,8,7,6,4,3,2,6,7,8,9,0,8,7,6,5};


    std::vector<int> res = adunare(a,b);
    for(int i:res){
        std::cout<<i<< ' ';
    }
    std::cout << '\n';
    for(int c:a){
        std::cout<<c;
    }
    std::cout << '\n';
    for(int x:b){
        std::cout<<x;
    }
    return 0;
}