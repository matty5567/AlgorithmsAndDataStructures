#include <iostream>

void shellSort(int *arr, int len){
	
	int step  = 1;
	while (step < len / 3){step = 3 * step + 1;};
	
	while (step > 0){
		for (int i=0; i<=len-step; i += step){
			int minPos = i;
			for (int j=i; j<=len-step; j += step){
				if (arr[j] < arr[minPos]){minPos = j;}
			};
			int tmp = arr[i];
			arr[i] = arr[minPos];
			arr[minPos] = tmp;
		};

		step = (step - 1) / 3;
	};	
};


int main(){
	const int len = 15;
	int arr[len] = {15, 13, 14, 12, 11, 9, 6, 7, 8, 10, 2, 5, 3, 1, 4};
	shellSort(arr, len);	
	
	for (auto &x : arr){
		std::cout << x << " ";
	}
	std::cout << std::endl;
};
