#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
	int number01;//4���ֽ�
	virtual void virtualFunction()//�麯��
	{}
};

int main(void)
{
	A obj_a;
	int length = sizeof(obj_a);
	cout << "length=" << length << endl;//8

	char*p1 = reinterpret_cast<char*>(&obj_a);//ǿ������ת����&obj_a���׵�ַ
	char*p2 = reinterpret_cast<char*>(&obj_a.number01);
	if (p1==p2)//����Ͷ����еĳ�Ա����λ����ͬ��˵��number01�ڶ����ڴ沼�����棬�麯����ָ�������档
	{
		cout << "number01�����ڴ�������4���ֽڣ��麯����ָ���ڶ����ڴ��ĩβ" << endl;
	}
	else
	{
		cout << "�麯����ָ��λ�ö����ڴ沼�ֿ�ʼλ�ã�number01��ĩβλ��" << endl;
	}
	//���ۣ��麯����ָ��λ�����������ڴ沼�ֵĿ�ͷλ�á�
	
	
	system("pause");
	return 0;
}
/*
 *3_1�麯����ָ��λ�÷���_λ�ڶ����ڴ沼�ֵĿ�ͷλ��
* (1)�麯����ָ��λ�÷���
* �ࣺ���麯������������һ���麯����
* ʹ�������ɶ����ʱ�򣬶����л���һ���麯����ָ�룬����ָ������麯����ʼ��ַ��
* �麯���������ɿ�ִ�г����ʱ��ᱣ���ڿ�ִ�г����ļ��С�
*
* //���ۣ��麯����ָ��λ�����������ڴ沼�ֵĿ�ͷλ�á�
*
*	�麯����ָ��
*	number01

length=8
�麯����ָ��λ�ö����ڴ沼�ֿ�ʼλ�ã�number01��ĩβλ��
�밴���������. . .
*	
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
