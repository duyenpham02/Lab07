// Duyen Pham
// COSC 2030 - 01 
// November 19th, 2018
// dpham2.h
// Lab 07

#ifndef _D_PHAM_2_H_
#define _D_PHAM_2_H_

#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>

using namespace std;


#include "dpham2.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "winTimer.h"

using namespace std;

void merge_sort(vector<int> & left, vector<int> & right, vector<int> & bar);
void swap(vector<int> & myVector, int left, int right);
void swap(vector<int> & myVector, int left, int right);
vector<int>random_vector(size_t vecSize, int minNum, int maxNum);
void bubble_sort(int vecSize, vector<int> & myVector);
void insertion_sort(vector<int> & myVector);
void selection_sort(vector<int> & myVector);
void merge(vector<int> & bar);
void merge_sort(vector<int> & left, vector<int> & right, vector<int> & bar);
void quick_sort(vector<int> & myVector, int Left, int Right);
void sort(vector<int> & myVector);


#endif

