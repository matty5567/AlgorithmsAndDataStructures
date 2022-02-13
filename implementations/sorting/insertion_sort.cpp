#include <iostream>

void insertionSort(int *arr, int len_arr){
	for (int k=0; k<len_arr-1; k++){
		int minPos = k;
		for (int j=k+1; j<len_arr; j++){
			if (arr[j] < arr[minPos]){minPos = j;};
		};
		int tmp = arr[k];
		arr[k] = arr[minPos];
		arr[minPos] = tmp;
	};	
};


int main(){
	const int len_arr = 5;
	int arr[len_arr] = {3, 5, 4, 1, 2};
	insertionSort(arr, len_arr);
	for (auto &x : arr){
		std::cout << x << ' ';
	};
	std::cout << std::endl;
};
