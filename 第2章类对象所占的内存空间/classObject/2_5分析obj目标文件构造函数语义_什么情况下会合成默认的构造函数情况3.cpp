#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;



class MBTX 
{
public:
	int m_i;
	int m_j;
	virtual void myFunctionVirtual()
	{
		cout << "vvvvvvvvvvvvvvvvvvvvvv" << endl;
	}
};

int main(void)
{
	MBTX mb;//����Ĺ��캯��������ϳɵĹ��캯������

	system("pause");
	return 0;
}
/*
* (1)���⣺������������Щ��Ҫ��ʱ��������Ǻϳ�Ĭ�ϵĹ��캯��������
* ���3�����һ���ຬ���麯����������û���κι��캯��ʱ
*	��Ϊ�麯���Ĵ��ڣ�
*		1.�����������������һ�����ڸ�����麯����(vtbl),vftable  =virtual function table
*		2.�������ϳ�Ĭ�Ϲ��캯������������麯�����ַ��ֵ���������麯����ָ�루��ֵ��䣩
*			Ҳ�����ڹ��캯�������һ�丳ֵ���
*			���ǿ��԰��麯����ָ�뿴��һ�����Ǳ����Ͽ�������������Ա��
*		���⣺Ϊʲô���麯��������ô�鷳����
*			��Ϊ�麯���ĵ��ô���һ����̬���⣬������Ӵ���õ��麯����ָ�룬��������ϸ���ۡ�
*
	40301040 flags
         Initialized Data
         COMDAT; sym= "const MBTX::`vftable'" (??_7MBTX@@6B@)
         4 byte align
         Read Only

RAW DATA #2B
  00000000: 00 00 00 00 00 00 00 00                          ........

RELOCATIONS #2B
                                                Symbol    Symbol
 Offset    Type              Applied To         Index     Name
 --------  ----------------  -----------------  --------  ------
 00000000  DIR32                      00000000        CE  ??_R4MBTX@@6B@ (const MBTX::`RTTI Complete Object Locator')
 00000004  DIR32                      00000000        88  ?myFunctionVirtual@MBTX@@UAEXXZ (public: virtual void __thiscall MBTX::myFunctionVirtual(void))


��������Լ���MBTX��д���Լ��Ĺ��캯�������̳���MBTXPARENT�࣬�����������˴��룿��--�������ûд��
	1.������������MBTX���麯����vftable
	2.�����˸���Ĺ��캯����
	3.��Ϊ�麯���Ĵ��ڣ�������麯�����ַ��ֵ���������麯����ָ�롣
		���������Լ���Ĭ�Ϲ��캯��ʱ�򣬱������������Ҫ���������Լ�д�Ĺ��캯�����룬������ø��๹�캯�������������麯����ָ�븳ֵ
	���������˺ܶ����飬û��Ĭ�Ϲ��캯���Ǳ�Ҫ����»�������Ǻϳ�Ĭ�Ϲ��캯�������������Ĭ�Ϲ��캯�����������������Ҫ�����������乹�캯�����롣

* (2)
*/
