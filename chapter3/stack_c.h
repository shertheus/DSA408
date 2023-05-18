//
// Created by shertheus on 2023/4/30.
//
#include <cstdlib>
#ifndef CHAPTER3_STACK_C_H
#define CHAPTER3_STACK_C_H

typedef struct LinkStackNode {
    int data;
    LinkStackNode *next;
} LinkStack;
class stack_c {
    LinkStack *s;
public:
    void init() {
        s = nullptr;
    }
    bool isEmpty() {
        return s == nullptr;
    }
    bool Push(int x) {
        LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
        node->data = x;
        node->next = s;
        s = node;
        return true;
    }
    bool Pop(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = s->data;
        LinkStackNode *node = s;
        s = s->next;
        free(node);
        return true;
    }
    bool getTop(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = s->data;
        return true;
    }
};


#endif //CHAPTER3_STACK_C_H
