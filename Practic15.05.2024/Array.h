#pragma once
#include <iostream>

using namespace std;

/*
Задание 1
Создать шаблонный класс-контейнер Array, который представляет собой массив,
позволяющий хранить объекты заданного типа.
Класс должен реализовывать следующие функции:
■ GetSize – получение размера массива (количество элементов,
под которые выделена память);
■ SetSize(int size, int grow = 1) – установка размера массива
(если параметр size больше предыдущего размера массива, то
выделяется дополнительный блок памяти, если нет, то «лишние»
элементы теряются и память освобождается); параметр
grow определяет для какого количества элементов необходимо выделить память,
если количество элементов превосходит
текущий размер массива. Например, SetSize(5, 5); означает,
что при добавлении 6-го элемента размер массива становится
равным 10, при добавлении 11-го - 15 и т. д.;
■ GetUpperBound - получение последнего допустимого индекса в массиве.
Например, если при размере массива 10, вы добавляете в него 4 элемента, то функция вернет 3;
■ IsEmpty - массив пуст?;
■ FreeExtra - удалить «лишнюю» память (выше последнего допустимого индекса);
■ RemoveAll – удалить все;
■ GetAt-получение определенного элемента (по индексу);
■ SetAt – установка нового значения для определенного элемента
(индекс элемента должен быть меньше текущего размера
массива);
■ operator [] – для реализации двух предыдущих функций;
■ Add – добавление элемента в массив (при необходимости
массив увеличивается на значение grow функции SetSize);
■ Append – «сложение» двух массивов;
■ operator =;
■ GetData – получения адреса массива с данными;
■ InsertAt – вставка элемента(-ов) в заданную позицию;
■ RemoveAt – удаление элемента(-ов) с заданной позиции
*/

template<class T>
class Array
{
	int size;
	int grow;
	int lastIndex;
	T* arr;

