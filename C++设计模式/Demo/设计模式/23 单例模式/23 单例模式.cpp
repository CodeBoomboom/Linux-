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
    Singleton_lazzy() { cout << "������������" << endl; }
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
#if 0   //����д���У��κ��˶��ܵ��������
    static void freeSpace() {
        if (pSigleton != NULL) {
            delete pSigleton;
        }
    }
#endif
    class Garbo {
        ~Garbo() {
            if (pSigleton != NULL) {
                delete pSigleton;
            }
        }
    };
private:
    static Singleton_hungry* pSigleton;
    static Garbo garbo;

};
//�����ʼ��
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;


void test01() {
    Singleton_lazzy* p1 = Singleton_lazzy::getInstance();
    Singleton_lazzy* p2 = Singleton_lazzy::getInstance();
    if (p1 == p2) {
        cout << "����ʽ����ָ��ָ��ͬһ���ڴ棬�ǵ���ģʽ" << endl;
    }
    else {
        cout << "���ǵ���ģʽ" << endl;
    }

    Singleton_hungry* p3 = Singleton_hungry::getInstance();
    Singleton_hungry* p4 = Singleton_hungry::getInstance();
    if (p3 == p4) {
        cout << "����ʽ����ָ��ָ��ͬһ���ڴ棬�ǵ���ģʽ" << endl;
    }
    else {
        cout << "���ǵ���ģʽ" << endl;
    }
}

//�ͷ�
void test02() {
    //Singleton_hungry::freeSpace();//����д���У��κ��˶��ܵ��������

    //ʵ���ϵ���ģʽֻ�ܴ����һ�����󣬲�������ڴ�����ķ���
    //�������������ʱ��ľ�̬������Զ��������������������������Բ��õ����ͷŵ�����

    //�����Ҫ�ͷţ�����д����������GarboǶ���࣬���ڵ�������
    //��������󣬻����Garbo�������������������Ѿ�̬�����ͷ�
}



int main(){
    cout << "main������ʼִ��" << endl;
    test01();
    //A::getInstace();
    return 0;
}