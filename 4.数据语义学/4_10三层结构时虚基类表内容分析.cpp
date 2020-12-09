#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class Grand  //үү��
{
 public:
    int m_grand;
};

class A1 : virtual public Grand {
 public:
    int m_a1;
};

class A2 : virtual public Grand {
 public:
    int m_a2;
};

class C : public A1, public A2 {
 public:
    int m_c;
};

int main() {
    cout << sizeof(Grand) << endl;
    cout << sizeof(A1) << endl;
    cout << sizeof(A2) << endl;
    cout << sizeof(C) << endl;

    C c;  //����鿴�ڴ�
    /*
	 003D2089  mov         eax,dword ptr [this]  
	 003D208C  mov         dword ptr [eax],offset C::`vbtable' (03D6B40h)  
	 003D2092  mov         eax,dword ptr [this]  
	 003D2095  mov         dword ptr [eax+8],offset C::`vbtable' (03D6B48h)

	���캯������ӵĸ�������ָ�븳ֵ�Ĵ���
	 */
    c.m_grand = 2;
    c.m_a1 = 5;
    c.m_a2 = 6;
    c.m_c = 8;

    //���ۣ��Լ̳й�����������Ա�����ķ��������������Ա�����ķ����ٶ�Ҫ����
    //û���õ�vbptr2��ֻ�õ���vbptr1

    /*
	 * ���������Ϊʲô��ô���
	 * �����Ϊ��ʵ��үү��ֻ��һ�ݿ�������Ƹ��ӣ�����ô��ƫ�ƺ�������ָ�룿Ϊʲô��ô��ƣ�����
	 * Ϊʲô��ô��ƣ��Ǹ����ѻش������
	 * ��ͬ�ı����������в�ͬ��ʵ�֣�vc++��ͨ��������ʵ��
	 * linux�µ�gcc���������ܰ�ƫ������������λ�ã����麯�����д洢
	 */

    // ����ͻ��õ�vbptr2ȥ��m_grand��ֵ
    A2 *pa2 = &c;
    pa2->m_grand = 8;
    pa2->m_a2 = 9;

    system("pause");
    return 1;
}

//������Ǳ�����ȷ���ģ�ÿ�������vbptr��һ����