	void initArr(int size, int for_size) {
		T* temp = new T[size];
		for (int i = 0; i < for_size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
public:
	Array();
	/// <summary>
	/// получение размера массива(количество элементов,
	///	под которые выделена память);
	/// </summary>
	int GetSize();

	/// <summary>
	/// установка размера массива
	/// (если параметр size больше предыдущего размера массива, то
	/// выделяется дополнительный блок памяти, если нет, то «лишние»
	/// элементы теряются и память освобождается); 
	/// параметр grow определяет для какого количества элементов необходимо 
	/// выделить память, если количество элементов превосходит
	/// текущий размер массива.Например, SetSize(5, 5) - означает,
	/// что при добавлении 6 - го элемента размер массива становится
	/// равным 10, при добавлении 11 - го - 15 и т.д.;
	/// </summary>
	/// <param name="size">размер массива</param>
	/// <param name="grow">размер увеличения массива при его заполнении</param>
	void SetSize(int size, int grow = 1);

	/// <summary>
	///  получение последнего допустимого индекса в массиве.
	/// Например, если при размере массива 10, вы добавляете 
	/// в него 4 элемента, то функция вернет 3;
	/// </summary>
	/// <returns>последний допустимый индекс в массиве</returns>
	int GetUpperBound();

	/// <summary>
	/// массив пуст?
	/// </summary>
	/// <returns>true: массив пустой, иначе false</returns>
	bool IsEmpty();

	/// <summary>
	/// удалить «лишнюю» память(выше последнего допустимого индекса)
	/// </summary>
	void FreeExtra();

	/// <summary>
	/// удалить все;
	/// </summary>
	void RemoveAll();

	/// <summary>
	/// получение определенного элемента(по индексу)
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>элемент по индексу</returns>
	T& GetAt(int index);

	/// <summary>
	/// установка нового значения для определенного элемента
	/// (индекс элемента должен быть меньше текущего размера
	///	массива);
	/// </summary>
	/// <param name="index">индекс</param>
	/// <param name="elem">элемент</param>
	void SetAt(int index, T elem);

	/// <summary>
	/// для реализации двух предыдущих функций;
	/// </summary>
	/// <param name="index">индекс</param>
	/// <returns>элемент</returns>
	T& operator [](int index);

	/// <summary>
	/// добавление элемента в массив(при необходимости
	/// массив увеличивается на значение grow функции SetSize);
	/// </summary>
	/// <param name="elem">эелемент</param>
	void Add(T elem);

	/// <summary>
	/// «сложение» двух массивов;
	/// </summary>
	/// <param name="arr">массив друго объекта класса</param>
	Array& Append(const Array& obj);
	Array& operator=(const Array& obj);

	/// <summary>
	/// получения адреса массива с данными;
	/// </summary>
	/// <returns></returns>
	T* GetData();

	/// <summary>
	/// вставка элемента(-ов) в заданную позицию;
	/// </summary>
	/// <param name="index">индекс</param>
	/// <param name="elems">элемент(-ы)</param>
	/// <param name="size">количество вставляемых элементов. По умолчанию - 1</param>
	void InsertAt(int index, T* elems, int size = 1);

	/// <summary>
	/// удаление элемента(-ов) с заданной позиции
	/// </summary>
	/// <param name="index">индекс</param>
	/// <param name="elems">элемент(-ы)</param>
	/// <param name="size">размер</param>
	void RemoveAt(int index, int count = 1);


	friend ostream& operator<<(ostream& out, Array& obj) {
		for (int i = 0; i <= obj.lastIndex; i++) {
			out << obj.arr[i] << " ";
		}
		out << endl;
		return out;
	}

	~Array() {
		if (arr)
			delete[] arr;
	}
};


template <class T>
Array<T>::Array() :size{ 0 }, arr{ nullptr }, grow{ 1 }, lastIndex{ -1 } {}

template <class T>
int Array<T>::GetSize() {
	return size;
}

template <class T>
void Array<T>::SetSize(int size, int grow) {

	this->grow = grow;

	if (this->size > size) {
		initArr(size, size);
	}
	else if (this->size < size) {
		initArr(size, this->size);
	}
	else {
		return;
	}
	this->size = size;
}

template <class T>
int Array<T>::GetUpperBound() {
	return lastIndex;
}

template <class T>
bool Array<T>::IsEmpty() {
	return lastIndex == -1 ? true : false;
}

template <class T>
void Array<T>::FreeExtra() {
	if (size == lastIndex + 1) return;

	size = lastIndex + 1;

	initArr(size, size);
}

template <class T>
void Array<T>::RemoveAll();
template <class T>
T& Array<T>::GetAt(int index) {
	return (index >= 0 && index <= lastIndex) ? arr[index] : arr[0];
}

template <class T>
void Array<T>::SetAt(int index, T elem) {
	if (index >= 0 && index < size)
		arr[index] = elem;
}

template <class T>
T& Array<T>::operator [](int index) {
	return GetAt(index);
}

template <class T>
void Array<T>::Add(T elem) {
	if (lastIndex + 1 == size) {
		size += grow;
		initArr(size + grow, size - grow);
	}
	arr[lastIndex++ + 1] = elem;
}

template <class T>
Array<T>& Array<T>::Append(const Array<T>& obj) {
	InsertAt(lastIndex + 1, obj.arr, obj.lastIndex + 1);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& obj) {
	return Append(obj);
}

template <class T>
T* Array<T>::GetData() {
	return arr;
}

template <class T>
void Array<T>::InsertAt(int index, T* elems, int size) {
	if (index < 0 || index >= this->size - 1)
		return;
	T* temp = new T[this->size + size];

	int j = 0;
	for (int i = 0; i < index; i++, j++) {
		temp[j] = this->arr[i];
	}

	for (int i = 0; i < size; i++, j++) {
		temp[j] = elems[i];
	}

	for (int i = index; i < this->size; i++, j++) {
		temp[j] = arr[i];
	}
	delete[] arr;
	arr = temp;
	this->size = this->size + size;
	lastIndex += size;
}

template <class T>
void Array<T>::RemoveAt(int index, int count) {
	if (index <= 0 || index > size - 1 && count < size) return;

	T* temp = new T[size - count];
	int j = 0;
	for (int i = 0; i < index; i++, j++) {
		temp[j] = arr[i];
	}
	for (int i = index + count; i <= lastIndex; i++, j++) {
		temp[j] = arr[i];
	}
	delete[] arr;
	arr = temp;
	lastIndex = j - 1;
}
