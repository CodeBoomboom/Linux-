#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException {
public:
    MyException() {
        cout << "���캯��" << endl;
    }

    MyException(const MyException& copy) {
        cout << "��������" << endl;
    }
    MyException(const MyException&& copy) {
        cout << "��������" << endl;
    }
    ~MyException() {
        cout << "��������" << endl;
        }
};
void func01() {
    throw MyException();    //������������ ���ù���
}

void func02() {
    MyException err = MyException();
    throw& err;
    //throw &(MyException());    //������������ ���ù���    //������������ֵ�޷�ȡ���ã���֪����Ƶ����ô���Ե�
}

void func03() {
    throw new MyException();
}

void test01() {

    //��ͨԪ������  ����  ָ��  

    //��ͨԪ������ catch������֮�������
    try {
        func01();
    }
    catch (MyException e) { //���ÿ�������
        cout << "�쳣����" << endl;
    }

    //�������� ���õ��ÿ������죬catch�����������
    try {
        func01();
    }
    catch (MyException& e) { //�����ٵ����κι���
        cout << "�쳣����" << endl;
    }

    //ָ������ ��catchǰ���Ѿ������ˣ��Ͳ�����catch�����MyException����ķ����Ƚ��д�����
    try {
        func02();
    }
    catch (MyException* e) { 
        cout << "�쳣����" << endl;
    }

    //ָ������ �������catch�����MyException����ķ����Ƚ��д�����Ҫ��ô����
    try {
        func03();
    }
    catch (MyException* e) {
        cout << "�쳣����" << endl;
        delete e;//�ֶ��ͷ�
    }
}

int main()
{
    test01();


    return 0;
}