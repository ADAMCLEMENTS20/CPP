/*
 * Name: Adam Clements
 * Date Submitted:
 * Lab Section: 2121-001
 * Assignment Name: Linked List Based Stacks and Queues
 */
 
#pragma once
 
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
 
//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{
 
 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list
 
 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);
 
  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }
 
}; //end of class interface (you may modify the code below)
 
//Implement all of the functions below
//Construct an empty list by initializing this list's instance variables
template <class T>
List<T>::List(){
	mySize = 0;
	start = nullptr;
}
 
//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
	//Ruun through the list 1 node at a time, deleting the memory as it goes
	Node<T>* temp = start;
	while(temp != nullptr){
		Node<T> *n = temp->next;
		delete temp;
		temp = n;
	}
}
 
//Return the size of this list
template <class T>
int List<T>::size(){
	return mySize;
}
 
//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
	if(mySize == 0){
		return true;
	}
	else{
		return false;
	}
}
 
//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
	//take a new node, and link it to the original starting node, then define it as the new starting point
	mySize++;
	Node<T> *newNode = new Node<T>(value);
	newNode->next = start;
	start = newNode;
}
 
//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
	//iterate through the list, and once the ->next value of a given node is nullptr, we have reached the end, so attach the new node there
	mySize++;
	Node<T> *newNode = new Node<T>(value);
	Node<T> *last = start;
	//special case if this is the first node added
	if(start == nullptr){
		start = newNode;
		return;
	}
	while(last->next != nullptr){
		last = last->next;
	}
	last->next = newNode;
}
 
//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
	//iterate through the list until a given point j, then link the previous node to newNode and newNode to the next node
	mySize++;
	if(j == 0 || start == nullptr){
		insertStart(value);
		return;
	}
	Node<T> *newNode = new Node<T>(value);
	Node<T> *before = start;
	for(int i=0;i<(j-1);i++){
		before = before->next;
	}
	Node<T> *after = before->next;
	before->next = newNode;
	newNode->next = after;
}
 
//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
	mySize--;
	//make start = start->next
	Node<T> *temp = start;
	start = temp->next;
	delete temp;
}
 
//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
	//iterate through the luist until we reach the 2nd to last node, and delete the next node
	mySize--;
	Node<T> *iterator = start;
	while((iterator->next)->next != nullptr){
		iterator = iterator->next;
	}
	iterator->next = nullptr;
	return;
}
 
//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
	//iterate through the list until a point, j, then take the node before j, and link it to the node after j
	Node<T> *iterator = start;
	for(int i=0;i<(j-1);i++){
		iterator = iterator->next;
	}
	Node<T> *temp = iterator;
	iterator = iterator->next;
	temp->next = (temp->next)->next;
	delete iterator;
	mySize--;
	return;
}
 
//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
	if(start == nullptr){
		return T();
	}
	return start->value;
}
 
//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
	if(start == nullptr){
		return T();
	}
	Node<T> *iterator = start;
	while(iterator->next != nullptr){
		iterator = iterator->next;
	}
	return iterator->value;
}
 
//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
	if(start == nullptr){
		return T();
	}
	Node<T> *iterator = start;
	for(int i=0; i<j; i++){
		iterator = iterator->next;
	}
	return iterator->value;
}
 
//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
	//iterate through the list until node->value == key, then return the poition, otherwise return -1
	int pos = 0;
	Node<T> *iterator = start;
	while(iterator->next != nullptr){
		pos++;
		if(iterator->value == key){
			return (pos-1);
		}
		iterator = iterator->next;
	}
	return -1;
}