#include <iostream>
using namespace std;

class Complex {
	private:
	float real, imag;
	public:
	Complex(float real, float imag) {
		this->real = real;
		this->imag = imag;
	}
	Complex(float real) {
		this->real = real;
		this->imag = 0.0f;		
	}
	operator float() {
		return this->real;
	}
};

int main() {
	Complex c(1.1, 2.2);
	float f1 = (float)c;
	float f2 = float(c);
	float f3 = c.operator float();
	float f4 = c;
	cout << f1 << " " << f2 << " "
		<< f3 << " " << f4 << endl;
	system("pause");
	return 0;
}
