#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//transform  ��һ�������е�Ԫ�ذ��˵���һ��������
struct MyPlus {
    int operator()(int val) {
        return val+100;
    }
};
struct MyPrint{
    void operator()(int val) {
        cout << val << " ";
    }
    
};
void test01() {
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    v2.resize(v1.size());//���ٿռ�
    transform(v1.begin(), v1.end(), v2.begin(), MyPlus());//��v1�е�Ԫ���������MyPlus�º����У��º������ص�ֵ����ŵ�v2��
    for_each(v2.begin(), v2.end(), MyPrint());

}

int main(){
    test01();

    return 0;
}