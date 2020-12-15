#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����������ֵ�������ص���ʱ�Զ���
class A {
 public:
    A() {
        cout << "A::A()���캯����ִ��" << endl;
    }
    A(const A& tmpobj) {
        cout << "A::A()�������캯����ִ��" << endl;
    }
    //���ؿ�����ֵ�����
    A& operator=(const A& tmpaobj) {
        cout << "A::operator()������ֵ�������ִ��" << endl;
        printf("������ֵ�������tmpaobj�ĵ�ַΪ%p\n", &tmpaobj);
        return *this;
    }

    ~A() {
        cout << "A::~A()����������ִ��" << endl;
    }
};

A operator+(const A& obj1, const A& obj2) {
    A tmpobj;

    printf("tmpobj�ĵ�ַΪ%p\n", &tmpobj);
    //printf("---------------------\n");
    //.....
    return tmpobj;
}

void func() {
    A myobj1;
    printf("myobj1�ĵ�ַΪ%p\n", &myobj1);

    A myobj2;
    printf("myobj2�ĵ�ַΪ%p\n", &myobj2);

    A resultobj;
    resultobj = myobj1 + myobj2;  //�ȵ���operator+��Ȼ����ÿ�����ֵ�����

    //A resultobj = myobj1 + myobj2; //�������캯��(�����ʱ�����ֵ�ͻ���ÿ������캯��)

    printf("resultobj�ĵ�ַΪ%p\n", &resultobj);

    return;
}
/*
A::A()���캯����ִ��
myobj1�ĵ�ַΪ0137FB9B
A::A()���캯����ִ��
myobj2�ĵ�ַΪ0137FB8F
A::A()���캯����ִ��
A::A()���캯����ִ��
tmpobj�ĵ�ַΪ0137FA6F
// A::A()�������캯����ִ��  �������Ż�����ʱ����
// A::~A()����������ִ��
A::operator()������ֵ�������ִ��
������ֵ�������tmpaobj�ĵ�ַΪ0137FAB7
A::~A()����������ִ��
resultobj�ĵ�ַΪ0137FB83
A::~A()����������ִ��
A::~A()����������ִ��
A::~A()����������ִ��
 */

int main() {
    func();
    system("pause");

    return 1;
}
