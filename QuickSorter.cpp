#include "Sorter.h"
using namespace std;

class QuickSorter : public Sorter {
	//O(1)
	string median_of_three(int low, int high) {
		int mid = low + (high - low)/2;
		if (buf[mid] < buf[low]) swap(low, mid);
		if (buf[high] < buf[low]) swap(low, high);
		if (buf[mid] < buf[high]) swap(mid, high);
		return buf[high];
	}
	//O(N) worse case if we had a poor pivot
	int partition(int low, int high, string pivot) {
		int below = low, above = high - 1;
		for(;;) {
			while(buf[below] < pivot) { ++below; }
			while(above > 0 and buf[above] > pivot) { --above; }
			if (below < above) {
				swap(below++, above--);
			} else { break; }
		}	
		swap(below, high);
		return below;
	}
	//O(NLogN)
	void quicksort(int low, int high) {
		if (low < high) {
			string pivot = median_of_three(low, high);
			int i = partition(low, high, pivot);
			quicksort(low, i - 1);
			quicksort(i + 1, high);
		}
	}
public:
	QuickSorter(int capacity) : Sorter(capacity) {
	}
	//O(N^2) //due to having insertionsort //O(NLogN) otherwise
	void sort() {
		if (size < 16) {
			insertionsort();
		} else {
			quicksort(0, size - 1);			
		}			
	}
};

