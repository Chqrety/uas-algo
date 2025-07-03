#include <iostream>
using namespace std;

// Husnul Fikri Averus
// A11.2024.15776

const int MAX = 100;

class Stack {
private:
    int data[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int value) {
        if (top < MAX - 1) {
            data[++top] = value;
        }
    }

    void display() {
        cout << "Stack (S): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

class Queue {
private:
    int data[MAX];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear < MAX - 1) {
            data[++rear] = value;
        }
    }

    void display() {
        cout << "Queue (Q): ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int A[] = {4, 7, 1, 9, 2};
    int n = 5;

    Stack S;
    Queue Q;

    for (int i = 0; i < n; i++) {
        S.push(A[i]);
        Q.enqueue(A[i]);
    }

    S.display();
    Q.display();

    return 0;
}
