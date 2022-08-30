#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//������
//��ѡ��һ����׼������ѡ���һ��Ϊ��׼
//Ȼ���λָ��high�ȴӺ���ǰ�ҵ���һ���Ȼ�׼С��ֵ����¼���±�
//Ȼ���λָ��low��ǰ����ҵ���һ���Ȼ�׼���ֵ����¼���±�
//����������ֵ
//�ظ���ֱ����׼ֵ��߶��Ǳ����ģ��ұ߶��Ǳ���С��
//Ȼ��ݹ�Ի�׼ֵ������䡢�ұ��������ν������Ϲ���

void quickSort(vector<int>& nums, int low, int high) {
    //��ֹ����
    if (low >= high) return;

    int first = low;//
    int last = high;
    int key = nums[first];//��׼ֵ

    while (first < last) {

        while (first < last && nums[last] > key)    last--;//lastָ��Ӻ���ǰ�ҵ�һ����keyС��
        if (first < last)   nums[first++] = nums[last];//��firstָ��ָ��Ļ�Ϊ���������λָ��first+1

        while (first < last && nums[first] <= key)    first++;//firstָ���ǰ����ҵ�һ����key���
        if (first < last) nums[last--] = nums[first];//��lastָ��ָ��Ļ�Ϊ���������λָ��last-1
    }
    nums[first] = key;//����׼ֵ��ӵ������м�λ��
    //��������ݹ���������
    quickSort(nums, low, first - 1);

    //��������ݹ���������
    quickSort(nums, first + 1, high);


}


void printfVector(vector<int>& nums) {
    for (auto& i : nums) {
        cout << i;
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 3,2,1,4 };

    quickSort(test, 0, test.size() - 1);
    printfVector(test);

}

int main(){
    test01();

    return 0;
}