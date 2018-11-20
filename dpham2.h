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

void swap(vector<int>&, int, int);
vector<int> random_vector(vector<int>&);
void bubble_sort(int, vector<int>&);
void insertion_sort(vector<int>&);
void selection_sort(vector<int>&);
void merge(vector<int>&);
void merge_sort(vector<int> &, vector<int> &, vector<int> &);
void quick_sort(vector<int>&, int, int);

#endif

