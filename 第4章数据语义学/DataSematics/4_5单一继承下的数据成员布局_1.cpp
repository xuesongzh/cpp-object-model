#include <iostream>
#include <stdio.h>
using namespace std;

class FAC //����
{
public:
	int m_fai;
	int m_faj;
};
class MYACLS :public FAC //����
{
public:
	int m_i;
	int m_j;
};

class Base //sizeof = 8�ֽڣ�
{
public:
	int m_i1;
	char m_c1;
	char m_c2;
	char m_c3;
};


int main()
{
	//�����  4-5��һ�̳��µ����ݳ�Ա����
	//�鿴ƫ��ֵ
	printf("FAC::m_fai = %d\n", &FAC::m_fai);//0
	printf("FAC::m_faj = %d\n", &FAC::m_faj);//4

	printf("MYACLS::m_fai = %d\n", &MYACLS::m_fai);//0
	printf("MYACLS::m_faj = %d\n", &MYACLS::m_faj);//4
	
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);//8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);//12
	/*
	    FAC::m_fai = 0
		FAC::m_faj = 4
		MYACLS::m_fai = 0
		MYACLS::m_faj = 4
		MYACLS::m_i = 8
		MYACLS::m_j = 12
	�ܽ᣺
		(1)һ��������������������ݣ������Լ��ĳ�Ա������������ĳ�Ա���ܺͣ�
		(2)��ƫ��ֵ���������Ա�ȳ��֣�Ȼ����Ǻ������Ա�������Ա���ϣ������Ա����
	 */
	
	FAC facobj;//����FAC���󲼾�
	MYACLS myaclobj; //���������ʵ�����ǰ����Ÿ����Ӷ����--�鿴���ݲ���ͼ

	//�����ڴ����ʱ���ƫ����
	cout << "---------------------------------" << endl;
	cout << sizeof(Base) << endl;   //8�ֽڣ����ݲ��֣��ڴ������ϣ����գ�
	printf("Base::m_i1 = %d\n", &Base::m_i1);//0
	printf("Base::m_c1 = %d\n", &Base::m_c1);//4
	printf("Base::m_c2 = %d\n", &Base::m_c2);//5
	printf("Base::m_c3 = %d\n", &Base::m_c3);//6
	/*
	 8
	Base::m_i1 = 0
	Base::m_c1 = 4
	Base::m_c2 = 5
	Base::m_c3 = 6
	 */

	system("pause");
	return 0;
}

/*
 * ���ۣ�1.���������������������ݳ�Ա
 * 2.���г�Ա�������Զ������ڴ����
 * 2019��12��15��17��18��
 */
