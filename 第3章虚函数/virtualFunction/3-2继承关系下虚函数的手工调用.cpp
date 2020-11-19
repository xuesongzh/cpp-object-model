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

class Derive:public Base
{
	//��д����myVirtualFunction02()����
	void myVirtualFunction02() override
	{
		cout << "����������д��myVirtualFunction02����" << endl;
	}
};

int main(void)
{
	cout << sizeof(Base) << endl;//4
	cout << sizeof(Derive) << endl;//4

	Derive *pderive01 = new Derive();//����ָ��
	long*pvptr = (long*)pderive01;//��ָ����������ָ��ת��Ϊlong*����
	long*vptr = (long*)(*pvptr);//(*pvptrָ��Ķ�����Ҳ����Deriv������)--
	//Derive��������ռ��4���ֽڵģ�����洢�����麯�����ַ   vptrָ���������麯����
	/*
	 pderive01	0x01534be0 {...}	Derive *
	 pvptr	0x01534be0 {7445368}	long *
	 vptr	0x00719b78(ֵΪ7445368) {virtualFunction.exe!const Derive::`vftable'} {7410594}	long *
	 */

	//����Ԥ���麯��������洢��3�3���麯��
	for (int i=0;i<5;i++)
	{
		printf("vptr[%d]=0x:%p\n", i, vptr[i]);
	}
	/*
	 *  vptr[0]=0x:00C513A2
		vptr[1]=0x:00C51258
		vptr[2]=0x:00C5108C
		vptr[3]=0x:00000000
		vptr[4]=0x:C7CAE2D5
	 */
	//���Ե����麯��
	typedef void(*Func)(void);//����һ������ָ������
	Func f1 = (Func)vptr[0];//vptr[0]��ָ���һ���麯��
	Func f2 = (Func)vptr[1];//vptr[0]��ָ��ڶ����麯��
	Func f3 = (Func)vptr[2];//vptr[0]��ָ��������麯��
	Func f4 = (Func)vptr[3];//vptr[0]��ָ���һ���麯��
	Func f5 = (Func)vptr[4];//vptr[0]��ָ���һ���麯��

	f1();
	f2();
	f3();
	//f4();//���쳣
	/*
	 myFunction01
	����������д��myVirtualFunction02����
	myFunction03
	 */

	Base *base01 = new Base();
	long*pbase = (long*)base01;
	long*vptrBase = (long*)(*pbase);//base01ָ��ָ����ڴ�ռ��д洢�ľ����麯����
	for (int i=0;i<3;i++)
	{
		printf("vptrBase[%d]=0x:%p\n", i, vptrBase[i]);
	}
	/*
	 *  vptrBase[0]=0x:009913A2
		vptrBase[1]=0x:0099119F
		vptrBase[2]=0x:0099108C
	 */
	Func fb1 = (Func)vptrBase[0];
	Func fb2 = (Func)vptrBase[1];
	Func fb3 = (Func)vptrBase[2];

	fb1();
	fb2();
	fb3();
	/*
	myFunction01
	myFunction02
	myFunction03
	*/
	
	
	system("pause");
	return 0;
}
/*
* (1)�̳й�ϵ���麯�����ֹ�����
*	��һ�����ж����麯�����͵ĳ�Ա��������ô�����ָ��ָ����ڴ�ռ䶼�����������麯����ġ�
*	�麯������Կ���һ�����飬����ʹ��[]�±���ʷ������ʡ��Ϳ���ʹ�ú��������������麯����������麯��
* (2)
*	1.һ����ֻ�а����麯���Ż�����麯����ͬ��һ����Ķ������麯�����������Լ����麯����ָ��
*	2.���������麯���������п϶����麯�������仰˵�����������麯�������������麯������Ϊ����̳и��ࡣ
*		2.1Ҳ������Ϊ�����������麯������������overwrite�ĺ�����д��дvirtual��Ȼ���麯����
*		2.2���ǲ��ܸ��໹�����࣬���ֱ���һ���麯����������Ϊ������һ���麯����+�����м̳е��麯����=������2���麯����
*		���ุ��ֱ�һ���麯����
*		2.3�������Ƿ���ܴ��ڶ���麯������ ���潲�⡣
*	3.���������ȫû���µ��麯���������ǿ�����Ϊ������麯����͸�����麯����������ͬ��
*		������������ͬ���������ڴ��д��ڲ�ͬλ�á����仰˵������������ͬ�����ű�
*		����ڴ�λ�úͱ��д洢�������ǲ�ͬ�ĸ��
*		3.2�麯������ÿһ�����һ���麯�����׵�ַ���������������麯����ĳ��͸����麯����ĳ���ʾͬһ��������
*			������û�и��Ǹ���ĺ���������ñ�������ʾ���麯����ַӦ����ͬ��
*
*	4.�����麯���������ݲ���֪������麯���м����Ϳ���ʹ�����鷽ʽ���ʼ�����
*		
* (4)
* (5)
* (6)(7)
*/
