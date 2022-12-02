#include <iostream>
using namespace std;
 
struct Node 
{
    int data, entryIdx;
    Node *left, *right;
    Node(int data, int entryIdx) : data(data), entryIdx(entryIdx), left(nullptr), right(nullptr) {}
};
 
Node* Insert(Node* root, int value, int entryIdx)
{
    if(root == nullptr) return new Node(value, entryIdx);
 
    if(value > root->data) root->right = Insert(root->right, value, entryIdx);
    else if(value < root->data) root->left = Insert(root->left, value, entryIdx);
 
    return root;
}
 
void Inorder(Node* root)
{
    if(root == nullptr) return;
    
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

int main()
{
    int fieldSize, shipCount, shipSize;
    cin >> fieldSize >> shipCount >> shipSize;

    int queryCount;
    cin >> queryCount;

    Node* root = nullptr;
    for (int i = 0; i < queryCount; i++)
    {
        int query;
        cin >> query;

        root = Insert(root, query, i + 1);
    }
    
    //Inorder(root);

    return 0;
}