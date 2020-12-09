#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

class MYACLS
{
public:
	int m_i;
	void myfunc(int abc)
	{
		//m_i += abc; //������Ҫ�õ�thisָ�룬��thisָ��Ϊ�գ���ᱨ���쳣
		mystfunc();
	}
	
	virtual void myvirfunc()
	{
		printf("myvirfunc()������,this = %p\n", this);
		//myvirfunc2(); ��Ȼ���麯����ָ�����(�鿴�����)
		MYACLS::myvirfunc2(); //ֱ�ӵ����麯����Ч�ʸ��ߡ�����д��ѹ����������ƣ�����ͨ����ѯ�麯����������
							  //����������::�麯����()��ȷ�����麯���ķ�ʽ�ȼ���ֱ�ӵ���һ����ͨ������
	}
	
	virtual void myvirfunc2()
	{
		printf("myvirfunc2()������,this = %p\n", this);
	}

	//��̬��Ա����
	//static int m_si;
	static void mystfunc() //����Ҫthis����
	{
		printf("mystfunc()������\n");
		//m_si = 1;
	}
};

int main()
{
	//һ�����Ա�������麯�������÷�ʽ
	MYACLS myacls;
	myacls.myvirfunc(); //�ö�������麯�������������ͨ��Ա����һ��(��������),����Ҫͨ���麯����

	MYACLS *pmyacls = new MYACLS();
	pmyacls->myvirfunc(); //Ҫͨ���麯����ָ������麯����ͨ���麯�����ںõ��麯������ڵ�ַ����ɶ��麯���ĵ���

	/*�������ӽ�
	 (*pmyacls->vptr[0])(pmyacls);
	 *a)vptr�������������ɵ��麯����ָ�룬ָ���麯����
	 *b)[0] �麯�����е�һ�����myvirfunc()��ַ
	 *c)����һ��������ȥ������this��Ҳ�Ǳ��������ӵ�
	 *d)*�͵õ����麯���ĵ�ַ��
	 �ܽ᣺���Ա����Ҳ��һ���̶����ڴ��ַ���ڱ����ʱ����Ѿ�ȷ����ͨ������ֱ�ӵ����麯�����ǲ�ͨ���麯����
		ͨ��ָ��������õ����麯�������麯����
	 */

	printf("MYACLS::myvirfunc2�麯���ĵ�ַΪ%p\n", &MYACLS::myvirfunc2);
	/*
		myvirfunc()������,this = 00EFFC90
		myvirfunc2()������,this = 00EFFC90
		myvirfunc()������,this = 010E4AB8
		myvirfunc2()������,this = 010E4AB8
		MYACLS::myvirfunc2�麯���ĵ�ַΪ00301415
	 */


	//������̬��Ա�������÷�ʽ
	cout << "--------------------" << endl;
	//ͨ�����󣬶���ָ�룬�������þ�̬��Ա������
	myacls.mystfunc();
	pmyacls->mystfunc();
	MYACLS::mystfunc();

	//���������У�
	//_ZN6MYACLS8mystfuncEv();
	//_ZN6MYACLS8mystfuncEv();
	//_ZN6MYACLS8mystfuncEv();

	/*��Ҫ��
	 *(1)�ѽṹ��Ԫ��MYACLS���ڴ���䷽ʽӳ�䵽�ڴ�λ0��λ��
	 *(2)((MYACLS *)0)����MYACLS�����ͽ���0��ʼ���ڴ�ռ�����ݡ�0���� pmyacls-pmyacls���ƶ���0��ַ�ռ�
	 */
	((MYACLS *)0)->mystfunc();  //�ܹ��������þ�̬��Ա��������Ϊ����Ҫ����thisָ�룬�������κηǾ�̬��Ա������������Ҫthisָ�롣
	cout << "*******************" << endl;
	//((MYACLS *)0)->myfunc(12);  //���myfunc()�������治�Գ�Ա�������в�����Ҳ���ǲ���thisָ�룬���Ե��á�
	//Ϊʲô��Ƴ���ô��ֵķ�������--��Щ��Ա����ϣ��֧�ֶ����������֮��Ĵ�ȡ������

	myacls.myfunc(12);
	pmyacls->myfunc(12);

	/*���ۣ�
	 *��̬��Ա��������
	 *a)��̬��Ա����û��thisָ�룬�������Ҫ
	 *b)�޷�ֱ�Ӵ�ȡ������ͨ�ķǾ�̬��Ա��������̬��Ա����ͨ��thisָ���ȡ��
	 *c)��̬��Ա����������ƨ�ɺ�ʹ��const��Ҳ��������Ϊvirtual
	 *d)�������������ã�������һ��Ҫ���������á�����ʹ������������ָ�룬�����֣������á�
	 *e)��̬��Ա������ͬ�ڷǳ�Ա�������е���Ҫ�ṩ�ص����������ֳ��ϣ����Խ���̬��Ա������Ϊ�ص�������
	 */

	printf("MYACLS::mystfunc()��ַ = %p\n", MYACLS::mystfunc);
	/*
	 mystfunc()������
	 mystfunc()������
	 MYACLS::mystfunc()��ַ = 00FA122B
	 */



	delete pmyacls;
	system("pause");
	return 1;
}
