#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
    MyArray(int capacity) {
        this->mCapacity = capacity;
        this->mSize = 0;
        //�����ڴ�
        this->pAddr = new T[this->mCapacity];
    }
    MyArray(const MyArray& arr) {
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //�����ڴ�ռ�
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = arr.pAddr[i];
        }
    }
    T& operator[](int index) {
        return this->pAddr[index];
    }
    const T& operator[](int index) const {
        return this->pAddr[index];
    }
    MyArray<T> operator=(const MyArray<T>& arr) {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //�����ڴ�ռ�
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }
    void PushBack(T& data) {
        //�ж��������Ƿ���λ��
        if (this->mSize >= this->mCapacity) {
            return;
        }

        //���ÿ������� =������
        //1.����Ԫ�ر����ܹ�������
        //2.��������ֵԢ�⣬��������Ԣ�⣬�������з���Ԫ�ض��Ƿ���Ԫ�صĿ���
        //3.���Ԫ�صĳ�Ա��ָ�룬ע�������ǳ��������
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
#if 1
    void PushBack(T&& data) {
        //�ж��������Ƿ���λ��
        if (this->mSize >= this->mCapacity) {
            return;
        }

        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
#endif
    ~MyArray() {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
    }
public:
    //һ���������¶��ٸ�Ԫ��
    int mCapacity;
    //��ǰ�����ж���Ԫ��
    int mSize;
    //�������ݵ��׵�ַ
    T* pAddr;
};


void test01() {
    MyArray<int> marray(20);
    int a = 10, b = 20, c = 30, d = 40;
    marray.PushBack(a);
    marray.PushBack(b);
    marray.PushBack(c);
    marray.PushBack(d);
    
    //���ܶ���ֵȡ���ã�����취��#if ���ݴ򿪣���ֵ����
    //marray.PushBack(100);
    marray.PushBack(100);

    for (int i = 0; i < marray.mSize; i++) {
        cout << marray[i] << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}