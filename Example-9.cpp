#include <iostream>
#include <string>
using namespace std;

// 继承与组合的含义
// (1) 继承：“是”（派生类类型“是”基类类型）
// (2) 组合：“有”（一个类型有另外一个类型的对象作为
// 其数据成员）
// 客观上，都使一个类具有了另外一个类的数据成员
// 好处是：重用代码，提高开发效率

class BirthDate {
private:
	int year, month, day;
public:
	BirthDate(int y, int m, int d)
	: year(y), month(m), day(d) {
	}
	void show() {
		cout << year << "-" << month << "-"
		<< day << endl;
	}
	BirthDate(BirthDate &b) {
		this->year = b.year;
		this->month = b.month;
		this->day = b.day;
	}
	BirthDate() {}
};

class Student {
private:
	int num;
	string name;
	BirthDate bd;	// 对象组合（子对象、对象内嵌、包装模式）
public:
	// 类内声明
	Student(int n, string na, BirthDate b);
	void show() {
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		bd.show();
	}
};

// 类外实现
Student::Student(int n, string na, BirthDate b)
: bd(b)
{
	num = n;
	name = na;
}

int main() {
	BirthDate b(1998, 1, 1);
	Student s(1000, "zhang", b);
	s.show();
	system("pause");
	return 0;
}