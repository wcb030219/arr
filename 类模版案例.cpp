#include <iostream>
using namespace std;
#include <string>
#include "MyArray.hpp"
/*����������ʵ��һ��ͨ�õ������࣬Ҫ�����£�

���Զ��������������Լ��Զ����������͵����ݽ��д洢

�������е����ݴ洢������

���캯���п��Դ������������

�ṩ��Ӧ�Ŀ������캯���Լ� operator= ��ֹǳ��������

�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��

����ͨ���±�ķ�ʽ���������е�Ԫ��

���Ի�ȡ�����е�ǰԪ�ظ��������������

*/

void Printfarr( MyArray <int> &arr) {
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i] << endl;
	}
}

class Person {
public:
	Person( ){}
	Person(string name,int age) {
		this->name = name;
		this->age = age;
	}

	string name;
	int age;

};
void Printf(MyArray<Person>&arr) {
	for (int i = 0; i < arr.getsize(); i++)
	{
		cout << arr[i].name << " " << arr[i].age << endl;
	}
}


void test01() {
	MyArray<Person> arr3(3);
	Person p1("�����", 99);
	Person p2("������", 9);
	Person p3("����", 999);
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	Printf(arr3);
	cout << "����" << arr3.getcapacity() << endl;
	cout << "��С" << arr3.getsize() << endl;

}

void test() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr"  << endl;
	Printfarr(arr1);
	cout <<"����" << arr1.getcapacity() << endl;
	cout <<"��С"<< arr1.getsize() << endl;
	MyArray <int> arr2(arr1);
	arr2.Pop_Back(); 
	cout << "����" << arr2.getcapacity() << endl;
	cout << "��С" << arr2.getsize() << endl;


}


int main() {
	test01();

	system("pause");
	return 0;
}