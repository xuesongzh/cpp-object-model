#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class AMember
{
public:
	int m_testSon;
};

class A
{
public:
	int m_i;
	AMember asubObj;
};


class CTB
{
public:
	CTB(const CTB&b)
	{
		cout << "ctb�������캯��ִ����" << endl;
	}
	CTB()
	{
		
	}
};

class B
{
public:
	CTB m_ctb;
};



int main(void)
{
	A obj_a;
	obj_a.m_i = 15;
	obj_a.asubObj.m_testSon = 120;
	A obj_02 = obj_a;//������������� ���ÿ������캯��
	/*obj_02.asubObj.m_testSon Ҳ����ֵΪ120
	 *��һ���������һ���������Ϊ��Ա������ʱ����Ȼû�кϳɿ������캯����
	 *�ܽ᣺
	 *	1.A obj_02 = obj_a;�ǿ�������һ������
	 *	2.�����Լ�û��д��A�Ŀ������캯����������Ҳû�а����������ɿ������캯��
	 *	3.ͨ��dumpbin����ȷʵ��Ա������ֵ����������һ������Ķ�Ӧ�����У����Ǳ������ڲ���һЩֱ�����ݿ���ʵ�ַ�����
	 *		����������������Ա����asubObj��Ҳ��ݹ�ʽȥ���������Ǳ������ڲ��ġ���λ��������
	 *		���ǽ�һ���������ڴ�ռ��ֵ��������һ����Ķ�Ӧ�ڴ�ռ���ȥ�������ڴ濽���ĸо���
	 */


	//���1
	CTB ctb01;
	B obj_b;
	obj_b.m_ctb = ctb01;
	B obj_b02 = obj_b;//���ÿ������캯��
	/*
		                                                 Symbol    Symbol
	 Offset    Type              Applied To         Index     Name
	 --------  ----------------  -----------------  --------  ------
	 0000000C  DIR32NB                    00000000        99  ??0B@@QAE@ABV0@@Z (public: __thiscall B::B(class B const &))
	 00000058  SECREL                     00000000        99  ??0B@@QAE@ABV0@@Z (public: __thiscall B::B(class B const &))
	 0000005C  SECTION                        0000        99  ??0B@@QAE@ABV0@@Z (public: __thiscall B::B(class B const &))
	 */
	

	system("pause");
	return 0;
}
/*
* (1)�������캯������_���������_����ֵһ�������˿������캯���𣿣�
*	��һ���������һ���������Ϊ��Ա������ʱ�򣬻ᡰ�ݹ鿽������
* 
*���⣺ʲô�ǡ���Ҫ��ʱ�򡱣�
*	ĳЩ����£����ǲ�д�Լ��Ŀ������캯�����������ͻ�������Ǻϳɳ��������캯����
*	����ϳɳ����Ŀ������캯����Ҫ��ʲô�����أ���
*	
*	���1�� ���һ����Bû���Լ��Ŀ������캯�������Ǻ���һ����CTB���͵Ķ�����Ϊ��Ա������������CTB�����Լ��Ŀ������캯����
*			�����������漰����A�Ŀ�������ʱ�򣬱������ͻ����B�ϳ�һ���������캯��.
*			�������ϳɵĿ������캯��ȥ���ð��������Ŀ������캯������B�Ŀ������캯��ȥ����CTB�����Ŀ������캯����
*			
*
*
* (3)
* (4)
* (5)
* (6)(7)
*/
