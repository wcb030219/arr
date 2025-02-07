#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		this->data = new T[this->capacity];
	}

	MyArray(const MyArray& arr) {
		this->capacity = arr.capacity;
		this->size = arr.size;
		/*this->data = arr.data;*/
		//深拷贝
		this->data =  new T[arr.capacity];
		//将arr中数据都拷贝过来
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = arr.data[i];
		}
	}
	MyArray& operator=(const MyArray& arr) {
		//自赋值检查
		if (this == &arr) {
			return* this;
		}
		if (this->data != NULL)
		{
			delete[] this->data;
			this->data = NULL;
			this->capacity = 0;
			this->size = 0;
		}


		this->size = arr.size;
		this->capacity = arr.capacity;
		this->data = new T[arr.capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = arr.data[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val) {
		//动态扩容
		if (this->capacity == this->size) {
			this->capacity *= 2;
			T* newData = new T[this->capacity];
			for (int i = 0; i < this->size; i++) {
				newData[i] = this->data[i];
			}
			delete[] this->data;
			this->data = newData;
		}
		this->data[this->size] = val;
		this->size++;
	}

	//尾删法
	void Pop_Back() {
		//访问不到最后一个元素
		if (this->size == 0) {
			return;
		}
		this->size--;
	}


	int getcapacity() {
		return this->capacity;
	}

	int getsize() {
		return this->size;
	}

	T& operator[](int index) {
		//下标访问操作符的边界检查
		if (index < 0 || index >= this->size) {
			throw out_of_range(" ");
		}
		return this->data[index];
	}


	~MyArray() {
		if (this->data != NULL) {
			delete[]this->data;
			this->data = NULL;
		}
	}

private:

	T* data; // 指针指向堆区开辟的真实数组

	int capacity;

	int size;

};