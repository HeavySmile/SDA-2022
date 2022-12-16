#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberCount;
    long magicalNumber;
    cin >> numberCount >> magicalNumber;

    vector<int> numbers(numberCount);
    unordered_map<long, long> oneNumbers;
    unordered_map<long, unordered_map<long, long>> twoNumbers;

    for (int i = 0; i < numberCount; i++) cin >> numbers[i];    

    long tripleCount = 0;
    for (int i = numberCount; i >= 0; i--)
    {
        long temp = numbers[i];

        auto add = [&]()
        {
            twoNumbers[temp][temp * magicalNumber] += oneNumbers[temp * magicalNumber];
            ++oneNumbers[temp];
        };
        
        tripleCount += twoNumbers[temp * magicalNumber][temp * magicalNumber * magicalNumber];

        add();
    }

    cout << tripleCount;

    return 0;
}