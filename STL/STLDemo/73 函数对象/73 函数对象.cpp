#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct MyPrint {
    MyPrint() {
        num = 0;
    }
    void operator()(int val) {
        cout << val << endl;
        num++;
    }
public:
    int num;
};
void test01() {
    MyPrint print;
    print(10);

    //������������ͨ������������
    //������������ͨ�����������ղ���
    //�������󳬳��˺����ĸ������������Ա��溯�����õ�״̬
}

int num1 = 0;//�����ڿ����У�����ʹ��ȫ�ֱ���
void MyPrint02(int val) {
    cout << val << endl;
    num1++;
}

void test02() {

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //���㺯�����ô���
    MyPrint02(10);
    MyPrint02(20);
    cout << num1 << endl;

    MyPrint print;
    print(10);
    print(20);
    cout << print.num << endl;

    MyPrint print1;
    MyPrint print2 = for_each(v.begin(), v.end(), print1);//��print1����һ�ݸ�print2����print2��ɴ�ӡ����
    cout << "print���ô�����" << print1.num << endl;
    cout << "print���ô�����" << print2.num << endl;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}