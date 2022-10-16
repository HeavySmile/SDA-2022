#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string filmSeq;
    cin >> filmSeq;

    if(filmSeq.length() < 0 || filmSeq.length() > 20 * pow(10,6)) return 1;

    for (size_t i = 0; i < filmSeq.length(); i++)
    {
        char ch = filmSeq[i];
        if( (ch < 'a' || ch > 'z') && 
            (ch < 'A' || ch > 'Z') && 
            (ch < '0' || ch > '9')) return 1;
    }
    
    int filmsDigit['9' - '0' + 1] = { -1 };
    int filmsUpper['Z' - 'A' + 1] = { -1 };
    int filmsLower['z' - 'a' + 1] = { -1 };

    fill_n(filmsDigit, '9' - '0' + 1, -1);
    fill_n(filmsUpper, 'Z' - 'A' + 1, -1);
    fill_n(filmsLower, 'z' - 'a' + 1, -1);

    for (size_t i = 0; i < filmSeq.length(); i++)
    {
        char ch = filmSeq[i];
        char chArea;
        int* arr;

        if(ch >= '0' && ch <= '9') 
        {
            chArea = '0';
            arr = filmsDigit;
        }
        if(ch >= 'A' && ch <= 'Z') 
        {
            chArea = 'A';
            arr = filmsUpper;
        }
        if(ch >= 'a' && ch <= 'z') 
        {
            chArea = 'a';
            arr = filmsLower;
        }
        
        if(arr[ch - chArea] == -1) arr[ch - chArea] = i;
        else arr[ch - chArea] = -2;
    }

    vector<size_t> idxes;

    for (size_t i = 0; i < '9' - '0' + 1; i++)
    {
        if(filmsDigit[i] != -2 && filmsDigit[i] != -1) idxes.push_back(filmsDigit[i]);
    }
    for (size_t i = 0; i < 'z' - 'a' + 1; i++)
    {
        if(filmsUpper[i] != -2 && filmsUpper[i] != -1) idxes.push_back(filmsUpper[i]);
        if(filmsLower[i] != -2 && filmsLower[i] != -1) idxes.push_back(filmsLower[i]);
    }
    
    sort(idxes.begin(), idxes.end());
    
    for (size_t i = 0; i < idxes.size(); i++)
    {
        cout << idxes[i] << " ";
    }
    cout << endl;
    
    return 0;
}