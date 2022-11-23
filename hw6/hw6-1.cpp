#include <iostream>
#include <vector>
using namespace std;
 
struct Node
{
    long long data, leftIdx, rightIdx;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr), leftIdx(0), rightIdx(0) {}
    Node(long long data) : data(data), left(nullptr), right(nullptr), leftIdx(0), rightIdx(0) {}
};

struct ListNode 
{
    long long data;
    ListNode* prev;
    ListNode* next;
};

Node* CreateNewNode(long long data)
{
    Node* temp = new Node;
    
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    
    return temp;
}
 
ListNode* CreateNewListNode(long long data)
{
    ListNode* temp = new ListNode;
    
    temp->data = data;
    temp->prev = nullptr;
    temp->next = nullptr;
    
    return temp;
}
 
void ComputeVerticalSum(Node* root, vector<long long> sum)
{
    sumNode->data = sumNode->data + root->data;
 
    if(root->left != nullptr) 
    {
        if (sumNode->prev == nullptr) 
        {
            sumNode->prev = CreateNewListNode(0);
            sumNode->prev->next = sumNode;
        }
        ComputeVerticalSum(root->left, sumNode->prev);
    }
 
    if(root->right != nullptr) 
    {
        if(sumNode->next == nullptr) 
        {
            sumNode->next = CreateNewListNode(0);
            sumNode->next->prev = sumNode;
        }
        ComputeVerticalSum(root->right, sumNode->next);
    }
}

int main()
{
    long long nodeCount;
    cin >> nodeCount;

    vector<Node> nodes(nodeCount);
    for (long long i = 0; i < nodeCount; i++)
    {
        cin >> nodes[i].data >> nodes[i].leftIdx >> nodes[i].rightIdx;
    }
    
    for (long long i = 0; i < nodeCount; i++)
    {
        long long leftIdx = nodes[i].leftIdx;
        long long rightIdx = nodes[i].rightIdx;

        if(leftIdx != -1) nodes[i].left = &nodes[leftIdx];
        else nodes[i].left = nullptr;
        
        if(rightIdx != -1) nodes[i].right = &nodes[rightIdx];
        else nodes[i].right = nullptr;   
    }
    
    ListNode* sumNode = CreateNewListNode(0);
    ComputeVerticalSum(&nodes[0], sumNode);
    
    while(sumNode->prev != nullptr) sumNode = sumNode->prev;
    while(sumNode != nullptr) 
    {
        cout << sumNode->data << " ";
        sumNode = sumNode->next;
    }
    
    return 0;
}