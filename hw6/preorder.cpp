#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    
    int N;
    while (cin >> N) {
        Node* root = nullptr;

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            root = insert(root, num);
        }

        preorder(root);
        cout << "\n";
    }

    return 0;
}