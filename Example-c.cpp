#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// 抽象类

// 不能产生对象，但是可以作为其他类的基类
class Shape {
public:
	// 纯虚函数(只是定义一个函数接口)
	virtual float area() = 0;
};

// 点(具体类)
class Point : public Shape {
protected:
	float x, y;	// 点的坐标
public:
	Point(float x, float y) {
		this->x = x;
		this->y = y;
	}
	void display() {
		cout << "Point : ("
		 << x << "," << y << ")" << endl;
	}
	// 实现抽象父类的功能
	virtual float area() {
		return 0.0f;
	}
};

// 圆
class Circle : public Point {
protected:
	float radius;	// 半径
public:
	Circle(float x, float y, float radius)
	: Point(x, y) {
		this->radius = radius;
	}
	void display() {
		cout << "Circle : ("
		 << x << "," << y << "," << radius
		 << ")" << endl; 
	}
	virtual float area() {
		return 3.14 * radius * radius;
	}
};

// 圆柱体
class Cylinder : public Circle {
protected:
	float height;	// 高度
public:
	Cylinder(float x, float y, float radius,
	float height) : Circle(x, y, radius) {
		this->height = height;
	}
	void display() {
		cout << "Cylinder: (" << x << ","
		<< y << "," << radius << ","
		<< height << ")" << endl;
	}
	virtual float area() {
		return 2 * 3.14 * radius * radius +
		2 * 3.14 * radius * height;
	}
};

// 全局area函数，接收统一的参数类型Shape *, 可以用来指向Point类及其子类对象
float area(Shape *p) {
	return p->area();	// 在这里会产生多态，调用对象所属类的area(), 而不是基类(Point)部分的area()
}

int main() {
	Point po(2.0, 3.0);
	Circle c (2.0, 3.0, 4.0);
	Cylinder cy(2.0, 3.0, 4.0, 5.0);

	// 多态出现的必要条件：
	// (1) 继承关系
	// (2) 同名覆盖的函数用virtual关键字修饰
	// (3) 基类类型的指针（引用）指向（引用）了派生类对象
	// (4) 调用了同名函数（此时产生多态！）

	// 产生多态的指针写法
	Shape *p;	// 抽象基类指针
	p = &po;
	cout << "Point's area: " << p->area() << endl;
	p = &c;
	cout << "Circle's area: " << p->area() << endl;
	p = &cy;
	cout << "Cylinder's area: " << p->area() << endl;


	// 产生多态的数组写法（举例），将不同类的对象统一放入一个基类类型的数组中
	Shape *s[3];
	s[0] = &po;
	s[1] = &c;
	s[2] = &cy;
	for (int i = 0; i < 3; i++) {
		cout << ::area(s[i]) << endl;
		//cout << s[i]->area() << endl;	// 这两行取其一，都是产生多态的写法
	}
	
	system("pause");
	return 0;
}
