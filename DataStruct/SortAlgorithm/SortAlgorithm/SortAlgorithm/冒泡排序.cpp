#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//ð������
//1.�Ƚ����ڵ�Ԫ�أ�����һ��Ԫ�رȵڶ����󣬾ͽ�����������
//2.��ÿһ�����ڵ�Ԫ����ͬ���Ĳ�������ǰ����������һȦ������Ԫ�ؾ���������
//3.ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ����ϲ��裬ֱ��û��һ��������Ҫ�Ƚϡ�

void bubbleSort(vector<int>& nums) {

    int len = nums.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (nums[j] > nums[j + 1])  swap(nums[j], nums[j + 1]);
        }
    }
}





void test01() {
    vector<int> test = { 3,2,1,8,5};
    bubbleSort(test);
    for (auto i : test) {
        cout << i ;
    }
    cout << endl;
	
}

int main(){
    test01();

    return 0;
}