#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
int main()
{
    unsigned int ticketCount;
    cin >> ticketCount;

    if(ticketCount < 1 || ticketCount > pow(10,6)) return 1;

    vector<long int> tickets;
    for (size_t i = 0; i < ticketCount; i++)
    {
        long int ticket;
        cin >> ticket;

        if(ticket < -pow(2,31) || ticket > pow(2,31) - 1) return 1;

        tickets.push_back(ticket);
    }
    
    bool present[ticketCount + 1];
    for (size_t i = 0; i < ticketCount + 1; i++)
    {
        present[i] = false;
    }
    
    for (size_t i = 0; i < ticketCount; i++) 
    { 
       if (tickets[i] > 0 && tickets[i] <= ticketCount) present[tickets[i]] = true;     
    }
 
    for (size_t i = 1; i < ticketCount + 1; i++)
    {
        if (!present[i]) 
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << ticketCount + 1 << endl;
}