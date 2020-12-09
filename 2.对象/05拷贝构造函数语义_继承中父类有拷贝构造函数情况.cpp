#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class CTB {
 public:
    CTB() {
    }
    CTB(const CTB& B)  //拷贝构造函数
    {
        cout << "父类有自己的拷贝构造函数" << endl;
    }
};

class CTBSon : public CTB {
 public:
};

int main(void) {
    CTBSon myctbSon;
    CTBSon myctbson02 = myctbSon;

    system("pause");
    return 0;
}

/*
*情况2.如果子类CTBSon没有自己的拷贝构造函数，但是他的父类CTB，父类有自己的拷贝构造函数
*当代码中有涉及到类CTBSon的拷贝构造函数时，编译器会为CTBSon合成一个拷贝构造函数。
*
*/