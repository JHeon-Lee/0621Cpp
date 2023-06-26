#include <iostream>

using namespace std;

// 순수가상함수, 추상클래스

/*
	순수가상함수
	자식클래스에서 반드시 재정의 해야하는 함수

	추상 클래스
	순수가상함수가 포함되있는 클래스

	인터페이스
	순수가상함수로만 만들어져있는 클래스
*/

#pragma region pure virtual function, abstract class

class animal abstract // 추상클래스
{
public:
	animal(const string& name) : name(name) {}

	auto getName()const { return name; }

	virtual void sleep() const final
	{
		cout << "sleep" << endl;
	}

	virtual void speak() const abstract = 0; // 순수 가상함수 선언

private:
	string name;
};

class cat : public animal
{
public:
	cat(string name) : animal(name) {}

	void speak() const override { cout << "야옹" << endl; }
};

class dog : public animal
{
public:
	dog(string name) : animal(name) {}

	void speak() const override { cout << "멍멍" << endl; }
};

class fox : public animal
{
public:
	fox(string name) : animal(name) {}
};

//int main()
//{
//	// animal ani("animal"); 순수가상함수가 들어있는 클래스는 객체화 불가능
//
//	cat cat("cat");
//	dog dog("dog");
//
//	dog.speak();
//
//	// fox fox("fox"); 순수가상함수가 재정의 안되있으면 객체화 불가능
//
//	return 0;
//}

#pragma endregion

#pragma region Interface

class IErrorLog // 인터페이스 클래스는 이름앞에 I 붙힘
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) = 0;
};

class FileErrorLog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error)
	{
		cout << "Writting error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error)
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void DoSomething(IErrorLog& log)
{
	log.ReportError("Error");
}

int main()
{
	FileErrorLog fileLog;
	ConsoleErrorLog consoleLog;

	DoSomething(fileLog);
	DoSomething(consoleLog);
}

#pragma endregion