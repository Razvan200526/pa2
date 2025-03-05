#include "../headere/sum_n_number.h"

int main(){

    vector<int> a = {1,2,3,4,5,6,7,8,9,9};
    vector<long long> res = findMissingandRepeating(10, a);
    for(int i:res){
        cout << i << " ";
    }

}