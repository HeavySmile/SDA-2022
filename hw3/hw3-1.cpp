#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
 
    return -1;
}
 
void rec(vector<int>& sweets, vector<int>& friends, int recDepth, int start, int end)
{
    if(end == start) 
    {
        int friendIdx = binarySearch(friends, 0, friends.size() - 1, start + 1);
        
        if(friendIdx != -1) sweets[friendIdx] = recDepth;
        
        return;
    }
    
    for (int i = start + ((end - start + 1) / 3); i < start + ((end - start + 1) / 3) * 2; i++)
    {
        int friendIdx = binarySearch(friends, 0, friends.size() - 1, i + 1);

        if(friendIdx != -1) sweets[friendIdx] = recDepth;
    }
    
    rec(sweets, friends, recDepth + 1, start, start + ((end - start + 1) / 3) - 1);
    rec(sweets, friends, recDepth + 1, start + ((end - start + 1) / 3) * 2, end);
}

int main()
{
    int p, n;
    cin >> p >> n;

    vector<int> friendNumbers;
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        friendNumbers.push_back(value);
    }
    
    vector<int> sweets(n);
    
    rec(sweets, friendNumbers, 1, 0, pow(3,p) - 1);

    for (size_t i = 0; i < friendNumbers.size(); i++)
    {
        cout << sweets[i] << endl;
    }
    
    return 0;
}