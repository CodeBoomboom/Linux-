#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//��ʼ��
void test01() {
    string s1;  //�޲ι���
    string s2(10, 'a');
    string s3("xdx");
    string s4(s3);  //��������
}

//��ֵ����
void test02() {
    string s1;
    string s2("xdx");
    s1 = "xdx1";
    cout << s1 << endl;
    s1 = s2;
    cout << s1 << endl;
    s1 = 'x';
    cout << s1 << endl;

    //��Ա����
    s1.assign("jkl");
    cout << s1 << endl;
}


//��ֵ����
void test03() {
    string s1 = "xedx";

    //����[]������
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i]<<" ";
    }
    cout << endl;

    //at��Ա����
    for (int i = 0; i < s1.size(); i++) {
        cout << s1.at(i)<<" ";
    }
    cout << endl;

    //����[]��ʽ�������Խ�磬ֱ�ӹ���
                 //at��ʽ���׳��쳣��out of range
    try
    {
        //cout << s1[100]<<endl;
        cout << s1.at(100) << endl;
    }
    catch (...)
    {
        cout << "Խ��" << endl;
    	
    }
}

//ƴ�Ӳ���
void test04() {
    string s = "abcde";
    s += "ads";
    string s2 = "11";
    s += s2;
    cout << s << endl;

    string s3 = "22222";
    s.append(s3);
    cout << s << endl;

    string s4 = s2 + s3;
    cout << s4 << endl;
}


//����
void test05() {
    string s = "abcdefghjfgkl";
    //��һ��
    int pos = s.find('fg');
    cout <<"pos:"<< pos << endl;

    //���һ��
    pos = s.rfind('fg');
    cout << "pos:" << pos << endl;
}

//�滻
void test06() {
    string s = "abcdefghjfgkl";
    s.replace(0, 2, "111");
    cout << s << endl;
}

//�Ƚ�
void test07() {
    string s1 = "abcd";
    string s2 = "abce"; 

    if (s1.compare(s2) == 0) {
        cout << "�����ַ������" << endl;
    }
    else
    {
        cout << "�����ַ��������" << endl;
    }

}

//��ȡ�Ӵ�
void test08() {
    string s = "abcdefg";
    string mysubstr = s.substr(1, 3);
    cout << mysubstr << endl;
}

//����
void test09() {
    string s = "abcdefghjfgkl";
    s.insert(1, "11");//��1λ�ã�1λ�ú���壩����11
    cout << s << endl;
    s.erase(1, 2);  // ��1λ�ÿ�ʼɾ��2��
    cout << s << endl;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    test09();
    
    system("pause");
    return 0;
}