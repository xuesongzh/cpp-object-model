#include<iostream>
#include <algorithm>
using namespace std;

/*
 *7_1_1����ģ��
 *���ۣ�
 *����ģ��  �������T�������ƶ��Ǳ������ڱ����ʱ�����addFunction�����ĵ�����ȷ��T�����͡�
 *�������û�����addFunction()�����ĵ��ô��룬����������Ϊ���ǲ����κκͺ���ģ���йصĴ��롣
 *�ͺ�����addFunctioinû�д��ڹ�һ��
*
 */
template<typename T>
//T addFunction( T&a, T&b)
T addFunction(const T&a,const T&b)
{
	T addtem = a + b;
	return  addtem;
}

void myFunction()
{
	int a = 12;
	int b = 23;
	cout << addFunction<int>(12, 14) << endl;//���������const�Ų��ᱨ��
	cout << addFunction(a, b) << endl;

}

int main(void)
{
	myFunction();
	system("pause");
	return 0;
}