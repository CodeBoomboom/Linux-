#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Person
{
public:
    Person(const char* name, int age) {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
        this->mAge = age;
    }
    Person(const Person& p) {
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);
        this->mAge = p.mAge;
    }
    Person& operator=(const Person& p) {
        if (this->pName != NULL) {
            delete[] this->pName;
        }
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);
        this->mAge = p.mAge;
        return *this;
    }

    ~Person() {
        if (this->pName != NULL) {
            delete[] this->pName;
        }
    }

private:
    int mAge;
    char* pName;//ָ�� ���׳���ǳ��������
};


void test01() {
    Person p("aaa", 20);
    vector<Person> vPerson;
    //vPerson.push_back(p);       //����ǳ�������⣬test01()����ʱp����������p push��vector��ʱ��ͨ��ǳ�������еģ�����ָ���ָ��һ���ڴ�ռ䣩Ҳ��������������������ͻ���쳣��������Ҫ���ӿ�������
    vPerson.push_back(p);
}

int main()
{
    test01();
    system("pause");
    return 0;
}