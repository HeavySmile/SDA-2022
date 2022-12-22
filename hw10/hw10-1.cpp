#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

unordered_map <int, bool> visited;
unordered_map <int, int> group;

bool findWithBFS(unordered_map<int, vector<int>> graph, int start, int offset) 
{
    queue<int> bfsQueue;
    bfsQueue.push(start);
    
    visited[start] = true;
    group[start] = offset;
    
    while (!bfsQueue.empty()) 
    {
        int front = bfsQueue.front();
        group[bfsQueue.front()] = offset;
        bfsQueue.pop();
        
        for (auto x : graph[front]) 
        {
            if(!visited[x]) 
            {
                visited[x] = true;
                bfsQueue.push(x);
            }
        }
    }
    
    return false;
}

int main() 
{
    int verticeCount, edgeCount;
    cin >> verticeCount >> edgeCount;
    
    vector<int> vertices;
    unordered_map<int, vector <int>> graph;
    int offset = 0;

    for (int i = 0; i < edgeCount; i++) 
    {
        int start, end;
        cin >> start >> end;
        
        if(graph.find(start) != graph.end()) vertices.push_back(start);
        if(graph.find(end) != graph.end()) vertices.push_back(end);
            
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    
    for (auto v : vertices) visited[v] = false;
    
    for (int i = 0; i < verticeCount; i++) 
    {
        if (!visited[vertices[i]]) 
        {   
            findWithBFS(graph, vertices[i], offset);
            offset++;
        }
    }
    
    int queryCount;
    cin >> queryCount;
    
    vector<bool> results;
    for (int i = 0; i < queryCount; i++) 
    {
        int start, end;
        cin >> start >> end;
        
        cout << (group[start] == group[end]) << " ";
        //results.push_back(group[start] == group[end]);
    }
    // for (auto res : results) 
    // {
    //     cout << res << " ";
    // }
    return 0;
    
}