#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream>
#include "Timer.h"
using namespace std;

class Sorter {
protected:
	int capacity, size;
	string *buf;
	
public:
	Sorter(int cap)
	: capacity(cap), size(0), buf(new string[cap+1]) {
	}
	//O(1)
	virtual void swap(int t1, int t2) {
		string temp = buf[t1];
		buf[t1] = buf[t2];
		buf[t2] = temp;
	}	
	//O(1)
	virtual void insert(string word) {
		buf[size++] = word;
	}
	//O(N^2) //due to worse case InsertionSort
	virtual void insertAllFromFile(int partition, char *fileName) {
		Timer t;
		double eTime;
		ifstream infile;
		infile.open(fileName);
		string word;
		for(int i = 0; i < partition*4539; i++) { 
			infile >> word;
			insert(word);
		}
		t.start();
		sort();
		t.elapsedUserTime(eTime);
		infile.close();
		cout << "File: " << fileName << ". Partition: " << partition << "/10. Time: " << eTime << endl;
	}
	//O(N^2)
	virtual void insertionsort() {
		string word;
		int i, prev_index;
		for(i = 1; i < size; i++) {
			word = buf[i];
			prev_index = i - 1;
			while(prev_index >= 0 and word < buf[prev_index]) {
				buf[prev_index + 1] = buf[prev_index];
				prev_index--;
			}
			buf[prev_index + 1] = word;
		}
	}
	virtual void sort() = 0;
	virtual void print(ostream &out) {
		for (int i = 0; i < size; i++) {
			out << buf[i] << endl;
		}
	}
	~Sorter() {
		delete[] buf;
	}
};

#endif
