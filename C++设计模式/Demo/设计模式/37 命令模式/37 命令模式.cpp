#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//Э�鴦����
class HandleClientProtocol {
public:
    //�������ӽ��
    void AddMoney() {
        cout << "��������ӽ��" << endl;
    }
    //����������ʯ
    void AddDiamond() {
        cout << "�����������ʯ" << endl;
    }
    //�������װ��
    void AddEquipemnt() {
        cout << "����Ҵ�װ��" << endl;
    }
    //�����������
    void AddLevel() {
        cout << "���������" << endl;
    }
};

//����ӿ�
class AbstractCommand {
public:
    virtual void handle() = 0;//����ͻ�������Ľӿ�
};

//�������ӽ��
class AddMoneyCommand : public AbstractCommand {
public:
    AddMoneyCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddMoney();
    }
public:
    HandleClientProtocol* pProtocol;
};
//����������ʯ
class AddDiamondCommand : public AbstractCommand {
public:
    AddDiamondCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddDiamond();
    }
public:
    HandleClientProtocol* pProtocol;
};
//�������Ҵ�װ��
class AddEquipemntCommand : public AbstractCommand {
public:
    AddEquipemntCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddEquipemnt();
    }
public:
    HandleClientProtocol* pProtocol;
};
//������������
class AddLevelCommand : public AbstractCommand {
public:
    AddLevelCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddLevel();
    }
public:
    HandleClientProtocol* pProtocol;
};



//����������
class Server {
public:
    void addRequest(AbstractCommand* command) {
        mCommand.push(command);
    }
    void startHandle() {
        while (!mCommand.empty()) {
            Sleep(2000);
            AbstractCommand* command = mCommand.front();
            command->handle();
            mCommand.pop();
        }
    }
public:
    queue<AbstractCommand*> mCommand;
};


void test01() {
    HandleClientProtocol* protocol = new HandleClientProtocol;
    
    AbstractCommand* addmoney = new AddMoneyCommand(protocol);
    AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
    AbstractCommand* addequpment = new AddEquipemntCommand(protocol);
    AbstractCommand* addlevel = new AddLevelCommand(protocol);

    Server* sever = new Server;
    sever->addRequest(addmoney);
    sever->addRequest(adddiamond);
    sever->addRequest(addequpment);
    sever->addRequest(addlevel);
    sever->startHandle();

}

int main(){
    test01();

    return 0;
}