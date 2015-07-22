#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>

template<typename T>
class Node{
	public:
		Node(){
			next=NULL;
		}
		Node(const T value){
			this->value=value;
			next=NULL;
		}
		T value;
		Node<T> *next;
};
template<typename T>
class Linkedlist{
	private:
		Node<T> *head,*tail;
		int size;
	public:
		Linkedlist();
		void addFirst(const T &value);
		void addLast(const T &value);
		void add(int index,const T &value);		
		void removeFirst();
		void removeLast();
		void remove(int index);
		T getFirst() const;
		T getLast() const;
		void clear();
		bool isEmpty();
		int getSize()const;
		void print();
		void sort();
};
template<typename T>
Linkedlist<T>::Linkedlist(){
	head=tail=NULL;
	size=0;
}
template<typename T>
void Linkedlist<T>::addFirst(const T &value){
	Node<T> *temp=new Node<T>(value);
	temp->next=head;
	head=temp;
	++size;
	if(tail==NULL)
		tail=head;
}
template<typename T>
void Linkedlist<T>::addLast(const T &value){
	if(tail==NULL){
		head=tail=new Node<T>(value);
	}else{
		tail->next=new Node<T>(value);
		tail=tail->next;
	}
	++size;
}
template<typename T>
void Linkedlist<T>::add(int index,const T &value){
	if(index==0){
		addFirst(value);
	}else if(index>=size){
		addLast(value);
	}else{
		Node<T> *temp=head;
		//while(temp->next)
		for(int i=1;i<index;i++){
			temp=temp->next;
		}
		Node<T> *temp2=temp->next;
		temp->next=new Node<T>(value);
		temp->next->next=temp2;
		++size;
	}
}
template<typename T>
void Linkedlist<T>::removeFirst(){
	if(head==NULL){
		throw runtime_error("Null list!");
	}else{
		Node<T> *temp=head;
		head=head->next;
		if(head==NULL){
			tail==NULL;
		}
		delete temp;
		--size;
	}
}
template<typename T>
void Linkedlist<T>::removeLast(){
	if(tail==NULL){
		throw runtime_error("NULL list!");
	}else if(head==tail){
		Node<T>*temp=head;
		head=tail=NULL;
		size=0;
		delete temp;
	}else{
		Node<T> *temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		Node<T> *temp2=tail;
		tail=temp;
		tail->next=NULL;
		delete temp2;
		--size;
	}
}
template<typename T>
void Linkedlist<T>::remove(int index){
	if(index==0){
		removeFirst();
	}else if(index==size-1){
		removeLast();
	}else if(index<0||index>=size){
		throw runtime_error("Out of range!");
	}else{
		Node<T>*current=head;
		for(int i=1;i<index;i++){
			current=current->next;
		}
		Node<T>*temp=current->next;
		current->next=temp->next;
		delete temp;
		--size;
	}
}
template<typename T>
T Linkedlist<T>::getFirst() const{
	if(head==NULL){
		throw runtime_error("null");
	}else{
	return head->value;		
	}
}
template<typename T>
T Linkedlist<T>::getLast() const{
	if(tail==NULL){
		throw runtime_error("NUll");
	}else{
		return tail->value;
	}
}
template<typename T>
void Linkedlist<T>::clear(){
	while(head!=NULL){
		Node<T>*temp=head;
		head=head->next;
		delete temp;
	}
	tail=NULL;
}
template<typename T>
bool Linkedlist<T>::isEmpty(){
	return head==NULL;
}
template<typename T>
int Linkedlist<T>::getSize() const{
	return size;
}
template<typename T>
void Linkedlist<T>::print(){
	Node<T>*current=head;
	while(current!=NULL){
		cout<<current->value<<" ";
		current=current->next;
	}
	cout<<endl;
}
//a little hard
template <typename T>
void Linkedlist<T>::sort(){
	Node<T> *p3=head;
	Node<T> *p1,*p2,*p4,*p5;
	while(p3->next->next!=NULL){
		p2=p3->next;
		p5=p2;
		p1=p2;
		bool flag=false;
		while(p1->next!=NULL){
			if(p5->value>p1->next->value){
				p5=p1->next;
				p4=p1;
				flag=true;
			}
			p1=p1->next;
		}
		if(flag){
			if(p2==p4){
				p2->next=p5->next;
				p5->next=p2;
				p3->next=p5;
			}else{
				Node<T> *temp=p5->next;
				p5->next=p2->next;
				p3->next=p5;
				p4->next=p2;
				p2->next=temp;
			}
		}
		p3=p3->next;
	}
	Node<T>*tmp=head;
	while(tmp!=NULL){
		cout<<tmp->value<<" ";
		tmp=tmp->next;
	}
}
#endif
