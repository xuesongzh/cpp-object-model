#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class A {
 public:
    int number;                        //4���ֽ�
    virtual void virtualFunction() {}  //�麯��
};

int main(void) {
    A a;
    int length = sizeof(a);
    cout << "length=" << length << endl;  //8

    char* p1 = reinterpret_cast<char*>(&a);  //ǿ������ת����&a���׵�ַ
    char* p2 = reinterpret_cast<char*>(&a.number);
    if (p1 == p2)  //����Ͷ����еĳ�Ա����λ����ͬ��˵��number�ڶ����ڴ沼�����棬�麯����ָ�������档
    {
        cout << "�麯����ָ��λ�ڶ����ڴ��ĩβ" << endl;
    } else {
        cout << "�麯����ָ��λ�ڶ����ڴ�Ŀ�ͷλ��" << endl;
    }
    //���ۣ��麯����ָ��λ�����������ڴ沼�ֵĿ�ͷλ�á�

    system("pause");
    return 0;
}
/*
 *3_1�麯����ָ��λ�÷���_λ�ڶ����ڴ沼�ֵĿ�ͷλ��
* (1)�麯����ָ��λ�÷���
* �ࣺ���麯������������һ���麯����(vtbl)��
* ʹ�������ɶ����ʱ�򣬶����л���һ���麯����ָ��(vptr)������ָ������麯����ʼ��ַ��
* �麯���������ɿ�ִ�г����ʱ��ᱣ���ڿ�ִ�г����ļ��С�
*
* //���ۣ��麯����ָ��λ�����������ڴ沼�ֵĿ�ͷλ�á�
*
*/
