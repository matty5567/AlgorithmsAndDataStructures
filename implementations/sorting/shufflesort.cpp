
#include <iostream>
using namespace std;

void shuffleSort(int *arr, int len_list){
	for (int i=0; i<len_list-1; i++){
			int maxPos = i;
			for (int j=i; j<len_list; j++){
				if (arr[j] > arr[maxPos]){
					maxPos = j;
				};
			int tmp = arr[i];
			arr[i] = arr[maxPos];
			arr[maxPos] = tmp;
			};
		};
	};

int main(){

	const int len_list = 5;
	int arr[len_list] = {5, 4, 3, 2, 1};
	shuffleSort(arr, len_list);

	for (int i=0; i<len_list; i++){
		cout << arr[i];
	};
	cout << "\n";

	return 0;
}
