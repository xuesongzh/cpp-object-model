#include <iostream>
#include <stdio.h>
using namespace std;

class Base
{
public:
	int m_bi;
	virtual void mybvirfunc() {}
};

class MYACLS :public Base
{
public:
	int m_i;
	int m_j;

	virtual void myvirfunc() {} //�麯��
	MYACLS()
	{
		int abc = 1; //���д���û��ʵ������ ֻ�Ƿ���Ӷϵ�
		/*
		 *1.�����麯���� 2.�麯����ָ��ָ���麯����
		 00CE1853  mov         eax,dword ptr [this]  
			00CE1856  mov         dword ptr [eax],offset MYACLS::`vftable' (0CE7B34h)  
					int abc = 1; //���д���û��ʵ������ ֻ�Ƿ���Ӷϵ�
			00CE185C  mov         dword ptr [abc],1  
				}
			00CE1863  mov         eax,dword ptr [this]  
		 */
	}
	~MYACLS()
	{
		int def = 0;//����Ӷϵ�
	}
};

int main()
{




	cout << sizeof(MYACLS) << endl;//16
	printf("MYACLS::m_bi = %d\n", &MYACLS::m_bi);//4
	printf("MYACLS::m_i = %d\n", &MYACLS::m_i);//8
	printf("MYACLS::m_j = %d\n", &MYACLS::m_j);//12
	//Base�����麯��ʱ���� 4 8  12  û���麯����ʱ����0 8 12

	MYACLS myobj;//�������ϵ㣬�������캯�����鿴�������룬���Կ����麯����ָ��ָ���麯���Ĵ���
	myobj.m_i = 3;
	myobj.m_j = 6;//�鿴�ڴ棬�ҳ���Ӧ��ֵ
	myobj.m_bi = 9;
	/*						�麯����ָ��
	 0x00CFFDB0  cc cc cc cc 40 7b 98 00 09 00 00 00  ????@{?.....
	 0x00CFFDBC  03 00 00 00 06 00 00 00 cc cc cc cc  ........????
	 */


	system("pause");
	return 1;
}

/*4_6���൥�̳д��麯�������ݳ�Ա����
 * 	һ����������麯�������ݳ�Ա����
 * 	���������麯��ʱ�����ж���ĳɱ�����
 * 	(1)�����ʱ�򣬱�����������麯�����ο��������
 * 	(2)�����л���� �麯����ָ��vptr������ָ���麯����ģ�
 * 	(3)�������б������ڹ��캯����ʹ�麯����ָ��ָ���麯�������ӻ�����չ���캯�������Ӹ��麯����ָ��vptr��ֵ�Ĵ��룬��vptrָ���麯����
 * 	(4)������ؼ̳У�������̳���2�����࣬ÿ�����඼���麯���Ļ���ÿ�����඼����vptr���Ǽ̳�ʱ��
 * 		����ͻ��������vptr���̳й�����
 *		������໹���Լ�������麯���Ļ����������һ�����๲��һ��vptr�������Ľڣ���
 * 	(5)����������Ҳ����չ�������麯����ָ��vptr��صĸ�ֵ���룬�о������ֵ�����ƺ��͹��캯���д�����ͬ��

	������һ�̳и�����麯�������ݳ�Ա����--��ͼ

	������һ�̳и��಻���麯�������ݳ�Ա����
	�뵥һ�̳и�����麯�������ݳ�Ա����ͼ��ͬ
	����m_bi��ƫ��ֵ��0��ô��⣿��
	��Ϊm_bi��ƫ��ֵ�������Base���ƫ��ֵ��0��
 */
