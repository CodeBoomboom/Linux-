#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//��������
//��һ���Ѿ������С���еĻ�����һ�β���һ��Ԫ��
//�տ�ʼ��������С����ֻ��1��Ԫ�أ����ǵ�һ��Ԫ��
//�Ƚ��Ǵ��������е�ĩβ��ʼ��Ҳ���ǽ���Ҫ�����Ԫ�غ��Ѿ���������Ԫ�ضԱ�
//����������ֱ�Ӳ���������棬�����������ôһֱ��ǰ��ֱ���ҵ��ò����λ��
//�������һ����������Ԫ����ȵ�Ԫ�أ���ô�Ὣ��������Ԫ�صĺ��棬��ͱ�֤�����е��ȶ���û�иı䣬����˵����������һ���ȶ�������

void insertSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)//��1��ʼ����
    {
        //ֻ�е���i��С�ڵ�i-1���Ž��в������򣬷���ֱ�Ӳ鵽����棨Ҳ���ǲ��ö�������
        if (nums[i] < nums[i - 1]) {
            int val = nums[i];//��¼һ�£���Ϊ������ƶ�����
            int j = i - 1;//��¼�����������һ��Ԫ���±꣬��������
            while (j >= 0 && nums[j] > val)//valС��nums[j]�Ļ��ż�����ǰ�Ҳ����λ��
            {
                //����λ�ã�ȫ�������
                nums[j + 1] = nums[j];
                j--;//������ǰ��
            }
            //�ҵ�λ���ˣ�ֱ�Ӳ���
            nums[j+1] = val;
        }
    }
}



void printfVector(vector<int>& nums) {
    for (auto& i : nums) {
        cout << i;
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 3,2,1 };
    insertSort(test);

    printfVector(test);

}

int main(){
    test01();
    //string a = "111";
    //int b = atoi(a.c_str());
    //cout << b;
    return 0;
}