#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int first(vector<int> arr, int start, int end, int min, int max)
{
    if (end >= start) 
    {
        int mid = start + (end - start) / 2;
        
        if ((mid == 0 || min > arr[mid - 1]) && arr[mid] >= min && arr[mid] <= max) return mid;
        else if (min > arr[mid]) return first(arr, (mid + 1), end, min, max);
        else return first(arr, start, (mid - 1), min, max);     
    }
    return -1;
}
 
int last(vector<int> arr, int start, int end, int min, int max)
{
    if (end >= start) 
    {
        int mid = start + (end - start) / 2;
        
        if ((mid == arr.size() - 1 || max < arr[mid + 1]) && arr[mid] >= min && arr[mid] <= max) return mid;
        else if (max < arr[mid]) return last(arr, start, (mid - 1), min, max);
        else return last(arr, (mid + 1), end, min, max);
    }
    return -1;
}

class Tournament
{
public:
    int min;
    int max;
    int participants;
    Tournament(const int min, const int max) : min(min), max(max), participants(0) {}
};

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> weights;
    for (size_t i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        weights.push_back(value);
    }
    
    vector<Tournament> tournaments;
    for (size_t i = 0; i < q; i++)
    {
        int minValue, maxValue;
        cin >> minValue >> maxValue;

        tournaments.push_back(Tournament(minValue, maxValue));
    }
    
    sort(weights.begin(), weights.end());

    for (size_t i = 0; i < tournaments.size(); i++)
    {
        int firstIdx = first(weights, 0, n - 1, tournaments[i].min, tournaments[i].max);
        int lastIdx = last(weights, 0, n - 1, tournaments[i].min, tournaments[i].max);
        
        if(firstIdx != -1 && lastIdx != -1)
        {
            tournaments[i].participants = lastIdx - firstIdx + 1;
        }
    }
    
    for (size_t i = 0; i < tournaments.size(); i++)
    {
        cout << tournaments[i].participants << '\n';
    }
    return 0;
}