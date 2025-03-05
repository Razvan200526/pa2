#pragma once 

#include <vector>
#include <iostream>
inline void bubble_sort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        bool swapped = false;
        for (int j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

inline void insertion_sort(std::vector<int>& arr){
    for(int i = 1;i < arr.size();i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

inline void selection_sort(std::vector<int>& arr){

    for(int i = 0;i < arr.size();i++){
        int min_index = i;

        for(int j = i + 1;j < arr.size();j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}