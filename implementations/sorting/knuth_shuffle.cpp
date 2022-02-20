#include<time.h>
#include<iostream>
#include "knuth_shuffle.h"

void shuffle(int *arr, int len_arr){
    for (int i=0; i<len_arr; i++){
        int swapPos = std::rand() % (i + 1);
        int tmp = arr[i];
        arr[i] = arr[swapPos];
        arr[swapPos] = tmp;
    };
};

