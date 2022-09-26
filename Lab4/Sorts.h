/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <vector>
template <class T>
void merge(std::vector<T> lst, int leftIndex, int middleIndex, int rightIndex){
	std::vector<T> temp;
	int a = leftIndex,b = middleIndex+1;
	while(a <= middleIndex && b <= rightIndex){
		if(lst[a] <= lst[b]) {
			temp.push_back(lst[a]);
			a++;
		}
		else{
			temp.push_back(lst[b]);
			b++;
		}
	}
	while(a <= middleIndex){
		temp.push_back(lst[a]);
		a++;
	}
	
	while(b <= rightIndex){
		temp.push_back(lst[b]);
		b++;
	}
	for(int i=leftIndex;i<=rightIndex;i++){
		lst[i] = temp[i-leftIndex];
	}
}

template <class T>
void recursiveMergeSort(std::vector<T> lst, int leftIndex, int rightIndex){
	if(leftIndex < rightIndex){
		int middleIndex = (leftIndex+rightIndex)/2;
		recursiveMergeSort(lst,leftIndex,middleIndex);
		recursiveMergeSort(lst,middleIndex+1,rightIndex);
		merge(lst,leftIndex,middleIndex,rightIndex);
	}
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
	recursiveMergeSort(lst, 0, lst.size());
	return lst;
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
	
}
