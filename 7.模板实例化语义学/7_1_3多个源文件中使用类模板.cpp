#include <iostream>

#include "MyTemplate.h"
using namespace std;
template class MyClass<int>;                       //��ʾʵ������ģ��
template void MyClass<int>::myFunction02() const;  //ʵ��������ĳ�Ա����

int main(void) {
    MyClass<int> myobj;
    myobj.m_i = 10;
    myobj.m_j = 20;
    myobj.myFunction01();
    myobj.myFunction02();
    myobj.myVirtualFunction01();
    system("pause");
    return 0;
}
/*
 * ���Դ�ļ���ʹ����ģ��
 * һ�����ļ������õ���ģ�壬���Է���.h�ļ���
 * �ڶ��cpp���ɵ�obj�ļ��У����ܲ�������ظ���ʵ�����࣬�������ӵ�ʱ��ֻ�ᱣ��һ��MyClass<int>���ʵ�壬����Ļᱻ���Ե���
 *
 * �麯����ʵ����
 *	Ϊʲô�麯��û�б����ã�Ҳ�ᱻʵ������������
 *	��Ϊ���麯�����������ͻ�����麯�����麯�������Ǹ����麯���ĵ�ַ����ô����Ҫʵ����ÿ���麯��������
 */