
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


	/*
	 *һ��ָ���Ա������ָ��
	 *��Ա������ַ������ʱ��ȷ���õġ����ǣ����ó�Ա����������Ҫͨ�����������õģ�
	 *���г��棨�Ǿ�̬����Ա������Ҫ����ã�����Ҫ һ����������������
	 *
	 *���Ա�����Ǳ����ڴ�����������ľ�̬��Ա�������ඨ��ʱ���Ѿ���ȫ���������������ڴ棬
	 �������������ġ����ڷǾ�̬��Ա�����������������ʵ����������(�������)����ջ�����߶���Ϊ������ڴ棬
	��Ϊÿ����������һ�������������������ڶ���ġ�
	 */

class A
{
public:
	void myfunc1(int tempvalue1)
	{
		cout << "tempvalue1 = " << tempvalue1 << endl;
	}
	void myfunc2(int tempvalue2)
	{
		cout << "tempvalue2 = " << tempvalue2 << endl;
	}

	static void mysfunc(int tempvalue)
	{
		cout << "A::mysfunc()��̬��Ա����--tempvalue = " << tempvalue << endl;
	}
};

void func()
{
	A mya;
	void (A::*pmypoint)(int) = &A::myfunc1; //����һ����Ա����ָ�벢����ֵ
	pmypoint = &A::myfunc2; //����Ա����ָ�븳ֵ

	(mya.*pmypoint)(15); //ͨ����Ա����ָ�������ó�Ա����������Ҫͨ������Ľ�����ܵ���

	A *pmya = new A();
	(pmya->*pmypoint)(20); //�ö���ָ�������ʹ�ó�Ա����ָ�� �����ó�Ա����

   //�������ӽ�
   //pmypoint(&mya, 15);
   //pmypoint(pmya, 20);

	//��̬����ָ�������ͨ�ĺ���ָ��
	void(*pmyspoint)(int) = &A::mysfunc; //һ����ͨ�ĺ���ָ�룬�����ǳ�Ա����ָ��
	pmyspoint(80);

	//ͨ����Ա����ָ��Գ���ĳ�Ա�������õĳɱ�����ͨ����ͨ�ĺ���ָ�������þ�̬��Ա�������ɱ��ϲ�ࣻ


}


int main()
{
	func();
	
	system("pause");
	return 1;
}

/*
    tempvalue2 = 15
	tempvalue2 = 20
	A::mysfunc()��̬��Ա����--tempvalue = 80
	�밴���������. . .

 */


