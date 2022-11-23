#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    long long data;
    //vector<Node*> children;
    Node* parent;
    Node() : data(0), parent(nullptr) {}
    Node(long long data) : data(data), parent(nullptr) {}
};

// Node* GetNodeIfExists(Node* node, int key)
// {
//     if(node == nullptr) return nullptr;
 
//     if(node->data == key) return node;
    
//     for(int i = 0; i < node->children.size(); i++)
//     {
//         Node* result = GetNodeIfExists(node->children[i], key);
//         if(result != nullptr) return result;
//     }
    
//     return nullptr;
// }

Node* GetNodeIfExists(Node* node, int key)
{
    Node* currNode = node;
    while(currNode != nullptr)
    {
        if(currNode->data == key) return currNode;
        currNode = currNode->parent;
    }

    return nullptr;
    // if(node == nullptr) return nullptr;
 
    // if(node->data == key) return node;
    
    // Node* result = GetNodeIfExists(node->parent, key);
    
    // if(result != nullptr) return result;
    
    // return nullptr;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long nodeCount;
    cin >> nodeCount;

    vector<Node> nodes(nodeCount);
    for(long long i = 0; i < nodeCount; i++) nodes[i].data = i;
    
    for(long long i = 0; i < nodeCount - 1; i++)
    {
        long long x, y;
        cin >> x >> y;

        //nodes[x].children.push_back(&nodes[y]);
        nodes[y].parent = &nodes[x];
    }

    long long queryCount;
    cin >> queryCount;

    for(long long i = 0; i < queryCount; i++)
    {
        long long x, y;
        cin >> x >> y;

        Node* temp = GetNodeIfExists(&nodes[y], x);

        cout << (temp != nullptr ? "YES\n" : "NO\n");
    }

    return 0;
}

