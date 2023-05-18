#include <iostream>
typedef int elementType;
typedef struct linkNode {
    elementType data;
    struct linkNode* next;
} *linkList;

bool insertNodeByHead (elementType e, linkList &head) {
    linkNode *currentPtr = head;
    if (currentPtr == nullptr) {
        return false;
    }
    linkNode *node = new linkNode;
    node->data = e;
    node->next = currentPtr->next;
    head->next = node;
    return true;
};

bool insertNodeByTail (elementType e, linkList &head) {
    linkNode *currentPtr = head;
    if (currentPtr == nullptr) {
        return false;
    }
    while (currentPtr->next != nullptr) {
        currentPtr = currentPtr->next;
    }
    linkNode *node = new linkNode;
    node->data = e;
    node->next = nullptr;
    currentPtr->next = node;
    return true;
};

linkList createList (int n, linkList list) {
    for (int i = 0; i < n; ++i) {
        std::cout << "input element data:" << std::endl;
        elementType e = 0;
        std::cin >> e;
//        insertNodeByHead(e, list);
        insertNodeByTail(e, list);
    }
    return list;
};
bool insertAfter(int idx, elementType e) {

}

int main() {
    linkList list = new linkNode;
    list->data = -1;
    list->next = nullptr;
    createList(10, list);
    linkNode *currentPtr = list->next;
    for (; currentPtr != nullptr; currentPtr = currentPtr->next) {
        std::cout << currentPtr->data << std::endl;
    }
    return 0;
}
