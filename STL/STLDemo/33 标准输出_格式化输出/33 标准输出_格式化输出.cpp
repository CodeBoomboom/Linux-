#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;
//��׼�����


void test01() {
    //cout << "hello world";
    //cout.flush();//ˢ�»�����
    cout.put('h').put('e').put('l') << endl;    //put�򻺳���д�ַ�

    cout.write("hello xdx",strlen("hello xdx"))<<endl;
}

//��ʽ�����
void test02() {
    //��Ա�����ķ�ʽ
    int num = 10;
    cout << num << endl;
    cout.unsetf(ios::dec);//ж�ص�ǰĬ�ϵ�10���������ʽ
    cout.setf(ios::oct);//����Ϊ�˽������
    cout.setf(ios::showbase);
    cout << num << endl;
    cout.unsetf(ios::oct);//ж�ذ˽���
    cout.setf(ios::hex);//16����
    cout << num << endl;

    cout.width(10);//����λ��
    cout.fill('*');//���ಿ����*���
    cout.setf(ios::left);//�����
    cout << num << endl;

    //ͨ�����Ʒ�  ��Ҫ����ͷ�ļ�iomanip
    int num2 = 10;
    cout << hex
        << setiosflags(ios::showbase)
        << setw(10)
        <<setfill('~')
        <<setiosflags(ios::left)
        << num2
        << endl;

}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}