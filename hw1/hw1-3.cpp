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
 
    for (size_t i = 1; i <= ticketCount; i++)
    {
        if (!present[i]) 
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << ticketCount + 1 << endl;
}

// int main()
// {
//     unsigned int ticketCount;
//     cin >> ticketCount;

//     if(ticketCount < 1 || ticketCount > pow(10,6)) return 1;

//     vector<long int> tickets;
//     for (size_t i = 0; i < ticketCount; i++)
//     {
//         long int ticket;
//         cin >> ticket;

//         if(ticket < -pow(2,31) || ticket > pow(2,31) - 1) return 1;

//         tickets.push_back(ticket);
//     }
    
//     long int minTicket = pow(2,31);
//     for (size_t i = 0; i < ticketCount; i++)
//     {
//         if(tickets[i] > 0 && minTicket > tickets[i]) minTicket = tickets[i];
//     }

//     size_t i;
//     for (i = minTicket; i < ticketCount + 1; i++)
//     {
//         bool ticketFound = false;
//         for (size_t j = 0; j < ticketCount; j++)
//         {
//             if(tickets[j] > 0 && tickets[j] == i + 1)
//             {
//                 ticketFound = true;
//                 break;
//             } 
//         }

//         if(!ticketFound)
//         {
//             cout << i + 1 << endl;
//             return 0;
//         }    
//     }
    
//     cout << minTicket + 1 << endl;
//     return 0;
// }
    // vector<long int> possibleVariants;
    // for (size_t i = 0; i < ticketCount; i++)
    // {
    //     if(tickets[i] > 0)
    //     {
    //         bool ticketFound = false;
    //         for (size_t j = 0; j < ticketCount; j++)
    //         {
    //             if(tickets[j] == tickets[i] + 1) 
    //             {
    //                 ticketFound = true;
    //                 break;
    //             }
    //         }
    //         if(!ticketFound) 
    //         {
    //             possibleVariants.push_back(tickets[i] + 1);    
    //         }
    //     }
    // }
    
    // long int minTicket = possibleVariants[0];
    // for (size_t i = 1; i < possibleVariants.size(); i++)
    // {
    //     if(minTicket > possibleVariants[i]) minTicket = possibleVariants[i];
    // }

    // cout << minTicket << endl;

// for (size_t i = 0; i < ticketCount - 1; i++)
    // {
    //     for (size_t j = 0; j < ticketCount - i - 1; j++)
    //     {
    //         if(tickets[j] > tickets[j + 1])
    //         {
    //             swap(tickets[j], tickets[j + 1]);
    //         }
    //     }
    // }
    // for (size_t i = 0; i < ticketCount - 1; i++)
    // {
    //     if(tickets[i] > 0 && tickets[i] != tickets[i + 1] && tickets[i] != tickets[i + 1] - 1) 
    //     {
    //         cout << tickets[i] + 1 << endl;
    //         return 0;
    //     }
    // }
    // cout << tickets[ticketCount - 1] + 1 << endl;
