#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class X {
 public:
    int m_x;
    X(int value = 0)
        : m_x(value) {
        printf("this = %p", this);
        cout << "����ת�����캯��������" << endl;
    }
    X(const X& t) {
        printf("this = %p", this);
        cout << "�������캯��������" << endl;
    }
    X& operator=(const X& t) {
        printf("this = %p", this);
        cout << "������ֵ�����������" << endl;
        return *this;
    }
    ~X() {
        printf("this = %p", this);
        cout << "��������������" << endl;
    }
};

class A {
 public:
    X obj_x;
    int m_a;
    A(int temvalue)  //���ﹹ����obj_x���󣬻�û��ָ������֮ǰ�͹��������
    /*
	 * վ�ڱ������ĽǶȣ�
	 * X obj_x;
	 * obj_x.X::X();
	 */
    {
        obj_x = 1000;  //��һ�е���3������
        /*
		 * ����һ����ʱ���󣬵�������ת�����캯�������ÿ�����ֵ��������и�ֵ��obj_x;
		 * Ȼ��������������ͷ��Լ���
         * X tmp;
         * tmp.X::X(1000);
         * obj_x.X::operator=(tmp);
         * tmp.X::~X();
		 */
        m_a = 500;
    }
};

class A {
 public:
    X obj_x;
    int m_a;
    A(int temvalue)
        : obj_x(1000)
    /*
	վ�ڱ������ĽǶ�
	X obj_x;
	obj_x.X::X(1000);
	 */
    {
        m_a = 500;
    }
};

int main(void) {
    A a(1000);
    /*
	 *û��ʹ�ó�ʼ����Ա�б�
	    this =00DAF934���캯��ִ��
		this =00DAF778����ת�����캯��ִ��
		this=00DAF934������ֵ����������ã��Ѿ�������ģ������ڳ�ʼ���͸�ֵ������
		this=00DAF778��������ִ��
		this=00DAF934��������ִ��

	  ʹ�ó�Ա��ʼ���б�:
		this =00AFFBFC����ת�����캯��ִ��
		this=00AFFBFC��������ִ��
	 */

    system("pause");
    return 0;
}
/*
* ��Ա��ʼ���б������
*	���˱����ó�ʼ���б�ĳ��ϣ������ó�ʼ���б������Ŀ������߳�������Ч�ʡ�
*
*	���԰ѳ�ʼ���б��еĴ��뿴���������һ���ּ��ɣ����������Զ������뵽�������ڲ���
*	���ۣ������͵Ķ����ʼ�������ʹ�ó�Ա��ʼ���б�ķ�ʽ�������Ч�ʡ�
*		 �����ͣ���int��char���ڳ�ʼ���б��Ǻ����������𲻴�
*/
