#pragma once

template<class T>
class TStack {
private:
	T* array;
	int maxsize;
	int size;

public:
	TStack(int ms = 200);
	TStack(const TStack& ts);
	~TStack();

	TStack& operator=(const TStack& ts);

	bool isFull();
	bool isEmpty();

	T top();
	T pop();
	void push(const T& element);
};

template<class T>
TStack<T>::TStack(int ms){
	if (ms <= 0) throw ms;
	maxsize = ms;
	size = 0;
	array = new T[maxsize];
}

template<class T>
TStack<T>::TStack(const TStack<T>& ts) {
	maxsize = ts.maxsize;
	size = ts.size;
	array = new T[maxsize];
	for (int i = 0; i < size; i++) array[i] = ts.array[i];
}

template<class T>
TStack<T>::~TStack() {
	delete[] array;
}

template<class T>
TStack<T>& TStack<T>::operator=(const TStack<T>& ts) {
	if (*this != ts) {
		if (maxsize != ts.maxsize) {
			delete[] array;
			maxsize = ts.maxsize;
			array = new T[maxsize];
		}
		size = ts.size;
		for (int i = 0; i < size; i++) array[i] = ts.array[i];
	}
}

template<class T>
bool TStack<T>::isFull() {
	return size == maxsize;
}

template<class T>
bool TStack<T>::isEmpty() {
	return size == 0;
}

template<class T>
T TStack<T>::top() {
	if (isEmpty()) throw -1;
	return array[size - 1];
}

template<class T>
T TStack<T>::pop() {
	if (isEmpty()) throw -1;
	size--;
	return array[size];
}

template<class T>
void TStack<T>::push(const T& element) {
	if (isFull()) throw -1;
	array[size] = element;
	size++;
}
