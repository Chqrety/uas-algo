#include <iostream>
using namespace std;

// Husnul Fikri Averus
// A11.2024.15776

const int MAX = 100;

class SyncList {
private:
    int stack[MAX];
    int queue[MAX];
    int top;
    int front, rear;

public:
    SyncList() {
        top = -1;
        front = 0;
        rear = -1;
    }

    void addValue(int value) {
        if (top < MAX - 1 && rear < MAX - 1) {
            stack[++top] = value;
            queue[++rear] = value;
        }
    }

    void updateValueAt(int index, int newValue) {
        if (index >= 0 && index <= top && index <= rear) {
            stack[index] = newValue;
            queue[index] = newValue;
        }
    }

    void display() {
        cout << "Stack (S): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;

        cout << "Queue (Q): ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int A[] = {4, 7, 1, 9, 2};
    int n = 5;

    SyncList list;

    for (int i = 0; i < n; i++) {
        list.addValue(A[i]);
    }

    list.display();

    list.updateValueAt(1, 99);
    list.display();

    list.addValue(88);
    list.display();

    return 0;
}
