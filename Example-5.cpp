#include <iostream>
using namespace std;

class Person {
protected:
	int id;
	string name;
public:
	Person(int id, string name) {
		this->id = id;
		this->name = name;
		cout << "Person()..." << endl;
	}
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

class Student : public Person {
private:
	Person monitor;	// 子对象（对象组合、对象内嵌、包装模式）
	int cpp_score;
	int java_score;
public:
	// 子类构造函数先后调用父类构造函数、子对象的构造函数后，
	// 再执行自身的代码
	Student(int id, string name, 
	int cpp_score, int java_score,
	int id1, string name1)
	 : Person(id, name), monitor(id1, name1) {
		this->cpp_score = cpp_score;
		this->java_score = java_score;
	}
	void display() {
		cout << id << " " << name << endl;
		cout << cpp_score << " " << java_score << endl;
	}
	~Student() {
		cout << "~Student()..." << endl;
	}
};


int main()
{
	Student *s = new Student(1001, "zhang"
	, 99, 100,
	1009, "wang");
	s->display();
	delete s;
	system("pause");
	return 0;
}
