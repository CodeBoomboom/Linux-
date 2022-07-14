#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//find(iterator beg, iterator end, value)  Ѱ��������valueֵ��Ԫ�أ������������
//������������
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
    if (ret != v1.end()) {
        cout << "�ҵ��ˣ�" << *ret<<endl;
    }
    else {
        cout << "û�ҵ�" << endl;
    }
}
//����  ��Ҫ�ڶ�����������һ��bool����==
class Person {
public:
    Person(int age, int id) :age(age), id(id) {}
    bool operator==(const Person& p) const {
        return p.id == this->id && p.age == this->age;
    }
    ~Person() {}
    void show() {
        cout << "age��" << age << "id��" << id << endl;
    }
public:
    int age;
    int id;
};
void test02() {
    vector<Person> v1;
    Person p1(10, 20), p2(20, 30);
    v1.push_back(p1);
    v1.push_back(p2);

    vector<Person>::iterator  ret = find(v1.begin(), v1.end(), p1);
    if (ret != v1.end()) {
        cout << "�ҵ���"<< endl;
    }
    else {
        cout << "û�ҵ�" << endl;
    }
}

//binary_search(iterator beg, iterator end, value);  ���ֲ��ң������������в����ã����ҳɹ�����true ʧ��false
void test03() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    bool ret = binary_search(v1.begin(), v1.end(), 5);
    if (ret) {
        cout << "�ҵ���" << endl;
    }
    else {
        cout << "û�ҵ�" << endl;
    }
}

//adjacent_find(iterator beg, iterator end, _callback);  ���������ظ�Ԫ�� ��������Ԫ�صĵ�һ��λ�õĵ�����
void test04() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    v1.push_back(9);

    vector<int>::iterator ret = adjacent_find(v1.begin(), v1.end());
    if (ret != v1.end()) {
        cout << "�ҵ��������ظ�Ԫ�أ�" << *ret << endl;
    }
    else {
        cout << "û�ҵ������ظ�Ԫ��" << endl;
    }
}

//find_if(iterator beg, iterator end, _callback);    find_if��������ǵ������������������ص�һ������������Ԫ�صĵ����� _callback�ص�������ν�� 
bool MySearch(int val){
    return val > 5;
}
void test05() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int>::iterator ret = find_if(v1.begin(), v1.end(), MySearch);
    if (ret != v1.end()) {
        cout << "�ҵ��ˣ�" <<*ret << endl;
    }
    else {
        cout << "û�ҵ�" << endl;
    }
}

//count ͳ��Ԫ�س��ִ��� count_if   count_if��������ǵ�����������������������������Ԫ�صĸ���
bool MySearch2(int val) {
    return val > 5;
}
void test06() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    v1.push_back(9);

    int num = count(v1.begin(), v1.end(), 9);
    cout << "9���ֵĴ�����" << num << endl;

    int num1 = count_if(v1.begin(), v1.end(), MySearch2);
    cout << "����5�ĸ�����" << num1 << endl;

}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    system("pause");
    return 0;
}