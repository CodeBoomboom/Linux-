#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ʵ�ֵ����Ĳ���
//1.���캯��˽�л�
//2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3.�ṩ��̬����ӿڣ��������û���õ�������
class A {
private:
    A(){
        a = new A;
    }

public:
    static A* getInstace() {
        return a;
    }
private:
    static A* a;
};
A* A::a = NULL;


//������Ϊ����ʽ������ʽ

//����ʽ��ֻ���ڵ���getInstance��ʱ��Ż�newһ���������
class Singleton_lazzy
{
private:
	Singleton_lazzy(){}
public:
    static Singleton_lazzy* getInstance() {
        if (pSigleton == NULL) {
            pSigleton = new Singleton_lazzy;
        }
        return pSigleton;
    }

private:
    static Singleton_lazzy* pSigleton;

};
//�����ʼ��
Singleton_lazzy* Singleton_lazzy::pSigleton = NULL;

//����ʽ����main������ʼִ��ǰ���Ѿ��������
class Singleton_hungry
{
private:
    Singleton_hungry() { cout << "���Ƕ�������" << endl; }
public:
    static Singleton_hungry* getInstance() {
        return pSigleton;
    }

private:
    static Singleton_hungry* pSigleton;

};
//�����ʼ��
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;


int main(){
    cout << "main������ʼִ��" << endl;
    //A::getInstace();
    return 0;
}