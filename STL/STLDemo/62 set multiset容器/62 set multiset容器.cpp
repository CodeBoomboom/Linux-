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


//�º����������˺������÷��ŵ���
class mycompare {
public:
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};


//��ʼ��
void test01() {
    set<int> s1;    //�Զ�����Ĭ�ϴ�С�������ʵ�ִӴ�С���º������������s3
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

    mycompare com;
    com(10, 20);

    set<int, mycompare> s3;    //���÷º������򣺴Ӵ�С
    s3.insert(7);
    s3.insert(2);
    s3.insert(4);
    s3.insert(5);
    s3.insert(1);
    for (set<int>::iterator it = s3.begin(); it != s3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
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

class Person
{
public:
    Person(int id, int age):id(id), age(age){}
public:
    int id;
    int age;

private:

};

class mycompare2 {
public:
    bool operator()(const Person& p1, const Person& p2)const{
        return p1.age > p2.age;
    }
};

void test03() {
    //set<Person> sp; //set��Ҫ���򣬵���Ŷ���set��֪����ô����������Ҫָ��
    set<Person,mycompare2> sp;
    Person p1(10, 20), p2(20, 30), p3(30, 40);

    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);

    Person p4(10, 30);

    for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end(); it++) {
        cout << (*it).age << " " << (*it).id << endl;
    }

    //����
    set<Person, mycompare2>::iterator ret = sp.find(p4);    //ֻ�����Person��age���Խ��в��ң����ܵ�����û��
    if (ret == sp.end()) {
        cout << "û�ҵ�" << endl;
    }
    else {
        cout << "�ҵ�" << (*ret).id << " " << (*ret).age << endl;
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