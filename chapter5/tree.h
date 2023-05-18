//
// Created by shertheus on 2023/5/16.
//

#ifndef CHAPTER5_TREE_H
#define CHAPTER5_TREE_H
#include <iostream>
#include "stack_c.h"
#include "queue_c.h"

void visit(treeNode *node){
    std::cout<<node->value<<std::endl;
}

void preOrder(tree t) {
    if (t != NULL) {
        visit(t);
        preOrder(t->l);
        preOrder(t->r);
    }
}

void inOrder(tree t) {
    if (t != NULL) {
        visit(t);
        inOrder(t->l);
        inOrder(t->r);
    }
}
void postOrder(tree t) {
    if (t != NULL) {
        visit(t);
        postOrder(t->l);
        postOrder(t->r);
    }
}

void levelOrder(tree t) {
    queue_c q;
    q.init();
    q.enQueue(t);
    tree p;
    while (!q.isEmpty()) {
        q.deQueue(t);
        visit(t);
        if (t->l != nullptr) {
            q.enQueue(t->l);
        }
        if (t->r != nullptr) {
            q.enQueue(t->r);
        }
    }
}

void stack_pre(tree t){
    stack_c s;
    s.init();
    tree p = t;
    while (!s.isEmpty() || p != nullptr) {
        if (p) {
            visit(p);
            s.Push(p);
            p = p->l;
        } else {
            s.Pop(p);
            p = p->r;
        }
    }
}

void stack_in(tree t){
    stack_c s;
    s.init();
    tree p = t;
    while (!s.isEmpty() || p != nullptr) {
        if (p) {
            s.Push(p);
            p = p->l;
        } else {
            s.Pop(p);
            visit(p);
            p = p->r;
        }
    }
}

void stack_post(tree t){
    stack_c s;
    s.init();
    tree p = t;
    tree r = nullptr;
    while (!s.isEmpty() || p != nullptr) {
        if (p) {
            s.Push(p);
            p = p->l;
        } else {
            s.getTop(p);
            if (p->r != nullptr && p->r != r) {
                p = p->r;
            } else {
                s.Pop(p);
                visit(p);
                r = p;
                p = nullptr;
            }
        }
    }
}

#endif //CHAPTER5_TREE_H
