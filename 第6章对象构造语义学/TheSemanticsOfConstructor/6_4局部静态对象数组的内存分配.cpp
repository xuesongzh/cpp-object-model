#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;


//����6_4�ֲ���̬����������ڴ����

class A
{
public:
	A()
	{
		//cout << "A::A()" << endl;
	}
	~A()
	{
		//cout << "A::~A()" << endl;
	}
	int m_i;
};

void myfunc()
{
	static A s_aobj[1000'0000]; //�����ڴ�Ӧ����������,--����û��ʹ�ã�����û��ֱ�ӷ����ڴ棬��ʹ�õ�ʱ�򣬲ŷ����ڴ�
	//for (int i = 0; i < 10000000; i++) //�ñ������ķ����ڴ��Ż�����ʧЧ
	//{
	//	s_aobj[i].m_i = i;
	//}
	printf("s_aobj������׵�ַ��%p\n", s_aobj);

}

void func()
{
	myfunc();
	myfunc();
}


int main()
{
	func();

	while (1)
	{

	}
	system("pause");

	return 1;
}



