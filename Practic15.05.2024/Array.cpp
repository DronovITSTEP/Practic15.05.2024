#include "Array.h"

template<class T>
int Array<T>::GetSize() {
	return size;
}
template<class T>
void Array<T>::SetSize(int size, int grow){

	this->grow = grow;

	if (this->size > size) {
		T* temp = new T[size];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	else if (this->size < size) {
		T* temp = new T[size];
		for (int i = 0; i < this->size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	else {
		return;
	}
}

template<class T>
int Array<T>::GetUpperBound() {
	return lastIndex;
}

template<class T>
bool Array<T>::IsEmpty() {
	return lastIndex == -1 ? true : false;
}

template<class T>
void Array<T>::FreeExtra() {
	if (size == lastIndex + 1) return;

	size = lastIndex + 1;

	T* temp = new T[size];
	for (int i = 0; i < size; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}

template<class T>
void Array<T>::RemoveAll() {
	for (int i = 0; i < size; i++) {
		arr[i] = nullptr; 
	}
}
void Array<int>::RemoveAll() {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
void Array<double>::RemoveAll() {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}
void Array<char>::RemoveAll() {
	for (int i = 0; i < size; i++) {
		arr[i] = '\0';
	}
}
void Array<string>::RemoveAll() {
	for (int i = 0; i < size; i++) {
		arr[i] = "";
	}
}

template<class T>
T& Array<T>::GetAt(int index) {
	return (index >=0 && index <= lastIndex)? arr[index] : arr[0];
}

template<class T>
void Array<T>::SetAt(int index, T elem) {
	if (index >= 0 && index < size)
		arr[index] = elem;
}

template<class T>
T& Array<T>::operator [](int index) {
	return GetAt(index);
}

template<class T>
void Array<T>::Add(T elem) {
	if (lastIndex + 1 == size) {
		size = size + grow;

		T* temp = new T[size + grow];
		for (int i = 0; i < size-grow; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	arr[lastIndex++ + 1] = elem;
}

template<class T>
Array<T>& Array<T>::Append(const Array& obj) {
	if (this->size <= obj.size)
		for (int i = 0; i < size; i++) {
			this->arr[i] = obj.arr[i]
		}
	else
		for (int i = 0; i < obj.size; i++) {
			this->arr[i] = obj.arr[i]
		}
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj) {
	return Append(obj);
}

template<class T>
T& Array<T>::GetData() {
	return arr;
}

template<class T>
void Array<T>::InsertAt(int index, T* elems, int size) {
	if (index <= 0 || index > this->size - 1) return;

	for (int i = 0; i < size; i++) {
		Add(elems[i]);
	}
}

template<class T>
void Array<T>::RemoveAt(int index, int count) {
	if (index <= 0 || index > size - 1 && count < size) return;

	T* temp = new T[size];
	int j = 0;
	for (int i = 0; i <= index; i++, j++) {
		temp[j] = arr[i];
	}
	for (int i = index + count; i < size; i++, j++) {
		temp[j] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
