#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;
typedef string mytype;

class A
{
public:
	void myFunction(mytype temvalue);//����mytype��string����

public:
	typedef int mytype;
	mytype m_value;//�ȶ������ͣ�����m_value��int����
};

void A::myFunction(::mytype temvalue)
{
	//m_value = temvalue;//error ��string����ת��Ϊint����0
}


int main(void)
{
	system("pause");
	return 0;
}


/*
* (1)���ۣ����ڳ�Ա���������������ڵ�һ����������mytype���͵�ʱ�򱻾����ġ�
* ���Ե�һ������mytpye��ʱ�򣬱�����������typedef string mytype;���ͰѲ�������string���͡�
* ���ۣ�Ϊ�������о��翴��mytype���ͣ����Ͷ������һ��Ҫ���嵽���ʼ��λ��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
