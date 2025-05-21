#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;                // 字母
    int freq;               // 頻率
    Node *left, *right;     // 左右子樹
    Node(char c, int f): ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r): ch(0), freq(l->freq + r->freq),
                            left(l), right(r) {}
};

// 比較函式：頻率小的優先
struct Cmp {
    bool operator()(Node* a, Node* b) const {
        return a->freq > b->freq;
    }
};

// DFS 生成每個字母的二進位編碼
void buildCodes(Node* root, const string& prefix,
                unordered_map<char,string>& codes)
{
    if (!root) return;
    if (!root->left && !root->right) {
        // 葉節點，即字母
        codes[root->ch] = (prefix.empty() ? "0" : prefix);
    }
    buildCodes(root->left,  prefix + '0', codes);
    buildCodes(root->right, prefix + '1', codes);
}

int main() {
    string s;
    if (!getline(cin, s)) return 0;

    // 1. 計算頻率
    unordered_map<char,int> freq;
    for (char c : s) {
        freq[c]++;
    }

    // 2. 構建 Huffman Tree
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto& kv : freq) {
        pq.push(new Node(kv.first, kv.second));
    }

    // 特殊情況：只有一種字母
    if (pq.size() == 1) {
        Node* only = pq.top(); pq.pop();
        pq.push(new Node(only, nullptr));
    }

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        // 頻率較小的 a 放左，較大的 b 放右
        Node* parent = new Node(a, b);
        pq.push(parent);
    }
    Node* root = pq.top();

    // 3. 生成編碼
    unordered_map<char,string> codes;
    buildCodes(root, "", codes);

    // 4. 將 (字母, 編碼) 依編碼的二進位值排序
    vector<pair<char,string>> vec;
    for (auto& kv : codes) {
        vec.emplace_back(kv.first, kv.second);
    }
    sort(vec.begin(), vec.end(),
         [](auto& A, auto& B){
             // 轉成整數比較
             int va = stoi(A.second, nullptr, 2);
             int vb = stoi(B.second, nullptr, 2);
             return va < vb;
         });

    // 5. 輸出結果
    for (auto& p : vec) {
        cout << p.first << ":" << p.second << "\n";
    }
    return 0;
}
