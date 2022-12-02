#include <iostream>
#include <cmath>
using namespace std;

struct Node 
{
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr) {}
};

int submaskCount = 0;

void FindSubmasks(Node* root, int mask)
{
    if(mask == 0) return;
    
    if(mask % 2 == 1)
    {
        if(root->left == nullptr)
        {
            submaskCount++;
            root->left = new Node();
        }

        FindSubmasks(root->left, mask >> 1);
    }

    if(root->right == nullptr) root->right = new Node();
    
    FindSubmasks(root->right, mask >> 1);
}

int main() 
{
    int maskCount;
    cin >> maskCount;

    Node* root = new Node();
    
    for (int i = 0; i < maskCount; i++)
    {
        int mask;
        cin >> mask;
        FindSubmasks(root, mask);
    }
    
    cout << submaskCount + 1 << '\n';

    return 0;
}