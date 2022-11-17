#include <iostream>
#include <deque>
using namespace std;
 
int main()
{
    int numberCount, subSetSize;
    cin >> numberCount >> subSetSize;
    
    int arr[numberCount];
    for (int i = 0; i < numberCount; i++)
    {
        cin >> arr[i];
    }
    
    deque<int> indexes(subSetSize);
    int sumOfMin = 0;
   
    int i;
    for (i = 0; i < subSetSize; ++i) 
    {
        while ((!indexes.empty()) && arr[i] < arr[indexes.back()]) indexes.pop_back();
 
        indexes.push_back(i);
    }
 
    for (; i < numberCount; ++i) 
    {
        sumOfMin += arr[indexes.front()];

        while ((!indexes.empty()) && indexes.front() <= i - subSetSize) indexes.pop_front();
 
        while ((!indexes.empty()) && arr[i] < arr[indexes.back()]) indexes.pop_back();
            
        indexes.push_back(i);
    }
    
    sumOfMin += arr[indexes.front()];

    cout << sumOfMin << '\n';
    return 0;
}