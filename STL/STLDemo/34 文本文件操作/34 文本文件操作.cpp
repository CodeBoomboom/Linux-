#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

void test01() {
    const char* sourcename = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 �ı��ļ�����\\source.txt";
    const char* targetname = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 �ı��ļ�����\\target.txt";
    ifstream ism(sourcename, ios::in);    //ֻ����ʽ���ļ�  �вι���
    ofstream osm(targetname, ios::out);
    //ofstream osm(targetname, ios::out | ios::app);
    //ifstream isml;
    //isml.open(filename, ios::in);
    if (!ism) {
        cout << "���ļ�ʧ��" << endl;
        return;
    }

    //���ļ�
    char ch;
    while (ism.get(ch)) {
        cout << ch;
        osm.put(ch);
    }

    //�ر��ļ�
    ism.close();
    osm.close();

}

//�������ļ�����  �������л�
class Person {
public:
    Person(){}
    Person(int age, int id): age(age), id(id){}
    void Show() {
        cout << "age:" << age << "id:" << id << endl;
    }
public:
    int age; 
    int id;
};

void test02() {
    //�ı�ģʽ�������ı��ļ���
    //������ģʽ�����Ƕ������ļ���
    //�����ǣ����Ƕ����ƣ�ֻ�ǻ��з���һ����windows��\r\n��linux��\n

    Person p1(10, 20);  //������
    Person p2(30, 40);

    //��p1 p2 �ŵ��ļ�
    const char* targetname = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 �ı��ļ�����\\class.txt";
    ofstream osm(targetname, ios::out | ios::binary);//�����Ƶķ�ʽ
    osm.write((char *)&p1, sizeof(Person));//�����Ʒ�ʽд�ļ�
    osm.write((char*)&p2, sizeof(Person));

    osm.close();

    ifstream ism(targetname, ios::in | ios::binary);
    Person p3, p4;
    ism.read((char*)&p3, sizeof(Person));//���ļ���ȡ����
    ism.read((char*)&p4, sizeof(Person));
    p3.Show();
    p4.Show();

}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}