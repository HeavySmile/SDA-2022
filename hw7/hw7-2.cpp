#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

int boxMaxSize = 0;

void boxMax(vector<int> sweets, int index)
{
    set<int> box;

    for (int i = index; i < sweets.size(); i++)
    {
        if(!box.insert(sweets[i]).second)
        {
            if(box.size() > boxMaxSize) boxMaxSize = box.size();
            
            boxMax(sweets, i);
        }
    }
    
    if(box.size() > boxMaxSize) boxMaxSize = box.size();
}

// C++ program to implement
// the above approach
  
// Function to find largest
// subarray with no duplicates
int GetBoxMaxSweets(vector<int> sweets)
{
    int maxCount = 0;
    unordered_map<int, int> sweetIndexes;
    
    for (int i = 0, j = 0; i < sweets.size(); i++) 
    {
        j = max(sweetIndexes[sweets[i]], j);
        maxCount = max(maxCount, i - j + 1);
        sweetIndexes[sweets[i]] = i + 1;
    }
  
    return maxCount;
}

int main()
{
    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++)
    {
        int sweetCount;
        cin >> sweetCount;
        
        vector<int> sweets(sweetCount);
        for (int j = 0; j < sweetCount; j++)
        {
            cin >> sweets[j];
        }
        
        cout << GetBoxMaxSweets(sweets) << '\n';
        boxMaxSize = 0;
    }
    
    return 0;
}