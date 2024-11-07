#include <bits/stdc++.h>
using namespace std;

struct node
{

    char ch;
    int freq;
    node *left;
    node *right;
    node(char ch, int freq)
    {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

struct compare
{
    bool operator()(node *a, node *b)
    {
        return a->freq > b->freq;
    }
};

void print(node *root, string ans)
{
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << ans << endl;

    print(root->left, ans + "0");
    print(root->right, ans + "1");
}

void huffman(vector<char> ch_arr, vector<int> freq_arr)
{
    int n = ch_arr.size();
    node *left, *right, *temp;

    priority_queue<node *, vector<node *>, compare> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(new node(ch_arr[i], freq_arr[i]));
    }

    while (pq.size() != 1)
    {
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        temp = new node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        pq.push(temp);
    }

    print(pq.top(), "");
}

int main()
{
    vector<char> ch = {'A', 'B', 'C', 'D'};
    vector<int> freq = {23, 12, 34, 10};

    huffman(ch, freq);
}