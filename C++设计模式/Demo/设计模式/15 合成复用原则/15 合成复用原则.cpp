#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�ϳɸ���ԭ��

class AbstractCar {
public:
    virtual void run() = 0;
};

class DaZhong :public AbstractCar {
public:
    virtual void run() {
        cout << "��������" << endl;
    }
};

class Tuolaji :public AbstractCar {
public:
    virtual void run() {
        cout << "����������" << endl;
    }
};

#if 0
//��Ծ����࣬�����ü̳�
class Person :public Tuolaji {
public:
    void Doufeng() {
        run();
    }
};
#endif

//����ʹ�����
class Person {
public:
    void setCar(AbstractCar* car) {
        this->Car = car;
    }
    void Doufeng() {
        this->Car->run();
        if (this->Car != NULL) {
            delete this->Car;
            this->Car = NULL;
        }
    }
    ~Person() {
    }
public:
    AbstractCar* Car;
};
void test02() {
    Person* p = new Person;
    p->setCar(new DaZhong);
    p->Doufeng();

    p->setCar(new Tuolaji);
    p->Doufeng();
    delete p;
}

int main()
{
    test02();
    return 0;
}
