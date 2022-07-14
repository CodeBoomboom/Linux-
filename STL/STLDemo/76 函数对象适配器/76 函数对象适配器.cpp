#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

struct MyPrint {
    void operator()(int val)const {
        cout << val + 100<< " "<<endl; //���ϣ����ֵ + 100�����
    }
};

//�����Ҫһ������ֵ�������������±ߵ�д����Ҫһ�Ѻ�������д�����ͺ��鷳��
//struct MyPrint02 {
//    void operator()(int val)const {
//        cout << val + 200 << " "; //���ϣ����ֵ + 200�����
//    }
//};

//���ǽ�����ֵ��Ϊ�������룬Ȼ��for_each��Ҫ����һԪ�������󣬴�ʱ����Ҫ��������
//��Ҫ�̳и���: public binary_function<int, int, void>  �������ͣ�����ֵ
struct MyPrint03 : public binary_function<int, int, void>{ 
    void operator()(int val, int plus)const {
        cout<<"val��"<<val<<"plus��"<< plus <<endl;
        cout << val + plus << " "; //���ϣ����ֵ + plus�����
    }
};

//�������������� bind1st bin2nd ��������
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint());
    int addNum = 200;
    for_each(v.begin(), v.end(), bind2nd(MyPrint03(),addNum));

    //������������һ����Ԫ��������ת���һԪ��������

    //bind1st��bind2nd����
    //bind1st���������Ĳ�����Ϊ��������ĵ�һ��������bind2nd��Ϊ�ڶ�������
    //�������ǽ���Ԫ���������ΪһԪ��������
}


//��Ҫ�̳и���: public binary_function<int, int, void>  �������ͣ�����ֵ
struct MyCompare : public  binary_function<int, int ,bool>{
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};
struct MyPrint04 {
    void operator()(int val)const {
        cout << val<< " " ; //���ϣ����ֵ + 100�����
    }
};

struct MyGreater5 : public unary_function<int, bool>{
    bool operator()(int v) const {
        return v > 5;
    }
};

//�������������� not1 not2 ȡ��������
void test02() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        //v.push_back(rand()%100 );//rand % (b - a + 1) + a  : a~bһ���������
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint04()); cout << endl;
    sort(v.begin(), v.end(), not2(MyCompare()));//ȡ�� �Ӵ�С��Ϊ��С����
    for_each(v.begin(), v.end(), MyPrint04()); cout << endl;

    //not1��not2������
    //����Զ�Ԫν��ȡ����not2
    //�����һԪν��ȡ����not1

    //һԪ
    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreater5()));
    if (it == v.end()) {
        cout << "û���ҵ�" << endl;
    }
    else {
        cout << "�ҵ��ˣ�" << *it << endl;
    }
}

void Myprint05(int val1, int val2) {
    cout << "val1��" << val1 << " " << "val2��" << val2 << endl;
    cout << val1 + val2 << endl;
}

//�º����������� ptr_fun
void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        //v.push_back(rand()%100 );//rand % (b - a + 1) + a  : a~bһ���������
        v.push_back(i);
    }

    //��ͨ�����޷�ͨ��bind1st�����������а󶨵Ȳ���
    //��ʱ�����Ҫ����ͨ��������ɣ�ת�ɣ���������
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint05),10)); 

}

class Person
{
public:
    Person(int age, int id) :age(age), id(id){}
    ~Person(){}
    void show() {
        cout << "age��" << age << "id��" << id << endl;
    }
public:
    int age;
    int id;
};


//��Ա������������mem_fun  men_fun_ref
void test04() {
    //��������д�ŵ��Ƕ�������ָ�룬����for_each�㷨��ӡ��ʱ��������Լ��ṩ�Ĵ�ӡ����
    vector<Person> v;
    Person p1(10, 20), p2(30, 40), p3(50, 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //��ʽ &����::������
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::show)); 

    vector<Person*> v1;
    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    for_each(v1.begin(), v1.end(), mem_fun(&Person::show));

    //������mem_fun_ref ����ָ����mem_fun
}


int main(){
    //test01();
    //test02();
    //test03();
    test04();
    system("pause");
    return 0;
}