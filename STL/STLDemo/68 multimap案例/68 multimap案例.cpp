#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<time.h>
#include<stdlib.h>
using namespace std;
//multimap����
//��˾������Ƹ�����Ա����5��Ա�����빫˾����Ҫָ��Ա�����ĸ����Ź���
//��Ա��Ϣ�У����� ���� �绰 ���ʵ����
//ͨ��multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ

#define SALE_DEPARTMENT             1       //���۲���
#define DEVELOP_DEPARTMENT      2       //�з�����
#define FINACIAL_DEPARTMENT      3      //������
#define ALL_DEPAERTMENT              4      //���в���   

class Worker {
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};
void Create_Worker(vector<Worker>& vWorker) {
    srand(time(NULL));
    string seedName = "ABCDE";
    for (int i = 0; i < 5; i++) {
        Worker worker;
        worker.mName = "Ա��";
        worker.mName += seedName[i];

        worker.mAge = rand() % 10 + 20;
        worker.mTele = "010-88888888";
        worker.mSalary = rand() % 10000 + 10000;

        vWorker.push_back(worker);
    }
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup) {
    //��Ա��������䵽��ͬ����
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
        int departID = rand() % 3 + 1;
        switch (departID)
        {
         case SALE_DEPARTMENT:
             workerGroup.insert(make_pair(SALE_DEPARTMENT, *it));
             break;
         case DEVELOP_DEPARTMENT:
             workerGroup.insert(make_pair(DEVELOP_DEPARTMENT, *it));
             break;
         case FINACIAL_DEPARTMENT:
             workerGroup.insert(make_pair(FINACIAL_DEPARTMENT, *it));
             break;
         default:
             break;
        }
    }
}

void ShowGroupWorkers(multimap<int, Worker>& workerGroup, int departid) {
    multimap<int, Worker>::iterator it = workerGroup.find(departid);//��һ�γ���λ��
    int DepartCount = workerGroup.count(departid);//��ǰ����������
    int num = 0;
    cout << "���ţ�" << departid << endl;
    for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++) {
        cout << "������" << pos->second.mName << " " << "����" << pos->second.mAge << " " << "�绰" << pos->second.mTele << " " << "����" << pos->second.mSalary << endl;
    }
}

void PrintWorkerByGroup(multimap<int, Worker>& workerGroup) {
     //��ӡ���۲�Ա��
    ShowGroupWorkers(workerGroup, SALE_DEPARTMENT);

     //��ӡ�з���Ա��
    ShowGroupWorkers(workerGroup, DEVELOP_DEPARTMENT);
     //��ӡ����Ա��
    ShowGroupWorkers(workerGroup, FINACIAL_DEPARTMENT);
}


void test01() {
    //�����Ա����Ϣ
    vector<Worker> vWorker;
    //multimap���������Ϣ
    multimap<int, Worker> workerGroup;

    //����Ա��
    Create_Worker(vWorker);
    //Ա������
    WorkerByGroup(vWorker, workerGroup);
    //��ӡÿһ���ŵ�Ա����Ϣ
    PrintWorkerByGroup(workerGroup);
}


class MyKey
{
public:
    MyKey(int index, int id) :mID(id), mIndex(index) {}


public:
    int mIndex;
    int mID;

};

struct mycompare {
    bool operator()(MyKey k1, MyKey k2) const{
        return k1.mIndex > k2.mIndex;
    }
};

void test02() {
    map<MyKey, int, mycompare> mymap;//�Զ������Զ����������ͣ�զ�ţ�

    mymap.insert(make_pair(MyKey(1, 2), 10));
    mymap.insert(make_pair(MyKey(4, 5), 20));

    for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        cout << it->first.mIndex << ":" << it->first.mID << " = " << it->second << endl;
    }
    

}

void test03() {
    map<int, int> mymap;
    mymap.insert(pair<int, int>(1, 4));
    mymap.insert(pair<int, int>(2, 5));
    mymap.insert(pair<int, int>(3, 6));

    pair<map<int, int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
    if (ret.first->second) {
        cout << "�ҵ���" << endl;
    }
    else {
        cout << "û�ҵ�" << endl;
    }
}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}