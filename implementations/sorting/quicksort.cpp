/*
Main idea:
    1) shuffle array
    
    2) partition with one element i where all elements to the left of i are less than or eqaual to i and all to the right are greater
    
    3) repeat till array sorted 

*/

#include <iostream>

void exch (int *arr, int a, int b){
    /*
    swap a and b in array arr
    */

   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
};


void quicksort (int *arr, int start, int end) {


    if (start==end){
        std::cout << "return" << '\n';
        return;
    };

    int i = start;
    int j = end;

    while (i != j){
        if (arr[i+1] <= arr[i]){
            exch(arr, i, i+1);
            i ++;
        }
        else {
            exch(arr, j, i+1);
            j --;
        };
    };

    quicksort(arr, start, std::max(start, i-1));
    quicksort(arr, std::min(i+1, end), end);
};


int main () {
    int arr_len = 10;
    int arr[arr_len] = {10, 2, 7, 5, 6, 9, 8, 1, 3, 4};

    for (auto &x: arr){
        std::cout << x << " ";
    };    
    std::cout << '\n';

    quicksort(arr, 0, arr_len-1);

    for (auto &x: arr){
        std::cout << x << " ";
    };
    std::cout << std::endl;
};

