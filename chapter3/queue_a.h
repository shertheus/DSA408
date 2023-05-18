//
// Created by shertheus on 2023/5/2.
//

#ifndef CHAPTER3_QUEUE_A_H
#define CHAPTER3_QUEUE_A_H
class queue_a {
    int data[10];
    int front, rear;
    int flag;
public:
    void init() {
        front = 0;
        rear = 0;
        flag = 0;
    }
    bool isEmpty(){
        if (!flag && front == rear) {
            return true;
        }
        return false;
    }
    bool enQueue(int x) {
        if (flag && front == rear) {
            return false;
        }
        data[rear] = x;
        rear = (rear + 1) % 10;
        flag = 1;
        return true;
    }
    bool deQueue(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = data[front];
        front = (front + 1) % 10;
        flag = 0;
        return true;
    }
    bool getTop(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = data[front];
        return true;
    }
    bool getEnd(int &x) {
        if (isEmpty()) {
            return false;
        }
        x = data[(rear + 9) % 10];
        return true;
    }
};
#endif //CHAPTER3_QUEUE_A_H
