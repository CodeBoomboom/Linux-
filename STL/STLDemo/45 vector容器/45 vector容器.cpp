#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//��ʼ��
void test01() {
    vector<int> v1;//Ĭ���޲ι���

    
    int arr[] = { 2,3,4,1,9 };
    vector<int> v2(arr, arr + sizeof(arr)/sizeof(int));

    vector<int> v3(v2.begin(), v2.end());

    vector<int> v4(v3);

    printVector(v2);
    printVector(v3);
    printVector(v4);
}

//��ֵ����
void test02() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
    //��Ա����
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    //=
    vector<int> v3 = v2;

    int arr1[] = { 100,200,300,400,500 };
    vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
    v4.swap(v1);

    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
}

//��С����
void test03() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

    cout << "size:" << v1.size() << endl;
    if (v1.empty()) {
        cout << "v1 ��" << endl;
    }
    else {
        cout << "v1 ����" << endl;
    }

    printVector(v1);
    v1.resize(2);//���resize��ֵ��ԭ����С����Ѻ�����ӵ�
    printVector(v1);
    //v1.resize(6);//���resize��ֵ��ԭ���Ĵ󣬻�Ѻ������Ĭ��ֵ
    printVector(v1);
    v1.resize(6, 1);//ָ��Ĭ��ֵΪ1
    printVector(v1);

    for (int i = 0; i < 100;  i++) {
        v1.push_back(i);
    }
    cout << "size:" << v1.size() << endl;
    cout << "capacity:" << v1.capacity() << endl;
}

//vector��ȡ����
void test04() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    //����at���쳣  []�����쳣

    //���ݴ�ȡ����
    cout << "front:" << v1.front() << endl;
    cout << "back:" << v1.back() << endl;

}

//�����ɾ��
void test05() {
    //insert��λ�����õ�������ʶ��
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    printVector(v);

    //ͷ�巨
    v.insert(v.begin(), 30);
    printVector(v);
    //β�巨
    v.insert(v.end(), 40);
    printVector(v);
    //�м��
    v.insert(v.begin() + 2, 100);//vector֧���������  ����֧��[]��һ�㶼֧���������  ����������ֱ��+2 +3 -5
    printVector(v);

    //ɾ��
    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin() + 1, v.end());
    printVector(v);
    v.clear();

}

//����swap�����ռ�
void test06() {
    //vector���Ԫ�� ���Զ�����
    //ɾ��Ԫ�� �����Զ�����
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;
    v.resize(10);
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    //����swap�����ռ�
    vector<int>(v).swap(v);//vector<int>(v) ͨ��v����һ���������� Ȼ����v���н��� ����������������
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;
}

//reserve��resize����
void test07() {
    //reserve Ԥ���ռ� resize ����

    int num = 0;
    int* address = NULL;

    vector<int> v;
    v.reserve(10000);
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
        if (address != &v[0]) {
            address = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
    //�����֪�����ݴ��Ҫ�洢�ĸ�����������reserveԤ���ռ�

}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
    system("pause");
    return 0;
}