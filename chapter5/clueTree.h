//
// Created by shertheus on 2023/5/17.
//

#ifndef CHAPTER5_CLUETREE_H
#define CHAPTER5_CLUETREE_H
typedef struct clueTreeNode {
    int value;
    struct clueTreeNode *l, *r;
    int ltag, rtag;
}clueTreeNode, *clueTree;

clueTreeNode *pre = nullptr;
void visit(clueTreeNode *t) {
    if (t->l == nullptr) {
        t->ltag = 1;
        t->l = pre;
    }
    if (pre && pre->r != nullptr) {
        pre->rtag = 1;
        pre->r = t;
    }
    pre = t;
}

void inOrder(clueTree t) {
    if (t != nullptr) {
        inOrder(t->l);
        visit(t);
        inOrder(t->r);
    }
}

void clueIn(clueTree t) {
    inOrder(t);
    if (pre->r == nullptr) {
        pre->rtag = 1;
    }
}

void preOrder(clueTree t) {
    if (t != nullptr) {
        visit(t);
        if (t->ltag == 0) {
            preOrder(t->l);
        }
        preOrder(t->r);
    }
}

void cluePre(clueTree t) {
    preOrder(t);
    if (pre->r == nullptr) {
        pre->rtag = 1;
    }
}

void postOrder(clueTree t) {
    if (t != nullptr) {
        inOrder(t->l);
        inOrder(t->r);
        visit(t);
    }
}

void cluePost(clueTree t) {
    postOrder(t);
    if (pre->r == nullptr) {
        pre->rtag = 1;
    }
}

clueTreeNode *inFirstNode(clueTreeNode *p) {
    while (p->ltag == 0) {
        p = p->l;
    }
    return p;
}
clueTreeNode *inNext(clueTreeNode *p) {
    if (p->rtag) {
        return inFirstNode(p->r);
    } else {
        return p->r;
    }
}

clueTreeNode *inLastNode(clueTreeNode *p) {
    while (p->rtag == 0) {
        p = p->r;
    }
    return p;
}
clueTreeNode *inPre(clueTreeNode *p) {
    if (p->ltag) {
        return inFirstNode(p->l);
    } else {
        return p->l;
    }
}

void RevInorder(clueTreeNode *p) {
    for (clueTreeNode *t; t != nullptr; p = inPre(p)) {
        visit(p);
    }
}
#endif //CHAPTER5_CLUETREE_H
