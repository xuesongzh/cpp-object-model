#include<iostream>

using namespace std;

class A
{
private:
	virtual void myVirtualFunction()
	{
		myFunction();
		
	}
	void myFunction()
	{
		cout << "myFunction()������" << endl;
	}
};


int main(void)
{

	A obj_a;
	(reinterpret_cast<void(*)()>(**(int**)(&obj_a)))();//ͨ���麯��������麯��myVirtualFunciton()
	/*
	 * ��ֻռ��4���ֽڣ����麯����ָ�룬ָ���麯����,ֻ��һ���麯���������麯�����һ��
	 */
	long*pvptr = (long*)(&obj_a);//�Ѷ���obj_a�ĵ�ַ�õ�
	long*vptr = (long*)(*pvptr);//�õ��麯����ָ��
	typedef void(*Func)(void);//����һ������ָ������
	Func f1 = (Func)vptr[0];//�麯����ĵ�һ��ΪmyVirtualFunction()������
	f1();
	
	
	system("pause");
	return 0;
}
/*
 * 7_2_2�������˽�к���
 *
 *myFunction()������
myFunction()������
�밴���������. . .

 *
 */