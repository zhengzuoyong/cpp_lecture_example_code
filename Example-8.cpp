#include <iostream>
#include <string>
using namespace std;

// 建立基类和派生类对象之间的转换
// (1) 赋值转换（产生2个对象）
// (2) 指针转换
// (3) 引用转换

class Student {
private:
	int num;
	string name;
	float score;
public:
	Student(int num, string name, float score) {
		this->num = num;
		this->name = name;
		this->score = score;
	}
	void display() {
		cout << "num: " << num << endl;
		cout << "name: " << name << endl;
		cout << "score: " << score << endl;
	}
};

class Graduate : public Student {
private:
	float pay;
public:
	Graduate(int num, string name,
	float score, float pay)
	:Student(num, name, score) {
		this->pay = pay;
	}
	void display() {
		Student::display();
		cout << "pay: " << pay << endl;
	}
};

int main() {
	// 以下写法成立（基类类型引用可以引用派生类对象）
	Graduate g(1000, "zhang", 95, 500);
	Student &p = g;
	p.display();

	//  以下写法不能成立(派生类型引用无法引用基类对象)
	Student s1(1000, "zhang", 95);
	Graduate &p1 = s1;
	p1.display();

	system("pause");
	return 0;
}