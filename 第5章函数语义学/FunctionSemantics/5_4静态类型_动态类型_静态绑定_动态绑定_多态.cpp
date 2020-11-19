#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Base
{
public:
	void myfunc() //��ͨ��Ա����
	{
		cout << "Base::myfunc()" << endl;
	}
	virtual void myvirfunc(int value = 1)
	{
		cout << "Base::myvirfunc(),value = " << value << endl;
	}
};

class Derive :public Base
{
public:
	void myfunc() //��ͨ��Ա����
	{
		cout << "Derive::myfunc()" << endl;
	}
	virtual void myvirfunc(int value = 2)
	{
		cout << "Derive::myvirfunc(),value = " << value << endl;
	}
};

class Derive2 :public Base
{
public:
};


class A
{
public:
	virtual void myvirfunc() {}
};
int main()
{
	//һ����̬���ͺͶ�̬����
	//��̬���ͣ�������ʱ�����ͣ������ڼ��ȷ���õ�
	Base base; //base�ľ�̬������Base��û�ж�̬���ͣ���Ϊ����ָ�벻������
	Derive derive; //derive�ľ�̬������Derive��û�ж�̬���ͣ���Ϊ����ָ�벻������
	Base *pbase; //pbase�ľ�̬����������Base *  ,����Ŀǰû�ж�̬���ͣ���Ϊ��û��ָ���κζ���
	Base *pbase2 = new Derive(); //pbase2�ľ�̬����������Base * ����̬������Derive 
	Base *pbase3 = new Derive2(); //pbase3�ľ�̬����������Base *����̬������Derive2 

	//��̬���ͣ�����Ŀǰ��ָ������ͣ����е�ʱ��ž��������ͣ���
	//һ��ֻ��ָ��������ò��ж�̬���͵�˵��������һ�㶼��ָ�����ָ��������ã�
	//���⣬��̬������ִ�й����п��Ըı䣺����
	pbase = pbase2; //pbase�Ķ�̬����Derive
	pbase = pbase3; //pbase�Ķ�̬���͸ı�ΪDerive2

	/*
	 *������̬�󶨺Ͷ�̬��
	 *��̬�󶨣��󶨵��Ǿ�̬���ͣ�����Ӧ�ĺ����������������ڶ���ľ�̬���ͣ������ڱ�����
	 *��̬�󶨣��󶨵��Ƕ�̬���ͣ�����һ���ĺ����������������ڶ���Ķ�̬���ͣ�������������
	 *һЩ���ۣ�
	 *a)��ͨ��Ա�����Ǿ�̬�󶨣����麯���Ƕ�̬�󶨣�
	 *b)ȱʡ����һ���Ǿ�̬��
	 *�������з�����ʾ
	 */

	//�����̳еķ��麯����-��ͨ������̬�󶨣�����ָ��ָ��������󲻻��������ĺ���
	Derive derive02;
	Derive *pderive = &derive02;
	pderive->myfunc(); //Derive::myfunc()//����������ͨ����

	Base *pbase02 = &derive02;
	pbase02->myfunc(); //Base::myfunc()�����ø�����ͨ����--��֪������Ƿ��뵽������

	 //��ͨ��Ա�����Ǿ�̬�󶨣����仰˵��myfunc() ����ͨ��Ա���������ﵽ�׵��ø����myfunc���������myfuncȡ���ڵ����ߵľ�̬���ͣ�
	 //��Ϊ����pbase�ľ�̬������Base����һ���õ���Base���myfunc()��pderive�ľ�̬������Derive *�����Ե��õ���Derive��myfunc();

	

	 //�ģ��麯���Ķ�̬��--����ȱʡֵ�Ǿ�̬�󶨵�
	cout << "----------------" << endl;
	Base base02;
	pderive->myvirfunc(); //ִ��Derive��myvirfunc(); ---  Derive::myvirfunc()
	pbase02->myvirfunc(); //pbase��̬������Derive�����麯���Ƕ�̬�󶨣����������Ķ�̬���ͣ�---  Derive::myvirfunc()
	//ȱʡvalue������ӡ�����ľ�Ȼ��1��Derive::myvirfunc(),value = 1
	//���ʼ�ں�������ȱʡֵ�ľ�̬�󶨣�����ȱʡ�����󶨵��˸��ຯ����ȱʡ������ȥ��

	Base &yinbase = derive02;
	cout << "----------------begin" << endl;
	yinbase.myvirfunc();  //Derive::myvirfunc(),����value = 1��������2
	cout << "----------------end" << endl;

	pbase02 = &base;   //
	pbase02->myvirfunc(); //----Base::myvirfunc();
	/*
	 * �麯���Ƕ�̬�󶨣����仰˵��myvirfunc()���麯�������ﵽ��ִ���ĸ�myvivfunc()ȡ���ڵ����ߵĶ�̬���ͣ�
	 * ����pbase�Ķ�̬���ͷֱ�Derive��Base�����Ե��õ�Ҳ�ֱ���Derive��Base��myvirfunc()��
	 * pderive�Ķ�̬������Derive�����Ե��õ���Derive��myvirfunc();
	 *
	 * ���ۣ�������Ĭ�ϲ����Ǿ�̬�󶨵�-��Ӧ�������������¶���һ���̳����ķ��麯����
	 */


	//�壺���¶����麯����ȱʡ������
	//��Ҫ���¶����麯����ȱʡ������ֵ

	/*
	 *����c++ �еĶ�̬�Ե�����
	 *c++�С���̬�ԡ�
	 *��̬�� ��������������̸��
	 *a)�Ӵ���ʵ����
	 *b)�ӱ�����ʽ��
	 *��һ���۵��ǿ϶��ģ���̬�������Ǵ����麯����û���麯�����������ܴ��ڶ�̬�����麯�����ҵ����麯����
	 */
	
	//(1)�Ӵ���ʵ����
	//�����ǵ���һ���麯��ʱ���ߵ��ǲ���ͨ����ѯ�麯�������ҵ��麯����ڵ�ַ��
	//Ȼ��ȥִ���麯��������ߵ������;�����Ǿ��Ƕ�̬������������;�������Ͳ��Ƕ�̬��
	A *pa = new A();
	pa->myvirfunc(); //�ǲ��Ƕ�̬���Ƕ�̬

	A a;
	a.myvirfunc(); //����Ͳ��Ƕ�̬

	A *pa1 = &a;
	pa1->myvirfunc(); //���Ҳ�Ƕ�̬

	/*
	 *b)�ӱ�����ʽ��(ͨ������������)
	 *(1)�м̳й�ϵ���и��������࣬�����б������麯��(����ζ��������һ�����麯��)��������д������麯����
	 *(2)����ָ���������ָ���������
	 *(3)���Ը���ָ����� ���õ�����������д�˵��麯��ʱ�����Ǿ��ܿ�������̬�ı����ˣ���Ϊ���õ���������麯����

	 */
	system("pause");
	return 1;
}
/*
	 Derive::myfunc()
	Base::myfunc()
	----------------
	Derive::myvirfunc(),value = 2
	Derive::myvirfunc(),value = 1
	----------------begin
	Derive::myvirfunc(),value = 1
	----------------end
	Base::myvirfunc(),value = 1
	�밴���������. . .




 */
