//
// Created by shertheus on 2023/5/2.
//
#include <iostream>
#ifndef CHAPTER3_QUEUE_C_H
#define CHAPTER3_QUEUE_C_H
typedef struct treeNode {
    int value;
    struct treeNode *l, *r;
}treeNode, *tree;

typedef struct LinkQueueNode {
    treeNode *data;
    LinkQueueNode *next;
} *LinkQueue;

class queue_c {
    LinkQueue q;
    LinkQueueNode *rear;
public:
    void init() {
        q = nullptr;
        rear = nullptr;
    }
    bool isEmpty() {
        return q == nullptr;
    }
    bool enQueue(tree x) {
        LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
        node->data = x;
        node->next = nullptr;
        if (isEmpty()) {
            q = node;
            rear = node;
        } else {
            rear->next = node;
            rear = node;
        }
        return true;
    }
    bool deQueue(tree &x) {
        if (isEmpty()) {
            return false;
        }
        x = q->data;
        LinkQueueNode *node = q;
        q = q->next;
        if (rear == node) {
            rear = nullptr;
        }
        free(node);
        return true;
    }
    bool getTop(tree &x) {
        if (isEmpty()) {
            return false;
        }
        x = q->data;
        return true;
    }
    bool getEnd(tree &x) {
        if (isEmpty()) {
            return false;
        }
        x = rear->data;
        return true;
    }
};
#endif //CHAPTER3_QUEUE_C_H
