#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>
using namespace std;


//����6_11_3ֱ�������������ʱ�Զ���
//��3.1����ʱ���󱻴ݻ�
//��3.2����ʱ������󶨵����ö�������_��ʱ������������ڱ�Ϊ���õ���������
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
		m_i = tmpobj.m_i;
	}

	A & operator=(const A& tmpaobj)
	{
		cout << "A::operator()������ֵ�������ִ��" << endl;
		return *this;
	}

	~A()
	{
		cout << "A::~A()����������ִ��" << endl;
	}
	int m_i;
};

A operator+(const A& obj1, const A& obj2)
{
	A tmpobj;
	tmpobj.m_i = obj1.m_i + obj2.m_i;

	return tmpobj; //������������ʱ���󣬰�tmpobj���������ͨ�����ÿ������캯�� ��tmpobj�����ݿ�������������ʱ����
				   //Ȼ�󷵻ص��������ʱ����

}

void func()
{
	A myobj1;
	myobj1.m_i = 1;

	A myobj2;
	myobj2.m_i = 2;

	A resultobj = myobj1 +myobj2;
	myobj1 + myobj2; //��������ʱ����Ȼ�����ʱ����������������
	printf("(myobj1 + myobj2).m_i = %d\n", (myobj1 + myobj2).m_i); //��ʱ����������������������һ�����������ܱ�֤printf��ӡ����һ����Чֵ��

	//A tmpobja1 = (myobj1 + myobj1); ������ʱ�����ͷ�����--������Ҫ����Ҫ�ĵط����������ǲ�����룬��������ʱ���󹩱�����������ǳ��򿪷��ߴ���Ҫʵ�ֵ���ͼ��
	/*if ((myobj1 + myobj1).m_i > 1 || (myobj1 + myobj2).m_i > 5)
	{
	int abc;
	abc = 4;
	}*/


	//c_str()ȡ������ָ����ַ���
	cout << "***************************************" << endl;
	const char *p = (string("123") + string("456")).c_str(); //��һ�������⣬��Ϊ��ʱ����������оͱ��ݻ٣�

	string aaa = (string("123") + string("456"));
	const char *q = aaa.c_str();   //���Ӧ��OK

	printf("p = %s\n", p); 
	printf("q = %s\n", q);
	/*
	    p =
		q = 123456
	 */

	const string &aaa1212 = string("123") + string("456");
	printf("aaa1212 = %s\n", aaa1212.c_str());
	//aaa1212 = 123456



return;
}


int main()
{
	
	func();
	system("pause");
	return 1;
}



