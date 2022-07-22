#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class TV {
public:
    void On() {
        cout << "���Ӵ�" << endl;
    }
    void Off() {
        cout << "���ӹر�" << endl;
    }
};
class Light {
public:
    void On() {
        cout << "�ƴ�" << endl;
    }
    void Off() {
        cout << "�ƹر�" << endl;
    }
};
class Audio {
public:
    void On() {
        cout << "�����" << endl;
    }
    void Off() {
        cout << "����ر�" << endl;
    }
};
class MKC {
public:
    void On() {
        cout << "��˷��" << endl;
    }
    void Off() {
        cout << "��˷�ر�" << endl;
    }
};
class DVD {
public:
    void On() {
        cout << "DVD��" << endl;
    }
    void Off() {
        cout << "DVD�ر�" << endl;
    }
};
class Gamemachine {
public:
    void On() {
        cout << "��Ϸ����" << endl;
    }
    void Off() {
        cout << "��Ϸ���ر�" << endl;
    }
};


class KTVMode {
public:
    KTVMode() {
        pTV = new TV;
        pLight = new Light;
        pAudio = new Audio;
        pMKC = new MKC;
        pDVD = new DVD;
    }

    void runKTV() {
        pTV->On();
        pLight->Off();
        pMKC->On();
        pAudio->On();
        pDVD->On();
    }
    void offKTV() {
        pTV->Off();
        pLight->On();
        pMKC->Off();
        pAudio->Off();
        pDVD->Off();
    }

    ~KTVMode() {
       delete pTV ;
       delete pLight;
       delete pAudio;
       delete pMKC;
       delete pDVD;
    }

public:
    TV* pTV;
    Light* pLight;
    Audio* pAudio;
    MKC* pMKC;
    DVD* pDVD;
};


void test01() {
    KTVMode* ktv = new KTVMode;
    ktv->runKTV();
}

int main(){
    test01();
    
    return 0;
}