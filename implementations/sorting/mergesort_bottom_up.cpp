#include <iostream>

void merge(int *arr, int *aux, int lo, int mid, int hi){
	for (int k=lo; k<=hi; k++){aux[k] = arr[k];};
 
	int i = lo;
	int j = mid + 1;

	for (int k=lo; k<=hi; k++){
		if      (i > mid){         arr[k] = aux[j++];}
		else if (j > hi){          arr[k] = aux[i++];}
		else if (aux[i] < aux[j]){ arr[k] = aux[i++];}
		else {                     arr[k] = aux[j++];}
	};
};

void sort(int *arr, int *aux, int len_arr){
	/**
	First merges arrays of size 1, then 2, 4, 8 and so on...
	*/
	for (int sz=1; sz<len_arr; sz = sz+sz){
		for(int j=0; j<len_arr-sz; j += sz + sz){
			merge(arr, aux, j, j+sz-1, std::min(j+sz+sz-1, len_arr-1));
		}; 
	}; 
};


int main(){
	const int len_arr = 10;
	int arr[len_arr] = {2, 4, 5, 9, 8, 7, 10, 1, 6, 3};
	int aux[len_arr];
	sort(arr, aux, len_arr);

	for (auto &x : arr){
		std::cout << x << '\n';
	};
	return 0;
};
