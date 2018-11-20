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

void swap(vector<int> & myVector, int left, int right)
{
	int temp = myVector[left];
	myVector[left] = myVector[right];
	myVector[right] = temp;
}

vector<int> random_vector(vector<int> & myVector)
{
	int number = rand() % 500 + 1;
	srand((unsigned)time(NULL));

	for (int i = 0; i <= number; i++)
	{
		int ran_num = rand() % 500 + 1;
		myVector.push_back(ran_num);
		cout << myVector[i] << endl;
	}

	return myVector;
}

void bubble_sort(int vecSize, vector<int> & myVector)
{
	for (int i = 0; i < vecSize; i++)
	{
		for (int j = i + 1; j < vecSize; j++)
		{
			if (true)
			{
				if (myVector[i] < myVector[j])
					std::swap(myVector[i], myVector[j]);
				else if (myVector[i] < myVector[j])
					std::swap(myVector[i], myVector[j]);
			}
		}

	}
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

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
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
	
int main()
{
	vector<int> myVector;
	vector<int> ranVector;
	int vecSize = myVector.size();

	ranVector = random_vector(myVector);
	bubble_sort(vecSize, ranVector);
	insertion_sort(ranVector);
	selection_sort(ranVector);
	merge(ranVector);
	quick_sort(ranVector, 0, vecSize);
	std::sort(ranVector.begin(), ranVector.end());

	return 0;
}