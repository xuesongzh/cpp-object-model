#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

/*
 * һ���ֲ���̬����Ĺ��������
 *	a)������ǲ�����myfunc()��������ô�������ᴥ��A�Ĺ��캯����
 *	b)�ֲ���̬�����ڴ��ַ���ڱ����ڼ��ȷ���õģ�
 *	c)��̬�ֲ����տ�ʼҲ����ʼ��Ϊ0��
 *	d)�ֲ���̬���������������main����ִ�н�����ű����õġ���ǰ���������̬�ֲ����󱻹������
 *
 *���ۣ� �ֲ���̬����ֻ�ᱻ����һ�Σ��ڵ��õ�ʱ���죻��main����ִ����Ϻ�����
 *
 *	
 */


class A
{
public:
	A()
	{
		cout << "A::A()" << endl;
	}
	~A()
	{
		cout << "A::~A()" << endl;
	}
	int m_i;
};

//void myfunc()
const A &myfunc()
{
	//�ֲ���̬����
	static A s_aobj1; //����myfunc()���������ü��Σ�s_aobj1���־�̬�ֲ�����ֻ�ᱻ����1�Σ�ֻ����һ�ι��캯����������ͨ������һ��������ж��Ƿ��������
	//static A s_aobj2;
	printf("s_aobj1�ĵ�ַ��%p\n", &s_aobj1);
	//printf("s_aobj2�ĵ�ַ��%p\n", &s_aobj2);
	return s_aobj1;
}

void func()
{	myfunc();
	myfunc();
}

int main()
{
	
	func();

	system("pause");
	return 1;
}

/*
A::A()
s_aobj1�ĵ�ַ��008AD14C
s_aobj1�ĵ�ַ��008AD14C
�밴���������. . .

 */


