#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������ֻ���׳�int float char�������͵��쳣���׳��������쳣�ᱨ����ֹ����
void func() throw(int, float, char) {
    throw "asd";//char*
}

//�����׳��κ��쳣      ��vc�п��������ܣ�����Ϊvc���������֧�ֲ�̫�ã���linux�����޷��ܵ�
void func01() throw() {
    throw - 1;
}

int main()
{
    //try {
    //    func();
    //}
    //catch (char* str) {
    //    cout << str << endl;
    //}
    //catch (int e) {
    //    cout << e << endl;
    //}
    //catch (...) {   //  ���������쳣

    //}

    try {
        func01();
    }
    catch (int a) {
        cout << a << endl;
    }
    return 0;
}