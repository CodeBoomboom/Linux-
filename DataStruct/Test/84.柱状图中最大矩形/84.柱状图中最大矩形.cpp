#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
#include<stdlib.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 1) {
        return heights[0];//��Ҫ����
    }
    int result = 0;
    stack<int> st;

    for (int i = 0; i < heights.size(); i++) {
        if (st.empty())  st.push(i);
        if (heights[i] > heights[st.top()])  st.push(i);
        else if (heights[i] == heights[st.top()]) st.push(i);
        else {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                int right = i;
                int w = right;//���st.pop()��Ϊ�յĻ�����Ⱦ���i
                if (!st.empty()) {
                    int left = st.top();
                    w = right - left - 1;//���st.pop()��Ϊ�յĻ�����Ⱦ���right -left -1
                }
                int h = heights[mid];
                result = max(result, h * w);
            }
            st.push(i);//һ����Ҫ������䣡����������
        }
    }

    //���������ջ�л���Ԫ��
    while (!st.empty()) {
        int mid = st.top();
        st.pop();
        int right = heights.size();
        int w = right;//���st.pop()��Ϊ�յĻ�����Ⱦ���height�ĳ���
        if (!st.empty()) {
            int left = st.top();
            w = right - left - 1;//���st.pop()��Ϊ�յĻ�����Ⱦ���right -left -1
        }
        int h = heights[mid];
        result = max(result, h * w);
    }
    return result;
}

void PrintVector(vector<int>& nums) {
    for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 1,1 };
    PrintVector(test);
    int res = largestRectangleArea(test);
    cout << res << endl;
}


int main(){
    //test01();
    //string s1;
    //while (cin >> s1) {
    //    cout << "OK" << endl;
    //    if (getchar() == '\n'){    //�������ǿո��˳�ѭ����
    //        break;
    //    cout << " ";
    //    }
    //}
    string s;
    while (cin >> s) { //������ȡ�ַ���
        int bit = 0; //��¼��ǰλ��
        int res = 0;
        for (int i = s.length() - 1; i > 1; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                res += (s[i] - '0') * pow(16, bit); //��ǰ���ֳ�16��λ���η�
                bit++;
            }
            else if (s[i] >= 'A' && s[i] <= 'F') {
                res += (s[i] - 'A' + 10) * pow(16, bit); //��ĸҪת��������
                bit++;
            }
        }
        cout << res << endl;
    }
    return 0;
}