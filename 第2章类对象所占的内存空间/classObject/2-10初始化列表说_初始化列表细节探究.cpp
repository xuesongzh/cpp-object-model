#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
	public:
	int test00;
	int test01;
	int test02;
	//3.��ʼ����Ա�б�ĳ�ʼ��˳���Ǳ�������˳��
	A(int a,int b):test01(a),test02(b),test00(test01)//���Ǵ���ģ����ն����˳���ֵ������test00��ֵ������test01,test02��ֵ
	{
		cout << "���캯��ִ��" << endl;
		cout << "test00="<<test00 << endl;
		cout << "test01=" << test01 << endl;
		cout << "test02=" << test02 << endl;
		
	}
};

int main(void)
{
	A(1, 2);
	/*
	    ���캯��ִ��
		test00=-858993460
		test01=1
		test02=2
	 */
	system("pause");
	return 0;
}
/*
* (1)��ʼ���б�ϸ��̽��
*	1.��Ա��ʼ���б��еĴ�����Կ����Ǳ����������嵽���캯���еĴ��룬ֻ����Щ������Щ���⡣
*	2.��Ա��ʼ���б�����Щ�����ִ��ʱ���������κ��û��Լ��Ĵ���ִ��֮ǰ��ִ�еģ������û�Ҫ�������������Ĵ�����û��Լ�д�Ĵ��롣
*		����������Ĵ�������ִ��
*	3.��ʼ����Ա�б�ĳ�ʼ��˳���Ǳ�������˳�򡣽��飺��Ҫ���ֳ�Ա�б����֮���໥��ֵ��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
