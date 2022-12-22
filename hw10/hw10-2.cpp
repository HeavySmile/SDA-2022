#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void dfs(char vertice, map<char, set<char>> &stringGraph, vector<bool> &visited, vector<char> &alphabetSorted) 
{
    if(visited[vertice]) return;
    visited[vertice] = true;

    for (auto i : stringGraph[vertice]) dfs(i, stringGraph, visited, alphabetSorted);

    alphabetSorted.push_back(vertice);
}

int main() 
{
    int stringCount;
    cin >> stringCount;

    vector<string> strings(stringCount);
    map<char, set<char>> stringGraph;
    vector<char> alphabetSorted;
    vector<bool> visited(26, false);
    
    
    for (int i = 0; i < stringCount; i++) cin >> strings[i];

    for (int i = 0; i < stringCount; i++)
    {
        for (int j = 0; j < strings[i].size(); j++) 
        {
            stringGraph[strings[i][j]] = set<char>();
        }
    }
    
    for (int i = 1; i < stringCount; i++) 
    {
        int length = min(strings[i].size(), strings[i - 1].size());
        for (int j = 0; j < length; ++j) 
        {
            if(strings[i][j] != strings[i - 1][j])
            {
                stringGraph[strings[i - 1][j]].insert(strings[i][j]);
                break;
            }
        }
    }

    for (auto i : stringGraph) dfs(i.first, stringGraph, visited, alphabetSorted);

    for (int i = alphabetSorted.size() - 1; i >= 0; i--) cout << alphabetSorted[i] << ' ';
    
}