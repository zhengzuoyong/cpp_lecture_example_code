#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

// 点
class Point {
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

// 全局area函数，接收统一的参数类型Point *, 可以用来指向Point类及其子类对象
float area(Point *p) {
	return p->area();	// 在这里会产生多态，调用对象所属类的area(), 而不是基类(Point)部分的area()
}

int main() {
	Point po(2.0, 3.0);
	Circle c (2.0, 3.0, 4.0);
	Cylinder cy(2.0, 3.0, 4.0, 5.0);

	// 指针写法(在没有使用虚函数之前)
	//Point *p = &c;
	//p->display();	// 调用基类（Point类）的display()
	// 引用写法
	//Point &r = c;
	//r.display();	// 调用基类（Point类）的display()

	// 多态出现的必要条件：
	// (1) 继承关系
	// (2) 同名覆盖的函数用virtual关键字修饰
	// (3) 基类类型的指针（引用）指向（引用）了派生类对象
	// (4) 调用了同名函数（此时产生多态！）

	// 产生多态的指针写法
	Point *p;
	p = &po;
	cout << "Point's area: " << p->area() << endl;
	p = &c;
	cout << "Circle's area: " << p->area() << endl;
	p = &cy;
	cout << "Cylinder's area: " << p->area() << endl;

	// 产生多态生的引用写法
	Point &r = po;
	cout << "Point's area: " << r.area() << endl;
	Point &r1 = c;
	cout << "Circle's area: " << r1.area() << endl;
	Point &r2 = cy;
	cout << "Cylinder's area: " << r2.area() << endl;

	// 产生多态的函数调用的写法（Point类型的形参指向各个类型的实参）
	cout << ::area(&po) << endl;
	cout << ::area(&c) << endl;
	cout << ::area(&cy) << endl;

	// 产生多态的数组写法（举例），将不同类的对象统一放入一个基类类型的数组中
	Point *s[3];
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
