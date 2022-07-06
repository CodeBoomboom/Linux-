#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T> class MyClass;
template<class T> void PrintAge(MyClass<T>& p);

template <class T>
class MyClass
{
public:
    MyClass(T age) {
        this->mAge = age;

    }
    ~MyClass() {

    }
    //template <class T>    //��������ôд����windows����������ͨ��������linux�²�����ͨ��
    //friend void PrintAge(MyClass<T>& p);
    friend void PrintAge<T>(MyClass<T>& p);     //�Ƽ���ôд���������������ڼ�<T>
    T mAge;

private:

};

template <class T>
void PrintAge(MyClass<T>& p) {
    cout << p.mAge << endl;
}

void test01() {
    MyClass<int> p(10);
    PrintAge(p);
}

int main()
{
    test01();

    system("pause");
    return 0;
}