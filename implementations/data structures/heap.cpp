#include<iostream>
#include <vector>
#include <math.h>

class Max_Heap {
	private:
		std::vector<int> heap;


	public:
		Max_Heap() {
			heap = {0};
		};

		void sink(int pos) {
			int N = heap.size() - 1;
			while (2 * pos <= N) {
				int j = 2 * pos;
				if (j < N && heap[j] < heap[j + 1]) { j++; }
				if (heap[pos] >= heap[j]) { break; }
				exch(pos, j);
				pos = j;
			}
		};

		void swim(int pos) {


			if (pos > 1 && heap[pos] > heap[pos/2]) {

				exch(pos, pos / 2);
				swim(pos / 2);
			}
			else { return; }

		};

		void exch(int x, int y) {
			int tmp = heap[x];
			heap[x] = heap[y];
			heap[y] = tmp;
		};

		int pop_max() {
			int max = heap[1];
			exch(1, heap.size()-1);
			heap.pop_back();
			sink(1);
			return max;
		};

		void insert(int x) {
			heap.push_back(x);
			swim(heap.size() - 1);
		};


		void display_heap() {
			int heap_height = std::floor(log2(heap.size()));
			int level = 0;

;			for (int i = 1; i < heap.size(); i *= 2) {

				std::cout << std::string(pow(2, (heap_height - level+1))-1, ' ');

				for (int j = i; j < i * 2 && j < heap.size(); j++ ){
					std::cout << heap[j] << std::string(pow(2, (heap_height - level+2))-2, ' ');

					if (heap[j] < 10) { std::cout << ' '; }
				}

				std::cout << '\n';

				level++;

			}
		};
};


int main() {
	srand(time(NULL));
	Max_Heap max_heap;
	//max_heap.display_heap();

	for (int i=0; i < 20; i++) {
		max_heap.insert(rand() % 100);
	}

	max_heap.display_heap();


};
