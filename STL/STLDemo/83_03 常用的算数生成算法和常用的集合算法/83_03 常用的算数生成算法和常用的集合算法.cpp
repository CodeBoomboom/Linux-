#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

struct MyPrint01 {
    void operator()(int  val) {
        cout << val << " ";
    }
};

//accumulate(iterator beg , iterator end) ��������Ԫ���ۼ��ܺ�
//fill(iterator beg, iterator end)  �����������Ԫ�� ���Ԫ��
void test01() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(9);

    int ret = accumulate(v1.begin(), v1.end(), 10);//���һ��������+10����˼

    cout <<"ret: " << ret << endl;//15+10 = 25

    vector<int> v2;
    v2.resize(10);
    fill(v2.begin(), v2.end(), 10);
    for_each(v2.begin(), v2.end(), MyPrint01());
    cout << endl;
}

// set_intersection(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest) ���������Ľ���
//set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin()) ��������������
// set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin()) �����������
void test02() {
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    for (int i = 5; i < 15; i++) {
        v2.push_back(i);
    }
    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());//����ָ�򽻼����һ��Ԫ�ص���һ��λ�õĵ�����
    for_each(v3.begin(), it, MyPrint01());
    cout << endl;
    cout << "it:" << *it << endl;

    //����
    vector<int> v4;
    v4.resize(v1.size()+v2.size());
    it = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    for_each(v4.begin(), it, MyPrint01());
    cout << endl;
    cout << "it:" << *it << endl;


    //�
    vector<int> v5;
    v5.resize(v1.size() + v2.size());
    it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    for_each(v5.begin(), it, MyPrint01());
    cout << endl;
    cout << "it:" << *it << endl;

}


int main(){
    //test01();
    test02();
    return 0;
}