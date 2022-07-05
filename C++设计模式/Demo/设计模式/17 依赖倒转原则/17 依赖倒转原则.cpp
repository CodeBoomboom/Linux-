#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//������תԭ��

//���й�����Ա
class BankWorker {
public:
    void saveService() {
        cout << "������ҵ��" << endl;
    }
    void payService() {
        cout << "����֧��ҵ��" << endl;
    }
    void transferService() {
        cout << "����ת��ҵ��" << endl;
    }
};

//�в�ģ��
void doSaveBussiness(BankWorker* worker) {
    worker->saveService();
}
void doPayBussiness(BankWorker* worker) {
    worker->payService();
}
void doTransferBussiness(BankWorker* worker) {
    worker->transferService();
}

void test01() {
    BankWorker* worker = new BankWorker;
    doSaveBussiness(worker);    //  ������ҵ��
    doPayBussiness(worker);    //  ����֧��ҵ��
    doTransferBussiness(worker);    //  ����ת��ҵ��
}

//���й�����Ա
class AbstractWorker {
public:
    virtual void doBusiness() = 0;
};

//ר�Ÿ�����������Ա
class SaveBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "������ҵ��" << endl;
    }
};
//ר�Ÿ���֧��������Ա
class PayBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "����֧��ҵ��" << endl;
    }
};
//ר�Ÿ������ת�˵���Ա
class TransferBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "����ת��ҵ��" << endl;
    }
};

//�в�ҵ��ģ��
void doNewBusiness(AbstractWorker* worker) {
    worker->doBusiness();
    delete worker;
}

void test02() {
    AbstractWorker* transfer = new TransferBankWoker;
    transfer->doBusiness();
}

int main()
{
    test02();


    return 0;
}