#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


	//�����̳й�ϵ������ӣ�����һ��Ҳ������_���캯��һ��һ����ǰ����C-->B--A(A1)
	//�ܶ�����£����ż̳���ȵ����ӣ���������˵ִ��ʱ��Ҳ�����ӣ�
	//��2.1�����ؼ̳�һ��Ҳ�ᵼ�¿�������

	class A
	{
	public:
		A()
		{
			cout << "A::A()" << endl;
		}
	};
	class A1
	{
	public:
		A1()
		{
			cout << "A1::A1()" << endl;
		}
	};

	class B :public A, public A1
	{
	public:
	};

	class C :public B
	{
	public:
		C()
		{
			cout << "C::C()" << endl;
		}
	};

/*
 00291FB0  push        ebp  
00291FB1  mov         ebp,esp  
00291FB3  sub         esp,0CCh  
00291FB9  push        ebx  
00291FBA  push        esi  
00291FBB  push        edi  
00291FBC  push        ecx  
00291FBD  lea         edi,[ebp-0CCh]  
00291FC3  mov         ecx,33h  
00291FC8  mov         eax,0CCCCCCCCh  
00291FCD  rep stos    dword ptr es:[edi]  
00291FCF  pop         ecx  
00291FD0  mov         dword ptr [this],ecx  
		{
00291FD3  mov         ecx,dword ptr [this]  
00291FD6  call        B::B (029139Dh)  
			cout << "C::C()" << endl;//�������ڹ��캯���в������--���캯��һ��һ���������
 */
	void func()
	{
		C cobj;

	}


int main()
{
	func();
		
	system("pause");
	return 1;
}



