#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long unsigned int betCount;
    cin >> betCount;

    if(betCount < 1 || betCount > pow(10,6)) return 1;

    unsigned short int bets[betCount];
    for (size_t i = 0; i < betCount; i++)
    {
        unsigned short int bet;
        cin >> bet;

        if(bet < 0 || bet > 1000) return 1;

        bets[i] = bet;
    }

    unsigned short int blacks[betCount];
    size_t counter = 0;
    for (size_t i = 0; i < betCount; i++)
    {
        if(bets[i] % 2 == 0) cout << bets[i] << endl;
        else blacks[counter++] = bets[i];
    }
    
    for (size_t i = 0; i < counter; i++)
    {
        cout << blacks[i] << endl;
    }
    
    return 0;
}

    // vector<unsigned short int> betsSorted;
    // for (size_t i = 0, lastRedIdx = 0; i < betCount; i++)
    // {
    //     if(bets[i] % 2 == 0) 
    //     {
    //         betsSorted.insert(betsSorted.begin() + lastRedIdx, bets[i]);
    //         lastRedIdx++;
    //     }
        
    //     else betsSorted.insert(betsSorted.begin() + i, bets[i]);
    // }
    
    // for (size_t i = 0; i < betsSorted.size(); i++)
    // {
    //     cout << betsSorted[i] << endl;
    // }


    // int countEven = 0;
    // for(int i = 0; i < betCount; i++) 
    // {
    //     if(bets[i] % 2 == 0) countEven++;
    // }
    
    // int i = 0, j = i + 1;
    // while(i != countEven)
    // {
    //     if(bets[i] % 2 == 0)
    //     {
    //         i++;
    //         j = i + 1;
    //     }
    //     else if(bets[i] % 2 == 1 && j < betCount)
    //     {
    //         swap(bets[i], bets[j]);
    //         j++;
    //     }
    // }
    
    // for (size_t i = 0; i < betCount; i++)
    // {
    //     cout << bets[i] << endl;
    // }

    
    // size_t blackIndexses[betCount];
    // size_t counter = 0;
    // for (size_t i = 0; i < betCount; i++)
    // {
    //     if(bets[i] % 2 == 0) cout << bets[i] << endl;
    //     else blackIndexses[counter++] = i;
    // }
    
    // for (size_t i = 0; i < counter; i++)
    // {
    //     cout << bets[blackIndexses[i]] << endl;
    // }