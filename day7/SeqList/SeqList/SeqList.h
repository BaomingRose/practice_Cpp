#pragma once
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

template<class T>
class SeqList {
private:
	T* _data;
	size_t _size;
	size_t _capacity;

	void checkCapacity();
public:
	SeqList(size_t capacity = 10) : _capacity(capacity),
		_data(new T[capacity]),
		_size(0) {}

	~SeqList() {
		if (_data) {
			delete[] _data;
		}
		_size = _capacity = 0;
	}

	int size() {
		return _size;
	}

	int	capacity() {
		return _capacity;
	}

	void push_back(const T& src);
	void pop_back();

	T& operator[] (int n) {
		return _data[n];
	}

};

template <class T>
void SeqList<T>::checkCapacity() {
	if (_size == _capacity) {
		_capacity *= 2;

		_data = (T *)realloc(_data, sizeof(T) * _capacity);
		/*T * newSpace = new T[_capacity];
		for (int i = 0; i < _size; i++) {
			newSpace[i] = _data[i];
		}
		delete[] _data;
		_data = newSpace;*/
	}
}

template <class T>
void SeqList<T>::push_back(const T& src) {
	checkCapacity();

	_data[_size] = src;
	_size++;
}

template <class T>
void SeqList<T>::pop_back() {
	if (_size == 0) {
		return;
	}
	_size--;
}

