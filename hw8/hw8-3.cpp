#include <deque>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int main()
{
    int queryHandledCount, timeSpan, timeSpanCount, queryCount;
    cin >> queryHandledCount >> timeSpan >> timeSpanCount;
    cin >> queryCount;

    priority_queue<int, vector<int>, greater<int> > queue;
    
    vector<int> queries(queryCount);
    
    for (int i = 0; i < queryCount; i++)
    {
        cin >> queries[i];
    }
    
    int currStart = 0;
    int currEnd = timeSpan;
    for (int i = 0; i < timeSpanCount; i++)
    {
        
        while(currStart != currEnd && currStart < queryCount)
        {
            queue.push(queries[currStart]);
            currStart++;
        }

        for (int j = 0; j < queryHandledCount; j++)
        {
            cout << queue.top() << ' ';
            queue.pop();
        }

        currStart = currEnd;
        currEnd += timeSpan;
    }
    
    cout << '\n';
    return 0;
}