#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
cout;    //ȫ�������� ������ݵ���ʾ��
cin;
//cerrû�л�������clog�л�����
cerr;//��׼���� ������ݵ���ʾ��
clog;//��׼��־ ������ݵ���ʾ��
#endif

//��׼������ cin.get()
void test01() {
    char ch;
    while ((ch = cin.get()) != EOF) {
        cout << ch << endl;
    }

    //cin.get()
    //char ch2;
    //cin.get(ch2);//��ȡһ���ַ�������ch2
    //char buf[256] = { 0 };
    //cin.get(buf, 256);//�ӻ�������һ���ַ��� ������buf
    //cin.getline(buf, 256);//��ȡһ������ �������з�
    //cout << buf << endl;
}


//cin.ignore() ���Ե�ǰ���ַ�
void test02() {
    char ch;
    cin.get(ch);//�ӻ�����Ҫ���� ����
    cout << ch << endl;
    cin.ignore();//���Ե���������һ���ַ����ӻ�����ȡ���ˣ��������Ѿ�û������ַ��ˣ�
    cin.ignore(10, '\n');//���Ի�����10���ַ��������\n�������\nǰ���ַ�
    cin.get(ch);
    cout << ch << endl;
}

//cin.peek()    ��cin.get��ͬ��cin.peekֻ�ǿ�һ�»��������ݣ���û��ȡ��
void test03() {
    cout << "���������ֻ����ַ���" << endl;
    char ch;
    ch = cin.peek();    //͵��һ�»����������ص�һ���ַ�
    if (ch >='0' && ch <= '9') {
        int num;
        cin >> num;
        cout << "�������������" << num << endl;
    }
    else {
        char buf[256] = { 0 };
        cin >> buf;
        cout << "����������ַ���" <<buf<< endl;
    }
}

//cin.putback  cin.get
void test04() {
    cout << "���������ֻ����ַ���" << endl;
    char ch;
    ch = cin.get(); 
    if (ch >= '0' && ch <= '9') {
        cin.putback(ch);//ch�Żص�������
        int num;
        cin >> num;
        cout << "�������������" << num << endl;
    }
    else {
        cin.putback(ch);//ch�Żص�������
        char buf[256] = { 0 };
        cin >> buf;
        cout << "����������ַ���" << buf << endl;
    }

}



int main()
{
    test01();
    //test02();
    //test03();
    //test04();

    return 0;
}