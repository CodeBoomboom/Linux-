#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<deque>
#include<time.h>
using namespace std;

class Player
{
public:
	Player(){}

public:
    string mName;
    int mScore[3];
};


//����ѡ�ֺͱ�ţ����浽p��v
void Crate_Player(map<int, Player>& mPlist, vector<int>& v1) {
    string seedName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 24; i++) {
        //ѡ��
        Player p;
        p.mName = "ѡ��";
        p.mName += seedName[i];
        for (int j = 0; j < 3; j++) {
            p.mScore[j] = 0;
        }
        //���
        int uID = 100+i;
        //����ѡ����Ϣ
        mPlist.insert(make_pair(uID, p));
        v1.push_back(uID);
    }
}

//ѡ�ֳ�ǩ  ����˳��
void Set_Random(vector<int>& vIn) {
    random_shuffle(vIn.begin(), vIn.end());
}

//�������
//num����������   vIn����������    mPlist��ѡ������  vOut��������������ţ�
void Set_Score(int num, vector<int>& vIn, map<int, Player>& mPlist, vector<int>& vOut) {
    srand((unsigned int)time(NULL));
    //��һ��int ���� ���ݷ����Զ�����
    //�ڶ���int ���
    multimap<int, int, greater<int>> mGroup;  //Ĭ�Ϸ�����С�������򣬸�Ϊ�Ӵ�С
    int groupIndex = 0;
    for (vector<int>::iterator it = vIn.begin(); it != vIn.end(); it++) {
        deque<int> dScore;
        //���
        for (int i = 0; i < 10; i++) {
            int score = rand()%41  + 60;    //100-60+1
            dScore.push_back(score);
        }
        //����
        sort(dScore.begin(), dScore.end());
        //ȥ�������ͷ�
        dScore.pop_back();
        dScore.pop_front();
        //��ƽ����
        int totalScore = accumulate(dScore.begin(), dScore.end(), 0);    //���ܺ�
        int avgScore = totalScore / (int)dScore.size();  //ƽ����
        //����ѡ�ַ���
        mPlist[*it].mScore[num-1] = avgScore; 

        //��ǰѡ�ֱ�ŷŵ�group��
        mGroup.insert(make_pair(avgScore, *it));
        groupIndex++;
        if (groupIndex % 6 == 0) {  //mGroup����6��ѡ����
            
            //ȡǰ��������vOut
            int numIndex = 0;
            for (multimap<int, int>::iterator mit = mGroup.begin(); mit != mGroup.end(); mit++) {
                if (numIndex >= 3) {
                    break;
                }
                vOut.push_back((*mit).second);//ѡ�ֱ��
                numIndex++;
            }
            mGroup.clear();
        }
    }
}

//��ӡ��������
//num����������   v��������������ţ�    mPlist��ѡ������
void Show_Good_Player(int num, vector<int>& v, map<int, Player>& mPlist){
    cout << "��" << num << "�ֱ�������������" <<endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout <<"������" << mPlist[*it].mName <<"  " << "������" << mPlist[*it].mScore[num - 1] << endl;
    }

}


int main(){
    //����map���������ݱ�ű���ѡ����Ϣ
    map<int, Player> mPlist;


    //��һ�ֱ����Ĳ����б�
    vector<int> v1;//24���ˣ�����12��

    //�ڶ��ֱ����Ĳ����б�
    vector<int> v2;//12���ˣ�����6��

    //�����ֱ����Ĳ����б�
    vector<int> v3; //6���� ����3��

    //����ǰ����
    vector<int> v4;

    //����ѡ��
    Crate_Player(mPlist, v1);

    //��һ�ֱ���
    Set_Random(v1);//����˳��
    Set_Score(1, v1, mPlist, v2);//����
    Show_Good_Player(1, v2, mPlist);//��ӡ��������

    //�ڶ��ֱ���
    Set_Random(v2);//����˳��
    Set_Score(2, v2, mPlist, v3);//����
    Show_Good_Player(2, v3, mPlist);//��ӡ��������

    //�����ֱ���
    Set_Random(v3);//����˳��
    Set_Score(3, v3, mPlist, v4);//����
    Show_Good_Player(3, v4, mPlist);//��ӡ���ձ������

    return 0;
}