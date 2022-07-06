#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//�̳����쳣�е�Ӧ��

//�쳣����
class BaseMyException {
public:
    virtual void what() = 0;
    virtual ~BaseMyException(){}
};

class TargetSpaceNullException :public BaseMyException {
public:
    virtual void what() {
        cout << "Ŀ��ռ��" << endl;
    }
    ~TargetSpaceNullException() {

    }
};

class SourceSpaceNullException :public BaseMyException {
public:
    virtual void what() {
        cout << "Դ�ռ�Ϊ��" << endl;
    }
    ~SourceSpaceNullException() {

    }
};


void copy_str(char* target, const char* source) {
    if (target == NULL) {
        throw TargetSpaceNullException();
    }

    if (source == NULL) {
        throw SourceSpaceNullException();
    }
    int len = strlen(source) + 1;
    while (*source != '\0') {
        *target = *source;
        target++;
        source++;
    }

}



int main()
{
    const char* source = "abcdefg";
    char buf[1024] = {0};
    try {
        copy_str(NULL, source);
    }
    catch (BaseMyException& e) {
        e.what();
    }

    try {
        copy_str(buf, NULL);
    }
    catch (BaseMyException& e) {
        e.what();
    }


    try {
        copy_str(buf, source);
    }
    catch (BaseMyException& e) {
        e.what();
    }

    cout << buf << endl;


    return 0;
}