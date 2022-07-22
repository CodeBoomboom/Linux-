#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//һ������� ʹ�ü̳���ʵ����Ĺ�����չ
//װ��ģʽ  ���Զ�̬�ĸ�һ������ӹ���

//����Ӣ��
class AbstractHero {
public:
    virtual void ShowStatus() = 0;
public:
    int mHP;
    int mMP;
    int mAt;
    int mDf;
};

//����Ӣ��
class HeroA : public AbstractHero {
public:
    HeroA() {
        mHP = 0;
        mMP = 0;
        mAt = 0;
        mDf = 0;
    }
    virtual void ShowStatus() {
        cout << "Ѫ����" << mHP << endl;
        cout << "ħ����" << mMP << endl;
        cout << "������" << mAt << endl;
        cout << "������" << mDf << endl;
    }
};

//Ӣ�۴���ĳ��װ�����ô�����Ǹ�Ӣ��
class AbstractEquipment : public AbstractHero {
public:
    AbstractEquipment(AbstractHero* Hero){
        this->pHero = Hero;
    }
    virtual void ShowStatus(){}
public:
    AbstractHero* pHero;
};

//��ͽ
class KuangTu :public AbstractEquipment {
public:
    KuangTu(AbstractHero* Hero):AbstractEquipment(Hero){}
    //���Ӷ��⹦��
    void AddKuangtu() {
        cout << "Ӣ�۴��Ͽ�ͽ��" << endl;
        this->mHP = this->pHero->mHP;
        this->mMP = this->pHero->mMP;
        this->mAt = this->pHero->mAt;
        this->mDf = this->pHero->mDf + 30;
        delete this->pHero;
    }
    virtual void ShowStatus() {
        AddKuangtu();
        cout << "Ѫ����" << mHP << endl;
        cout << "ħ����" << mMP << endl;
        cout << "������" << mAt << endl;
        cout << "������" << mDf << endl;
    }
};

//�޾�
class WuJin :public AbstractEquipment {
public:
    WuJin(AbstractHero* Hero) :AbstractEquipment(Hero) {}
    //���Ӷ��⹦��
    void AddWuJin() {
        cout << "Ӣ�۴����޾���" << endl;
        this->mHP = this->pHero->mHP;
        this->mMP = this->pHero->mMP;
        this->mAt = this->pHero->mAt+80;
        this->mDf = this->pHero->mDf ;
        delete this->pHero;

    }
    virtual void ShowStatus() {
        AddWuJin();
        cout << "Ѫ����" << mHP << endl;
        cout << "ħ����" << mMP << endl;
        cout << "������" << mAt << endl;
        cout << "������" << mDf << endl;
    }
};


void test01() {
    AbstractHero* hero = new HeroA;
    hero->ShowStatus();

    cout << "------------------------------" << endl;
    //���㱼��Ӣ�۴����·�
    hero = new KuangTu(hero);
    hero->ShowStatus();
    cout << "------------------------------" << endl;
    hero = new WuJin(hero);
    hero->ShowStatus();

}

int main(){
    test01();

    return 0;
}