#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

void PirntMap(map<int, int>& m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        //*itȡ������һ��pair
        cout << "key:" << it->first << "value:" << (*it).second << endl;
    }
}

//map������ʼ��
void test01() {
    map<int, int> mymap;//map����ģ���������һ������key�����ͣ��ڶ�������value������

    //��������  pair.first keyֵ��pair.second valueֵ
    //��һ��
    pair<map<int, int>::iterator ,bool> ret = mymap.insert(pair<int, int>(10, 10));//insert����һ��pair��first�ǵ�������second��bool���ͣ��Ƿ�ɹ���
    if (ret.second) {
        cout << "��һ�β���ɹ�" << endl;
    }
    else {
        cout << "��һ�β���ʧ��" << endl;
    }
    ret = mymap.insert(pair<int, int>(10, 20));//keyһ��value�ı�
    if (ret.second) {
        cout << "�ڶ��β���ɹ�" << endl;
    }
    else {
        cout << "�ڶ��β���ʧ��" << endl;
    }
    //�ڶ���
    mymap.insert(make_pair(20, 20));
    //������
    mymap.insert(map<int, int>::value_type(30, 30));
    //������
    mymap[40] = 40;
    mymap[10] = 20;//���key�������򴴽�pair���룬���key���ڣ����޸Ķ�Ӧ��valueֵ
    mymap[50] = 50;

    //��ӡ��ͨ��������
    //for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
    //    //*itȡ������һ��pair
    //    cout << "key:" << it->first << "value:" << (*it).second << endl;
    //}
    PirntMap(mymap);
    //���ͨ��[]�ķ�ʽȥ����map�в����ڵ�key��map�Ὣ������ʵ�key���뵽map�в���valueһ��Ĭ��ֵ0
    cout << mymap[60] << endl;
    PirntMap(mymap);

}

int main()
{
    test01();
    system("pause");
    return 0;
}