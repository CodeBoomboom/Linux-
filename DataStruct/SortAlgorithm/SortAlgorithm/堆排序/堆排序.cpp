#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//�鲢����

//�ϲ�
void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    //�����������Ұ���δ����ĵ�һ��Ԫ��
    int l_pos = left;
    int r_pos = mid + 1;
    //��ʱ����Ԫ�ص��±�
    int pos = left;

    //�ϲ�
    while (l_pos <= mid && r_pos <= right) {
        if (nums[l_pos] < nums[r_pos]) {//�������һ��Ԫ�ظ�С
            temp[pos++] = nums[l_pos++];
        }
        else {//�Ұ�����һ��Ԫ�ظ�С
            temp[pos++] = nums[r_pos++];
        }
    }

    //�ϲ������ʣ���Ԫ�أ����ϲ���ʣ���Ԫ�طŽ�temp��Ҳ���������/�Ұ���ֻʣһ��Ԫ�ص������
    while (l_pos <= mid)     temp[pos++] = nums[l_pos++];
    //�ϲ��Ұ���ʣ���Ԫ��
    while (r_pos <= mid)     temp[pos++] = nums[r_pos++];

    //����ʱ�����кϲ����Ԫ�ظ��ƻ�nums����
    while (left <= right) {
        nums[left] = temp[left];
        left++;
    }
}

//
void MSort(vector<int>& nums, vector<int>& temp, int left, int right) {

    if (left < right) {//ֻ��left<right��left��right֮���Ԫ�ظ�������1�Ż��֣��������1����ô���صݹ��ϲ�ִ��merge�ϲ�������
        int mid = (left + right) / 2;//���м仮��
        MSort(nums, temp, left, mid);//����벿�ֹ鲢����
        MSort(nums, temp, mid + 1, right);//���Ұ벿�ֹ鲢����
        merge(nums, temp, left, mid, right);//�鲢
    }
}

//�鲢������ڣ��������ڵ�Ŀ����Ϊ�˷���temp���飬��Ȼ�Ļ���ֻ�����߼����Լ�����temp�����ˣ�
void MergeSort(vector<int>& nums) {
    vector<int> temp(nums.size());//����һ����������
    MSort(nums, temp, 0, nums.size() - 1);
}




void test01() {
    vector<int> test = { 3,2,1,8,5 };
    MergeSort(test);
    for (auto i : test) {
        cout << i;
    }
    cout << endl;
}

int main() {
    test01();

    return 0;
}