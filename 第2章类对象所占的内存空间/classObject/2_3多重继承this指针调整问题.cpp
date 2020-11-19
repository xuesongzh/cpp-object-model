#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
	int a;
	A()
	{
		printf("A::A()��thisָ����%p\n", this);
	}

	void myFunctionA()
	{
		printf("A::myFunctionA��thisָ����%p\n", this);

	}
};

class B
{
public:
	int b;
	B()
	{
		printf("B::B()��thisָ����%p\n", this);
	}

	void myFunctionB()
	{
		printf("B::myFunctionB��thisָ����%p\n", this);

	}
};

class C:public A,public B
{
public:
	int c;
	C()
	{
		printf("C::C()��thisָ����%p\n", this);
	}

	void myFunctionC()
	{
		printf("C::myFunctionC��thisָ����%p\n", this);

	}
	//��д�ĺ���

	void myFunctionB()
	{
		printf("C::myFunctionB��thisָ����%p\n", this);

	}
};
int main(void)
{
	cout << sizeof(A) << endl;//4
	cout << sizeof(B) << endl;//4
	cout << sizeof(C) << endl;//12

	C obj_c;
	obj_c.myFunctionA();
	obj_c.myFunctionB();//����������д�ĺ���
	obj_c.B::myFunctionB();//���ø���ĺ���
	obj_c.myFunctionC();
	/*
	A::A()��thisָ����006FF904
	B::B()��thisָ����006FF908
	C::C()��thisָ����006FF904
	A::myFunctionA��thisָ����006FF904
	C::myFunctionB��thisָ����006FF904
	B::myFunctionB��thisָ����006FF908
	C::myFunctionC��thisָ����006FF904
	A B C�Ĺ��캯�������ȸ�������࣬�����ռ̳�˳��ִ�С�
	��A����C�õ�ָ��ָ��ͬһ����ַ����B����4���ֽڡ�

	����������ǰ���������Ӷ���
	���������ֻ��һ������̳У���ô������������ĵ�ַ�ͻ����Ӷ���ĵ�ַ��ͬ��
	������������ͬʱ�̳ж�����࣬��һ�������Ӷ���Ŀ�ʼ��ַ�����������Ŀ�ʼ��ַ��ͬ��
	�����Ļ����Ӷ���Ŀ�ʼ��ַ���������Ӷ������٣���
	��ǰ�ߵĻ������ռ�е��ڴ�ռ䣬����A��ռ��4���ֽ��ڴ�ռ䣬���Ի���A�ͻ���B�� 4���ֽ��ڴ�ռ�

	�������obj_c.myFunctionA()  obj_c.myFunctionC()ʹ��001EFCE4���ָ�룬
	����obj_c.myFunctionB()������B�ĺ���;ϵͳ�����thisָ�룬ʹthisָ������4���ֽڡ�
	�����C������д��B���myFunctionB()������thisָ����ñ��������õ�����
	�ܽ᣺������ĸ�����ĳ�Ա������thisָ��ͻᱻ�������Զ������������ڴ沼���ж�Ӧ�������ʼ��ַ��
	 */
	

	system("pause");
	return 0;
}
/*
* (1)thisָ�����
* һ������ڶ��ؼ̳���
* (2)
*/
