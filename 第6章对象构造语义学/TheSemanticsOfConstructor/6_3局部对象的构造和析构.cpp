#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

//һ��6_3�ֲ�����Ĺ��������
//��Ҫ���˶���������򣬱������ܻ����ʵ��ĵط�������ö������������Ĵ��룻
//���ۣ�ʹ�õ�ʱ���壬��Ҫ�ڿ�ͷ���壬������һ�������򣬿��ܶ���ù��캯��
class A
{
public:
	A()
	{
		cout << "A::A()" << endl;
	}
	~A()
	{
		cout << "A::~A()" << endl;
	}
	int m_i;
};


void func()
{
	int i;
	int j;

	//......
	/*if (1)
	{
	return;
	}*/
	//.......
	//....
	A obja;//���飺�����ֶ��� �����崦�ǲ�����ù��캯������䣬���ھֲ�������ߵ�m_i�����ֵ����
	//������ڿ�ͷ��������һ�������򣬾�Ҫ���������������ȵ�ʹ�õ�ʱ��Ҫ�ٴε��ù��캯������������ι��������
	obja.m_i = 10;

	int mytest = 1;
	if (mytest == 0) //swtich case return;
	{
		return;
	}
	
	return;
}

//main������ʼ֮ǰҪ�ɺܶ���
int main()
{

	func();		
	system("pause");
	return 1;
}
//main��������֮��Ҫ�ɺܶ���


