/*
	queue based linkedlist
*/
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "linkedlist.h"

using namespace std;
template <typename T>
class Queue{
	private:
		Linkedlist<T> data;
	public:
		Queue();
		void enqueue(const T &value);
		void dequeue();
		void clear();
		bool isEmpty();
		int getSize();
};
template <typename T>
Queue<T>::Queue(){
}
template <typename T>
void Queue<T>::enqueue(const T &value){
	data.addLast(value);
}
template <typename T>
void Queue<T>::dequeue(){
	data.removeFirst();
}
template <typename T>
void Queue<T>::clear(){
	data.clear();
}
template <typename T>
bool Queue<T>::isEmpty(){
	return data.isEmpty();
}
template <typename T>
int Queue<T>::getSize(){
	return data.getSize();
}
#endif
