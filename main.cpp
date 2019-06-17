#include <iostream>
#include "Sorter.h"
#include "InsertionSorter.cpp"
#include "QuickSorter.cpp"
#include "HeapSorter.cpp"

ostream &operator << (ostream &out,  Sorter &S) {
	S.print(out);
     	return out;
}

void measureAll(char *fileName) {
	for (int i = 1; i <= 1; i++) {
		InsertionSorter T1 = i*4539;
		QuickSorter T2 = i*4539;
		HeapSorter T3 = i*4539;
		cout << "InsertionSorter: ";
		T1.insertAllFromFile(i, fileName);
		cout << "QuickSorter: ";
		T2.insertAllFromFile(i, fileName);
		cout << "HeapSorter: ";
		T3.insertAllFromFile(i, fileName);
	}
}

int main(int argc, char * argv[]) {
	string input_file = argc == 2 ? argv[1] : "random.txt";
	char* fileName = &input_file[0u];
	measureAll(fileName);
}