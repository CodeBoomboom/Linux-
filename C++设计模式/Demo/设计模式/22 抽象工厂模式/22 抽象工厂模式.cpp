#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����ƻ��
class AbstractApple
{
public:
    virtual void showName() = 0;
};
//�й�ƻ��
class ChinaApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "�й�ƻ��" << endl;
    }
};
//����ƻ��
class USAApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "����ƻ��" << endl;
    }
};
//����ƻ��
class JapanApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "����ƻ��" << endl;
    }
};


//�����㽶
class AbstractBanana
{
public:
    virtual void showName() = 0;
};
//�й��㽶
class ChinaBanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "�й��㽶" << endl;
    }
};
//�����㽶
class USABanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "�����㽶" << endl;
    }
};
//�����㽶
class JapanBanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "�����㽶" << endl;
    }
};


//����Ѽ��
class AbstractPear
{
public:
    virtual void showName() = 0;
};
//�й�Ѽ��
class ChinaPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "�й�Ѽ��" << endl;
    }
};
//����Ѽ��
class USAPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "����Ѽ��" << endl;
    }
};
//����Ѽ��
class JapanPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "����Ѽ��" << endl;
    }
};


//���󹤳�
class AbstractFactory {
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};
//�й�����
class ChinaFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new ChinaPear;
    }
};
//���۹���
class USAFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new USABanana;
    }
    virtual AbstractPear* CreatePear() {
        return new USAPear;
    }
};
//���ܹ���
class JapanFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new JapanPear;
    }
};


void test01() {
	//����һ���������������й����������۹��������ܹ�������ƻ�����㽶��Ѽ��
    AbstractFactory* factory = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    //�й�ƻ��
    factory = new ChinaFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //�й��㽶
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //�й�Ѽ��
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

    //����ƻ��
    factory = new USAFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //�����㽶
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //����Ѽ��
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

    //����ƻ��
    factory = new JapanFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //�����㽶
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //����Ѽ��
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

}

int main(){
    test01();

    return 0;
}