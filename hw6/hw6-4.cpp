#include <iostream>
#include <vector>
#include <string>
using namespace std;

//const int ALPHABET_SIZE = 26;

struct Node
{
    Node* characters[26];
    bool isEnd;
};
 
Node* createNode()
{
    Node* pNode =  new Node;
    pNode->isEnd = false;
 
    for(int i = 0; i < 26; i++) pNode->characters[i] = nullptr;
 
    return pNode;
}

void insert(Node* root, string word)
{
    Node* currNode = root;
 
    for(int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if(currNode->characters[index] == nullptr) currNode->characters[index] = createNode();
 
        currNode = currNode->characters[index];
    }
 
    currNode->isEnd = true;
}

bool search(Node* root, string word)
{
    Node* currNode = root;
 
    for(int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if(currNode->characters[index] == nullptr) return false;

        currNode = currNode->characters[index];
    }
 
    return currNode->isEnd;
}
 

int main()
{
    long long wordCount;
    cin >> wordCount;

    Node* root = createNode();
    for(long long i = 0; i < wordCount; i++)
    {
        string word;
        cin >> word;

        insert(root, word);
    }
    
    long long queryCount;
    cin >> queryCount;

    for(long long i = 0; i < queryCount; i++)
    {
        string word;
        cin >> word;
        cout << (search(root, word) ? "YES\n" : "NO\n");
    }
    
    return 0;
}