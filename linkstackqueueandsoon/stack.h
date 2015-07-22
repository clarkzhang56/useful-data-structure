/*
	stack based linkedlist
*/
#ifndef STACK2_H
#define STACK2_H
#include"linkedlist.h"

using namespace std;
template <typename T>
class Stack2{
	private:
		Linkedlist<T> data;
		int top;
	public:
		Stack2();
		void push(const T &value);
		void pop();
		bool isEmpty();
		T peek();
};
template <typename T>
Stack2<T>::Stack2(){
}
template <typename T>
void Stack2<T>::push(const T &value){
	data.addLast(value);
}
template <typename T>
void Stack2<T>::pop(){
	data.removeLast();
}
template <typename T>
T Stack2<T>::peek(){
	return data.getLast();
}
template <typename T>
bool Stack2<T>::isEmpty(){
	return data.isEmpty();
}
#endif
