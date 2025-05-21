#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    bool has;
    Node* left;
    Node* right;
    Node(): val(0), has(false), left(nullptr), right(nullptr) {}
};

// 在樹中加入一個節點，path 由 'L'/'R' 組成，空 path 表示根
// 若父節點不存在或重複插入，就回傳 false
bool insertNode(Node* root, int v, const string& path) {
    Node* cur = root;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] == 'L') {
            if (!cur->left) {
                // 只有最後一步可以 new，途中若父不存在即錯
                if (i == path.size() - 1)
                    cur->left = new Node();
                else
                    return false;
            }
            cur = cur->left;
        } else { // 'R'
            if (!cur->right) {
                if (i == path.size() - 1)
                    cur->right = new Node();
                else
                    return false;
            }
            cur = cur->right;
        }
    }
    if (cur->has) return false;  // 重複插入
    cur->val = v;
    cur->has = true;
    return true;
}

// 層序遍歷，如果途中遇到尚未填值的節點就回傳空 vector
vector<int> levelOrder(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        if (!p->has) return {}; // 發現 hole
        ans.push_back(p->val);
        if (p->left)  q.push(p->left);
        if (p->right) q.push(p->right);
    }
    return ans;
}

// 釋放整棵樹
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string token;
    // 一直讀，直到 EOF
    while (true) {
        Node* root = new Node();
        bool ok = true, hasRoot = false;

        // 讀一組資料，直到遇到 "()"
        while (cin >> token) {
            if (token == "()") break;
            // 去掉左右括號
            token = token.substr(1, token.size() - 2);
            // split by comma
            int comma = token.find(',');
            int v = stoi(token.substr(0, comma));
            string path = token.substr(comma + 1);
            if (path.empty()) hasRoot = true;
            if (ok && !insertNode(root, v, path))
                ok = false;
        }

        if (!hasRoot) ok = false;  // 一定要有根

        if (!ok) {
            cout << "not complete\n";
        } else {
            auto ans = levelOrder(root);
            if (ans.empty()) {
                cout << "not complete\n";
            } else {
                for (int i = 0; i < ans.size(); ++i) {
                    if (i) cout << ' ';
                    cout << ans[i];
                }
                cout << "\n";
            }
        }

        freeTree(root);
        // 如果已經到檔尾，結束
        if (!cin) break;
    }

    return 0;
}
