#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

class Node 
{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node(int value)
    {
        prev = nullptr; 
        data = value; 
        next = nullptr; 
    }
};
 
Node* insert_at_head(Node*& head, int value)
{
    Node* n = new Node(value);
    n->next = head;
 
    if (head != nullptr) 
    {
        head->prev = n;
    }
 
    head = n;

    return n;
}
 
Node* insert_at_tail(Node*& head, int value)
{
 
    if (head == nullptr) 
    {
        return insert_at_head(head, value);;
    }
 
    Node* n = new Node(value);
    Node* temp = head;
 
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;

    return n;
}


void display(Node* head)
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << '\n';
}

class Shell
{
public:
    Node* head;
    int counter;
    Shell(Node* head, int counter = 0) : head(head), counter(counter) {}
};

Shell collapse(Node* head, Node* position)
{
    if(head == nullptr) return Shell(head, 0);
    if(position == nullptr) return Shell(head, 0);

    Node* leftNode = position;
    Node* rightNode = position;
    int counter = 1;

    while(leftNode->prev != nullptr && leftNode->prev->data == position->data)
    {  
        leftNode = leftNode->prev;
        counter++;
    }

    while(rightNode->next != nullptr && rightNode->next->data == position->data)
    {
        rightNode = rightNode->next;
        counter++;
    }
    
    if(counter >= 3) 
    {
        if(leftNode->prev == nullptr && rightNode->next == nullptr)
        {
            //head = nullptr;
            return Shell(nullptr, counter); 
        }
        else if(leftNode->prev == nullptr && rightNode->next != nullptr)
        { 
            rightNode->next->prev = nullptr;
            head = rightNode->next;
        }
        else if(rightNode->next == nullptr && leftNode->prev != nullptr)
        {
            leftNode->prev->next = nullptr;
        }
        else if(leftNode->prev != nullptr && rightNode->next != nullptr)
        {
            leftNode->prev->next = rightNode->next;
            rightNode->next->prev = leftNode->prev;
        }
        
        Shell shell = collapse(head, rightNode->next);
        shell.counter += counter;
        return shell; 
    }
    
    
    return Shell(head, 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int ballCount = 10;
    cin >> ballCount;
    
    Node* head = nullptr;
    Node* initialNodes[ballCount];
    for (int i = 0; i < ballCount; i++)
    {
        int value;
        cin >> value;

        initialNodes[i] = insert_at_tail(head, value);
    }
    
    int queryCount = 10;
    cin >> queryCount;
    
    int positions[queryCount];
    int colors[queryCount];
    for (int i = 0; i < queryCount; i++)
    {
        cin >> positions[i] >> colors[i];
    }
    
    for (int i = 0; i < queryCount; i++)
    {
        if(head == nullptr) cout << "Game Over\n";
        else 
        {
            int position = positions[i];
            Node* newNode = new Node(colors[i]);
            Node* temp = newNode;
            
            newNode->next = initialNodes[position]->next;
            newNode->prev = initialNodes[position];
            
            if(newNode->prev != nullptr) newNode->prev->next = newNode;
            if(newNode->next != nullptr) newNode->next->prev = newNode;
            
            Shell shell = collapse(head, newNode);
            cout << shell.counter << '\n';
            head = shell.head;
        }
    }
    
    if(head != nullptr)
    {
        display(head);
    }
    else cout << -1 << '\n';

    return 0;
}