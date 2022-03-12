/*
Main idea:
    1) shuffle array
    
    2) partition with one element i where all elements to the left of i are less than or eqaual to i and all to the right are greater
    
    3) repeat till array sorted 

*/

#include <iostream>
#include <time.h> 

void shuffle(int *arr, int len_arr){
    for (int i=0; i<len_arr; i++){
        int swapPos = std::rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[swapPos];
        arr[swapPos] = tmp;
    };
};


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
        return;
    };

    int i = start;
    int lt = start;
    int gt = end;

    while (i != gt){
        if (arr[i+1] == arr[i]){
            i ++;
        }
        else if (arr[i+1] < arr[i]){
            exch(arr, lt++, ++i);
        }
        else {
            exch(arr, gt--, i+1);
        };
    };

    quicksort(arr, start, std::max(start, i-1));
    quicksort(arr, std::min(i+1, end), end);
};


int main () {
    const int arr_len = 10;
    int arr[arr_len] = {10, 2, 7, 5, 6, 7, 8, 1, 3, 4};

    std::srand(time(NULL));
    shuffle(arr, arr_len);

    quicksort(arr, 0, arr_len-1);

    for (auto &x: arr){
        std::cout << x << " ";
    };
    std::cout << std::endl;
};



