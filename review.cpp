#include "review.h"

#include <string>

#include <vector>

#include <iostream>

void ReadStdIn(){
	int num;
	double dou;
	std::string str;
	std::cin >> num;
	std::cin >> dou;
	std::cin >> str;
	std::cout << num << std::endl;
	std::cout << dou << std::endl;
	std::cout << str << std::endl;
}

int WriteOut(std::string output){
	std::cout << output << std::endl;
	return 1;
}
int WriteOut(int output){
	std::cout << output << std::endl;
	return 2;
}
int WriteOut(double output){
	std::cout << output << std::endl;
	return 3;
}

std::vector <int> InitializeArray(int size){
	std::vector <int> a(size,0);
	return a;
}

void ReadStdIn2(){
	std::string temp;\
	int i=0;
	while(temp != "q"){
		std::cin >> temp;
		i++;
	}
	std::cout << (i-1) << std::endl;
}

void ReadWrite(){
	std::string temp;
	std::vector<std::string> wordList;
	while(temp != "q"){
		std::cin >> temp;
		wordList.push_back(temp);
	}
	for(int i=0; i<(wordList.size()-1); i++){
		std::cout << wordList[i] << " ";
	}
	std::cout << std::endl;
}

void LoopThrough(double * data, int size){
	for(int i=0;i<size;i++){
		*(data+i) = *(data+i) + 1;
	}
}

int Fibonacci(int a){
	if(a == 0 || a == 1){
		return 1;
	}
	else{
		return Fibonacci(a-1) + Fibonacci(a-2);
	}
}