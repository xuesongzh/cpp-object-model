#include<iostream>

using namespace std;

//���ܱ��̳е���
class A
{
private:
	A(){}
	friend class B;//����ϣ����B�ܳ�Ϊһ�����ܱ��̳е���
};

class B:virtual public A//��C::C(void)�� : ����������ɾ���ĺ���
//class B : public A//��C::C(void)�� : ����������ɾ���ĺ���	

{
public:
	int m_b;
};

//class C:public B
class C :public B
{
public:
	int m_c;
};
void myFunction01()
{
	//A obj_a;//A�Ĺ��캯����˽�еģ�error
	B obj_b;//B��Ĺ��캯��ȥ����A��Ĺ��캯����B��A�����Ԫ��
	obj_b.m_b = 12;
	//C obj_c;
	//obj_c.m_c = 20;

	/*
	 * ���B������̳�A��C����B�Ĺ��캯����B����A�Ĺ��캯����
	 * ���B��̳���A����ôA��Ĺ��캯��ʱC�������������ã���C���ܵ���A��private���캯�����ᱨ��
	 */
	
}

int main(void)
{

	system("pause");
	return 0;
}
/*
 * 1.7_2_1���ܱ��̳е���
 *		c++11�е�final�ؼ��֣�������ùؼ�����ô���಻�ܱ��̳У���
 *		��Ԫ����+��̳�ʵ�ֲ��ܱ��̳е���
 *		�����ã���Ԫ�����ƻ���ķ�װ�ԣ���̳����ıȽϴ�
 */