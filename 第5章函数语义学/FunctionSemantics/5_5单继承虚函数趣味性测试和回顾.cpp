#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Base
{
public:
	virtual void f() { cout << "Base::f()" << endl; }
	virtual void g() { cout << "Base::g()" << endl; }
	virtual void h() { cout << "Base::h()" << endl; }
	//virtual void pvfunc() = 0;
};

class Derive :public Base {
public:
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }//��д
	//void myselffunc() {} //ֻ����Derive�ĺ���
};
int main()
{
	//һ�����̳��µ��麯��
	Derive myderive;
	Derive *pmyderive = &myderive;
	pmyderive->f();
	pmyderive->g();
	pmyderive->h();
	pmyderive->i();
	//�鿴�������룬���Կ��������������麯���ڴ�ֲ��Ǻ͸���һ����Ȼ���i()�麯��������������ڴ�����档
	
	Base *pb = new Derive();  //����ָ�� ָ��һ���������
	pb->g();
	//�������ӽ�
	//(*pb->vptr[1])(pb);//�麯����������һ��thisָ�룬���ﴫ�ݹ�ȥpb

	Derive myderive02;
	Base &yb = myderive02; //�������� ���� һ���������
	yb.g();

	//����Ψһ��Ҫ��ִ���ڼ�֪���Ķ������� ͨ�� �ĸ��麯����(�����麯����������麯����)�������麯����������Ļ��������);
	//���ۣ������ߵ�������麯����

	/*
	 *�����ع˺�һЩС����
	 *�麯����ַ�������ڼ�֪��,д���˿�ִ���ļ���,�����ڼ��Ѿ�����������
	 *vptr�����ڼ�������������ڹ��캯���в����˸�vptr��ֵ�Ĵ��룻����������ʱ����ΪҪִ�ж���Ĺ��캯������ʱvptr�ͱ���ֵ��
	 */

	Derive a1;
	Derive a2;//��Derive�ﶼ���麯����ʱ��a1��a2�洢������Ӧ������ͬ�ģ��洢�Ķ����麯����ĵ�ַ
	//0x003c9b80 {FunctionSemantics.exe!const Derive::`vftable'} {0x003c14ab {FunctionSemantics.exe!Base::f(void)}, ...}
	Derive *pa3 = new Derive();


	Base b1;//������û���κγ�Ա�����ͺ�����������Ȼ���Լ����麯����

	
	//���ۣ����麯��Ҳ���麯�����С�
	cout << sizeof(Base) << endl;//ע�͵�����Base�������麯����ֻ�������麯����4

	system("pause");
	return 1;
}
