#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣�����﷨
//�쳣�纯��
//�쳣���봦��

int divide(int x, int y) {
    if (y == 0) {
        throw y;    //���쳣
    }
    return x / y;
}

void test01() {
    //����ȥ�����쳣
    try {
        divide(10, 0);
    }
    catch (int e) {  //�쳣�Ǹ������ͽ���ƥ��
        cout << "����Ϊ" <<e<< endl;
    }
}


void CallDivide(int x, int y) {
    divide(x, y);
}
void test02() {
    //����ȥ�����쳣
    try {
        CallDivide(10, 0);
    }
    catch (int e) {  //�쳣�Ǹ������ͽ���ƥ��
        cout << "����Ϊ" << e << endl;
    }
}


int main()
{
    test01();
    test02();
    return 0;
}