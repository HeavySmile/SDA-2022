#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
    long long data, leftIdx, rightIdx;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr), leftIdx(0), rightIdx(0) {}
    Node(long long data) : data(data), left(nullptr), right(nullptr), leftIdx(0), rightIdx(0) {}
};

bool InorderTraversal(Node* root, Node* &prev)
{
    if(root != nullptr) 
    {
        if(!InorderTraversal(root->left, prev) || 
           (prev != nullptr && root->data <= prev->data)) return false;
        
        prev = root;
 
        return InorderTraversal(root->right, prev);
    }
 
    return true;
}
 
bool IsBinaryTree(Node* root)
{
    Node* prev = nullptr;
    return InorderTraversal(root, prev);
}

int main()
{
    long long treeCount;
    cin >> treeCount;

    //vector< vector<Node> > trees(treeCount);
    for(long long i = 0; i < treeCount; i++)
    {
        long long nodeCount;
        cin >> nodeCount;
    
        vector<Node> nodes(nodeCount);
        for(long long j = 0; j < nodeCount; j++)
        {
            cin >> nodes[j].data >> nodes[j].leftIdx >> nodes[j].rightIdx;
        }
        
        for(long long j = 0; j < nodeCount; j++)
        {
            long long leftIdx = nodes[j].leftIdx;
            long long rightIdx = nodes[j].rightIdx;

            if(leftIdx != -1) nodes[j].left = &nodes[leftIdx];
            else nodes[j].left = nullptr;
            
            if(rightIdx != -1) nodes[j].right = &nodes[rightIdx];
            else nodes[j].right = nullptr;   
        }

        cout << IsBinaryTree(&nodes[0]) << '\n';

    }
    
    return 0;
}