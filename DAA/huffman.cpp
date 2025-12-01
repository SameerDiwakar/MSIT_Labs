#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

void preOrder(Node* root, vector<string>& ans, string code) {
    if (!root) return;
    if (!root->left && !root->right) {
        ans.push_back(code);
        return;
    }
    preOrder(root->left, ans, code + "0");
    preOrder(root->right, ans, code + "1");
}

vector<string> huffmanCodes(string s, vector<int> freq) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < freq.size(); i++) {
        pq.push(new Node(freq[i]));
    }

    while (pq.size() >= 2) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* newNode = new Node(l->data + r->data);
        newNode->left = l;
        newNode->right = r;
        pq.push(newNode);
    }

    Node* root = pq.top();
    vector<string> ans;
    preOrder(root, ans, "");
    return ans;
}

int main() {
    string s = "wxyz";
    vector<int> freq = {7, 3, 10, 15};
    vector<string> ans = huffmanCodes(s, freq);
    
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}

// 0
// 10
// 110
// 111
