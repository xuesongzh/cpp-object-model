#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef string mytype;

class A {
    //typedef int mytype;
 public:
    void myFunction(mytype temvalue);  //这里mytype是string类型

 public:
    typedef int mytype;
    mytype value;  //先定义类型，这里m_value是int类型
};

void A::myFunction(::mytype temvalue) {
    //value = temvalue;//error 将string类型转换为int类型0
}

int main(void) {
    system("pause");
    return 0;
}

/*
* 结论：对于成员函数参数，是在第一次遇到mytype类型的时候被决定的。
* 所以第一次遇见mytpye的时候，编译器看到了typedef string mytype，就把参数当作string类型。
* 结论：为了在类中尽早看到mytype类型，类型定义语句一定要定义到类最开始的位置。
*/
