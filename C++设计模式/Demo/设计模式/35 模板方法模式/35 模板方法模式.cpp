#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���ݹ���
class DrinkTemplate {
public:
    virtual void BoilWater() = 0;//��ˮ
    virtual void Brew() = 0;//����
    virtual void PourInCup() = 0;//���뱭��
    virtual void AddSomething() = 0;//�Ӹ�����

    //ģ�巽��
    void Make() {
        this->BoilWater();
        this->Brew();
        this->PourInCup();
        this-> AddSomething();
    }
};

class Coffee :public DrinkTemplate {
public:
    virtual void BoilWater() {
        cout << "�󴿾�ˮ..." << endl;
    }
    virtual void Brew() {
        cout << "���ݿ���" << endl;
    }
    virtual void PourInCup() {
        cout << "�����ȵ��뱭��" << endl;
    }
    virtual void AddSomething() {
        cout << "���ȼ����ǣ�ţ��" << endl;
    }
};

class Tea :public DrinkTemplate {
public:
    virtual void BoilWater() {
        cout << "��ɽȪˮ..." << endl;
    }
    virtual void Brew() {
        cout << "������������" << endl;
    }
    virtual void PourInCup() {
        cout << "���赹�뱭��" << endl;
    }
    virtual void AddSomething() {
        cout << "��Ҷ��������" << endl;
    }
};

void test01() {
    Tea* tea = new Tea;
    tea->Make();

    Coffee* coffee = new Coffee;
    coffee->Make();

}

int main(){
    test01();

    return 0;
}