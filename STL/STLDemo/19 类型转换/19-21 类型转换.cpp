#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

class Buliding{};
class Animal{};
class Cat : public Animal {};

//static_cast  �������õ��������ͻ��߾��м̳й�ϵ��ָ���������
void test01() {
    //��������ת��
    int a = 51;
    char c = static_cast<char>(a);
    cout << "a:" << a << endl;
    cout << "c:" << c << endl;

    //��������i����ָ��
    //int* p = NULL;
    //char* sp = static_cast<char*>(p);

    //����ָ��
    //Buliding* building = NULL;
    //Animal* animal = static_cast<Animal*>(building);

    //ת�����м̳й�ϵ��ָ��
    //����ָ��ת������ָ��
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);

    //ת�����м̳й�ϵ��ָ��
    //����ָ��ת�ɸ���ָ��
    Cat* soncat = NULL;
    Animal* anifather = static_cast<Animal*>(soncat);

    //��������תΪ��������
    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& cat1 = static_cast<Cat&>(aniref);

    Cat catobj;
    Cat& catrief = catobj;
    Animal& anifather2 = static_cast<Animal &>(catrief);

    //���ۣ�static_cast�������õ��������ͻ��߾��м̳й�ϵ��ָ���������
}

//dynamic_cast  ת�����м̳й�ϵ��ָ��������ã���ת��ǰ����ж������͵ļ��
void test02() {
    //��������ת��
    //int a = 51;
    //char c = dynamic_cast<char>(a);
    //cout << "a:" << a << endl;
    //cout << "c:" << c << endl;

    //������������ָ��
    //int* p = NULL;
    //char* sp = dynamic_cast<char*>(p);

    //�Ǽ̳й�ϵ��ָ���������
    //Animal* ani = NULL;
    //Buliding* building = dynamic_cast<Building*>(ani);

    //���м̳й�ϵ��ָ��
    //Animal* ani = NULL;
    //Cat* cat = dynamic_cast<Cat*>(ani);   //ʧ��ԭ��dynamic_cast��������ͼ�飬���಻��ת��Ϊ����ָ�루Сת�󲻰�ȫ��

    Cat* cat = NULL;
    Animal* ani = dynamic_cast<Animal*>(cat);//�ɹ�������תΪ���࣬��תС��ȫ

    //���ۣ�dynamicֻ��ת�����м̳й�ϵ��ָ��������ã�����ֻ����������תΪ������
}

//const_cast    ָ�롢���á�����ָ��  ȡ��/����const����
void test03() {
    //����
    int a = 10;
    const int& b = a;
    int & c = const_cast<int&>(b);
    c = 20;
    cout << "a:" << a << endl;  
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    //ָ��
    int pp = 0;
    const int* p = &pp;
    int* p2 = const_cast<int*>(p);
    if (p2) {
        *p2 = 10;
    }
    cout << *p2 << endl;


    int* p3 = NULL;
    const int* p4 = const_cast<const int*>(p3);

    //�ܽ᣺���ӻ���ȥ��������const����
}

//reinterpret_cast ǿ������ת��  �޹ص�ָ�����Ͷ����Խ���ת�� ��������ָ��
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test04() {
    //1.�޹ص�ָ�����Ͷ����Խ���ת��
    Buliding* buliding = NULL;
    Animal* animal = reinterpret_cast<Animal*>(buliding);

    //2.����ָ��ת��
    FUNC1 func1;
    FUNC2 func2 = reinterpret_cast<FUNC2>(func1);

}


int main()
{
    cout << "test01:" << endl;;
    test01();
    cout << "test02:" << endl;
    test02();
    cout << "test03:" << endl;
    test03();
    cout << "test04:" << endl;
    test04();

    return 0;
}