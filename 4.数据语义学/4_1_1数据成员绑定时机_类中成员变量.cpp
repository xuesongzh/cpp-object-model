#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string myvar = "jisuanjizuchengyuanli";  //ȫ�ֱ��� �ַ�������
class A {
 public:
    A(int value)
        : myvar(value) {
    }
    int myFunction();

 private:
    int myvar;  //ͬ���ֲ��������������Ͳ�ͬ
};

int A::myFunction() {
    return myvar;  //�������ڵ�int����myvar
}

string myFunciton01() {
    return myvar;  //���ص���ȫ�ֵ�string���ͱ���
}

int main(void) {
    //������ڲ���myvar
    A obj_a(12);
    cout << obj_a.myFunction();
    cout << endl;

    //ȫ�ֵ�myvar
    cout << ::myvar << endl;  //::���Ǳ�ʾȫ�ֱ���

    system("pause");
    return 0;
}
/*
* �ܽ�
* ��������myFunction�����Ľ�������������A������Ϻ�ſ�ʼ�ġ�
* ��Ϊֻ��������A������Ϻ󣬱��������ܿ�����A��myvar�����ܸ���ʱ������Ҫ�ѳ���myvar�ĳ����������ʵ��Ľ��͡�
* ��Ա�����н��ͳ�����myvar��ȫ�ֱ����н��ͳ�string myvar��
*/
