// Duyen Pham
// COSC 2030 - 01 
// November 19th, 2018
// dpham2.cpp
// Lab 07

#include "dpham2.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "winTimer.h"

using namespace std;

void merge_sort(vector<int> & left, vector<int> & right, vector<int> & bar);
void swap(vector<int> & myVector, int left, int right);

void swap(vector<int> & myVector, int left, int right)
{
	int temp = myVector[left];
	myVector[left] = myVector[right];
	myVector[right] = temp;
}


vector<int> 
random_vector(size_t vecSize, int minNum, int maxNum)
{
	vector<int> theVec;
	for (size_t i = 0; i < vecSize; ++i)
	{
		theVec.push_back(rand() % maxNum + minNum);
	}

	return theVec;
}


void bubble_sort(int vecSize, vector<int> & myVector)
{
	bool swap_occurred;

	do {
		swap_occurred = false;
		for (int i = 0; i < vecSize - 1; i++)
		{
			if (myVector[i] > myVector[i + 1]) {
				std::swap(myVector[i], myVector[i + 1]);
				swap_occurred = true;
			}

		}
	} while (swap_occurred);
}

void insertion_sort(vector<int> & myVector)
{
	for (auto it = myVector.begin(); it != myVector.end(); it++)
	{
		auto const insertion_point = std::upper_bound(myVector.begin(), it, *it);
		std::rotate(insertion_point, it, it + 1);
	}
}

void selection_sort(vector<int> & myVector)
{
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it)
	{
		std::iter_swap(it, std::min_element(it, myVector.end()));
	}
}

void merge(vector<int> & bar)
{
	if (bar.size() <= 1)
		return;

	int mid = bar.size() / 2;
	vector<int> left;
	vector<int> right;

	for (int j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (int j = 0; j < ((int)bar.size() - mid); j++)
		right.push_back(bar[mid + j]);

	merge(left);
	merge(right);
	merge_sort(left, right, bar);
}

void merge_sort(vector<int> & left, vector<int> & right, vector<int> & bar)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k])
		{
			bar[i] = left[j];
			j++;
		}
		else
		{
			bar[i] = right[k];
			k++;
		}
		i++;
	}

	while (j < nL)
	{
		bar[i] = left[j];
		j++; i++;
	}

	while (k < nR)
	{
		bar[i] = right[k];
		k++; i++;
	}
}

void quick_sort(vector<int> & myVector, int Left, int Right)
{
	int mid = Left + (Right - Left) / 2;
	int i = Left;
	int j = Right;
	int piv = myVector[mid];

	while (i < Right || j > Left)
	{
		while (myVector[i] < piv)
			i++;
		while (myVector[j] > piv)
			j--;

		if (i <= j)
		{
			swap(myVector, i, j);
			i++;
			j--;
		}
		else {
			if (i < Right)
				quick_sort(myVector, i, Right);
			if (j > Left)
				quick_sort(myVector, Left, j);
			return;
		}
	}
}

void sort(vector<int> & myVector)
{
	sort(begin(myVector), end(myVector));
}
	
int main()
{
	//vector<int> ranVector;
	int minNum = 1;
	int maxNum = 500;
	//int vecSize = myVector.size();

	//ranVector = random_vector(myVector);

	//vector<double> random_vector(size_t vecSize, int minNum, int maxNum);

	//vector<int> vectorBubbleSort = random_vector(10, 1, 500);
	//vector<int> vectorInsertionSort = random_vector(320000, 1, 500);
	//vector<int> vectorSelectionSort = random_vector(48240, 1, 500);
	//vector<int> vectorMergeSort = random_vector(274000, 1, 500);
	//vector<int> vectorQuickSort = random_vector(1161960, 1, 500);
	vector<int> vectorSort = random_vector(12000000, 1, 500);

	//unsigned int vecBubbleSize = vectorBubbleSort.size();
	//unsigned int vecInsertionSize = vectorInsertionSort.size();
	//unsigned int vecSelectionSize = vectorSelectionSort.size();
	//unsigned int vecMergeSize = vectorMergeSort.size();
	//unsigned int vecQuickSize = vectorQuickSort.size();
	unsigned int vecSortSize = vectorSort.size();


	
	Timer get;
	/*
	get.start();
	bubble_sort(vecBubbleSize, vectorBubbleSort);
	get.stop();
	*/

	//get.start();
	//insertion_sort(vectorInsertionSort);
	//get.stop();

	//get.start();
	//selection_sort(vectorSelectionSort);
	//get.stop();

	//get.start();
	//merge(vectorMergeSort);
	//get.stop();

	//get.start();
	//quick_sort(vectorQuickSort, 0, (vecQuickSize - 1));
	//get.stop();

	get.start();
	sort(vectorSort);
	get.stop();
	
	
	cout << "Bubble sort took " << get() << " seconds"
		<< endl;
		

	cout << "Insertion sort took " << get() << " seconds"
		<< endl;
	
	cout << "Selection sort took " << get() << " seconds"
		<< endl;
	
	cout << "Merge sort took " << get() << " seconds"
		<< endl;

	cout << "Quick sort took " << get() << " seconds"
		<< endl;

	cout << "Sort function took " << get() << " seconds"
		<< endl;
		

	return 0;
	
}