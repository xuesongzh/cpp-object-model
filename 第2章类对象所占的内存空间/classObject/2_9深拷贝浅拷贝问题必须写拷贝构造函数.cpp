#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class TEST
{
public:
	int m_i;
	int *p;
	//���캯��
	TEST()
	{
		p = new int(23);
		m_i = 0;
		cout << "���캯��ִ��" << endl;
	}
	TEST(int value):m_i(value)
	{
		p = new int(value);
		cout << "��һ�������Ĺ��캯��ִ��" << endl;
		
	}
	~TEST()
	{
		delete p;
		cout << "��������ִ��" << endl;
	}
	//�������캯��--û�п������캯���ᱨ�쳣
	TEST(const TEST&t)
	{
		this->p = new int(t.m_i);//�ֽڷ����ڴ�
		this->m_i = t.m_i;
	}
};


void playObj()
{

	TEST test01(12);
	TEST test02(test01);
}

int main(void)
{
	playObj();
	//�������󣬻��ͷ�����pָ����ڴ�ռ䣬�ᱨ�쳣��
	
	system("pause");
	return 0;
}
/*
* (1)
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
