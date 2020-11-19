#include <iostream>
#include <stdio.h>
using namespace std;

class Base1
{
public:
	int m_bi;
	virtual void mybvirfunc() {}

	Base1()
	{
		printf("Base1::Base1()��thisָ���ǣ�%p!\n", this);
	}
};
class Base2
{
public:
	int m_b2i;
	virtual void mybvirfunc2() {}

	Base2()
	{
		printf("Base2::Base2()��thisָ���ǣ�%p!\n", this);
	}
};
class MYACLS :public Base1, public Base2
{
public:
	int m_i;
	int m_j;

	virtual void myvirfunc() {} //�麯��
	MYACLS()
	{
		int abc = 1; //����Ӷϵ�
		printf("MYACLS::MYACLS()��thisָ���ǣ�%p!\n", this);
	}
	~MYACLS()
	{
		int def = 0;//����Ӷϵ�
	}
};
int main()
{
	
	/*
	 *����4_7���ؼ̳��Ҹ��඼���麯�������ݳ�Ա����02
	 ��1��ͨ��thisָ���ӡ�����ǿ�������Base1��Ա������ ������Base2��ԱҪthisָ��Ҫƫ�ƣ�������8�ֽڣ�
	 ��2�����ǿ���ƫ��ֵ��m_bi��m_b2iƫ�ƶ���4��
	 ��3��ÿ������thisָ�룬����ƫ��ֵ �͵��ܹ����ʶ�Ӧ�ĳ�Ա����������m_b2i = thisָ��+ƫ��ֵ

	 //����ѧϰ�õ�һ�����ۣ�
	 //����Ҫ����һ��������еĳ�Ա����Ա�Ķ�λ��ͨ����thisָ�루���������Զ��������Լ��ó�Ա��ƫ��ֵ�����������������壻
	 //����thisָ��ƫ�Ƶĵ��� ����Ҫ������������������ɣ�
	 */

	cout << sizeof(MYACLS) << endl;
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
	printf("MYACLS::m_b2i = %d\n", &MYACLS::m_b2i);
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

	MYACLS myobj;
	myobj.m_i = 3;
	myobj.m_j = 6;
	myobj.m_bi = 9;
	myobj.m_b2i = 12;


	MYACLS *pmyobj = new MYACLS();
	pmyobj->m_i = 3;
	pmyobj->m_j = 6;
	pmyobj->m_bi = 9;
	pmyobj->m_b2i = 12;
	/*
		 24
		MYACLS::m_bi = 4--����ڸ���Base01��ƫ���������麯����ָ��
		MYACLS::m_b2i = 4--����ڸ���Base01��ƫ���������麯����ָ��
		MYACLS::m_i = 16
		MYACLS::m_j = 20
		Base1::Base1()��thisָ���ǣ�00EFF854!--��������ͬ
		Base2::Base2()��thisָ���ǣ�00EFF85C!	+8�ֽڣ����ܷ��ʵ�
		MYACLS::MYACLS()��thisָ���ǣ�00EFF854!
	
		Base1::Base1()��thisָ���ǣ�010CFD00!
		Base2::Base2()��thisָ���ǣ�010CFD08!
		MYACLS::MYACLS()��thisָ���ǣ�010CFD00!
	��ϸ��ͼ
	 */

	//������룺base2ֵָ��������������base1ָ��������󲻵���
	Base2 *pbase2 = &myobj; //thisָ���������pbase2ʵ������ǰ��8���ֽڵ��ڴ�λ�õ�
	//myobj = 0x0093fad0������������Ժ�pbase2 = 0x0093fad8
	//վ�ڱ������ӽǣ����ϱ������������˵���
	////Base2 *pbase2 = (Base2 *)(((char *)&myobj) + sizeof(Base1));
	Base1 *pbase1 = &myobj; //Base1����������thisָ�벻�õ��������￴�ڴ��ַ���Կ���

	//����2����ʹ����������ڴ棬ʹ�ø���ָ����գ�Ȼ��ת��Ϊ��������ͷŻᱨ��ʹ�ø�����յ�ʱ������ָ�����
	Base2 *pbase3 = new MYACLS(); //����ָ��new������� ������new��������24�ֽ�
	MYACLS *psubobj = (MYACLS *)pbase2; //���ϱߵ�ַ����8�ֽڣ�ƫ�ƣ�
	//delete pbase3; //���쳣������������Ϊpbase2��߷��صĵ�ַ���Ƿ�����׵�ַ������ƫ�ƺ��ַ��
	          //������������׵�ַӦ������psubobj��ߵ������ַ
	//delete psubobj;

	system("pause");
	return 1;
}
