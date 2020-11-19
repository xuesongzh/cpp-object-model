
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;



class A
{
public:
	void myfunc1(int tempvalue1)
	{
		cout << "tempvalue1 = " << tempvalue1 << endl;
	}
	void myfunc2(int tempvalue2)
	{
		cout << "tempvalue2 = " << tempvalue2 << endl;
	}

	static void mysfunc(int tempvalue)
	{
		cout << "A::mysfunc()��̬��Ա����--tempvalue = " << tempvalue << endl;
	}

	virtual void myvirfuncPrev(int tempvalue)
	{
		cout << "A::myvirfuncPrev()���Ա����--tempvalue = " << tempvalue << endl;
	}

	virtual void myvirfunc(int tempvalue)
	{
		cout << "A::myvirfunc()���Ա����--tempvalue = " << tempvalue << endl;
	}

};

void func()
{
	void (A::*pmyvirfunc)(int) = &A::myvirfunc; //��Ա����ָ��  -- vcall(vcall trunk)��ַ���麯����

	A *pvaobj = new A;
	pvaobj->myvirfunc(190);//����ָ������麯��--��vcall
	(pvaobj->*pmyvirfunc)(190);//ͨ����Ա����ָ����ã���Ȼ���麯��������麯��
	printf("%p\n", &A::myvirfunc);//��ӡ����vcall�ĵ�ַ���Ǹ��м��ַ���������麯����������ַ

	//������ͨ��Ա�������������ĵ�ַ
	pmyvirfunc = &A::myfunc2;  //�����ĳ�Ա������ַ
	(pvaobj->*pmyvirfunc)(33);

	delete pvaobj;

}



int main()
{
	func();


	return 1;
}
/*
 *����5_10_2ָ�����Ա������ָ�뼰vcall��һ��̸
 *vcall (vcall trunk) = virtual call�������
 *	������һ��Ҫִ�еĴ���ĵ�ַ����δ�����������ȥִ����ȷ���麯����
 *	��������ֱ�Ӱ�vcall�����麯���������ô�����Ļ�����ôvcall{0}����ľ����麯������ĵ�һ��������
 *	vcall{4}�ʹ����麯������ĵڶ����麯��
 *
 *	������⣺&A::myvirfunc����ӡ��������һ����ַ�������ַ����һ�δ��룬��������м�¼���Ǹ��麯�����麯�����е�һ��ƫ��ֵ
 *	�������ƫ��ֵ�������˾���Ķ���ָ�룬���Ǿ��ܹ�֪�����õ����ĸ��麯������ߵ��ĸ��麯���ˣ�
 *
 *	��Ա����ָ�������Ŀ�����һ��vcall(vcall trunk)��ַ�������麯����,ҪôҲ������һ�������ĳ�Ա������ַ(���ó�Ա����)
 *	�����һ��vcall��ַ����vcall�ܹ������������ҳ���ȷ���麯�����е��麯����ַ���е��ã�

 */



