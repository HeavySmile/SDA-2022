#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    long double var1, var2;
    char operation;
    
    bool flag = true;
    while(flag)
    {
        cin >> var1 >> operation >> var2;
        switch (operation)
        {
            case '+': cout << var1 + var2 << endl;
                break;
            case '-': cout << var1 - var2 << endl;
                break;
            case '*': cout << var1 * var2 << endl;
                break;
            case '/': 
                if(var2 == 0)
                {
                    cout << "Invalid operation" << endl;
                    return 1;
                }
                else cout << var1 / var2 << endl;
                break;

            default: cout << "Invalid operation" << endl;
                break;
        }

        cout << "Do you wish to continue?" << endl;
        cin >> flag;
    }

    
    
    return 0;
}