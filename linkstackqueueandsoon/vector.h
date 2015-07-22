#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include <iostream>
using namespace std;
template<typename T>
class Vector{
	public:
		Vector(int size);
		Vector(int size,const T &value);
		Vector(const Vector<T> &v);
		virtual ~Vector();
		const Vector<T> &operator=(const Vector<T>&right);
		int getSize();
		void setSize(int size);
		void print();
		T &operator[](int index);
		T operator[](int index) const;
	private:
		int size;
		T *pVector;
};
template<typename T>
Vector<T>::Vector(int size){
	if(size<=0)
		throw invalid_argument("Must be a positive num!");
	else
		this->size=size;
	pVector=new T[size];
}
template<typename T>
Vector<T>::Vector(int size,const T &value){
	/*The initial value are all the same*/
	if(size<=0)
		throw invalid_argument("Must be a positive num!");
	else
		this->size=size;
	pVector=new T[size];
	for(int i=0;i<size;i++)
		pVector[i]=value;
}
template<typename T>
Vector<T>::Vector(const Vector<T>&v){
	size=v.size;
	pVector=new T[size];
	for(int i=0;i<size;i++)
		pVector[i]=v.pVector[i];
}
template<typename T>
Vector<T>::~Vector(){
	delete[] pVector;
}
template<typename T>
const Vector<T>&Vector<T>::operator=(const Vector<T>&right){
	if(this!=&right){
		if(size!=right.size){
			delete[] pVector;
			size=right.size;
			pVector=new T[size];
		}
		for(int i=0;i<size;i++)
			pVector[i]=right.pVector[i];
	}
	return *this;
}
template<typename T>
int Vector<T>::getSize(){
	return size;
}
template<typename T>
void Vector<T>::setSize(int size){
	if(size<=0){
		throw invalid_argument("Must be positive!");
	}
	else{
		if(this->size!=size){
			T *old=pVector;
			pVector=new T[size];
			int num=(this->size>size)?size:this->size;
			for(int i=0;i<num;i++){
				pVector[i]=old[i];
			}
			this->size=size;
			delete []old;
		}
	}
}
template<typename T>
void Vector<T>::print(){
	for(int i=0;i<size;i++){
		cout<<pVector[i]<<" ";
	}
}
template<typename T>
T &Vector<T>::operator[](int index){
	return pVector[index];
}
template<typename T>
T Vector<T>::operator[](int index) const{
	return pVector[index];
}
#endif
