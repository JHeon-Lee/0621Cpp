#include <iostream>

using namespace std;

// ���������Լ�, �߻�Ŭ����

/*
	���������Լ�
	�ڽ�Ŭ�������� �ݵ�� ������ �ؾ��ϴ� �Լ�

	�߻� Ŭ����
	���������Լ��� ���Ե��ִ� Ŭ����

	�������̽�
	���������Լ��θ� ��������ִ� Ŭ����
*/

#pragma region pure virtual function, abstract class

class animal abstract // �߻�Ŭ����
{
public:
	animal(const string& name) : name(name) {}

	auto getName()const { return name; }

	virtual void sleep() const final
	{
		cout << "sleep" << endl;
	}

	virtual void speak() const abstract = 0; // ���� �����Լ� ����

private:
	string name;
};

class cat : public animal
{
public:
	cat(string name) : animal(name) {}

	void speak() const override { cout << "�߿�" << endl; }
};

class dog : public animal
{
public:
	dog(string name) : animal(name) {}

	void speak() const override { cout << "�۸�" << endl; }
};

class fox : public animal
{
public:
	fox(string name) : animal(name) {}
};

//int main()
//{
//	// animal ani("animal"); ���������Լ��� ����ִ� Ŭ������ ��üȭ �Ұ���
//
//	cat cat("cat");
//	dog dog("dog");
//
//	dog.speak();
//
//	// fox fox("fox"); ���������Լ��� ������ �ȵ������� ��üȭ �Ұ���
//
//	return 0;
//}

#pragma endregion

#pragma region Interface

class IErrorLog // �������̽� Ŭ������ �̸��տ� I ����
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