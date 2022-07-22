#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�������� ��������
class WeapomStrategy {
public:
    virtual void UseWeapon() = 0;
};

class Knife :public WeapomStrategy {
public:
    virtual void UseWeapon() {
        cout << "ʹ��ذ��" << endl;
    }
};
class AK47 :public WeapomStrategy {
public:
    virtual void UseWeapon() {
        cout << "ʹ��AK47" << endl;
    }
};

class Character {
public:
    void setWeapon(WeapomStrategy* weapon) {
        this->pWeapon = weapon;
    }
    void ThrowWeapon() {
       this->pWeapon->UseWeapon();
    }
public:
    WeapomStrategy* pWeapon;
};

void test01() {
    //������ɫ
    Character* character = new Character;

    //��������
    WeapomStrategy* knife = new Knife;
    WeapomStrategy* ak47 = new AK47;

    character->setWeapon(knife);
    character->ThrowWeapon();
    character->setWeapon(ak47);
    character->ThrowWeapon();


}

int main(){
    test01();

    return 0;
}