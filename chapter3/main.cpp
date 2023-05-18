#include <iostream>
#include "stack_a.h"
#include "stack_c.h"
#include "queue_a.h"
#include "queue_c.h"
class stackQ {
    stack_a a, b;
public:
    void init() {
        a.init();
        b.init();
    }
    bool Push(int x) {
        if (a.isFull()) {
            return false;
        }
        while (!a.isEmpty()) {
            int tmp;
            a.Pop(tmp);
            b.Push(tmp);
        }
        a.Push(x);
        while (!b.isEmpty()) {
            int tmp;
            b.Pop(tmp);
            a.Push(tmp);
        }
        return true;
    }
    bool Pop(int &x) {
        if (a.isEmpty()) {
            return false;
        }
        a.Pop(x);
        return true;
    }
};
int main() {
    stackQ a{};
    a.init();
//    std::cout << a.isEmpty() << std::endl;
    for (int i = 0; i < 10; ++i) {
        a.Push(i);
    }
    for (int i = 0; i < 10; ++i) {
        int x;
        a.Pop(x);
        std::cout << x << std::endl;
    }
    return 0;
}
