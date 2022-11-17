#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;

int binarySearch(int v[], int size, int value)
{
    int lo = 0, hi = size - 1;
    int mid;
    
    while (hi - lo > 1) 
    {
        int mid = (hi + lo) / 2;
        if (v[mid] < value) 
        {
            lo = mid + 1;
        }
        else 
        {
            hi = mid;
        }
    }
    if (v[lo] == value) 
    {
        return lo;
    }
    else if (v[hi] == value) 
    {
        return hi;
    }
    else 
    {
        return -1;
    }
}

int main()
{
    int queryCount = 11, maxPackageCount = 3;
    cin >> queryCount >> maxPackageCount;

    int currPackageCount = 0;
    int queries[maxPackageCount];
    
    for (int i = 0; i < queryCount; i++)
    {
        cin >> queries[i];
    }
    
    list<int> packageList;
    int packagesSorted[maxPackageCount];
    packagesSorted[0] = queries[0];

    for (size_t i = 0; i < queryCount; i++)
    {
        
        //auto itr = find(packageList.begin(), packageList.end(), queries[i]);
        if(itr != packageList.end())
        {
            cout << "true\n";
            packageList.erase(itr);
            packageList.push_front(*itr);
            continue;
        }

        if(currPackageCount < maxPackageCount) 
        {
            cout << "false\n";
            packageList.push_front(queries[i]);
            currPackageCount++;    
            continue;
        }
        
        cout << "false\n";
        packageList.pop_back();
        packageList.push_front(queries[i]);
    }

    return 0;
}
