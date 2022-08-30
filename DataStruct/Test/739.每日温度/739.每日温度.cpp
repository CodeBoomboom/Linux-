#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//����
//����ѭ������¼�±�
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> answer(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
        for (int j = i + 1; j < temperatures.size(); j++) {
            if (temperatures[j] > temperatures[i]) {
                answer[i] = j - i;
                break;//ֻ��¼��һ�����ڵ�
            }
        }
    }
    return answer;

}

void PrintVector(vector<int>& nums) {
    for (vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
        cout << *i<<" ";
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 73,74,75,71,69,72,76,73};
    PrintVector(test);
    vector<int> answer = dailyTemperatures(test);
    PrintVector(answer);
}

int main(){
    test01();

    return 0;
}