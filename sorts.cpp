/*
 * sorts.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: sarah
 */

#include "sorts.hpp"
#include <limits>
#include <math.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

//insertion sort
void insertionSort(std::vector<std::string> &A){
	std::string key;
	int i;
	for(int j=1; j < static_cast<int>(A.size()); j++){
		key = A.at(j);
		i = j-1;
		while(i > -1 && A.at(i).compare(key) > 0){
			A.at(i+1) = A.at(i);
			i--;

		}
		A.at(i+1) = key;
	}
}

// merge sort, come back to, issues on not fully sorting, likely to be counting issue in for loop in merge
void mergeSort(std::vector<int> &A, int p, int r){
	int q;

	if(p < r) {
		q = floor((p+r)/2);
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A,p,q,r);


	}


}
void merge(std::vector<int> &A, int p, int q, int r){
	int n1 = q-p + 1;
	int n2 = r-q;
	int h1, h2=0;
	std::vector<int> left, right;
	for(int i =0; i <= n1; i++){
		left.push_back(A.at(p+i-1));
	}
	for(int j = 0; j <= n2; j++){
		right.push_back(A.at(q+j));
	}

	left.push_back(std::numeric_limits<int>::max());
	right.push_back(std::numeric_limits<int>::max());


	for(int k = p; k < r; k++){
		if(left.at(h1) <= right.at(h2)){
			A.at(k) = left.at(h1);
			h1++;
		} else {
			A.at(k) = right.at(h2);
			h2++;
		}
	}
}
// Start QuickSort

int part(std::vector<int> &A, int p, int r){
	int x = A.at(r);
	int i = p-1, temp;

	for(int j = p; j < r; j++){
		if(A.at(j) <= x){
			i++;
			temp = A.at(i);
			A.at(i) = A.at(j);
			A.at(j) = temp;

		}


	}
	temp = A.at(i+1);
	A.at(i+1) = A.at(r);
	A.at(r) = temp;
	return ++i;


}

void quickSort(std::vector<int> &A, int p, int r){
	int q;
	if (p < r) {
		q = part(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);

	}
}

// Start Randomized QuickSort

int randPart(std::vector<int> &A, int p, int r){
	int randInt, temp;
std::cout << r-p << std::endl << std::endl;
	srand(time(NULL));

	randInt = rand() % (r-p+1) + p;
	//std::cout << randInt << std::endl << std::endl;
	temp = A.at(r);
	A.at(r) = A.at(randInt);
	A.at(randInt) = temp;

	return part(A, p, r);

}
void randQS(std::vector<int> &A, int p, int r){
	int q;
	if(p < r) {
		q = randPart(A, p, r);
		randQS(A, p, q-1);
		randQS(A, q+1, r);
	}
}

// max heap sort functions
int parent(int i){
	return floor(i/2);
}
int left(int i){
	if(i == 0) return 1;
	return (2*i) + 1;
}
int right (int i){
	if(i == 0) return 2;
	return (2*i) + 2 ;
}

void maxHeapify(std::vector<int> &A, int i, int size){
	int leftC = left(i);
	int rightC = right(i);

	int largest, temp;

	if (leftC < size && ( A.at(leftC) > A.at(i))){
		largest =  leftC;

	} else { largest = i; }

	if(rightC < size && (A.at(rightC) > A.at(largest))){
		largest = rightC;
	}

	if(!(largest == i)){
		temp = A.at(i);
		A.at(i) = A.at(largest);
		A.at(largest) = temp;
		maxHeapify(A, largest, size); //**

	}

}
void buildMaxHeap(std::vector<int> &A){
	int heapSize = A.size();

	for(int i = floor(heapSize/2)-1; i > -1; i--){
		maxHeapify(A, i, heapSize);
	}
}
void heapSort(std::vector<int> &A, int size){
	int temp;

	buildMaxHeap(A);

	for(int i = A.size()-1; i < 2; i--){
		temp = A.at(0);
		A.at(0) = A.at(i);
		A.at(i) = temp;
		size --;
		maxHeapify(A, 0, size);
	}
}




