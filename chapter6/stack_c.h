//
// Created by shertheus on 2023/4/30.
//
#include <cstdlib>
#ifndef CHAPTER3_STACK_C_H
#define CHAPTER3_STACK_C_H
typedef struct treeNode {
    int value;
    struct treeNode *l, *r;
}treeNode, *tree;

typedef struct LinkStackNode {
    treeNode* data;
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
    bool Push(tree x) {
        LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
        node->data = x;
        node->next = s;
        s = node;
        return true;
    }
    bool Pop(tree &x) {
        if (isEmpty()) {
            return false;
        }
        x = s->data;
        LinkStackNode *node = s;
        s = s->next;
        free(node);
        return true;
    }
    bool getTop(tree &x) {
        if (isEmpty()) {
            return false;
        }
        x = s->data;
        return true;
    }
};


#endif //CHAPTER3_STACK_C_H
