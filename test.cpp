#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    TreeNode *a = NULL, *b = NULL, *prev = NULL;

    void inorder(TreeNode* r) {
        if (!r) return;
        inorder(r->left);
        if (prev && prev->val > r->val) {
            if (!a) a = prev;
            b = r;
        }
        prev = r;
        inorder(r->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(a->val, b->val);
    }
};

const int N = INT_MIN;   // stands for "null" in the input list

TreeNode* build(vector<int> v) {          // LeetCode-style level order
    if (v.empty() || v[0] == N) return NULL;
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < v.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < v.size() && v[i] != N) { cur->left = new TreeNode(v[i]); q.push(cur->left); }
        i++;
        if (i < v.size() && v[i] != N) { cur->right = new TreeNode(v[i]); q.push(cur->right); }
        i++;
    }
    return root;
}

void print(TreeNode* root) {              // prints level order with nulls
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (!cur) { out.push_back("null"); continue; }
        out.push_back(to_string(cur->val));
        q.push(cur->left);
        q.push(cur->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    cout << "[";
    for (size_t i = 0; i < out.size(); i++) cout << (i ? "," : "") << out[i];
    cout << "]\n";
}

int main() {
    TreeNode* root = build({3, 1, 4, N, N, 2});
    Solution().recoverTree(root);
    print(root);                          // expected: [2,1,4,null,null,3]
}