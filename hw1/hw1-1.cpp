#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Roommates task

int main()
{
    vector<int> changesCountList;

    int listCount;
    cin >> listCount;

    if(listCount < 1 || listCount > 10) return 1;

    for (size_t i = 0; i < listCount; i++)
    {
        int len;
        cin >> len;

        if(len < 1 || len > pow(10,6)) return -1;

        char* list = new char[len + 1];
        cin >> list;
        
        char currChar = list[0];
        int changesCount = 0;
        for (size_t i = 1; i < len; i++)
        {
            if(list[i] == currChar) changesCount++;
            else currChar = list[i];
        }
        
        changesCountList.push_back(changesCount);
        
        delete[] list;
    }
    
    cout << endl;
    for (size_t i = 0; i < changesCountList.size(); i++)
    {
        cout << changesCountList[i] << endl;
    }
    

    return 0;
}