#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class CTB
{
public:
	CTB()
	{
		
	}
	CTB(const CTB&B)//�������캯��
	{
		cout << "�������Լ��Ŀ������캯��" << endl;
	}
};

class CTBSon:public CTB
{
public:
	
};


int main(void)
{
	CTBSon myctbSon;
	CTBSon myctbson02 = myctbSon;
	
	system("pause");
	return 0;
}


/*
* (1)�������캯������_���������_����ֵһ�������˿������캯���𣿣�
*	��һ���������һ���������Ϊ��Ա������ʱ�򣬻ᡰ�ݹ鿽������
*
*���⣺ʲô�ǡ���Ҫ��ʱ�򡱣�
*���2.�������CTBSonû���Լ��Ŀ������캯�����������ĸ���CTB���������Լ��Ŀ������캯��
*�����������漰����CTBSon�Ŀ������캯��ʱ����������ΪCTBSon�ϳ�һ���������캯����
*
* (3)
* (4)
* (5)
* (6)(7)
*/