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
		//���
		this->data =  new T[arr.capacity];
		//��arr�����ݶ���������
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = arr.data[i];
		}
	}
	MyArray& operator=(const MyArray& arr) {
		//�Ը�ֵ���
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

	//β�巨
	void Push_Back(const T& val) {
		//��̬����
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

	//βɾ��
	void Pop_Back() {
		//���ʲ������һ��Ԫ��
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
		//�±���ʲ������ı߽���
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

	T* data; // ָ��ָ��������ٵ���ʵ����

	int capacity;

	int size;

};