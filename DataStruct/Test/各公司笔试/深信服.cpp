//#include<vector>
//#include<iostream>
//using namespace std;
//
//int fun(vector<int>& a, int n, int x) {
//    if (n == 0)  return 0;
//    //     if(x < 0)    return 0;
//    vector<pair<int, int>> dif;//���ҳ�����ÿ��Ԫ������Ӧ��v�ķ�Χ   v��Χ[a[i]-x,a[i]+x]  v>0
//    dif.reserve(n);
//    for (auto& num : a) {
//        int left = num - x < 0 ? 0 : num - x;
//        int right = num + x;
//        dif.push_back({ left, right });
//    }
//    vector<pair<int, int>> over;
//    over.push_back(dif[0]);//�Ȱѵ�һ��push��ȥ����ʾһ��ʼv�ķ�Χ��Ȼ��ӵ�һ����ʼģ��
//    for (int i = 1; i < n; i++) {
//        int left = max(over.back().first, dif[i].first);//������Χ����������һ������߽�ȡ��ģ��ұ߽�ȡС��
//        int right = min(over.back().second, dif[i].second);
//        if (left < right) {//�����ʱ������left<right˵��v��left��right��Χ�ڻ��������㣬ֻ��Ҫ�����������һ��Ԫ�ؼ���
//            over.back().first = left;
//            over.back().second = right;
//        }
//        else {//�����˵��v���������ˣ���ô��Ҫ�仯һ��αװ����Ҫ�������һ��dif
//            over.push_back(dif[i]);
//        }
//    }
//    return over.size() - 1;  //�仯αװ�Ĵ�����������ʼֵ
//}
//
//
//
//
//int main() {
//    int n, x;
//    while (cin >> n >> x) {
//        vector<int> a(n, 0);
//        for (int i = 0; i < n; i++) {
//            cin >> a[i];
//        }
//        cout << fun(a, n, x) << endl;
//    }
//
//
//
//    return 0;
//}
//
//

#include<iostream>
#include<vector>
using namespace std;

//��Ҫ���Ƕ�������1���Ӵ���Ҫ������
//1��dp[i]��ʾ��iΪ��β����1�ĸ���Ϊdp[i]
//2�����ƹ�ʽ��
//    ���str[i] == 1��      ����str[i-1] ==1, ��ôdp[i] = dp[i-1] + 1�� ��str[i-1] !=   1 ��ôdp[i]���ã�dp[i] = 1
//    ��Ϊ1�Ļ�        dp[i] = 0
//3����ʼ��������Ϊ1�ģ�dp[0] = str[0] - '0'
int fun(string& str, int n) {
    int i = 0, j = -1;
    vector<int> dp(n, 0);
    dp[0] = str[0] - '0';
    int max = dp[0];
    for (int i = 1; i < n; ++i) {
        if (str[i] == '1') {
            if (str[i - 1] == '1')    dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;
        }
        else {
            dp[i] = 0;
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    if (max == 0)  return 0;
    vector<pair<int, int>> spaces;
    for (int i = 0; i < n; i++) {
        if (dp[i] == max) {
            spaces.push_back({ i - max + 1, i });//�Ӵ�������ӽ�ȥ��dp[i]����һ�����������ж����ͬ���ȵ���������Ӵ�
        }
    }
    long long res = 0;
    int left_pre = -1;
    for (auto& space : spaces) {//��ÿ�����������
        auto left = space.first;
        auto right = space.second;
        long long cur = (long long)(left - left_pre) * (n - right);//��ÿ���Ӵ���������ȡ
        res += cur;
        left_pre = left;//Ϊ�˷�ֹ�ظ�����ߵ��Ӵ��Ѿ�ȡ����
    }
    return res % (1000000007);
}

int main() {
    int n;
    while (cin >> n) {
        string str;
        cin >> str;
        cout << fun(str, n) << endl;
    }



    return 0;
}