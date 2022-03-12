#include<time.h>
#include<iostream>
#include <time.h> 

void shuffle(int *arr, int len_arr){
    for (int i=0; i<len_arr; i++){
        int swapPos = std::rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[swapPos];
        arr[swapPos] = tmp;
    };
};

int main () {
    const int arr_len = 10;
    int arr[arr_len] = {10, 2, 7, 5, 6, 7, 8, 1, 3, 4};

    std::srand(time(NULL));

    shuffle(arr, arr_len);

    for (auto &x: arr){
        std::cout << x << " ";
    };
    std::cout << std::endl;
};