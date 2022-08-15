#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int a : stones) sum += a;
    int target = sum / 2;//���������������target������ȡ�� ��sum=7��target=sum/2=3����Ҳ�͵��µõ���dp[stones.size()-1][target]��������ͬ�����е�һ�����Ǳ���һ��sum-dp[stones.size()-1][target]С

    vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
    for (int b = stones[0]; b <= target; b++)    dp[0][b] = stones[0];//����Ʒ0��ʯͷ0��ʱ������������С����Ʒ0����������Ϊ0������Ϊstones[0]
    //����Ʒ�󱳰�
    for (int i = 1; i < stones.size(); i++) {
        for (int j = 0; j <= target; j++) {
            if (j < stones[i])   dp[i][j] = dp[i - 1][j];//��j������װ����stones[i]
            if (j >= stones[i])  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
        }
    }

    return (sum - dp[stones.size() - 1][target]) - dp[stones.size() - 1][target];//��������ʯͷ�Ĳ�ֵ���Ƿ�������С������

}

int main(){
    vector<int> stones = { 1,2 };
    lastStoneWeightII(stones);

    return 0;
}