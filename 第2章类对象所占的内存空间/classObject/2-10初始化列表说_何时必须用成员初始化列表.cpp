#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
	int m_x;
	int m_y;
	A():m_x(0),m_y(0)//��ʼ���б�����ʹ�ã����Բ���
	{
		
	}	
};

//1.��Ա�����Ǹ�����
class B
{
public:
	int m_x;
	int m_y;
	int &m_value;
	const int myConst;
	B(int number01,int number02,int &temValue,int myc) :m_x(number01), m_y(number02),m_value(temValue),myConst(myc)//��ʼ���б�	{
	{
		
	}
};


class BASE
{
public:
	int ba;
	int bb;
	BASE(int a,int b):ba(a),bb(b)
	{
		;
	}
};

class SON :public BASE
{
public:
	int s;
	SON(int a,int b,int ss):BASE(a,b),s(ss)
	{
		;
	}
};


//4.���ĳ����Ա�����������ͣ����������Ա�����Ĺ��캯��������

class IncludeTest
{
public:
	BASE base01;
	int i;
	IncludeTest(int in, int a, int b) :i(in), base01(a, b)
	{
		;
	}
};
int main(void)
{
	//1.��Ա�����Ǹ�����
	int number01 = 12;
	int number02 = 23;
	B b(122,23,number01,23);//����һ������

	//3.������Ǽ̳�һ�����࣬���һ����еĹ��캯���в�����
	SON son01(1, 2, 3);


	//4.���ĳ����Ա�����������ͣ����������Ա�����Ĺ��캯��������
	IncludeTest it(23, 34, 45);
	system("pause");
	return 0;
}
/*
* (1)��ʱ�����ó�Ա��ʼ���б�
* ��û��ʲô���ϱ���ʹ�ó�Ա��ʼ���б�
*	1.��Ա�����Ǹ�����
*	2.�Ǹ�const���ͳ�Ա
*	3.������Ǽ̳�һ�����࣬���һ����еĹ��캯���в�����
*	4.���ĳ����Ա�����������ͣ����������Ա�����Ĺ��캯��������
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
