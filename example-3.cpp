#include <iostream>
using namespace std;

class Person {
public:
	int id;
	string name;
public:
	Person(int id, string name) {
		this->id = id;
		this->name = name;
	}
	int GetID() {
		return id;
	}
	string GetName() {
		return name;
	}
};

// 父类成员在子类中的访问权限
// 由两个因素确定：（1）在父类中的访问权限
// （2）子类的继承方式
// 9种组合：在父类中是private，子类和类外都不能访问(private)
// protected+public=protected
// protected+protected=protected
// protected+private=private
// public+public=public
// public+protected=protected
// public+private=private

class Student : public Person {
private:
	int cpp_score;
	int java_score;
public:
	// 子类构造函数调用父类构造函数
	Student(int id, string name, int cpp_score, int java_score)
	 : Person(id, name) {
		this->cpp_score = cpp_score;
		this->java_score = java_score;

	}
	void display() {
		cout << id << " " << name << endl;
		cout << cpp_score << " " << java_score << endl;
	}
};


int main()
{
	Student s(1001, "zhang", 99, 100);
	s.display();
	system("pause");
	return 0;
}
