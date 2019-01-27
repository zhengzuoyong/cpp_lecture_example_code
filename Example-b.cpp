#include <iostream>
#include <string>
using namespace std;

// 虚析构函数

class Point {
public:
	Point() {}
	virtual ~Point() {	// 将基类的析构函数声明为虚析构函数（用virtual关键字修饰）
		cout << "~Point() executed." << endl;
	}
};

class Circle : public Point {
public:
	Circle() {}
	virtual ~Circle() {	// 派生类的析构函数，即使不加virtual关键字，也是虚析构函数
		cout << "~Circle() executed." << endl;
	}
};

int main() {
	Point *p = new Circle();	// 基类类型指针指向派生类对象
	delete p;	// 删除对象时，派生类和基类的析构函数都会执行

	system("pause");

	return 0;
}


