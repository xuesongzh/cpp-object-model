#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class CTemValue
{
public:
	int value1;
	int value2;
public:
	CTemValue(int v1=0,int v2=0):value1(v1),value2(v2)//���캯��
	{
		cout << "�����˹��캯��" << endl;
		cout << "value1=" << value1 << endl;
		cout << "value2=" << value2 << endl;
	}
	CTemValue(const CTemValue &ct):value1(ct.value1),value2(ct.value2)
	{
		cout << "�����˿������캯��" << endl;
		
	}
	virtual  ~CTemValue()
	{
		cout << "��������������" << endl;
	}
};

//�������ӽ�
CTemValue DoubleMyself(CTemValue&t)
{
	//(1)�����߲���
	//CTemValue tem;
	//tem.value1 = t.value1 * 2;
	//tem.value2 = t.value2 * 2;
	//return  tem;//����һ����ʱ����Ȼ����ÿ������캯����tem���󿽱��������������ڴ�ռ䡣

	//�Ż���
	return CTemValue(t.value1 * 2, t.value2 * 2);//����һ����ʱ����ֱ�ӷ���
}
//�������ӽ�
void DoubleMyself(CTemValue&obj,CTemValue&t)
{
	obj.CTemValue::CTemValue(t.value1 * 2, t.value2 * 2);
	return;
}


int main(void)
{
	CTemValue ts1(10, 20);
	//CTemValue ts2=DoubleMyself(ts1);//ʹ��һ�����������գ��ͻ���һ����������
	DoubleMyself(ts1);
	/*
	 * �������ӽ�
	 * CTemValue ts1;
	 * ts1.CTemValue::CTemValue(10,20);
	 * CTemValue temObj;
	 * DoubleMyself(temObj,ts1);
	 */
	/*
	 �����˹��캯��
	value1=10
	value2=20
	�����˹��캯��
	value1=20
	value2=40
	��������������
	 */
	
	system("pause");
	return 0;
}
/*
* (1)�����߲���
* 
* (2)����������
* (3)
* (4)
* (5)
* (6)(7)
*/
