#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

//����
class A {
 public:
};

class B {
 public:
    void myFunction01(){};  //��Ա����
    void myFunction02(){};
    void myFunction03(){};
};

class C {
 public:
    void myFunction01(){};  //��Ա����
    void myFunction02(){};
    void myFunction03(){};
    char ab;  //��Ա����
};

class D {
 public:
    void myFunction01(){};  //��Ա����
    void myFunction02(){};
    void myFunction03(){};

    int dd;  //��Ա����
};

int main(void) {
    A a;
    cout << sizeof(a) << endl;  // 1  sizeof(a)��sizeof(A)�ǵȼ۵�
    cout << sizeof(A) << endl;  // 1
    /*
     * Ϊʲôsizeof(����)=1�������ǵ���0��
     * shift+f9���ټ��ӣ��鿴��ַ�����ڴ��в鿴��ַ�������ǣ�cc
     * 	&a	0x008ffc13 {...}	A *
     * 	��Ϊ�������ڴ���������ʼ��ַ�ģ���Ȼ�����ʼ��ַ�����ڶ���a,
     * 	����sizeof(a)һ��������ڴ�ռ�����Ҫ��һ���ֽڣ���Ϊ���ڴ���ռ��λ�á�
     * 	�ͺ���һ�����ӵ����Ҫ���ڣ�������0ƽ���ס�
     * 	һ��������ھ����ڴ��ַ������Ҫ���ڴ�ռ���ռ��һ���ֽڡ�
     */

    B b;
    cout << sizeof(B) << endl;  // 1
    cout << sizeof(b) << endl;  // 1
    /*
     * ��ĳ�Ա������ռ�������(b)���ڴ�ռ�
     *
     */

    C c;
    cout << sizeof(C) << endl;  // 1
    cout << sizeof(c) << endl;  // 1
    /*
     * ���ڼ���һ��char����ռһ���ֽ��ڴ棬����Ϊʲô����һ���ֽڣ���
     * ������һ���ֽ�����洢����char��Ա��������ô��֤��
     */
    c.ab = 'c';
    /*
     *�Ӷϵ���ԣ�shift+F�鿴c�ĵ�ַ��Ȼ���ڡ��ڴ�1������в鿴
     *+		&c	0x00f9fc87 {ab=-52 '?' }
     *
     *ֵΪ0x00F9FC87  63 cc cc cc cc cc cc cc cc cc cc
     *
     *���ۣ���Ա������ռ���������ڴ�ռ��
     *
     */
    D d;
    cout << sizeof(D) << endl;  // 4
    cout << sizeof(d) << endl;  // 4
    d.dd = 4;
    /*+		&d	0x00affb9c {dd=-858993460 }
     *0x00AFFB9C  04 00 00 00 cc cc cc cc cc cc cc  ....???????
     *
     * ���ۣ���Ա�����ǰ�����ÿ�������еģ���ռ�ö����ֽ��ڴ�ģ�����Ա������ȻҲд����Ķ����У����ǳ�Ա�����ǲ�ռ�����ֽ����ģ���ռ�ڴ�ռ䣩
     *һ�������ɶ������ÿ�����󶼸��Լ��ĳ�Ա���������ڴ�ռ䣬ÿ����ĳ�Ա���Կ��Դ洢��ͬ��ֵ��
     * ��Ա����ÿ����ֻ����һ�����������ߣ������������������˶��ٸ�����Ķ���
     */

    system("pause");
    return 0;
}

/*
 * �������ռ�õĿռ�
 *	1.һ�����������ռ��1���ֽڵ��ڴ�ռ�
 *	2.��ĳ�Ա������ռ���������ڴ�ռ�
 *	3.��Ա������ռ���������ڴ�ռ��
 */
