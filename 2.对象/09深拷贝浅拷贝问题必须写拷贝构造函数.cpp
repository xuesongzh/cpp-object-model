#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class TEST {
 public:
    int m_i;
    int *p;
    //���캯��
    TEST() {
        p = new int(23);
        m_i = 0;
        cout << "���캯��ִ��" << endl;
    }
    TEST(int value)
        : m_i(value) {
        p = new int(value);
        cout << "��һ�������Ĺ��캯��ִ��" << endl;
    }
    //�������캯��--û�п������캯���ᱨ�쳣
    TEST(const TEST &t) {
        this->p = new int(t.m_i);  //���
        this->m_i = t.m_i;
    }
    ~TEST() {
        delete p;
        cout << "��������ִ��" << endl;
    }
};

int main(void) {
    TEST test01(12);
    TEST test02(test01);
    //���û�п������캯�����������󣬻��ͷ�����pָ����ڴ�ռ䣬�ᱨ�쳣��

    system("pause");
    return 0;
}

// �Լ�д�˿������캯��һ��Ҫʵ�ֿ������캯���Ĺ��ܣ�Ҫ��ÿ����Ա������ʼ����
// ����ָ�����͵ĳ�Ա����ָ�������ڴ棬����Ҫд�������캯�������--��̬�ڴ���䡣
