#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Grand //үү��
{
public:
	int m_grand;
};

class A1 : virtual public Grand
{
public:
	int m_a1;
};

class A2 : virtual public Grand
{
public:
	int m_a2;
};

class C1 :public A1, public A2
{
public:
	int m_c1;
};


int main()
{
	//һ������ṹʱ���������ݷ���
	cout << sizeof(Grand) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(C1) << endl;

	C1 c1obj;//����鿴�ڴ�
	/*
	 003D2089  mov         eax,dword ptr [this]  
	 003D208C  mov         dword ptr [eax],offset C1::`vbtable' (03D6B40h)  
	 003D2092  mov         eax,dword ptr [this]  
	 003D2095  mov         dword ptr [eax+8],offset C1::`vbtable' (03D6B48h)

	���캯������ӵĸ�������ָ�븳ֵ�Ĵ���
	 */
	c1obj.m_grand = 2;
	c1obj.m_a1 = 5;
	c1obj.m_a2 = 6;
	c1obj.m_c1 = 8;
	//C1 c2obj;
	//���ۣ��Լ̳й�����������Ա�����ķ��������������Ա�����ķ����ٶ�Ҫ����
	//û���õ�vbptr2��ֻ�õ���vbptr1

	/*
	 * ���������Ϊʲô��ô���
	 * �����Ϊ��ʵ��үү��ֻ��һ�ݿ�������Ƹ��ӣ�����ô��ƫ�ƺ�������ָ�룿Ϊʲô��ô��ƣ�����
	 * Ϊʲô��ô��ƣ��Ǹ����ѻش�����⣻
	 * ��ͬ�ı����������в�ͬ��ʵ�֣�vc++��ͨ��������ʵ�֣�
	 * linux�µ�gcc���������ܰ�ƫ������������λ�ã����麯�����д洢��
	 */
	//A2 *pobja2 = new C1();  
	A2 *pa2 = &c1obj;
	pa2->m_grand = 8;
	pa2->m_a2 = 9;


	system("pause");
	return 1;
}

/*
 * 4_10����ṹʱ���������ݷ���
 * 
 */