#include <iostream>
using namespace std;

// Husnul Fikri Averus
// A11.2024.15776

const int MAX = 100;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) return newNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void preOrder(Node* root, int result[], int& idx) {
    if (root) {
        result[idx++] = root->data;
        preOrder(root->left, result, idx);
        preOrder(root->right, result, idx);
    }
}

void inOrder(Node* root, int result[], int& idx) {
    if (root) {
        inOrder(root->left, result, idx);
        result[idx++] = root->data;
        inOrder(root->right, result, idx);
    }
}

void postOrder(Node* root, int result[], int& idx) {
    if (root) {
        postOrder(root->left, result, idx);
        postOrder(root->right, result, idx);
        result[idx++] = root->data;
    }
}

int compare(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void printArray(const char* label, int arr[], int n) {
    cout << label << ": ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int A[] = {4, 3, 2};
    int n = 3;

    int S[MAX], Q[MAX];
    for (int i = 0; i < n; i++) {
        S[i] = A[n - 1 - i];
        Q[i] = A[i];
    }

    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insert(root, A[i]);
    }

    int pre[MAX], in[MAX], post[MAX];
    int idx;

    idx = 0; preOrder(root, pre, idx);
    idx = 0; inOrder(root, in, idx);
    idx = 0; postOrder(root, post, idx);

    printArray("Stack (S)", S, n);
    printArray("Queue (Q)", Q, n);
    printArray("PreOrder", pre, n);
    printArray("InOrder", in, n);
    printArray("PostOrder", post, n);

    cout << endl;
    cout << "|        |  S  |  Q  |" << endl;
    cout << "|--------|-----|-----|" << endl;
    cout << "| Pre    |  " << compare(pre, S, n) << "  |  " << compare(pre, Q, n) << "  |" << endl;
    cout << "| In     |  " << compare(in, S, n) << "  |  " << compare(in, Q, n) << "  |" << endl;
    cout << "| Post   |  " << compare(post, S, n) << "  |  " << compare(post, Q, n) << "  |" << endl;

    return 0;
}