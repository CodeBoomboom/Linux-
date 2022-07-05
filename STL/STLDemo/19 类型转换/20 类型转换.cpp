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

    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& cat = static_cast<Cat&>(aniref);

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
int main()
{
    test01();
    test02();


    return 0;
}