#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣����

void func01() {
    throw 1;//�׳�int�����쳣
}

void func02() {
    throw "abc";//�׳�char*�����쳣
}

class MyException {
public:
    MyException(const char* str) {
        error = new char[strlen(str) + 1];
        strcpy(error, str);
    }
    //27����취�����ӿ������캯����=���㷨����
    MyException(const MyException& copy) {
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }
    MyException& operator=(const MyException& copy) {
        if (this->error != NULL) {
            delete[] this->error;
            this->error = NULL;
        }
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }

    void what() {
        cout << error << endl;
    }
    ~MyException() {
        if (error != NULL) {
            delete[] error;
        }
    }
public:
    char* error;
};

void func03() {
    throw MyException("�Ҹ�д���쳣");
}

void test01() {
    try {
        func01();
    }
    catch (int e) {
        cout << "����int�쳣" << e << endl;
    }

    try {
        func02();
    }
    catch (const char* e) {
        cout << "����char*�쳣" << e << endl;
    }

    try {
        func03();
    }
    catch (MyException e) {//27 �����ԭ��throw����������´�����˴���e����������errorָ�붼ָ��ͬһ���ڴ�ռ䣬��������ûд�������캯��������������ʱ��ͬһ�ڴ�ռ����������
        cout << "����MyException�쳣" << endl;
        e.what();
    }

}


int main()
{
    test01();
    return 0;
}