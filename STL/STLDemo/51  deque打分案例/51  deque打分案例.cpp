#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
//��ί��ְ�����sort �㷨����
//����5��ѡ�֣��������÷֣���10����ί��5��ѡ�ֽ��д��
//�÷ֹ���ȥ����߷֣�ȥ����ͷ֣�ȡ��ƽ����
//���÷ֶ�5��ѡ�ֽ�������


//ѡ����
class Player
{
public:
    Player(){}
    Player(string name, int score):mName(name),mScore(score){}
public:

    string mName;
    int mScore;
protected:
private:
};

//����ѡ��
void Create_Player(vector<Player>& v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++) {
        Player p;
        p.mName = "ѡ��";
        p.mName += nameSeed[i];
        p.mScore = 0;

        v.push_back(p);
    }

}

void PrintScore(int val) {
    cout << val << " ";
}

//���
void Set_score(vector<Player>& v) {
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        //��ǰѧ�����д��
        deque<int> dScore;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;   //rand % (b-a+1) +a  : a~bһ��������� 
            dScore.push_back(score);
        }

        //�Է�����������,Ĭ�ϴ�С����
        sort(dScore.begin(), dScore.end());
        //for_each(dScore.begin(), dScore.end(), PrintScore);
        //cout << endl;

        //ȥ�������ͷ�
        dScore.pop_back();
        dScore.pop_front();

        //��ƽ����
        int totalScore = 0;
        for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++) {
            totalScore += (*dit);
        }
        int avgScorce = totalScore / dScore.size();

        //�������
        (*it).mScore = avgScorce;
    }
}

//�������
bool mycompare(Player& p1, Player& p2) {
    return p1.mScore > p2.mScore;
}

//����ѡ�ַ�������
void Print_Rank(vector<Player>& v) {
    //�Ӵ�С����
    sort(v.begin(), v.end(), mycompare);
    for (vector<Player>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "������" << (*it).mName << "�÷֣�" << (*it).mScore << endl;
    }
}


int main()
{
    //����vector����������ѡ����Ϣ
    vector<Player> vPlist;
    Create_Player(vPlist);
    Set_score(vPlist);
    Print_Rank(vPlist);


    system("pause");
    return 0;
}