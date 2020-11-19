#include<iostream>

using namespace std;

//7_1_2��ģ�����ģ���е�ö������_ģ�����о�̬����_��Ա����
/*
 * ���ۣ�1.���������û��ʹ�õ���ģ�壬��ô�������ͻ��MyClass����ģ���Ӷ��������ͺ������û�����һ����
 * 2.1ģ���е�ö������
 * 2.2��ģ���еľ�̬��Ա����
 *		���ۣ��౾��û�б�ʵ������ֻ�ǳ�Ա������ʵ����
 *2.3��ģ���ʵ����
 *
 *2.4��Ա������ʵ����
 * ���⣺�౻ʵ�������������еĳ�Ա������ʵ�����������𣿣�
 *		��û�е��ó�Ա����������£��ǲ���ʵ����
 *
 * 
 * 
 */
template <typename T>
class MyClass
{
public:
	T m_i;
	T m_j;
	MyClass(T temi=0,T temj=0):m_i(temi),m_j(temj)
	{
		;
	}

	//��ͨ��Ա����
	void myFunction01() const{ cout << "myFunction01������" << endl; }
	void myFunction02() const{ cout << "myFunction02������" << endl; }
	
	//��ģ���е�ö������
	enum ECURRSTATUS
	{
		ECUS_Busy, ECUS_Free
	};

	//��̬��Ա����--����
	static int m_static_i;
	static T m_static_j;



};

//��̬��Ա��������
template<typename T>
int MyClass<T>::m_static_i = 10;

template<typename T>
T MyClass<T>::m_static_j = 15;//���︳ֵȡ����T�����ͣ�����ָ������Ҫ��15����


void func()
{
	MyClass<int>::ECURRSTATUS myEnum;
	myEnum = MyClass<int>::ECUS_Busy;

	//������ö������
	MyClass<double>::ECURRSTATUS myEnum02;
	myEnum02 = MyClass<double>::ECUS_Free;
	//���ۣ����е�ö�����������ھ������ģ�����ͣ����Ǻ���ģ���ϵ����


	//2.2��̬��Ա����--�౾��û�б�ʵ������ֻ�ǳ�Ա������ʵ����
	MyClass<int>::m_static_i = 14;
	MyClass<float>::m_static_i = 15;
	cout << MyClass<int>::m_static_i << endl;//14
	cout << MyClass<float>::m_static_i << endl;//15
	//����������ص����ͱ���

	MyClass<int>::m_static_j = 34;
	cout << MyClass<int>::m_static_j << endl;//34
	

	//2.3��ģ���ʵ����
	MyClass<int>*pobj01 = NULL;//����д��û��ʵ�������������
	
	const MyClass<int>&obj01 = 0;//�����˹��캯����ʵ��������ģ��
	/*
	 * վ�ڱ������Ƕȣ�
	 * MyClass<int> temObj(0);
	 * const MyClass<int>&obj01=temObj;
	 */

	//2.4��Ա����ʵ����
	obj01.myFunction01();//const����������const����
	
}

int main(void)
{
	func();
	system("pause");
	return 0;
}