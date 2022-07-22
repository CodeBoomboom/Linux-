#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��������ģʽ

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
    virtual AbstractFruit* CreateFruit() = 0;
};

//ƻ������
class AppleFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Apple;
    }
};

//�㽶����
class BananaFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Banana;
    }
};

//Ѽ�湤��
class PearFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Pear;
    }
};

void test01() {
    FriutFactorty* factorty = new AppleFactory;
    AbstractFruit* fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;

    factorty = new BananaFactory;
    fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;

    factorty = new PearFactory;
    fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;
}

int main()
{
    test01();

    return 0;
}