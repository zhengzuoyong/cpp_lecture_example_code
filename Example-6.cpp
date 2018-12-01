#include <iostream>
#include <string>
using namespace std; // cout定义在std中

class Person {
protected:
	string name;
public:
	Person(string name) {
		this->name = name;
	}
};

// 虚基类
class Teacher : virtual public Person {
protected:
	string title;
public:
	Teacher(string name, string title)
	: Person(name) {	// 对Person类构造函数的调用被阻断(因为继承了虚基类)
		this->title = title;
	}
	void show() {
		cout << name << " " << title << endl;
	}
};

// 虚基类
class Student : virtual public Person {
protected:
	float score;
public:
	Student(string name, float score)
	: Person(name) {	// 对Person类构造函数的调用被阻断(因为继承了虚基类
		this->score = score;
	}
	void show() {
		cout << name << " " << score << endl;
	}
};

// 多重继承，有两个及以上的基类
class Graduate : public Teacher, public Student {
private:
	float wage;
public:
	// 子类的构造函数，用于向两个直接基类和虚基类的构造函数传递参数
	Graduate(string name, string title,
	float score,
	float wage) : Teacher(name, title),
	Student(name, score),
	Person(name) {	// 直接调用间接基类（虚基类）的构造函数
		this->wage = wage;
	}
	// 如何调用基类的同名函数/同名数据
	// (用直接基类名字区分)
	void show() {
		Teacher::show();
		Student::show();
		// name此时只有1个，不再需要用直接基类名字区分了
		// 只有在二义性的情况下，才使用基类名（作用域）来区分同名情况
		cout << name << endl;
		cout << wage << endl;
	}
};

int main() {
	Graduate *g = new Graduate("zhang", "professor",
	100, 600.0);
	g->show();
	system("pause");
	delete g;
	return 100;
}