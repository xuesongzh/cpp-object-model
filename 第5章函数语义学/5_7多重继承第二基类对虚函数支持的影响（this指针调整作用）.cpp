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

	virtual ~Base() {
		
	}

	virtual Base *clone() const
	{
		return new Base();
	}

};

class Base2
{
public:
	virtual void hBase2() {

		cout << "Base2::hBase2()" << endl;
	}

	virtual ~Base2()	{
	
	}

	virtual Base2 *clone() const
	{
		return new Base2();
	}
};

class Derive :public Base,public Base2 {
public:
	virtual void i() { cout << "Derive::i()" << endl; }
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //ֻ����Derive�ĺ���

	virtual ~Derive() {
		
	}	
	virtual Derive *clone() const
	{
		return new Derive();
	}
};



int main()
{
	//һ�����ؼ̳еڶ�������麯��֧�ֵ�Ӱ�죨thisָ��������ã�
	//����̳��˼������࣬������м����麯����

	/*
	 *���ؼ̳��£��м���������ڶ������ߺ����Ļ������麯����֧�ֲ���Ӱ��
	 *thisָ�����,������Ŀ���Ǹ�ʲô��
	 *thisָ�������Ŀ�ľ����ö���ָ����ȷ��ָ������׵�ַ���Ӷ�����ȷ�ĵ��ö���ĳ�Ա��������˵��ȷȷ�����ݳ�Ա�Ĵ洢λ�á�
	 */

	//a)ͨ��ָ��ڶ��������ָ����ü̳�����麯����
	Base2 *pb2 = new Derive();
	delete pb2; //���ü̳��������������

	//b)һ��ָ���������ָ�룬���õڶ��������е��麯��
	Derive *pd3 = new Derive();
	pd3->hBase2();

	//c)�����麯���ķ���ֵ���������仯--����͸����ͬ����������ֵ���Բ�ͬ
	Base2 *pb1 = new Derive(); //pb1ָ�����Base2�Ӷ�����׵�ַ
	Base2 *pb4 = pb1->clone(); //����Derive::clone();
	 //ִ��clone()ʱ��pb1���Ȼ������ָ��Derivce������׵�ַ���������õ���Derive�汾��clone()

	system("pause");
	return 1;
}
