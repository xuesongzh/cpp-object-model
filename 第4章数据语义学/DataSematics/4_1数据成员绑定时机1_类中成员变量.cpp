#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string myvar="jisuanjizuchengyuanli";//ȫ���� �ַ�������
class A
{
public:
	A(int value):myvar(value)
	{
		;
	}
	int myFunction();
private:
	int myvar;//ͬ���ֲ�������������ͬ���������Ͳ�ͬ
};

int A::myFunction()
{
	return myvar;//�������ڵ�int����myvar
}
//�������Գ�Ա�����Ľ����Ͱ���������A������ɺ�ſ�ʼ��

string myFunciton01()
{
	return myvar;//���ص���ȫ�ֵ�string���ͱ���
}

int main(void)
{
	//������ڲ���myvar
	A obj_a(12);
	cout << obj_a.myFunction();
	cout << endl;
	//ȫ�ֵ�myvar
	cout << ::myvar << endl;//::���Ǳ�ʾȫ�ֱ���
	
	system("pause");
	return 0;
}
/*
* (1)�ܽ�
* ��������myFunction�����Ľ�������������A������Ϻ�ſ�ʼ�ġ�
* ��Ϊֻ��������A������Ϻ󣬱��������ܿ�����A��myvar�����ܸ���ʱ������Ҫ�ѳ���myvar�ĳ����������ʵ��Ľ��͡�
* ��Ա�����н��ͳ�����myvar��ȫ�ֱ����н��ͳ�string myvar��
* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
