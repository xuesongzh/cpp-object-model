
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/*
 *һ�������Ĭ�ϸ�����Ϊ
 *������ǲ�д�Լ��Ŀ������캯���Ϳ�����ֵ�������������Ҳ����Ĭ�ϵĶ��󿽱��Ͷ���ֵ��Ϊ��
 *ֱ�ӵ��ڴ濽�����������Ա������ֵ��������һ������Ķ�Ӧλ���ϡ�
 *
 *����������ֵ��������������캯��
 *�������ṩ�Լ��Ŀ�����ֵ������Ϳ������캯��ʱ�����Ǿͽӹ���ϵͳĬ�ϵĿ�����Ϊ��
 *��ʱ�������������ڿ�����ֵ������Ϳ������캯����д�ʵ��Ĵ��룬����ɶ���Ŀ������߸�ֵ������
 *
 *������ν�ֹ����Ŀ�������͸�ֵ���ѿ������캯���Ϳ�����ֵ�����˽��������ֻ����������ҪЩ�����壻delete
 */

class A {
 public:
    int m_i, m_j;

    A() {}
    A& operator=(const A& tmp) {
        m_i = tmp.m_i;
        m_j = tmp.m_j;
        return *this;
    }

    A(const A& tmp) {
        m_i = tmp.m_i;
        m_j = tmp.m_j;
    }
};

void func() {
    A aobj;
    aobj.m_i = 15;
    aobj.m_j = 20;

    A aobj2 = aobj;  //ִ�п������캯��(�����д�˿������캯��)

    A aobj3;
    aobj3.m_i = 13;
    aobj3.m_j = 16;
    aobj2 = aobj3;  //ִ�п�����ֵ������������д�˿�����ֵ�������
}

int main() {
    func();

    system("pause");
    return 1;
}
