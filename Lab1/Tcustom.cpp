#include <iostream>
#include <string>
#include <sstream>
#include "List.h"
#include "ListQueue.h"
#include "ListStack.h"

int main(){
//Test List Functions

	List<int> test;
	std::cout << "Empty?: " << test.empty() << std::endl;
	std::cout << "Size: " << test.size() << std::endl;
	for(int i=0;i<10;i++){
		test.insertStart(i);
	}
	test.print("test");
	for(int i=0;i<10;i++){
		test.insertEnd(i);
	}
	test.print("test");
	test.insertAt(-1,10);
	test.removeStart();
	test.print("list1");
	test.removeEnd();
	test.print("test");
	test.removeAt(9);
	test.print("test");
	std::cout << "First: " << test.getFirst() << "\nLast: " << test.getLast() << "\nAt 3: " << test.getAt(3) << std::endl;
	std::cout << "Found the value 4 at position " << test.find(4) << std::endl;

//Test Queue Functions
	ListQueue<int> testq;
	std::cout << "Empty?: " << testq.empty() << "\nSize: " << testq.size() << std::endl;
	for(int i=0; i<10; i++){
		testq.enqueue(i);
	}
	testq.print("queue");
	std::cout << "Dequeueing: " << testq.dequeue() << std::endl;
	testq.print("queue");
	
//Test Stack Functions
	ListStack<int> tests;
	std::cout << "Empty?: " << tests.empty() << "\nSize: " << tests.size() << std::endl;
	for(int i=0; i<10; i++){
		tests.push(i);
	}
	tests.print("stack");
	std::cout << "Popping: " << tests.pop() << std::endl;
	tests.print("stack");


}