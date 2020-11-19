#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class Base
{
public:
	virtual void myVirtualFunction01() { cout << "myFunction01" << endl; }
	virtual void myVirtualFunction02() { cout << "myFunction02" << endl; }
	virtual void myVirtualFunction03() { cout << "myFunction03" << endl; }

};

class Derive :public Base
{
	//��д����myVirtualFunction02()����
	void myVirtualFunction02() override
	{
		cout << "����������д��myVirtualFunction02����" << endl;
	}
};

int main(void)
{
	typedef void(*Func)(void);//����һ������ָ������
	Derive derive01;
	long*pDe = (long*)(&derive01);
	long* VptrDerive = (long*)(*pDe);//����pDe�д洢�ľ����麯����ָ�롣0x005c8b78 {virtualFunction.exe!const Derive::`vftable'} {6034243}
	//long* VptrDerive = (long*)(derive01);//ʹ���������е�ԭ���ǲ���֮���һ��Derive����ת��Ϊָ��
	Func f1 = (Func)VptrDerive[0];//0x005c1343 {virtualFunction.exe!Base::myVirtualFunction01(void)}
	Func f2 = (Func)VptrDerive[1];//0x005c1217 {virtualFunction.exe!Derive::myVirtualFunction02(void)}
	Func f3 = (Func)VptrDerive[2];//0x005c1082 {virtualFunction.exe!Base::myVirtualFunction03(void)}
	Func f4 = (Func)VptrDerive[3];//0x00000000
	Func f5 = (Func)VptrDerive[4];

	Derive derive02 = derive01;//���ÿ������캯��
	long*pDe02 = (long*)(&derive02);
	long* VptrDerive02 = (long*)(*pDe02);
	//��������ָ������麯����

	Base base = derive01;//ʹ����������ำֵ
	long* pBase = (long*)(&base);
	long*vptrBase = (long*)(*pBase);//������麯����ָ��  0x00f7f9ac {6064948}
	Func fb1 = (Func)vptrBase[0];//0x005c1343 {virtualFunction.exe!Base::myVirtualFunction01(void)}
	Func fb2 = (Func)vptrBase[1];//0x005c116d {virtualFunction.exe!Base::myVirtualFunction02(void)}
	Func fb3 = (Func)vptrBase[2];//0x005c1082 {virtualFunction.exe!Base::myVirtualFunction03(void)}
	Func fb4 = (Func)vptrBase[3];//0x00000000
	Func fb5 = (Func)vptrBase[4];

	
	
	system("pause");
	return 0;
}
/*
* (1)
* ʹ����������ʼ��������󣬸��������麯����ֵ����������
* �и�
* ���������ڸ�����ǲ��ֻᱻ�������и���֣��������������������
* ����Base base = derive01;����2������
*	1.����һ��base����
*	2.ʹ��derive01����ʼ��base'���󣬱���������������һ��ѡ��derive01���麯��ָ��ֵ
*	��û�и���base����� �麯����ָ��ֵ����������������������һ�㡣
* (4)oo ��������ob���ڶ������
*	1.c++ͨ�����ָ�����������ʾ����������������֧�ֶ�̬������һ��������Ʒ��
*		���������˵���������object-oriented model
*	2.object-basedҲ��AD����������ģ�� abstract datatype model
*		��֧�ֶ�̬��û���麯������Ϊ�������õĽ�������Ҫ����ʱ�����������ٶȸ��졣
*		�����ڱ����ڼ�ͽ�������˺����ĵ��ã������ڴ�ռ���ӽ��գ���Ϊû���麯������麯����ָ�롣
*		����OB���������ԾͲ
*	c++��֧��������ֳ�����ƣ��̳У���̬����Ҳ֧�ֻ��ڶ��������ơ�
* (5) 
* (6)(7)
*/
