#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <climits>
using namespace std;

void createGraph(vector<vector<int>> &graph, int verticeCount)
{
    for (int i = 0; i < verticeCount; i++)
    {
        for (int j = 0; j < verticeCount; j++)
        {
            if(j == i) continue;
            graph[i].push_back(j);
        }
    }
}

void deleteNode(vector<vector<int>> &graph, int start, int end)
{
    for (int i = 0; i < graph[start].size(); i++) 
    {
        if (graph[start][i] == end) 
        {
            graph[start].erase(graph[start].begin() + i);
            break;
        }
    }

    for (int i = 0; i < graph[end].size(); i++) 
    {
        if (graph[end][i] == start) 
        {
            graph[end].erase(graph[end].begin() + i);
            break;
        }
    }
}

bool BFS(vector<vector<int>> graph, int start, int end, int distance[])
{
    list<int> queue;
    bool visited[graph.size()];
 
    for (int i = 0; i < graph.size(); i++) 
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
 
    visited[start] = true;
    distance[start] = 0;
    queue.push_back(start);
 
    while (!queue.empty()) 
    {
        int u = queue.front();
        queue.pop_front();
        
        for (int i = 0; i < graph[u].size(); i++) 
        {
            if (visited[graph[u][i]] == false) 
            {
                visited[graph[u][i]] = true;
                distance[graph[u][i]] = distance[u] + 1;
                queue.push_back(graph[u][i]);
 
                if(graph[u][i] == end) return true;
            }
        }
    }
 
    return false;
}

int main()
{
    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++)
    {
        int verticeCount, edgeCount;
        cin >> verticeCount >> edgeCount;

        vector<vector<int>> graph(verticeCount);
        createGraph(graph, verticeCount);

        for (int j = 0; j < edgeCount; j++)
        {
            int start, end;
            cin >> start >> end;

            deleteNode(graph, start - 1, end - 1);
        }
        
        int initialVertice;
        cin >> initialVertice;

        for (int j = 0; j < verticeCount; j++)
        {
            if(j == initialVertice - 1) continue;

            int distance[graph.size()];
 
            if (BFS(graph, initialVertice - 1, j, distance) == false) 
            {
                cout << -1 << " ";
                continue;
            }
        
            cout << distance[j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}