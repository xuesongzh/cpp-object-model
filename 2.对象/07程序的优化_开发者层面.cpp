#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class CTemValue {
 public:
    int value1;
    int value2;

 public:
    CTemValue(int v1 = 0, int v2 = 0)
        : value1(v1), value2(v2)  //构造函数
    {
        cout << "调用了构造函数" << endl;
        cout << "value1=" << value1 << endl;
        cout << "value2=" << value2 << endl;
    }
    CTemValue(const CTemValue &ct)
        : value1(ct.value1), value2(ct.value2) {
        cout << "调用了拷贝构造函数" << endl;
    }
    virtual ~CTemValue() {
        cout << "调用了析构函数" << endl;
    }
};

//开发者视角
CTemValue DoubleMyself(CTemValue &t) {
    // (1) 开发者层面
    // CTemValue tem;
    // tem.value1 = t.value1 * 2;
    // tem.value2 = t.value2 * 2;
    // return tem;  //生成一个临时对象，然后调用拷贝构造函数把tem的内容拷贝构造到这个临时对象，然后返回临时对象。

    //优化后
    return CTemValue(t.value1 * 2, t.value2 * 2);  //生成一个临时对象直接返回，减少一次拷贝构造和析构
}

int main(void) {
    CTemValue ts1(10, 20);
    //CTemValue ts2 = DoubleMyself(ts1);//使用一个对象来接收，return的时候才析构
    DoubleMyself(ts1);  // 调用完立即析构
    /*
	 调用了构造函数
	value1=10
	value2=20
	调用了构造函数
	value1=20
	value2=40
	调用了析构函数
	 */

    system("pause");
    return 0;
}