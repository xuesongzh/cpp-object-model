#include<iostream>
#include "MyTemplate.h"
using namespace std;
template class MyClass<int>;//��ʾʵ������ģ��
template void MyClass<int>::myFunction02()const;//ʵ��������ĳ�Ա����



int main(void)
{
	MyClass<int>myOjb01;
	myOjb01.m_i = 10;
	myOjb01.m_j = 20;
	myOjb01.myFunction01();
	myOjb01.myFunction02();
	myOjb01.myVirtualFunction01();
	system("pause");
	return 0;
}
/*
 * (1)7_1_3���Դ�ļ���ʹ����ģ��
 * һ�����ļ������õ���ģ�壬���Է���.h�ļ���
 * �ڶ��cpp���ɵ�obj�ļ��У����ܲ�������ظ���ʵ�����࣬�������ӵ�ʱ��ָ�ӱ���һ��MyClass<int>���ʵ�塣
 *
 * 1.1�麯����ʵ����
 *	Ϊʲô�麯��û�б����ã�Ҳ�ᱻʵ������������
 *	��Ϊ���麯�����������ͻ�����麯�����麯���������麯���ĵ�ַ��Ҳ����ζ��Ҫ֪���麯���ĵ�ַ����
 */