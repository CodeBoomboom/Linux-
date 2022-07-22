#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�ṩһ�ִ���ʽ�����ƶ���������ķ���

class AbstractCommonInterface {
public:
    virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface {
public:
    virtual void run() {
        cout << "ϵͳ����" << endl;
    }
};
//����Ҫ��Ȩ����֤�����������˶����������ҵ�ϵͳ���ṩ�û���������
class MySystemProcy : public AbstractCommonInterface {
public:
    MySystemProcy(string username, string password): mUserName(username), mPassword(password) {
        pSystem = new MySystem;
    }

    bool checkUsernameAndPahhword(){
        if(mUserName == "admin" && mPassword == "admin")
        {
            return true;
        }
        else {
            return false;
        }
    }
    virtual void run() {
        if (checkUsernameAndPahhword()) {
            cout << "�û�����������ȷ����֤ͨ��" << endl;
            this->pSystem->run();
        }
        else {
            cout << "�û������������Ȩ�޲���" << endl;
        }
    }
    ~MySystemProcy()
    {
        if (pSystem != NULL)
        {
            delete pSystem;
        }
    }
public:
    MySystem* pSystem;
    string mUserName;
    string mPassword;
};

void test01() {
    MySystemProcy* proxy = new MySystemProcy("root", "admin");
    proxy->run();
    
    delete proxy;
    proxy = new MySystemProcy("admin", "admin");
    proxy->run();
}

int main(){
    //MySystem* system = new MySystem;
    //system->run();
    test01();
    return 0;
}