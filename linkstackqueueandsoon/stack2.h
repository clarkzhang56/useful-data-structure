/*
	stack based vector
*/
#ifndef STACK_H
#define STACK_H
#include"vector.h"
using namespace std;
template<typename T>
class Stack{
	private:
		Vector<T>data;
		int top;
	public:
		Stack(int size=6);
		Stack(const Stack<T>&v);
		void clear();
		bool isEmpty();
		void push(T value);
		T pop();
		T peek()const;
};
template<typename T>
Stack<T>::Stack(int size):data(size){
	clear();
}
template<typename T>
Stack<T>::Stack(const Stack<T>&v):data(v.data),top(v.top){
}
template<typename T>
void Stack<T>::clear(){
	top=0;
}
template<typename T>
bool Stack<T>::isEmpty(){
	return top==0;
}
template<typename T>
void Stack<T>::push(T value){
	if(top>=data.getSize())
		data.setSize(2*data.getSize());
	data[top++]=value;
}
template<typename T>
T Stack<T>::pop(){
	return data[--top];
}
template<typename T>
T Stack<T>::peek() const{
	return data[top-1];
}
#endif
