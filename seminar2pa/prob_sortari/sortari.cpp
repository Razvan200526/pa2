#include "../headere/sortari.h"

int main()
{
    std::vector<int> arr={9,8,7,6,5,4,3,2,1};
    std::vector<int> arr2 = {7,65,543,1231};
    std::vector<int> arr3 = {34,3242,456,678,345};
    bubble_sort(arr);
    insertion_sort(arr2);
    selection_sort(arr3);

    for(int a:arr){
        std::cout << a << ' ';
    }
    return 0;
}