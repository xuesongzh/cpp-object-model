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

	virtual ~Base()
	{
		int abc;
		abc = 1;
	}

};

class Base2
{
public:
	virtual void hBase2() {

		cout << "Base2::hBase2()" << endl;
	}

	virtual ~Base2() {
		int abc;
		abc = 1;
	}
};

class Derive :public Base, public Base2
{
public:
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //ֻ����Derive�ĺ���

	virtual ~Derive()
	{
		int abc;
		abc = 1;//������Ϊ�˵��Է��㣬���������
	}
};
int main()
{
	//һ����̳��µ��麯��
	//���ؼ̳и����������ں�����������,����thisָ�����������--����Base1��thisָ�벻��Ҫ������Base2��thisָ����Ҫ����
	Base2 *pb2 = new Derive();//pb2ָ��ĵ�ַ�Ǿ���thisָ�������ĵ�ַ��pb2��ָ��Base2 ������е��Ӷ��󣬲���ָ���Ӷ���ʼλ�á�
	//�������ӽ�
	//Derive *temp = new Derive();
	//Base2 *pb2 = temp + sizeof(Base); // tem���;�������Ӷ��٣�ʵ������sizeof(Base) * sizeoeof(Base2);//����Base������Base2����ȼ�������
	//Base2 *pb2 = (Base2 *)((char *)temp + sizeof(Base));
	//double���ͱ���+1��ʵ������8���ֽ�

	delete pb2;//ʹ�õ������thisָ��ɾ���ڴ�ռ䱨�쳣����ν��������Derive�������������һ��������������


	/*
	 *������γɹ�ɾ���õڶ�����ָ��new�����ļ̳������--��Derive�������������һ��������������(������Base2��Base1��������������)
	 *a)����Ҫɾ����ʵ��������Derive()����
	 *b)Ҫ�ܹ���֤Derive()�����������������������
	 *c)�����������Base2���������������ǵ���Derive�����������أ�
	 *d)ִ��delte pb2ʱ��ϵͳ�Ķ������ǣ�--һ��Ҫ����Derive������������Ŷԡ�
	 *	d.1)���Base2��û����������,��������ֱ��ɾ����pb2��ͷ������ڴ棬һ�����쳣����Ϊ����ڴ�ѹ���Ͳ���new��ʼ���ڴ棬���м�ɾ���ˡ�
	 *	d.2)���Base2����һ���������������������������Ǹ���ͨ����������������������������ô��delte pb2��
	 *		������������ͻᱻϵͳ����,����delete���Ծ���pb2��ͷ����ڴ棬����һ�����쳣����Ϊ����ڴ�ѹ���Ͳ���new��ʼ���ڴ棻
	 *		����������������麯������������ʵʩ��̬�󶨣���̬����ζ����delete Base2ָ��ʱ��ɾ�����ڴ濪ʼ��ַ����pb2�ĵ�ǰλ�ã�
	 *		���Կ϶��Ǵ����
	 *	d.3)���Base2����һ��������������
	 *	�������ڲ�
			 *	1.~Dervice()��������Derive����������
			 *	2.~Base2()���ø���2������������
			 *	3.~Base()���ø���1������������
	d.4)Derive��;���û����������������ΪBase2�� ��������������������Ҳ��Ϊ�˸�Derive����������������Ϊ�˵���~Base2()��~Base()������������
		e)��ʦҪ���ң������漰���̳еģ������඼Ҫ����Щ����������;

	 */

	//���Դ��룬���ڻ����麯����--����Ƶ5-6 46��27��
	Base *pbm = new Base();
	/* [0] = 0x009414ab {FunctionSemantics.exe!Base::f(void)}
	 * [1] = 0x009414b5 {FunctionSemantics.exe!Base::g(void)}
	 * [2] = 0x009414b0 {FunctionSemantics.exe!Base::h(void)}
	 * [3] = 0x009414fb {FunctionSemantics.exe!Base::`vector deleting destructor'(unsigned int)}��������
	 */
	Base2 *pb222 = new Base2();
	/*[0] = 0x009414ec {FunctionSemantics.exe!Base2::hBase2(void)}
	 *[1] = 0x009414e2 {FunctionSemantics.exe!Base2::`vector deleting destructor'(unsigned int)}��������
	 * 
	 */
	Derive *p11212 = new Derive();
	/*�̳�Base��Base2�����麯����
	 *__vfptr = 0x00949ba4 {FunctionSemantics.exe!const Derive::`vftable'{for `Base'}} {0x009414ab {FunctionSemantics.exe!Base::f(void)}, ...}
	 *	[0] = 0x004814ab {FunctionSemantics.exe!Base::f(void)}
	 *	[1] = 0x004814a6 {FunctionSemantics.exe!Derive::g(void)}
	 *	[2] = 0x004814b0 {FunctionSemantics.exe!Base::h(void)}
	 *	[3] = 0x004814f6 {FunctionSemantics.exe!Derive::`vector deleting destructor'(unsigned int)}
	  __vfptr = 0x00949bc4 {FunctionSemantics.exe!const Derive::`vftable'{for `Base2'}} {0x009414ec {FunctionSemantics.exe!Base2::hBase2(void)}, ...}
		[0] = 0x004814ec {FunctionSemantics.exe!Base2::hBase2(void)}
		[1] = 0x004814dd {FunctionSemantics.exe![thunk]:Derive::`vector deleting destructor'`adjustor{4}' (unsigned int)}

	Derive ��ĵڶ����麯�����з�����thunk������
	һ�����������ڶ��ؼ̳��У��ӵڶ����麯����ʼ���ܾ� ���У�������thisָ���������������ʵ��һ�λ����룬��δ�����������飺
	(1)����thisָ�룬������Derive�����Ŀ�ʼλ�ã�������Base2�����λ�á�
	(2)����Derive��������
	 */
	p11212->g();
	p11212->i(); //���麯����

	Derive dddd;
	dddd.i(); //ֱ�ӵ����麯��




	system("pause");
	return 1;
}
