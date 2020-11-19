#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class X
{
public:
	int x;
	int y;
	int z;
	//X():x(0),y(0),z(0)
	X() 
	{
		/*��������������α���룺
		 *this->vptr=&vtebl
		*
		 */
		memset(this, 0, sizeof(X));
		cout << "���캯����ִ��" << endl;
		
	}
	//�������캯��
	//X(const X&tm):x(tm.x),y(tm.y),z(tm.z)
	X(const X&tm)
	{
		memcpy(this, &tm, sizeof(X));//��������--������Ч�ʵĿ�������--����麯����ָ�����
		cout << "�������캯����ִ��" << endl;
	}
	//��ͨ��Ա����
	void myFunction()
	{
		cout << "��ͨ����myFunction()������ִ����" << endl;
	}
	
	virtual  ~X()
	{
		cout << "������������ִ��" << endl;
	}
	virtual void myVirtualFunction()
	{
		cout << "��ͨ����������myVirtualFunction��ִ��" << endl;
	}
};

int main(void)
{
	X x0;//���ù��캯��
	x0.x = 100;
	x0.y = 200;
	x0.z = 300;
	X x1(x0);//���ÿ������캯��   ��ע�͵��������캯�����memset���麯��ָ����ֵ0x00a78b34 {virtualFunction.exe!const X::`vftable'} {0x00a711ae {virtualFunction.exe!X::`vector deleting destructor'(unsigned int)}, ...}
	cout << "x1.x" << x1.x << endl;
	cout << "y1.x" << x1.y << endl;
	cout << "z1.x" << x1.z << endl;

	//�麯��ָ�뱻��գ����ǻ��ǿ��Ե��óɹ��麯��
	x0.myVirtualFunction();
	

	//�ڶ��Ϸ����ڴ洴�������ܷ�����麯������ --new�����Ķ��󣨶��ϣ��޷������麯��
	X *p_x = new X();//���캯�����Գɹ�����
	p_x->myFunction();//ok
	//p_x->myVirtualFunction();//error �������쳣,�޷������麯����--��ͨ���麯����ָ�룬���麯�������ҵ���Ӧ�ĺ���ִ�С�
	//delete p_x;//errorҲ�޷���������������

	int i = 9;
	printf("&i=%p\n", &i);

	printf("myFunction�ĵ�ַ��%p\n", &X::myFunction);//0x00ca2830 {virtualFunction.exe!X::myFunction(void)}
	//������ӡ���麯����ַ�Բ��ԣ�����������Ҫʹ��ǰ���ת��Ϊlong*��������ӡ??
	printf("myVirtualFunction�ĵ�ַ��%p\n", &X::myVirtualFunction);//0x00ca28b0 {virtualFunction.exe!X::myVirtualFunction(void)}
	/*
	 &i=0076F8F8
	myFunction�ĵ�ַ��001B14B5
	myVirtualFunction�ĵ�ַ��001B14BA
	ÿ������i�ĵ�ַ�������ı䣬����ÿ������myFunction ��M��VirtualFunction�ĵ�ַ���������ı䡣

	�鿴�������룺
			printf("myFunction�ĵ�ַ��%p\n", &X::myFunction);//0x00ca2830 {virtualFunction.exe!X::myFunction(void)}
		00C02B14  push        offset X::myFunction (0C014B5h)  
		00C02B19  push        offset string "myFunction\xb5\xc4\xb5\xd8\xd6\xb7\xca\xc7%p\n" (0C09B68h)  
		00C02B1E  call        _printf (0C014B0h)  
		00C02B23  add         esp,8  
			//������ӡ���麯����ַ�Բ��ԣ�����������Ҫʹ��ǰ���ת��Ϊlong*��������ӡ??
			printf("myVirtualFunction�ĵ�ַ��%p\n", &X::myVirtualFunction);//0x00ca28b0 {virtualFunction.exe!X::myVirtualFunction(void)}
		00C02B26  push        offset X::`vcall'{4}' (0C014BAh)  
		00C02B2B  push        offset string "myVirtualFunction\xb5\xc4\xb5\xd8\xd6\xb7\xca\xc7%p\n" (0C09B94h)  
		00C02B30  call        _printf (0C014B0h)  
		00C02B35  add         esp,8  

	�����ƶϣ������ʱ���ȷ�����˺����ĵ�ַ�����ݾ��Ƿ���������ֱ��callһ�����ֵġ�

	��̬���ࣺ�����ʱ���ȷ��������һ���������������Ѻ�������ֱ��ת��Ϊһ����ַ��ֱ��call
	��̬���ࣺ���ڳ�������ʱ������ʱ���������̬�ѵ������ͱ����ú����󶨵�һ�𣬶�̬����һ��ֻ�ڶ�̬���麯��������²Żᷢ����
		����60��x0.myVirtualFunction();�ĺ������ò��ж�̬���麯��ָ�뱻��գ�Ҳ����ֱ�ӵ����麯����
		66��//p_x->myVirtualFunction();��ͨ���麯������á�

	�ܽ᣺1����ջ�Ϸ���Ķ����ǲ�ͨ���麯��������麯�����Ǿ�̬���࣬�����������麯����ָ�뱻���Ҳ���Ե����麯��
		2.�ڶ���ͨ��new����Ķ�����ͨ���麯����ָ�룬���麯�����Ӧ���������ã��麯����ָ�벻����գ�Ҳ���ǹ��캯������ʹ��memset��memcoy
		3.��Ҫ���ף��麯������̬�����ָ�����ר�Ÿ�ָ���������ʹ�õġ�
	 */

	system("pause");
	return 0;
}
/*
* (1)�������಻��ʱ�������麯����������
*	�������ࣺ�Ƚϼ򵥵��࣬���䲻�����麯���������
*	
*ʹ��memset��memcoyд���캯������������ಢ��������������������麯����ʹ������д���ͻ��д���
���ۣ����캯���У������麯��ʱ����ʹ��memset��memcpy()������
*��������ĳЩ����£��������������ڲ����һЩ���ǿ��������������Ǵ��ڵĳ�Ա����(��ʽ��Ա����,���麯����ָ��),������Щ��Ա�������࣬�Ͳ������ˡ�
*ͬʱ�������صĳ�Ա���������ӻ��߸�ֵ��ʱ������������������ִ�й��캯�����߿������캯���ĺ����忪ʼ֮ǰ��
*��ô�����ʹ��memcpy��memset���ܰѱ����������ر���(�麯����ָ��)��ֵ�������(���߸�����)��
*�磺���������������麯����������Ĭ����������������麯����ָ�룬����麯����ָ��������صĳ�Ա������
*	
* (2)��Ĺ��캯���а���memset��memcoy�����ϵ�new�����Ķ����޷������麯��
*	���ڶ�̬���麯�������࣬���࣬�麯������Ҫ�����������Ǹ���ָ��ָ������������������
*	ֻ���麯����û�м̳У���ô�麯������ͨ������ʲô�����أ�----������Ϊûʲôʵ������
*	
* (3)��̬�������
* �����麯����ָ�룬ͨ���麯����ָ������麯�����е��麯��ִ��������Ϊ�ж�̬��
* (4)
* (5)
* (6)(7)
*/
