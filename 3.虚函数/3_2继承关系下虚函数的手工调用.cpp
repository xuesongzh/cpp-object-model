#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Base {
 public:
    virtual void myVirtualFunction01() {
        cout << "myVirtualFunction01" << endl;
    }
    virtual void myVirtualFunction02() {
        cout << "myVirtualFunction02" << endl;
    }
    virtual void myVirtualFunction03() {
        cout << "myVirtualFunction03" << endl;
    }
};

class Derive : public Base {
    //��д����myVirtualFunction02()����
    void myVirtualFunction02() override {
        cout << "����������д��myVirtualFunction02����" << endl;
    }
};

int main(void) {
    cout << sizeof(Base) << endl;    //4
    cout << sizeof(Derive) << endl;  //4

    Derive *derive = new Derive();  //����ָ��
    long *pvptr = (long *)derive;   //��ָ����������ָ��ת��Ϊlong*����
    long *vptr = (long *)(*pvptr);  //(*pvptrָ��Ķ�����Ҳ����Deriv������)--
    //Derive��������ռ��4���ֽڵģ�����洢�����麯�����ַ  vptrָ���������麯����
    /*
	 derive	0x01534be0 {...}	Derive *
	 pvptr	0x01534be0 {7445368}	long *
	 vptr	0x00719b78(ֵΪ7445368) {virtualFunction.exe!const Derive::`vftable'} {7410594}	long *
	 */

    //����Ԥ���麯��������洢��3�3���麯��
    for (int i = 0; i < 5; i++) {
        printf("vptr[%d]=0x%p\n", i, vptr[i]);
    }
    /*
	 *  vptr[0]=0x00C513A2
		vptr[1]=0x00C51258
		vptr[2]=0x00C5108C
		vptr[3]=0x00000000
		vptr[4]=0xC7CAE2D5
	 */
    //���Ե����麯��
    typedef void (*Func)(void);  //����һ������ָ������
    Func f1 = (Func)vptr[0];     //vptr[0]��ָ���һ���麯��
    Func f2 = (Func)vptr[1];     //vptr[1]��ָ��ڶ����麯��
    Func f3 = (Func)vptr[2];     //vptr[2]��ָ��������麯��
    Func f4 = (Func)vptr[3];
    Func f5 = (Func)vptr[4];

    f1();
    f2();
    f3();
    //f4();//���쳣
    /*
	 myVirtualFunction01
	 ����������д��myVirtualFunction02����
	 myVirtualFunction03
	*/

    Base *base = new Base();
    long *pbase = (long *)base;
    long *vptrBase = (long *)(*pbase);
    for (int i = 0; i < 3; i++) {
        printf("vptrBase[%d]=0x%p\n", i, vptrBase[i]);
    }
    /*
	 *  vptrBase[0]=0x009913A2
		vptrBase[1]=0x0099119F
		vptrBase[2]=0x0099108C
	 */
    Func fb1 = (Func)vptrBase[0];
    Func fb2 = (Func)vptrBase[1];
    Func fb3 = (Func)vptrBase[2];

    fb1();
    fb2();
    fb3();
    /*
	myVirtualFunction01
	myVirtualFunction02
	myVirtualFunction03
	*/

    system("pause");
    return 0;
}
/*
* (1)�̳й�ϵ���麯�����ֹ�����
*	��һ�����ж����麯�����͵ĳ�Ա��������ô�����ָ��ָ����ڴ�ռ䶼�����������麯����ġ�
*	�麯������Կ���һ�����飬����ʹ��[]�±���ʷ������ʡ��Ϳ���ʹ�ú��������������麯����������麯��
* (2)
*	1.һ����ֻ�а����麯���Ż�����麯����ͬ��һ����Ķ������麯�����������Լ����麯����ָ��
*	2.���������麯���������п϶����麯�������仰˵�����������麯�������������麯������Ϊ����̳и��ࡣ
*		2.1Ҳ������Ϊ�����������麯������������override�ĺ�����д��дvirtual��Ȼ���麯����
*		2.2���ǲ��ܸ��໹�����࣬���ֱ���һ���麯����������Ϊ������һ���麯����+�����м̳е��麯����=������2���麯����
*		���ุ��ֱ�һ���麯����
*		2.3�������Ƿ���ܴ��ڶ���麯������ ���潲�⡣
*	3.���������ȫû���µ��麯���������ǿ�����Ϊ������麯����͸�����麯����������ͬ��
*		������������ͬ���������ڴ��д��ڲ�ͬλ�á����仰˵������������ͬ�����ű�
*		����ڴ�λ�úͱ��д洢�������ǲ�ͬ�ĸ��
*		�麯������ÿһ�����һ���麯�����׵�ַ���������������麯����ĳ��͸����麯����ĳ���ʾͬһ��������
*			������û�и��Ǹ���ĺ���������ñ�������ʾ���麯����ַӦ����ͬ��
*
*	4.�����麯���������ݲ���֪������麯���м����Ϳ���ʹ�����鷽ʽ���ʼ�����
*
*/
