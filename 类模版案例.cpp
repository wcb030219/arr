#include <iostream>
using namespace std;
#include <string>
#include "MyArray.hpp"
/*案例描述：实现一个通用的数组类，要求如下：

可以对内置数据类型以及自定义数据类型的数据进行存储

将数组中的数据存储到堆区

构造函数中可以传入数组的容量

提供对应的拷贝构造函数以及 operator= 防止浅拷贝问题

提供尾插法和尾删法对数组中的数据进行增加和删除

可以通过下标的方式访问数组中的元素

可以获取数组中当前元素个数和数组的容量

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
	Person p1("孙悟空", 99);
	Person p2("孙悟能", 9);
	Person p3("孙悟净", 999);
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	Printf(arr3);
	cout << "容量" << arr3.getcapacity() << endl;
	cout << "大小" << arr3.getsize() << endl;

}

void test() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr"  << endl;
	Printfarr(arr1);
	cout <<"容量" << arr1.getcapacity() << endl;
	cout <<"大小"<< arr1.getsize() << endl;
	MyArray <int> arr2(arr1);
	arr2.Pop_Back(); 
	cout << "容量" << arr2.getcapacity() << endl;
	cout << "大小" << arr2.getsize() << endl;


}


int main() {
	test01();

	system("pause");
	return 0;
}