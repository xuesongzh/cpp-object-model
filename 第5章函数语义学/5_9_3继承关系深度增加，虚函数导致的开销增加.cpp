#include <iostream>
#include <vector>
#include <ctime>

using namespace std;



	//�����̳й�ϵ������ӣ��麯�����µĿ�������
	//�麯���Ĵ��ڵ��������һ���麯���������������һ���麯����ָ�룬�ڹ��캯������Ӵ��룬���麯����ָ��ָ���麯����
	class A
	{
	public:
		/*A()
		{
		cout << "A::A()" << endl;
		}*/
		virtual void myvirfunc() {}
	};

	class B :public A
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
 		public:
			C()
	00DF2040  push        ebp  
	00DF2041  mov         ebp,esp  
	00DF2043  sub         esp,0CCh  
	00DF2049  push        ebx  
	00DF204A  push        esi  
	00DF204B  push        edi  
	00DF204C  push        ecx  
	00DF204D  lea         edi,[ebp-0CCh]  
	00DF2053  mov         ecx,33h  
	00DF2058  mov         eax,0CCCCCCCCh  
	00DF205D  rep stos    dword ptr es:[edi]  
	00DF205F  pop         ecx  
	00DF2060  mov         dword ptr [this],ecx  
			{
	00DF2063  mov         ecx,dword ptr [this]  
	00DF2066  call        B::B (0DF1433h)  
	00DF206B  mov         eax,dword ptr [this]  
	00DF206E  mov         dword ptr [eax],offset C::`vftable' (0DF9B4Ch)  //�麯����ָ�븳ֵ
				cout << "C::C()" << endl;
	00DF2074  mov         esi,esp  
	00DF2076  push        offset std::endl<char,std::char_traits<char> > (0DF109Bh)  
	00DF207B  push        offset string "C::C()" (0DF9B54h)  
	00DF2080  mov         eax,dword ptr [_imp_?cout@std@@3V?$basic_ostream@DU?$char_traits@D@std@@@1@A (0DFD098h)]  
	00DF2085  push        eax  
	00DF2086  call        std::operator<<<std::char_traits<char> > (0DF140Bh)  
	00DF208B  add         esp,8  
	00DF208E  mov         ecx,eax  
	00DF2090  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0DFD0A4h)]  
	00DF2096  cmp         esi,esp  
	00DF2098  call        __RTC_CheckEsp (0DF11A4h)  
			}
 */

	void func()
	{
		C *pc = new C();


	}


int main()
{
	func();
	system("pause");
	return 1;
}



