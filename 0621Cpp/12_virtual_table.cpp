#include <iostream>

using namespace std;

// �����Լ� ���̺��� Ŭ���� �� �ϳ��� ����

// https://cosyp.tistory.com/228 ����

/*
	    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1()
                                                       \-func2()

    --> ���� ���ε����� �̷���� �Լ� ������
*/

class Base
{
public:
    virtual void func1() { cout << "func1" << endl; }
    virtual void func2() { cout << "func2" << endl; }
};

class Derived : public Base
{
public:
    virtual void func1() override { cout << "Derived::func1" << endl; }
    void func3() { cout << "func3" << endl; }
};

int main()
{
    Base* bptr = new Base();
    bptr->func1();
    bptr->func2();

    Derived* dptr = new Derived();
    dptr->func1();
    dptr->func2();
    dptr->func3();

	return 0;
}