#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class Animal {
public:
    void Jiao() {
        cout << mAge << "�궯���ڽУ�" << endl;
    }
    T mAge;
};

//CatҲ��ģ�壬��ʵ��������
template<class T>
class Cat : public Animal<T> {

};

int main()
{


    printf("\n");
    system("pause");
    return 0;
}