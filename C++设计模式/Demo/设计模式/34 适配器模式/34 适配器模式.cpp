#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//������ģʽ���ǽ��Ѿ�д�õĽӿڣ���������ӿڲ���������
//��д�õĽӿ�ת����Ŀ��ӿ�

//�⺯�����Ѿ�д�ã������������ģ�����for_each��Ҫ����һ�������ģ���Ҫת�������һ��������
struct MyPrint{
    void operator()(int v1, int v2) {
        cout << v1 + v2 << endl;
    }
};

//����Ŀ��ӿڣ���Ҫ�����ʲô����
class Targrt {
public:
    virtual void operator()(int val) = 0;
};

//������
class Adapter :public Targrt {
public:
    Adapter(int param) {
        this->param = param;
    }
    virtual void operator()(int val) {
        print(val , param);
    }
public:
    MyPrint print;
    int param;
};

//MyBind2nd
Adapter MyBind2nd(int v) {
    return Adapter(v);
}

int main(){

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyBind2nd(10));

    return 0;
}