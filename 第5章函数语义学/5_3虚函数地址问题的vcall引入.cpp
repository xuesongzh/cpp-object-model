#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class MYACLS
{
public:
	virtual void myvirfunc1()
	{

	}
	virtual void myvirfunc2()
	{

	}
};

int main()
{
	printf("MYACLS::myvirfunc1()��ַ=%p\n", &MYACLS::myvirfunc1); //��ӡ����vcall���������룩��ַ���������������麯����
	printf("MYACLS::myvirfunc2()��ַ=%p\n", &MYACLS::myvirfunc2);
	cout << sizeof(MYACLS) << endl;//4
	MYACLS *pmyobj = new MYACLS();
	/*
	 *�麯�����е�������ַ��
	 0x00a41096 {FunctionSemantics.exe!MYACLS::myvirfunc1(void)}
	 0x00a4112c {FunctionSemantics.exe!MYACLS::myvirfunc2(void)}
	 ��ӡ�ĵ�ַ��
	 MYACLS::myvirfunc1()��ַ=00B8114A
	 MYACLS::myvirfunc2()��ַ=00B81064
	 4
	 vcall thunk-�Ǳ������ڱ���׶����ɵĶ��������Ϊһ�δ��룬�������������ĺ���ȥִ�С�ÿһ��vcall����Ӧ��һ���麯����
	 (1)����this���ڼ̳й����У�����ָ��ָ��������󣬵�����������麯����Ҫ�����������λ�á�
	 (2)��ת���������麯����ȥ

	 */
	

	system("pause");
	return 1;
}
/*5_3�麯����ַ�����vcall����
 *���ۣ��麯���ĵ�����ͨ�����������ɵ�vcall�����ӵ��ã�
 *vcall���������ܣ������档
 *
 *

�밴���������. . .
 * 
 */
