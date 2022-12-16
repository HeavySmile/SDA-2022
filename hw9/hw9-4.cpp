#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string firstString, secondString;
    cin >> firstString >> secondString;
 
    int** table = new int*[firstString.size() + 1];
    
    for (int i = 0; i < firstString.size() + 1; i++)
    {
        table[i] = new int[secondString.size() + 1];
    }
    
    int maxLength = 0;
 
    for (int i = 0; i < firstString.size() + 1; i++)
    {
        for (int j = 0; j < secondString.size() + 1; j++)
        {
            if(i != 0 && j != 0 && firstString[i - 1] == secondString[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                maxLength = max(maxLength, table[i][j]);
                continue;
            }
            
            table[i][j] = 0;
        }
    }
 
    cout << maxLength << '\n';
    
    return 0;
}