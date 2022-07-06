#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
//��д�Լ����쳣��

class Person {
public:
    Person() {
        mAge = 0;
    }
    void setAge(int age) {
        if (age < 0 || age >100) {
            throw out_of_range("����Ӧ����0-100֮�䣡");
        }
        this->mAge = age;
    }
public:
    int mAge;
};

void test01() {
    Person p;
    //try {
    //    p.setAge(1000);
    //}
    //catch (out_of_range e) {
    //    cout << e.what() << endl;
    //}
    try {
        p.setAge(1000);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}


class MyOutOfRange : public exception {
public:
    MyOutOfRange(const char* error) {
        pError = new char[strlen(error) + 1];
        strcpy(pError, error);
    }
    ~MyOutOfRange() {
        if (pError != NULL) {
            delete[] pError;
        }
    }
    virtual char const* what() const {
        return pError;
    }
public:
    char* pError;

};

void func02() {
    throw MyOutOfRange("���Լ���out_of_range");
}

void test02() {
    try {
       func02();
    }
    catch (exception& e) {  //ûд�������죬���Բ�ʹ����ͨ���������쳣��ʹ�����ý�
        cout << e.what() << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}