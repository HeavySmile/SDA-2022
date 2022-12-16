#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    int arrSize;
    cin >> arrSize;

    int array[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        cin >> array[i];
    } 

    int maxCount = 0;
    unordered_map<int, int> elementsIndexes;
    
    for (int i = 0, j = 0; i < arrSize; i++) 
    {
        j = max(elementsIndexes[array[i]], j);
        maxCount = max(maxCount, i - j + 1);
        elementsIndexes[array[i]] = i + 1;
    }
    
    cout << maxCount << '\n';
}