
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Grand //үү��
{
public:
	//int m_grand;
};

class A1 : virtual public Grand//ֱ�Ӹ���A1
{
public:
};

class A2 : virtual public Grand//ֱ�Ӹ���A2
{
public:
};

class C1 :public A1, public A2
{
public:
};


int main()
{
	/*
	 * 4_8��������������ͳ�̽
	 * һ������ࣨ��̳�/����������������
	 * һ����(������)����������̳���ͬһ��үү�࣬�ᵼ��үү������ݳ�Ա���������������ݡ�
	 * ��ͳ���ؼ̳���ɵ� ���ռ����⣬Ч�����⣬���������⣻
	 * үү�������࣬����ļ̳з�ʽ����̳С�
	 */
	
	cout << sizeof(Grand) << endl;//1
	cout << sizeof(A1) << endl;//4
	cout << sizeof(A2) << endl;//4
	cout << sizeof(C1) << endl;//8

	C1 c1;
	//c1.m_grand = 12; //ֱ�Ӹ��಻��̳�үү��--���ʲ���ȷ�����ֳ�ͻ�������ԣ�
	//���������֮�󣬾Ͳ�����ַ��ʲ���ȷ��������
	//c1.A1::m_grand = 13;
	//c1.A2::m_grand = 15;

	//����࣬��Grand��ֻ���̳�һ�Σ�
	
	/*����������̽
	 *�������(1)������ vbtable(virtual base table).(2)������ָ�� vbptr(virtual base table pointer)
	 *��Grand A1 A2 C1��ȫ���ǿ����ʱ��ʹ��sizeof�����ֵ�ֱ�Ϊ1��4��4��8
	 *����sizeof(Grand) ==1����⣻
	 *virtual��̳�֮��A1,A2��ͻᱻ����������һ��������ָ�룬���ָ�룬�е��Ա�����ĸо�
	 *A1,A2����Ϊ����������ָ�룬���ռ����4���ֽ�
	 *C1�̳�����������ָ�룬����ռ��8���ֽ�
	*/
	A1 a1;//�鿴a1��a2�е����ݣ����ݾ���������ĵ�ַ--��������������--30 6b 8d 00 
	A2 a2;//---3c 6b 8d 00
	//������ָ�룬����ָ������������̸����


	system("pause");
	return 1;
}
/*
 * �鿴����
 *	1. cl /d1 reportSingleClassLayoutGrand�ļ���.cpp  (ע��û�п��ո�)
 *	cl /d1 reportSingleClassLayoutA1�ļ���.cpp
 *	cl /d1 reportSingleClassLayoutC1�ļ���.cpp
 *	
 */