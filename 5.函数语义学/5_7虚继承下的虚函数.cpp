#include<iostream>

using namespace std;

class Base
{
public:
	virtual void f() {}
	virtual ~Base() {}
	int m_basei;
};

class Derive :public virtual Base
{
public:
	virtual ~Derive() {}
	int m_derivei;
};

int main()
{



   //���� ��̳��µ��麯��
   cout << sizeof(Derive) << endl;  //16   --2��int��һ��������һ���麯����
   Derive dobj;
   dobj.m_basei = 2;//13-16�ֽ�
   dobj.m_derivei = 5;//5-8�ֽ�
	//9-12�ֽ�--�麯�����ַ
	//1-4�ֽ�������ָ��---������ϸ��ͼ

   Derive *pdobj = new Derive();
   pdobj->f();
	/*
	 * 
	 */

   Base *pbase = new Derive();//������������ø���������
   pbase->m_basei = 6;

	
   Derive *pderive = new Derive();//pderive = 0x013349b0 {m_derivei=0 }
   Base *pbase2 = (Base *)pderive;//pbase2 = 0x013349b8 {m_derivei=0 }//��ַ��8�ֽ�
	/*
	 *
	 *
	 * __vfptr = 0x00068b44 {FunctionSemantics.exe!const Derive::`vftable'} {0x00061078 {FunctionSemantics.exe!Base::f(void)}, ...}
	 *	[0] = 0x00061078 {FunctionSemantics.exe!Base::f(void)}
	 *	[1] = 0x000613f7 {FunctionSemantics.exe!Derive::`vector deleting destructor'(unsigned int)}
	 */
   pbase2->m_basei = 7;




system("pause");
return 1;
}
/*�ڴ沼�ּ�ͼ
 *���ۣ� ���������ڴ沼�ַǳ����ӣ�����Ҫ�����о�
 */