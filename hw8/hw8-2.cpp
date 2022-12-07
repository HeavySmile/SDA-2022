#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    int citizenCount;
    cin >> citizenCount;

    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    double median = 0;
    int citizenMoney;
    
    while(citizenCount > 0) 
    {
        cin >> citizenMoney;

        int difference = maxHeap.size() - minHeap.size();
        if(difference == 0)
        {
            if(median > citizenMoney) 
            {
                maxHeap.push(citizenMoney);
                median = maxHeap.top();
            }
            else 
            {
                minHeap.push(citizenMoney);
                median = minHeap.top();
            }
        }
        else if(difference == 1)
        {
            if(median > citizenMoney)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(citizenMoney);
            }
            else minHeap.push(citizenMoney);
            
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            if(median >= citizenMoney) maxHeap.push(citizenMoney);
            else 
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(citizenMoney);
            }
            
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }

        // switch(maxHeap.size() - minHeap.size()) 
        // {
        //     case 0:
        //         if(median > citizenMoney) 
        //         {
        //             maxHeap.push(citizenMoney);
        //             median = maxHeap.top();
        //         }
        //         else 
        //         {
        //             minHeap.push(citizenMoney);
        //             median = minHeap.top();
        //         }
        //         break;
            
        //     case 1:
        //         if(median > citizenMoney)
        //         {
        //             minHeap.push(maxHeap.top());
        //             maxHeap.pop();
        //             maxHeap.push(citizenMoney);
        //         }
        //         else minHeap.push(citizenMoney);
                
        //         median = (maxHeap.top() + minHeap.top()) / 2;
        //         break;
            
        //     default:
        //         if(median >= citizenMoney) maxHeap.push(citizenMoney);
        //         else 
        //         {
        //             maxHeap.push(minHeap.top());
        //             minHeap.pop();
        //             minHeap.push(citizenMoney);
        //         }
                
        //         median = (maxHeap.top() + minHeap.top()) / 2;
        // }
        
        cout << median << '\n';
        citizenCount--;
    }

    return 0;
}