#include <iostream>

using namespace std;

// ���� �Ҹ���

class Base
{
public:
	Base() { cout << "Base()" << endl;}
	virtual ~Base() { cout << "~Base()" << endl;} // �θ� Ŭ�������� �׻� �ٿ��ִ°� ����
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

	return 0;
}