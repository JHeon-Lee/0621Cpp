#include <iostream>

using namespace std;

// 가상 소멸자

class Base
{
public:
	Base() { cout << "Base()" << endl;}
	virtual ~Base() { cout << "~Base()" << endl;} // 부모 클래스에선 항상 붙여주는게 좋음
};

class Derived : public Base
{
public:
	~Derived()
	{
		cout << "~Derived()" << endl;
	}

private:
	int* arr = nullptr;
};

int main()
{
	Base b;
	Base* base = new Derived;
	delete base;
	// b생-> base생-> Derived생(미출력) -> Derived소-> base소-> b소

	return 0;
}