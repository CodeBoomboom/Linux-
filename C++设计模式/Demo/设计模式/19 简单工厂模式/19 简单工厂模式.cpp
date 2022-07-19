#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//�򵥹���ģʽ

class AbstractFruit {

public:
    virtual void ShowName() = 0;
};

//ƻ��
class  Apple :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "����ƻ��" << endl;
    }
protected:
private:
};

//�㽶
class  Banana :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "�����㽶" << endl;
    }
protected:
private:
};

//Ѽ��
class  Pear :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "����Ѽ��" << endl;
    }
protected:
private:
};


//ˮ������
class FriutFactorty {
public:
    static AbstractFruit* CreateFruit(string flag) {
        if (flag == "Apple") {
            return new Apple;
        }
        else if (flag == "Banana") {
            return new Banana;
        }
        else if (flag == "Pear") {
            return new Pear;
        }
        else {
            return NULL;
        }
    }
};

void test01() {
    FriutFactorty* factorty = new FriutFactorty;
    AbstractFruit* fruit = factorty->CreateFruit("Apple");
    fruit->ShowName();
    delete fruit;

    fruit = factorty->CreateFruit("Banana");
    fruit->ShowName();
    delete fruit;

    fruit = factorty->CreateFruit("Pear");
    fruit->ShowName();
    delete fruit;

    delete factorty;
}

int main()
{
    test01();

    return 0;
}