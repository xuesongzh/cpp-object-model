#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
public:
	int m_bi;
	virtual void mybvirfunc() {}

	Base()
	{
		printf("Base1::Base1()��thisָ���ǣ�%p!\n", this);
	}
};

class MYACLS :public Base
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
	 * 	//һ��4_7��һ�̳����ݳ�Ա����thisָ��ƫ��֪ʶ����01
	 * ����������麯����thisָ�벻��Ҫ������
	 */

	cout << sizeof(MYACLS) << endl;
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);

	MYACLS myobj;
	myobj.m_i = 3;
	myobj.m_j = 6;
	myobj.m_bi = 9;


	MYACLS *pmyobj = new MYACLS();
	pmyobj->m_i = 3;
	pmyobj->m_j = 6;
	pmyobj->m_bi = 9;

	
	 	/*
	 ����Base�಻���麯����
	16
	MYACLS::m_bi = 0--����ڸ���ƫ��Ϊ0
	MYACLS::m_i = 8
	MYACLS::m_j = 12
	Base1::Base1()��thisָ���ǣ�00AFFE4C!
	MYACLS::MYACLS()��thisָ���ǣ�00AFFE48!
	Base1::Base1()��thisָ���ǣ�00BF522C!
	MYACLS::MYACLS()��thisָ���ǣ�00BF5228!  ����ָ��ȸ���ָ��С4���ֽ�  ����this+4=����this

	 ����Base����麯����
	16
	MYACLS::m_bi = 4--������麯����ָ��
	MYACLS::m_i = 8
	MYACLS::m_j = 12
	Base1::Base1()��thisָ���ǣ�00AFF880!
	MYACLS::MYACLS()��thisָ���ǣ�00AFF880!
	Base1::Base1()��thisָ���ǣ�00D8CE98!
	MYACLS::MYACLS()��thisָ���ǣ�00D8CE98! ---����ָ��͸���ָ��ͬ����--thisָ����ʸ����Ա��������Ҫ����
		
	 */
	
	system("pause");
	return 1;
}
