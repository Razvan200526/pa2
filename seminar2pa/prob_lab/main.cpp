#include <vector>
#include <stdio.h>
#include <algorithm>
// No additional includes needed
int main() {
    std::vector<int> arr = {1, 2, 0, 3, 5, 4, 7, 6};
    std::sort(arr.begin(), arr.end()); 

    int left = 0;
    int right = arr.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == mid) {
            printf("Element found at index %d\n", mid);
            found = true;
            break;
        } else if (arr[mid] < mid) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("No element found where arr[i] == i\n");
    }

    return 0;
}