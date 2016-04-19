/*
 * sorts.hpp
 *
 *  Created on: Apr 13, 2016
 *      Author: sarah
 */

#ifndef SORTS_HPP_
#define SORTS_HPP_

#include<vector>
#include<string>


void insertionSort(std::vector<std::string>& A);
void mergeSort(std::vector<int> &A, int p, int r);
void merge(std::vector<int> &A, int p, int q, int r);

int part(std::vector<int> &A, int p, int r);
void quickSort(std::vector<int> &A, int p, int r);

int randPart(std::vector<int> &A, int p, int r);
void randQS(std::vector<int> &A, int p, int r);

// max heap sort dec
int parent(int i);
int left(int i);
int right (int i);

void maxHeapify(std::vector<int> &A, int i, int size);
void buildMaxHeap(std::vector<int> &A);
void heapSort(std::vector<int> &A, int size);


#endif /* SORTS_HPP_ */
