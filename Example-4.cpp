#include <iostream>
using namespace std;

class Person {
protected:
	int id;
	string name;
public:
	// 基类的构造函数先执行
	Person(int id, string name) {
		this->id = id;
		this->name = name;
	}
	// 基类的析构函数后执行
	~Person() {
		cout << "~Person()..." << endl;
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
	// 子类构造函数调用父类构造函数，本身的代码后执行
	Student(int id, string name, int cpp_score, int java_score)
	 : Person(id, name) {
		this->cpp_score = cpp_score;
		this->java_score = java_score;

	}
	void display() {
		cout << id << " " << name << endl;
		cout << cpp_score << " " << java_score << endl;
	}
	// 子类的析构函数先执行
	~Student() {
		cout << "~Student()..." << endl;
	}
};

class PostGraduate() : public Student {
private:
	int computer_graphics;
public:
	// 子类构造函数只需要调用直接父类的构造函数
	// 不需要调用间接父类的构造函数(虚基类除外)
	PostGraduate(int id, string name, 
	int cpp_score, int java_score,
	int computer_graphics)
	 : Student(id, name, cpp_score, java_score) {
		 this->computer_graphics = computer_graphics;
	 }
};

int main()
{
	Student *s = new Student(1001, "zhang", 99, 100);
	s->display();
	delete s;
	system("pause");
	return 0;
}
