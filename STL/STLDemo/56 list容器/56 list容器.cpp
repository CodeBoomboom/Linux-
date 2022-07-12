#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

void PrintList(list<int>& mlist) {

    for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01() {
    //��ʼ��
    list<int> mlist1;
    list<int> mlist2(10, 10);//�вι���
    list<int> mlist3(mlist2);
    list<int> mlist4(mlist2.begin(), mlist2.end());
    PrintList(mlist4);
    
}

//����ɾ��
void test02() {
    list<int> mlist;

    mlist.push_back(100);
    mlist.push_front(200);
    mlist.insert(mlist.begin(), 300);
    mlist.insert(mlist.end(), 400);
    
    list<int>::iterator it = mlist.begin();
    it++;
    it++;
    mlist.insert(it, 500);

    //mlist.pop_back();
    //mlist.pop_front();
    //mlist.erase(mlist.begin(), mlist.end());

    mlist.remove(200);//ɾ��ƥ������ֵ
    PrintList(mlist);
}


//list���� ��ֵ
void test03() {
    list<int> mlist;
    mlist.assign(10, 10);

    list<int> mlist2;
    mlist2 = mlist;

    mlist2.swap(mlist);

}

// ��ת
void test04() {
    list<int> mlist;
    for (int i = 0; i < 10; i++) {
        mlist.push_back(i);
    }
    PrintList(mlist);
    mlist.reverse();
    PrintList(mlist);
}

bool mycompare(int v1, int v2) {
    return v1 > v2;
}

//���� 
void test05() {
    list<int> mlist;
    mlist.push_back(2);
    mlist.push_back(1);
    mlist.push_back(7);
    mlist.push_back(5);
    PrintList(mlist);
    mlist.sort();//Ĭ�ϴ�С����
    PrintList(mlist);

    mlist.sort(mycompare);
    PrintList(mlist);
}
int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    test05();
    system("pause");
    return 0;
}