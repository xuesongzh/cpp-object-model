#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class Base01
{
public:
	virtual void myVirtulFunction01()
	{
		cout << "Base01 myVirtualFunction01()" << endl;
	}
	virtual void myVirtulFunction02()
	{
		cout << "Base01 myVirtualFunction02()" << endl;
	}	
};


class Base02
{
public:
	virtual void myVirtulFunction03()
	{
		cout << "Base02 myVirtualFunction03()" << endl;
	}
	virtual void myVirtulFunction04()
	{
		cout << "Base02 myVirtualFunction04()" << endl;
	}
};

//����
class Derived:public Base01,public Base02
{
public:
	//���Ǹ���1���麯��
	virtual  void myVirtulFunction02() override
	{
		cout << "Derive myVirtualFunction02()" << endl;
	}
	
	//���Ǹ���2���麯��
	virtual void myVirtulFunction04() override
	{
		cout << "Derive myVirtualFunction04()" << endl;
	}
	
	//������麯��
	
	virtual void deriveVirtulFunction05()
	{
		cout << "DeriveVirtualFunction05()" << endl;
		
	}
	
	virtual void deriveVirtulFunction06()
	{
		cout << "DeriveVirtualFunction06()" << endl;

	}
};

int main(void)
{
	cout << sizeof(Base01) << endl;//4
	cout << sizeof(Base02) << endl;//4
	cout << sizeof(Derived) << endl;//8--�������麯����ָ��

	Derived derived01;
	Base01 &b1 = derived01;
	Base02 &b2 = derived01;
	Derived &d02 = derived01;

	typedef void(*Func)(void);
	long*pder = (long*)(&derived01);
	long*vptr01 = (long*)(*pder);//��ȡ�������ĵ�һ��pterָ��
	//long*vptr01 = reinterpret_cast<long*>(derived01);//error,����ǿ������ת������
	
	long*pder02 = pder + 1;//����4���ֽڣ����ǵڶ����麯����ָ��
	long*vptr02 = (long*)(*pder02);//��ȡ�������ĵڶ���pterָ��

	Func f1 = (Func)vptr01[0];//0x004c123a {virtualFunction.exe!Base01::myVirtulFunction01(void)}
	Func f2 = (Func)vptr01[1];//0x004c13d9 {virtualFunction.exe!Derived::myVirtulFunction02(void)}
	Func f3 = (Func)vptr01[2];//0x004c10cd {virtualFunction.exe!Derived::deriveVirtulFunction05(void)}
	Func f4 = (Func)vptr01[3];//0x004c11ae {virtualFunction.exe!Derived::deriveVirtulFunction06(void)}
	Func f5 = (Func)vptr01[4];//0x00000000
	Func f6 = (Func)vptr01[5];
	Func f7 = (Func)vptr01[6];
	Func f8 = (Func)vptr01[7];

	//�ڶ��麯����ָ��
	Func f21 = (Func)vptr02[0];//0x004c11b3 {virtualFunction.exe!Base02::myVirtulFunction03(void)}
	Func f22 = (Func)vptr02[1];//0x004c1433 {virtualFunction.exe!Derived::myVirtulFunction04(void)}
	Func f23 = (Func)vptr02[2];//0x00000000
	Func f24 = (Func)vptr02[3];

	b1.myVirtulFunction02();//�������ຯ��
	b2.myVirtulFunction04();//�������ຯ��
	d02.myVirtulFunction02();//�������ຯ��

	cout << "1111111111111111111111111" << endl;
	f1();
	f2();
	f3();
	f4();
	cout << "222222222222222222" << endl;
	f21();
	f22();
	
	system("pause");
	return 0;
}
/*
* (1)���ؼ̳��麯�������
*	1.һ������������ж�����������ж���麯����ָ��(ע���������麯����ָ�룬���������麯����)
*	2.�ڶ�̳��У���Ӧ��������vptrָ�밴�ռ̳�˳�����η���������ڴ�ռ��С�
*		���������һ�����๫��һ��vptr���ڶ����������Լ���vptrָ�롣
*	3.ʾ��ͼ�ʺ�vs2017����һ���ʺ�g++��������
*	�ܽ᣺
*		1.�������derived01�������麯����ָ�룬vptr01,vptr02.
*		2.��Derived�������麯������Ϊ���̳����������ࡣ
*		3.����͵�һ�����๲����һ��vptr����Ϊvptrָ���һ���麯��������Ҳ����˵����͵�һ�����๲��һ��vptr��
*		��Ϊ����ע�⵽��Derived���麯����1�����4����������Base01�ĺ�����
*		4.������麯�������˸����е�ͬ���麯����
*		
*		
* (2)�ܽ᣺�麯������������ģ��麯����ָ�������ڶ���ġ�
* һ������麯��������ж��������һ���������麯����ָ��Ҳ�����ж����
* (3)
* (4)
* (5)
* (6)(7)
*/
