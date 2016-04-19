/*
 * main.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: sarah
 */

#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include "sorts.hpp"

using namespace std;

int main(){
	int ri;

	vector<string> S;
	vector<int> I;



	S.push_back("Z");
	S.push_back("z");
	S.push_back("_");

	srand(time(NULL));
for(int i =0; i < 25; i++){
	ri = rand() % 100 +1;
	I.push_back(ri);
}



 heapSort(I, I.size());


	for(int i=0; i < static_cast<int>(I.size()); i++){

		cout << I.at(i) << endl;
	}




	return 0;
}


