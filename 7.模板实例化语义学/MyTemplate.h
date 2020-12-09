#pragma once

template <typename T>
class MyClass
{
public:
	T m_i;
	T m_j;
	MyClass(T temi = 0, T temj = 0) :m_i(temi), m_j(temj)
	{
		;
	}

	//��ͨ��Ա����
	void myFunction01() const { cout << "myFunction01������" << endl; }
	void myFunction02() const { cout << "myFunction02������" << endl; }

	//�麯��
	void myVirtualFunction01() const { cout << "myVirtualFunction01������" << endl; }


	//��ģ���е�ö������
	enum ECURRSTATUS
	{
		ECUS_Busy, ECUS_Free
	};

	//��̬��Ա����--����
	static int m_static_i;
	static T m_static_j;



};