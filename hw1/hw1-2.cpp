#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 
// Investing 101 task

int main()
{
    int dayCount;
    cin >> dayCount;

    if(dayCount < 1 || dayCount > pow(10,5)) return 1;
    
    vector<unsigned int> coinPrices;
    for (size_t i = 0; i < dayCount; i++)
    {
        unsigned int coinPrice;
        cin >> coinPrice;

        if(coinPrice < 0 || coinPrice > pow(10,5)) return 1;

        coinPrices.push_back(coinPrice);
    }
 
    int profit = 0;
    int i = 0;
    
    while (i < dayCount - 1)
    {
        while ((i < dayCount - 1) && (coinPrices[i + 1] <= coinPrices[i])) i++;
 
        if (i == dayCount - 1) break;
            
        int buy = i++;
 
        while ((i < dayCount) && (coinPrices[i] >= coinPrices[i - 1])) i++;
 
        int sell = i - 1;

        profit += coinPrices[sell] - coinPrices[buy];
    }

    cout << profit << endl;

    return 0;
}
