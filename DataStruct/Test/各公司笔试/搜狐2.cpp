#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int>& vec, int n, int k, int x) {
    while (k--) {
        int maxi = 0;//���ֵ�±�
        for (int i = 0; i < vec.size(); i++) {
            maxi = vec[maxi] > vec[i] ? maxi : i;
        }
        vec[maxi] -= x;
    }
    //�����ֵ
    int max = INT_MIN;
    for (auto& i : vec) {
        max = max > i ? max : i;
    }
    return max;
}


int main() {
    int n, k, x;//n�����Сk��������xÿ�μ�ȥ����
    cin >> n >> k >> x;
    int temp;
    vector<int> vec;
    while (cin >> temp) {
        vec.push_back(temp);
        if (cin.get() == '\n') break;
    }
    int result = getMax(vec, n, k, x);
    cout << result << endl;


    return 0;
}