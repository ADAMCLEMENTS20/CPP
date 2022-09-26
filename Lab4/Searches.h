/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
	for(int i=0;i<data.size();i++){
		if(data[i] == target){
			return i;
		}
	}
}


template <class T>
int binarySearch(std::vector<T> data, T target){
	int lowIndex = 0;
	int highIndex = data.size();
	int midIndex;
	while(lowIndex != highIndex){
		midIndex = (highIndex+lowIndex)/2;
		if(data[midIndex] == target){
			return midIndex;
		}
		else if(target > data[midIndex]){
			lowIndex = midIndex + 1;
		}
		else{
			highIndex = midIndex-1;
		}
	}
}
