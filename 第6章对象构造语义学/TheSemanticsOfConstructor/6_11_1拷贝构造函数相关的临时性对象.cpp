#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>
#include<string>

using namespace std;


//һ��6_11_1�������캯����ص���ʱ�Զ���
class A
{
public:
	A()
	{
		cout << "A::A()���캯����ִ��" << endl;
	}
	A(const A& tmpobj)
	{
		cout << "A::A()�������캯����ִ��" << endl;
	}
	~A()
	{
		cout << "A::~A()����������ִ��" << endl;
	}
};

A operator+(const A& obj1, const A& obj2)
{
	A tmpobj;//������ù��캯�������������������������

	printf("tmpobj�ĵ�ַΪ%p\n", &tmpobj);
	printf("---------------------\n");
	//.....
	return tmpobj; //������������ʱ���󣬰�tmpobj���������ͨ�����ÿ������캯�� ��tmpobj�����ݿ�������������ʱ����
					//Ȼ�󷵻ص��������ʱ������ʱ����û�б�����

}

void func()
{
	A myobj1;
	printf("myobj1�ĵ�ַΪ%p\n", &myobj1);

	A myobj2;
	printf("myobj2�ĵ�ַΪ%p\n", &myobj2);

	A resultobj = myobj1 + myobj2; //�����operator +�ﷵ�ص���ʱ����ֱ�ӹ��쵽��resultobj�
	printf("resultobj�ĵ�ַΪ%p\n", &resultobj);
	return;
}
/*
	A::A()���캯����ִ��
	myobj1�ĵ�ַΪ00AFF923
	A::A()���캯����ִ��
	myobj2�ĵ�ַΪ00AFF917
	A::A()���캯����ִ��
	tmpobj�ĵ�ַΪ00AFF80B//ֱ�Ӱ�temobj������resultobj�Ķ���ռ䣬���ǵĵ�ַ��ͬ
	---------------------
	A::A()�������캯����ִ��
	A::~A()����������ִ��
	resultobj�ĵ�ַΪ00AFF90B
	A::~A()����������ִ��
	A::~A()����������ִ��
	A::~A()����������ִ��

��������Ŀ���� c++ --���Ż���--���Ż���--�����Ż�����
ͬʱ�����������ɡ�--����������ʱ��顱--�����ߡ�
*/

int main()
{
	func();
	system("pause");

	return 1;
}



