#include <bits/stdc++.h>
using namespace std;
struct Node {
    int freq;
    char ch;
    Node *left, *right;
    Node(char c, int f, Node *l = NULL, Node *r = NULL) {
        freq = f;
        ch = c;
        left = l;
        right = r;
    }
};
struct compare {
    bool operator()(Node*l, Node*r) {
        return (l->freq > r->freq);
    }
};
void printcodes(Node *root, string str) {
    // if (!root)
    // return;
    if (root->ch != '$') {
        cout << root->ch << ":" << str << "\n";
        return;
    }
    printcodes(root->left, str + "0");
    printcodes(root->right, str + "1");

}
void printHCodes(char arr[], int freq[], int n)
{
    priority_queue<Node*, vector<Node*>, compare>h;
    for (int i = 0; i < n; i++)
    {
        h.push(new Node(arr[i], freq[i]));
    }
    while (h.size() > 1) {
        Node *l = h.top(); h.pop();
        Node *r = h.top(); h.pop();
        Node *node = new Node('$', l->freq + r->freq, l, r);
        h.push(node);
    }
    printcodes(h.top(), "");
}

int main()
{
    char arr[] = { 'a', 'd', 'e', 'f' };
    int freq[] = { 30, 40, 80, 60 };

    int size = sizeof(arr) / sizeof(arr[0]);

    printHCodes(arr, freq, size);

    return 0;
}
