#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//�����ط�������֪ʶԭ�򣬵���ϣ����ھ�
class AbstractBuliding {
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;

};

//¥��A
class BulidingA : public AbstractBuliding {
public:
    BulidingA() {
        mQulity = "��Ʒ��";
    }
    virtual void sale() {
        cout << "¥��A" << mQulity << "������" << endl;
    }
    virtual string getQuality() {
        return mQulity;
    }
public:
    string mQulity;
};

//¥��B
class BulidingB : public AbstractBuliding {
public:
    BulidingB() {
        mQulity = "��Ʒ��";
    }
    virtual void sale() {
        cout << "¥��B" << mQulity << "������" << endl;
    }
    virtual string getQuality() {
        return mQulity;
    }
public:
    string mQulity;
};

//�ͻ���
void test01() {
    BulidingA* ba = new BulidingA;
    if (ba->mQulity == "��Ʒ��") {
        ba->sale();
    }

    BulidingB* bb = new BulidingB;
    if (bb->mQulity == "��Ʒ��") {
        bb->sale();
    }

}

//�н���
class Mediator {
public:
    Mediator() {
        AbstractBuliding* buliding = new BulidingA;

        vBuliding.push_back(buliding);
        buliding = new BulidingB;
        vBuliding.push_back(buliding);
    }
      //�����ṩ�ӿ�
    AbstractBuliding* findMyBuliding(string quality) {
        for (vector<AbstractBuliding*>::iterator it = vBuliding.begin(); it != vBuliding.end(); it++) {
            if ((*it)->getQuality() == quality) {
                return *it;
            }
        }
        return NULL;
    }

    ~Mediator() {
        for (vector<AbstractBuliding*>::iterator it = vBuliding.begin(); it != vBuliding.end(); it++) {
            if (*it != NULL) {
                delete* it;
            }
        }
    }
public:
    vector<AbstractBuliding* > vBuliding;
};


void test02() {
    Mediator* mediator = new Mediator;
    AbstractBuliding* building = mediator->findMyBuliding("��Ʒ��");
    if (building != NULL) {
        building->sale();
    }
    else {
        cout << "û�з���������¥��" << endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}