#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//ϣ��������ֱ�Ӳ��������һ�ֱ��֣����������������Ƚϴ�����ݾ��нϿ������
void shellSortCore(vector<int>& nums, int gap, int i) {
    int inserted = nums[i];
    int j;
    //  �����ʱ������в���
    for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {
        nums[j + gap] = nums[j];
    }
    nums[j + gap] = inserted;//��һ���������ǽ�nums[i]�ŵ����յ�nums[j+gap]�ϣ����j+gap����jһֱ��ǰ��������ͣ�ڵĵط���
}

void shellSort(vector<int>& nums) {
    int len = nums.size();
    //���з��飬�ʼ��ʱ��gapΪ���鳤��һ��
    for (int gap = len / 2; gap > 0; gap /= 2) {
        //�Ը���������в������
        for (int i = gap; i < len; ++i) {
            //��nums[i]���뵽���ڷ�����ȷ��λ����
            shellSortCore(nums, gap, i);
        }
    }

}




void test01() {
    vector<int> test = { 3,2,1,8,5 };
    shellSort(test);
    for (auto i : test) {
        cout << i;
    }
    cout << endl;
}

int main(){
    test01();

    return 0;
}