#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;


/*
 * һ������Ĺ���˳��_�������е��ø���Ĺ��캯�����ȹ��츸���Ӷ���Ȼ���ٹ����������еĶ�������������Ĺ��졣
 * �����麯���ļ����۲�--�������麯��ָ�뱻��ֵ���Σ��ڹ������ת����ʱ����Ҫ���麯��ָ��ָ��ÿ������麯����
 *    ���ǧ��Ҫ�ڹ��캯�������Լ��Ĵ�����ʹ������memcpy����ֱ�Ӳ������ֶΣ����޸��麯����ָ���ֵ�����򣬵����麯��ʱ�Ϳ������ϵͳ������
 * �������캯���ж��麯���ĵ���
 *	 ���캯���е����麯�����������麯������ã����Ҳ���Ƕ�̬����Ϊ���캯�����麯����ָ�뻹û��ָ���麯����
 *	 �������麯���е��������麯�����������麯����ʵ�ֶ�̬����ͬ������ʵ�ֲ�һ��
 *   ĳ����Ĺ��캯�� �� ����һ���麯������ô�ߵĲ����麯��������ֱ�ӵ��á�
 * �ģ���һ����
 *	����࣬��̳��еķ���
 * 

 */

class A
{
public:
	A()
	{
		printf("A this = %p\n", this);
		cout << "A::A()" << endl;
	}
	virtual ~A() {}
	virtual void myvirfunc() {}
	virtual void myvirfunc2() {}
};

class B :public A
{
public:
	B()
	{
		printf("B this = %p\n", this);
		cout << "B::B()" << endl;
	}
	virtual ~B() {}
	virtual void myvirfunc() {}
	virtual void myvirfunc2() {}
};

class C :public B
{
public:
	C() :m_c(11)//ע���Ա����m_c�ĸ�ֵʱ��
	{
		//memcpy(this,)
		myvirfunc(); //���캯���У�����û�����麯��������ֱ��ͨ���麯����ַ��ֱ�ӵ�������麯������̬��ʽ���ã�
		printf("C this = %p\n", this);
		cout << "C::C()" << endl;
	}
	virtual ~C() {}
	virtual void myvirfunc() { myvirfunc2(); }//����myvirfunc2()��ͨ���麯������õ�
	virtual void myvirfunc2() {}
	int m_c;

};

void func()
{
	//C cobj;
	/*
    C cobj;
    C::C()   //ĩ����--��C��Ĺ��캯���е���B��Ĺ��캯������B��Ĺ��캯���е���A��Ĺ��캯����
        B::B()
            A::A()  //��Դ��
                vptr = A::vftable; //����������Ĵ���   34 9b 2f 01  үү��A���麯�����ַ��ֵ��vptr
                cout << "A::A()" << endl; //�����Լ��Ĵ���
            vptr = B::vftable;   //����������Ĵ���  54 9b 2f 01  ����B���麯�����ַ��ֵ��vptr
            cout << "B::B()" << endl;  //�����Լ��Ĵ���
        vptr = C::vftable;   //����������Ĵ���  3c 9b 2f 01	������C���麯�����ַ��ֵ��vptr--�麯����ָ���ֵ����ֵ3��
        //....��Ҫ�����ﶯ�麯����ָ��
        //memset(this,0,sizeof(C));

        m_c = 11; //��ʼ���б��л������ͱ���m_c�ĸ�ֵʱ��
        cout << "C::C()" << endl; //�����Լ��Ĵ���


	A B C��ͬһ��thisָ��
	A this = 010FF614
	A::A()
	B this = 010FF614
	B::B()
	C this = 010FF614
	C::C()

	 */
	
	C *mycobj = new C();
	mycobj->myvirfunc(); //����ʵ���ϵĶ�̬�������Ľ�


}

int main()
{

	func();
	system("pause");
	return 1;
}



