
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
	virtual ~Base() {}
};

class Derive :public Base {
public:
	virtual void g() { cout << "Derive::g()" << endl; }
	void myselffunc() {} //ֻ����Derive�ĺ���
	virtual ~Derive() {}
};

int main()
{
	//һ��RTTI������ʱ����ʶ�𣩼򵥻ع�--c++����RTTI��Ŀ�ľ���Ϊ���ó��������е�ʱ�򣬸���ָ��������õ�ʵ�����͵��ú���
	Base *pb = new Derive();
	pb->g();

	Derive myderive;
	Base &yb = myderive;//���������������
	yb.g();

	//c++����ʱ����ʶ��RTTI��Ҫ�����б���������һ���麯�������������û���麯������ô�õ�RTTI�Ͳ�׼ȷ��
	//RTTI�Ϳ�����ִ���ڼ��ѯһ����ָ̬�룬���߶�̬���õ���Ϣ�ˣ�
	//RTTI������typeid��dynamic_cast����������֣�
	cout << typeid(*pb).name() << endl;
	cout << typeid(yb).name() << endl;
	cout << "----------------------------" << endl;
	/*
	    Derive::g()
		Derive::g()
		class Derive
		class Derive
	 */
	//����ת�����ж�����
	Derive *pderive = dynamic_cast<Derive *>(pb);
	if (pderive != NULL)
	{
		cout << "pbʵ����һ��Derive����" << endl;
		pderive->myselffunc(); //�����Լ�ר������
	}

	cout << "8888888888888888888888" << endl;
	//����RTTIʵ��ԭ��--RTTI����������Ϣ�洢���麯�����У����麯����ַ����4���ֽڣ�
	//typeid���ص���һ��������������ã�����������������һ����type_info���ࣩ��
	const std::type_info &tp = typeid(*pb);//����Ӷϵ�鿴tp����
	//tp = {_Data={_UndecoratedName=0x01184c8c "class Derive" _DecoratedName=0x007cc158 ".?AVDerive@@" } }
	Base *pb2 = new Derive();
	Base *pb3 = new Derive();
	const std::type_info &tp2 = typeid(*pb2);
	const std::type_info &tp3 = typeid(*pb3);



	cout << typeid(int).name();

	if (tp == tp2)
	{
		cout << "�ܺã�������ͬ" << endl;
	}

	//�����÷�����̬���ͣ������ڶ�̬����
	cout << typeid(int).name() << endl;
	cout << typeid(Base).name() << endl;
	cout << typeid(Derive).name() << endl;
	Derive *pa3 = new Derive();
	cout << typeid(pa3).name();
	

	Base *pb4 = new Derive();
	Derive myderive01;
	Base &yb1 = myderive;
	cout << typeid(*pb4).name() << endl; //class Derive
	cout << typeid(yb1).name() << endl; //class Derive
	Base *pb5 = new Derive();
	const std::type_info &tp4 = typeid(*pb5);

	//RTTI�Ĳ����������������Ƿ��в������麯�����й�ϵ�����������û���麯����Ҳ�Ͳ����ڻ�����麯����RTTI���޷��õ���ȷ�����
	//���ۣ�RTTI����������Ϣ�洢���麯�����У����麯����ַ����4���ֽڣ������ͼ

	//RTTI��ص�ַ
	printf("tp2��ַΪ:%p\n", &tp2);
	long *pvptr = (long *)pb2;
	long *vptr = (long *)(*pvptr);
	printf("�麯�����׵�ַΪ:%p\n", vptr);
	printf("�麯�����׵�ַ֮ǰһ����ַΪ:%p\n", vptr - 1); //�����-1ʵ��������������4���ֽ�

	long *prttiinfo = (long *)(*(vptr - 1));
	prttiinfo += 3; //����12�ֽ�
	long * ptypeinfoaddr = (long *)(*prttiinfo);
	const std::type_info *ptypeinfoaddrreal = (const std::type_info *)ptypeinfoaddr;
	printf("ptypeinfoaddrreal��ַΪ:%p\n", ptypeinfoaddrreal);
	cout << ptypeinfoaddrreal->name() << endl;
	/*
	    int�ܺã�������ͬ
		int
		class Base
		class Derive
		class Derive *class Derive
		class Derive
		tp2��ַΪ:000FC150
		�麯�����׵�ַΪ:000F9B70
		�麯�����׵�ַ֮ǰһ����ַΪ:000F9B6C
		ptypeinfoaddrreal��ַΪ:000FC150
		class Derive
	 */

	//����vptr,vtbl,rtti��type_info��Ϣ ����ʱ��
	/*vprt�Ǳ����������뵽�����еģ����������һ����Ա�������ڹ��캯���в��������麯����ָ��ָ���麯����
	 *vpblҲ�Ǳ����ʱ������õģ�
	 * rtti��type_info��ϢҲ�ǻ������:�����ʹ����ˣ�д���˿�ִ���ļ���
	 */

	//�ܽ�һ�£�����������ʵ����һ�����죬�����嶼�����麯����ʼ��ַΪͻ�ƿڣ�

	system("pause");
	return 1;
}
