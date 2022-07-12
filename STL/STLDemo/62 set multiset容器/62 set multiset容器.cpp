#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;

void PrintSet(set<int>& s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//��ʼ��
void test01() {
    set<int> s1;    //�Զ�����Ĭ�ϴ�С����
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);
    PrintSet(s1);
    
    //��ֵ����
    set<int> s2;
    s2 = s1;
    s2.swap(s1);

    if (!s1.empty()) cout << "size:"<< s1.size() << endl;

    //ɾ��
    s1.erase(s1.begin());
    s1.erase(7);
    PrintSet(s1);

}

//set ���� 
void test02() {
    //ʵ�ʵ�ֵ(set��ֵһ��)
    set<int> s1; 
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);

    set<int>::iterator ret = s1.find(4);//�ҵ����ص����������򷵻�end������
    if (ret == s1.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ��ˣ�" << *ret << endl;
    }
    
    ret = s1.lower_bound(2);//���ص�һ�����ڵ���2��Ԫ�صĵ�����
    if (ret == s1.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ��ˣ�" << *ret << endl;
    }

    ret = s1.upper_bound(2);//���ص�һ������2��Ԫ�صĵ�����
    if (ret == s1.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ��ˣ�" << *ret << endl;
    }

    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(2);//����lower_bound(2)��upper_bound(2)��ֵ
    if (p.first == s1.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ���p.first��" << *p.first << endl;
    }

    if (p.second == s1.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ���p.second��" << *p.second << endl;
    }
}


int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}