#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct Purchase 
{
    int index; 
    int start; 
    int duration;
};

bool longStart(Purchase first, Purchase second)
{
    return (first.duration == second.duration && 
           first.index > second.index) || 
           first.duration > second.duration;
}

bool earlyStart(Purchase first, Purchase second)
{
    return first.start < second.start;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int purchaseCount;
    cin >> purchaseCount;

    vector<Purchase> purchases(purchaseCount);
    for (int i = 0; i < purchaseCount; i++) 
    {
        cin >> purchases[i].start >> purchases[i].duration;
        purchases[i].index = i;
    }

    sort(purchases.begin(), purchases.end(), earlyStart);
    
    priority_queue<Purchase, vector<Purchase>, function<bool(Purchase, Purchase)>> purchasesQueue(longStart);
    
    int time = purchases[0].start;
    int currIdx = 0;
    
    while(!purchasesQueue.empty() || currIdx < purchaseCount) 
    {
        while(currIdx < purchaseCount && purchases[currIdx].start <= time) 
        {
            purchasesQueue.push(purchases[currIdx]);
            currIdx++;
        }

        if(purchasesQueue.empty()) 
        {
            time = purchases[currIdx].start;
            continue;
        }

        cout << purchasesQueue.top().index << ' ';
        
        time += purchasesQueue.top().duration;
        purchasesQueue.pop();
    }

    return 0;
}