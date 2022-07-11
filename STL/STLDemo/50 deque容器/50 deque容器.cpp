#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;

void printDeque(deque<int>& d) {
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it ;
    }
    cout << endl;
}

//��ʼ��
void test01() {
    deque<int> d1;
    deque<int> d2(10, 5);//10��5
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);
    printDeque(d4);
}

//��ֵ����С����
void test02() {
    deque<int> d1;
    d1.assign(10, 5);//10��5
    deque<int> d2;
    d2.assign(d1.begin(), d1.end());//������ָ�����丳ֵ
    deque<int> d3;
    d3 = d2;//�ȺŸ�ֵ

    d1.swap(d2);
    if (d1.empty()) {
        cout << "d1 ��" << endl;
    }
    else {
        cout << "size:" << d1.size() << endl;
    }

    d1.resize(5);//��5���ӵ�
}

//deque�����Ĳ����ɾ��
void test03() {
    deque<int> d1;
    d1.push_back(100);
    d1.push_front(200);
    d1.push_back(300);
    d1.push_back(400);
    d1.push_front(500);
    //500 200 100 300 400 
    printDeque(d1);

    int val = d1.front();//�õ���ɾ��������
    d1.pop_front();
    printDeque(d1);

    val = d1.back();//�õ���ɾ��������
    d1.pop_back();
    printDeque(d1);


}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}