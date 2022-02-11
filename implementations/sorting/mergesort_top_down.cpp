#include <iostream>
using namespace std;

void merge(int *arr, int *aux, int lo, int mid, int hi){

	// copy to aux array
	for (int k=lo; k<=hi; k++){aux[k] = arr[k];};
	
	int i = lo;
	int j = mid+1;

	for (int n=lo; n<=hi; n++){

		if (i > mid) {             arr[n] = aux[j++];}
		else if (j > hi) {         arr[n] = aux[i++];}
		else if (aux[i] <= aux[j]){arr[n] = aux[i++];}
		else {                     arr[n] = aux[j++];};	
		};
	};
	
void sort(int *arr, int *aux, int lo, int hi){
	if (hi <= lo){return;};
	int mid = lo + (hi-lo)/2;
	sort(arr, aux, lo, mid);
	sort(arr, aux, mid+1, hi);
	merge(arr, aux, lo, mid, hi);
	};

int main(){
	const int arr_len = 10;
	int arr[arr_len] = {5, 4, 2, 3, 1, 7, 10, 9, 6, 8};
	int aux[arr_len];
	sort(arr, aux, 0, arr_len-1);

	for (int s=0; s<arr_len; s++){
		cout << arr[s] << ", ";
	};
	cout << '\n';
	return 0;
};
