#include<iostream>
#include<vector>
using namespace std;
//ѡ������
//�ӵ�һ��Ԫ�ؿ�ʼ���Ƚϵ�ǰԪ����ʣ��Ԫ������С��ֵ�Ĵ�С�������ʣ��Ԫ����С��ֵ����ô��������Ԫ�ص�λ��
//����������ƣ�ֱ�����һ��Ԫ��
//ѡ��������һ�����ȶ������򣬱���˵����Ϊ{5,5,2,8}����ô��һ��5������2����λ�ã�����ԭ���ĵ�һ��5�͵ڶ���5���Ⱥ����͵ߵ��ˣ������ǲ��ȶ�����


void selectSort(vector<int>& nums) {
    int len = nums.size();
    int minIndex = 0;
    for (int i = 0; i < len; i++) {
        minIndex = i;//ÿ�ζ�Ҫ����minIndexΪi
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[minIndex])    minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main() {
    vector<int> test = { 3,2,1 };
    selectSort(test);
    for (auto i: test) {
        cout << i;
    }
    cout << endl;

    return 0;
}