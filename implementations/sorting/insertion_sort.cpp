#include<iostream>


void insertionSort(int *arr, int len_arr){
	for (int i; i<len_arr; i++){
		for (int j=i-1; j>=0; j--){
			if (arr[j] > arr[j+1]){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;

			}
			else {break;};
		};
	};
};


int main(){
	const int len_arr = 10;
	int arr[len_arr] = {9, 10, 2, 3, 1, 6, 4, 7, 8, 5};
	insertionSort(arr, len_arr);
	
	for (auto &x : arr){
		std::cout << x << " ";
	};

	std::cout << std::endl;
};
