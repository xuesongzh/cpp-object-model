
#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class CTBSon
{
public:
	virtual void myFunctionStatic()
	{
		;
	}
};

int main(void)
{
	CTBSon ctbs_son;
	CTBSon ctbs_son02 = ctbs_son;//�������캯��
	/*
	 *          Code
       COMDAT; sym= "public: __thiscall CTBSon::CTBSon(class CTBSon const &)" (??0CTBSon@@QAE@ABV0@@Z)
	 */
	
	system("pause");
	return 0;
}
/*
* (1)�������캯������ѧ���3
*	���һ����CTBSonû�п������캯�������Ǹ��������˻��߼̳����麯����
*	������������CTBSon�Ŀ������캯��ʱ�򣬾ͻ�ϳ�Ĭ�ϵĿ������캯��,������������캯���в�����䡣
*
*	���������������趨�����ctbs_son���麯����ָ��ָ���麯����
*	
*	
* (2)
*/
