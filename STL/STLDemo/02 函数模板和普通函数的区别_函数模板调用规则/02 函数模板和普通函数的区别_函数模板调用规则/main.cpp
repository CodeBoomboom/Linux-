#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template <class T>
void MyAdd(T a, T b)
{
    return a + b;
}


int MyAdd(int a, char c)
{
    return a + c;
}

void test02() {
    int a = 10;
    int b = 20;
    char c1 = 'a';
    char c2 = 'b';
    MyAdd(a, b);//���ú���ģ��
    MyAdd(a, c1);//������ͨ����
    MyAdd(c1, b);//����ͨ��������Ϊ��ͨ���������Զ�����ת��
}

int main()
{
    test02();

    printf("\n");
    system("pause");
    return 0;
}