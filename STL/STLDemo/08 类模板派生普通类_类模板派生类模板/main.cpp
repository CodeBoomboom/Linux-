#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class MyClass
{
public:
    MyClass()
    {
        mAge = 0;

    }
    ~MyClass() {
        default;
    }
    T mAge;
private:

};

//Ϊʲô<int>��
//��ȥ���������������ǲ�����Ҫ��������ڴ�
class MyClass01 :public MyClass<int> {

public:

private:

};


int main()
{


    printf("\n");
    system("pause");
    return 0;
}