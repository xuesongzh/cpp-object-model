#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


//����5_10_3vcall�ڼ̳й�ϵ�е�����_�Ǹ�ƫ��ֵ�������������ƫ��ֵ��ͬ
class A
{
public:
	virtual void myvirfunc(int tempvalue)
	{
		cout << "A::myvirfunc()���Ա����--tempvalue = " << tempvalue << endl;
	}
	//����������
	virtual ~A()
	{

	}
};

class B :public A
{
public:
	virtual void myvirfunc(int tempvalue)
	{
		cout << "B::myvirfunc()���Ա����--tempvalue = " << tempvalue << endl;
	}
	
	virtual ~B() {}
};

void func()
{
	B *pmyb = new B();   //pmyb������ָ��
	void (B::*pmyvirfunc)(int) = &A::myvirfunc; //��Ա����ָ��
	//void (B::*pmyvirfunc)(int) = &B::myvirfunc; //��Ա����ָ��
	/*
	 *   A::myvirfunc;--��¼����һ��vcall��ַ,ʵ���ϼ�¼����һ��ƫ�ƣ���B::myvirfunc�����ƫ��ֵһ��

	 */

	(pmyb->*pmyvirfunc)(190);

	printf("%p\n", &A::myvirfunc); //A��vcall��ַ ���¸�vcall��ַ��һ�����������汣���ƫ������ͬ����
	printf("%p\n", &B::myvirfunc); //B��vcall��ַ
}


int main()
{
	func();
	system("pause");
	return 1;
}



