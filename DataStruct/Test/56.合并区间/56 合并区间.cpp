#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//����1��2�ص�������1��end > ����2��start �������㲻�㣿��
//�Ȱ�end�����С����
static bool mycmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0) return result;
    sort(intervals.begin(), intervals.end(), mycmp);

    //�����ص�������1����һ���䣩��begin������2����ǰ���䣩��end��ϳ����������result���������һ������
    //��û���ص���ֱ�ӽ���һ�������result
    //����һ��flag���ж����һ��������û�кϲ�
    bool flag = false;
    for (int i = 1; i < intervals.size(); i++) {
        int start = 0, end = 0;
        if (intervals[i][0] < intervals[i - 1][1]) {
            //�ص�������1��end > ����2��start
            //������1��begin������2��end��ϳ����������result
            if (i == intervals.size() - 1) {
                flag = true;    //˵�����һ�����䱻�ϲ���
            }
            start = intervals[i - 1][0];
            end = intervals[i][1];
            i++;//�����һλ����Ϊ��ǰ�����Ѿ�����һ������ɺϲ���
        }
        else {
            //���ص���ֱ�ӽ�����1����result
            start = intervals[i - 1][0];
            end = intervals[i - 1][1];
        }
        result.push_back({ start, end });//����
    }
    if (flag = false) {//���һ������δ���ϲ�
        result.push_back({ intervals[intervals.size()][0], intervals[intervals.size()][1] });
    }
    return result;
}


int main(){
    int i = 0;
    for (i = 0; i < 5; i++) {

    }
    cout << i << endl;
    return 0;
}