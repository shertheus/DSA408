//
// Created by shertheus on 2023/4/30.
//

#ifndef CHAPTER3_STACK_A_H
#define CHAPTER3_STACK_A_H


class stack_a {
    int data[10];
    int top;
public:
    void init() {
        top = 0;
    }
    bool isEmpty() {
        return top == 0;
    }
    bool Push(int x) {
        if (top == 10) {
            return false;
        }
        data[top] = x;
        top += 1;
        return true;
    }
    bool Pop(int &x) {
        if (isEmpty()) {
            return false;
        }
        top -= 1;
        x = data[top];
        return true;
    }
    bool getTop(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = data[top - 1];
        return true;
    }

    bool isFull() {
        if (top == 10) {
            return true;
        }
        return false;
    }
};


#endif //CHAPTER3_STACK_A_H
